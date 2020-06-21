#include"Buff.h"

#include"HelloWorldScene.h"

#include"cocos2d.h"

USING_NS_CC;

Buff* Buff::create(HelloWorld* combatScene, std::string buffName, Hero* hero, float armor, float hp, float mp, float attack, float beginTime, float endTime, float duration)
{
	Buff* buff = new(std::nothrow)Buff;
	if (buff->init(combatScene, buffName, hero, armor,hp,mp,attack,beginTime,endTime,duration))
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

bool Buff::init(HelloWorld* combatScene, std::string buffName, Hero* hero, float armor, float hp, float mp, float attack, float beginTime, float endTime, float duration)
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
	_hero = hero;
	_buffName = buffName;
	_combatscene = combatScene;
	return true;

}