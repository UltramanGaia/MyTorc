/***************************************************************************
 
    file                 : BaseDriver.h
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
#ifndef BASEDRIVER_H_
#define BASEDRIVER_H_

#include<iostream>

using namespace std;

class BaseDriver
{
public:
	
	typedef enum{WARMUP,QUALIFYING,RACE,UNKNOWN} tstage;

	tstage stage;
	char trackName[100];

	// 默认构造函数 
	BaseDriver() {};
	
	// 默认析构函数 
	virtual ~BaseDriver(){};
	
	// 初始化想要的角度范围
	// Initialization of the desired angles for the rangefinders
	virtual void init(float *angles){
		for (int i = 0; i < 19; ++i)
			angles[i]=-90+i*10;
		//-90,-80,-70,-60,...,+90
	};

	// 主函数
	// 输入string sensors代表当前世界状态
	// 返回的string代表着要执行的控制操作
	// The main function: 
	//     - the input variable sensors represents the current world sate
	//     - it returns a string representing the controlling action to perform    
	virtual string drive(string sensors)=0;

	// 关闭时调用的回调函数
	virtual void onShutdown() {};
	
	// 服务器重启时的回调函数
	virtual void onRestart() {};

};
#endif /*BASEDRIVER_H_*/
