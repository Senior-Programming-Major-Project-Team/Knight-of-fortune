#include"Buff.h"

Buff* Buff::create(float armor, float hp, float mp, float attack, float beginTime, float endTime, float duration)
{
	Buff* buff = new(std::nothrow)Buff;
	if (buff->init(armor,hp,mp,attack,beginTime,endTime,duration))
	{
		buff->autorelease();
		return buff;
	}
	else
	{
		CC_SAFE_DELETE(buff);
		return nullptr;
	}
}

bool Buff::init(float armor, float hp, float mp, float attack, float beginTime, float endTime, float duration)
{
	if (!Sprite::init())

	{

		return false;

	}
	_armor = armor;
	_HP = hp;
	_MP = mp;
	_attack = attack;
	_beginTime = beginTime;
	_endTime = endTime;
	_duration = duration;
	return true;

}