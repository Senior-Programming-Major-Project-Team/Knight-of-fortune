#pragma once

#ifndef _CONSTNUMBER_
#define _CONSTNUMBER_

#include "cocos2d.h"

#define HEALTH 6
#define MAGIC 200				  
#define ARMOR 5
#define SPEED 1
#define MINDEGREE 0.3926991
#define MIN_ATTACK_INTERVAL 1
#define ATTACK_RADIUS 10

#define PRESS 1
#define RELEASE	2

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

#endif //_CONSTNUMBER_ 
