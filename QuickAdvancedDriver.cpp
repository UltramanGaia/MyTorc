/***************************************************************************
 
    file                 : QuickAdvancedDriver.cpp
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
#include "QuickAdvancedDriver.h"

void QuickAdvancedDriver::processImage()
{
//The channels of the colors that we use. In this case are 3, our
// data layout of a color image is: b0, g0, r0, b1, g1, r1 ... We have
// to realize that is different in OpenCV is BGR and is not RGB as we
// are get used.

	//process image
	//....
}

CarControl
QuickAdvancedDriver::wDrive(CarState cs)
{
	float accel,brake,steer;
	int gear;

	processImage();

	accel = 0.5;
	brake = 0.0;
	steer = getSteer(cs);
	gear = 2;
	// build a CarControl variable and return it
	CarControl cc(accel,brake,gear,steer,clutch);

	return cc;
}
