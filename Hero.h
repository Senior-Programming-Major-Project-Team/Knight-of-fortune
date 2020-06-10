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

	virtual bool checkSkillStatus();

	virtual void castSkill();
	
	virtual void heroMove();

	virtual void stopMove();

	virtual bool init(HelloWorld* combatScene, std::string heroName, Camp atorcamp);

	static Hero* create(HelloWorld* combatScene, std::string heroName, Camp atorcamp);

protected:

	virtual void startAnimation();

	virtual bool initHeroData(HelloWorld* combatScene, std::string heroName, Camp actorcamp);

	virtual Weapon* pickupWeapon(Weapon* weapon);

	virtual void changeWeapon();
};

#endif // _HERO_
