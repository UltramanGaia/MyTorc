/***************************************************************************
 
    file                 : QuickBasicDriver.h
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
#ifndef QUICKBASICDRIVER_H_
#define QUICKBASICDRIVER_H_

#include <iostream>
#include <cmath>
#include "BaseDriver.h"
#include "CarState.h"
#include "CarControl.h"
#include "SimpleParser.h"
#include "WrapperBaseDriver.h"
#include "SimpleDriver.h"

using namespace std;

class QuickBasicDriver : public SimpleDriver
{
public:
	
	// 构造函数
	QuickBasicDriver() {};

	// 简单的控制小车的主函数
	virtual CarControl wDrive(CarState cs);

};

#endif /*QUICKBASICDRIVER_H_*/
