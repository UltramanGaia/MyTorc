/***************************************************************************
 
    file                 : QuickAdvancedDriver.h
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
#ifndef QUICKADVANCEDDRIVER_H_
#define QUICKADVANCEDDRIVER_H_

#include <iostream>
#include <cmath>
#include "BaseDriver.h"
#include "CarState.h"
#include "CarControl.h"
#include "SimpleParser.h"
#include "WrapperBaseDriver.h"
#include "SimpleDriver.h"

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv/cvaux.h"
#include "opencv/cxmisc.h"

#include <stdio.h>

using namespace std;

class QuickAdvancedDriver : public SimpleDriver
{
public:
	
	// Constructor
	QuickAdvancedDriver(){};

	// SimpleDriver implements a simple and heuristic controller for driving
	virtual CarControl wDrive(CarState cs);

private:

	void processImage();

};

#endif /*QUICKADVANCEDDRIVER_H_*/

