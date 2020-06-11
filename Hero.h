#ifndef _HERO_
#define _HERO_

#include "cocos2d.h"
#include "MovingActor.h"

USING_NS_CC;

class Hero :public MovingActor
{
	CC_SYNTHESIZE(String, _heroName, HeroName);
	CC_SYNTHESIZE(float, _calmTime, CalmTime);
	CC_SYNTHESIZE(float, _lastSkillTime, LastSkillTime);

public:

	virtual void Attack();//攻击

	virtual bool checkSkillStatus();//确认技能是否可以使用

	virtual void castSkill();//释放技能
	
	virtual void heroMove(const Vec2& targetPosition);//移动

	virtual void stopMove();//停止移动

	virtual bool init(HelloWorld* combatScene, std::string heroName, Camp atorcamp);

	static Hero* create(HelloWorld* combatScene, std::string heroName, Camp atorcamp);

protected:

	virtual void startAnimation();//动画

	virtual bool initHeroData(HelloWorld* combatScene, std::string heroName, Camp actorcamp);

	virtual Weapon* pickupWeapon(Weapon* weapon);//拾取武器

	virtual void changeWeapon();//更换武器
};

#endif // _HERO_
