/***************************************************************************
 
    file                 : QuickBasicDriver.cpp
    copyright            : (C) 2007 Daniele Loiacono
 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include "QuickBasicDriver.h"




/*
CarControl
QuickBasicDriver::wDrive(CarState cs)
{
	float accel,brake,steer;
	int gear;

	accel = 0.5;
	brake = 0.0;
	steer = getSteer(cs);
	gear = 3;
	// build a CarControl variable and return it
	CarControl cc(accel,brake,gear,steer,clutch);

	return cc;

//	return SimpleDriver::wDrive(cs);    		
}
*/

CarControl
QuickBasicDriver::wDrive(CarState cs)
{

	// 检查是否卡住了 
	if ( fabs(cs.getAngle()) > stuckAngle )
    {
		// update stuck counter
        stuck++;
    }
    else
    {
    	// if not stuck reset stuck counter
        stuck = 0;
    }

	// after car is stuck for a while apply recovering policy
	// 车子被卡住了一段时间了
	// 在此情况下生成的操作
    if (stuck > stuckTime)
    {
		
    	/* set gear and sterring command assuming car is 
    	 * pointing in a direction out of track */
    	
		// 将车身摆正
    	// to bring car parallel to track axis
        float steer = - cs.getAngle() / steerLock; 
        int gear = -1; // gear R 倒挡
        
        // if car is pointing in the correct direction revert gear and steer  
		// 如果车身已经正了，换成一档出发
        if (cs.getAngle()*cs.getTrackPos()>0)
        {
            gear = 1;
            steer = -steer;
        }

        // Calculate clutching
		// 计算离合
        clutching(cs,clutch);

        // build a CarControl variable and return it
        CarControl cc (1.0,0.0,gear,steer,clutch);
        return cc;
    }

    else // car is not stuck
    {
    	// compute accel/brake command
        float accel_and_brake = getAccel(cs);
        // compute gear 
        int gear = getGear(cs);
        // compute steering
        float steer = getSteer(cs);

        // normalize steering
        if (steer < -1)
            steer = -1;
        if (steer > 1)
            steer = 1;
        
        // set accel and brake from the joint accel/brake command 
        float accel,brake;
        if (accel_and_brake>0)
        {
            accel = accel_and_brake;
            brake = 0;
        }
        else
        {
            accel = 0;
            // apply ABS to brake
            brake = filterABS(cs,-accel_and_brake);
        }

        // Calculate clutching
        clutching(cs,clutch);

        // build a CarControl variable and return it
        CarControl cc(accel,brake,gear,steer,clutch);
        return cc;
    }
}
