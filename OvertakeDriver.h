/***************************************************************************
 
    file                 : OvertakeDriver.h
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
#ifndef OVERTAKEDRIVER_H_
#define OVERTAKEDRIVER_H_

#include <iostream>
#include <cmath>
#include "BaseDriver.h"
#include "CarState.h"
#include "CarControl.h"
#include "SimpleParser.h"
#include "WrapperBaseDriver.h"
#include "SimpleDriver.h"

using namespace std;

class OvertakeDriver : public SimpleDriver
{
public:
	
	// Constructor
	OvertakeDriver(){};

	// SimpleDriver implements a simple and heuristic controller for driving
	virtual CarControl wDrive(CarState cs);

};

#endif /*OVERTAKEDRIVER_H_*/
