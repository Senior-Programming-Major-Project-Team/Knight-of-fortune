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

#define TOMMY_GUN  500
#define HAND_GUN   501
#define SWORD      700
#define AXE        701

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

enum EType
{
	PIG,
	HANDGUNGOBLIN,
	LANCEGOBLIN,
	FLOWER
};

#endif //_CONSTNUMBER_ 
