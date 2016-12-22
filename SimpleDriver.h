/***************************************************************************
 
    file                 : SimpleDriver.h
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
#ifndef SIMPLEDRIVER_H_
#define SIMPLEDRIVER_H_

#include <iostream>
#include <cmath>
#include "BaseDriver.h"
#include "CarState.h"
#include "CarControl.h"
#include "SimpleParser.h"
#include "WrapperBaseDriver.h"

#define PI 3.14159265

using namespace std;

class SimpleDriver : public WrapperBaseDriver
{
public:
	
	// 构造函数
	SimpleDriver(){stuck=0;clutch=0.0;};

	// 实现简单的、具有启发式的驾驶控制函数
	// SimpleDriver implements a simple and heuristic controller for driving
	virtual CarControl wDrive(CarState cs);

	// 关闭时的回调函数，
	// 这时打印关闭的信息
	virtual void onShutdown();
	
	// 重启时的回调函数，
	// 这时打印重启的信息
	virtual void onRestart();

	// 初始化想要的角度范围,车子行驶方向和跑道轴线的夹角
	// Initialization of the desired angles for the rangefinders
	virtual void init(float *angles);

protected:
	
	/* Gear Changing Constants*/
	// 档位改变常数
	
	// RPM values to change gear 
	// 要改变档位的发动机当前转速值
	static const int gearUp[6];
	static const int gearDown[6];
		
	/* Stuck constants*/
	// 卡住，无法移动的相关常数
	
	// How many time steps the controller wait before recovering from a stuck position
	// 
	static const int stuckTime;
	// When car angle w.r.t. track axis is grather tan stuckAngle, the car is probably stuck
	// 当车子与轴线的夹角大于tan stuckAngle，车子可能卡住了
	static const float stuckAngle;
	
	/* Steering constants*/
	// 转向，1 左方向打满，-1右方向打满
	
	// Angle associated to a full steer command
	static const float steerLock;	
	// Min speed to reduce steering command 
	static const float steerSensitivityOffset;
	// Coefficient to reduce steering command at high speed (to avoid loosing the control)
	// 在高速的时候减少打方向盘命令的率
	static const float wheelSensitivityCoeff;
	
	/* Accel and Brake Constants*/
	// 与油门和刹车相关的构造函数
	
	// 允许的最大速度
	static const float maxSpeed;
	// Min distance from track border to drive at  max speed
	// 是否应该用最高速驾驶的距离分界线
	static const float maxSpeedDist;
	// pre-computed sin5
	// 预先处理好的sin5
	static const float sin5;
	// pre-computed cos5
	// 预先处理好的con5
	static const float cos5;
	
	/* ABS Filter Constants */
	// 与ABS防爆死相关的常量
	
	// Radius of the 4 wheels of the car
	// 四个轮的车的直径
	static const float wheelRadius[4];
	// min slip to prevent ABS
	static const float absSlip;						
	// range to normalize the ABS effect on the brake
	// 此距离范围内将ABS 换成 刹车
	static const float absRange;
	// min speed to activate ABS
	// ABS 最低速度
	static const float absMinSpeed;

	/* Clutch constants */
	// 离合常量，0 不踩离合， 1 离合踩满
	static const float clutchMax;
	static const float clutchDelta;
	static const float clutchRange;
	static const float clutchDeltaTime;
	static const float clutchDeltaRaced;
	static const float clutchDec;
	static const float clutchMaxModifier;
	static const float clutchMaxTime;

	// counter of stuck steps
	// stuck 步骤的计数器
	int stuck;
	
	// current clutch
	// 当前离合状态
	float clutch;

	// Solves the gear changing subproblems
	// 解决换挡问题
	int getGear(CarState &cs);

	// Solves the steering subproblems
	// 解决转向问题
	float getSteer(CarState &cs);
	
	// Solves the gear changing subproblems
	// 解决油门问题
	float getAccel(CarState &cs);
	
	// Apply an ABS filter to brake command
	// ABS 和 break 状态间的转换
	float filterABS(CarState &cs,float brake);

	// Solves the clucthing subproblems
	// 解决卡住了的问题
	void clutching(CarState &cs, float &clutch);
};

#endif /*SIMPLEDRIVER_H_*/
