/***************************************************************************
 
    file                 : WrapperBaseDriver.cpp
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
#include "WrapperBaseDriver.h"

string 
WrapperBaseDriver::drive(string sensors)
{
	// string 转换成Car状态信息
	CarState cs(sensors);
	// 传递状态信息，返回采取的操作
	CarControl cc = wDrive(cs);
	return cc.toString();	
}


