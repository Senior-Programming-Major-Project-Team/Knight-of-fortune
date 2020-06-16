#pragma once
#ifndef _CONSTANT_H_
#define _CONSTANT_H_

#include "cocos2d.h"
USING_NS_CC;


#define TAG_MAP						  100000
#define FRAMES_PER_SECOND             30



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



namespace MyMath
{
	inline float getRad(const Vec2& startPoint, const Vec2& endPoint)
	{
		float py1 = startPoint.y;
		float py2 = endPoint.y;
		//������߳���  
		auto delta = endPoint - startPoint;
		//����   ��  ���η� ��ʽ  
		auto distance = startPoint.distance(endPoint);
		auto cos = delta.x / distance;
		//�����Ҷ���֪�����߳���Ƕȣ�cos = �ڱ�/б��  
		auto rad = acos(cos);
		//������Y���� <ҡ�˵�Y����ʱ��ȡ��ֵ  
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

#endif // !Constant_H