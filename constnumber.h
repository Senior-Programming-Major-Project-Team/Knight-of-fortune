#pragma once

#ifndef _CONSTNUMBER_
#define _CONSTNUMBER_

#include "cocos2d.h"

#define TAG_MAP						  100000
#define FRAMES_PER_SECOND             30

#define HEALTH 6
#define MAGIC 200				  
#define ARMOR 5
#define SPEED 1
#define MINDEGREE 0.3926991
#define MIN_ATTACK_INTERVAL 1
#define ATTACK_RADIUS 10

#define PRESS 1
#define RELEASE	2

typedef std::vector<std::vector<bool>> DyaDicVector;

typedef struct PointINT
{
	INT32 x, y;

	PointINT(INT32 x = 0, INT32 y = 0) :x(x), y(y) {}

	PointINT& operator = (const cocos2d::Vec2& point)
	{
		x = static_cast<INT32>(point.x);
		y = static_cast<INT32>(point.y);
		return *this;
	}


}SizeINT;

enum Camp
{
	ME,
	ENEMY
};

enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UPLEFT,
	UPRIGHT,
	DOWNLEFT,
	DOWNRIGHT,
	NO
};

namespace MyMath
{
	inline float getRad(const Vec2& startPoint, const Vec2& endPoint)
	{
		float py1 = startPoint.y;
		float py2 = endPoint.y;
		//求出两边长度  
		auto delta = endPoint - startPoint;
		//开方   与  几次方 公式  
		auto distance = startPoint.distance(endPoint);
		auto cos = delta.x / distance;
		//反余弦定理，知道两边长求角度：cos = 邻边/斜边  
		auto rad = acos(cos);
		//当触屏Y坐标 <摇杆的Y坐标时，取反值  
		if (py1 > py2)
		{
			rad = 2 * M_PI - rad;
		}
		return rad;
	}

	inline Vec2 calculatePositionDelta(float angle, float speed)
	{
		return Vec2(cos(angle) * speed / FRAMES_PER_SECOND, sin(angle) * speed / FRAMES_PER_SECOND);
	}
};

#endif //_CONSTNUMBER_ 
