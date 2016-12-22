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
