#include "Hero.h"

USING_NS_CC;

Hero* Hero::create(HelloWorld* combatScene, std::string heroName, Camp actorcamp)
{
	Hero* hero = new(std::nothrow)Hero;
	if (hero && hero->init(combatScene, heroName, actorcamp))
	{
		hero->autorelease();
		return hero;
	}
	CC_SAFE_DELETE(hero);
	return nullptr;
}

bool Hero::init(HelloWorld* combatScene, std::string heroName, Camp actorcamp)
{
	if (!Sprite::init())
	{
		return false;
	}
	initHeroData(combatScene, heroName, actorcamp);
	return true;
}

bool Hero::initHeroData(HelloWorld* combatScene, std::string heroName, Camp camp)
{
	_combatScene = combatScene;
	setTexture(StringUtils::format("%sRight.png", heroName.c_str(), heroName.c_str()));
	_maxArmor = ARMOR;
	_currentArmor = ARMOR;
	_maxMagic = MAGIC;
	_currentMagic = MAGIC;
	_maxHealth = HEALTH;
	_currentHealth = HEALTH;
	_currentSpeed = SPEED;
	_minAttackInterval = 2;
	_alreadyDead = false;
	_heroName = heroName;
	_actorcamp = camp;
	_actordirection = Direction::RIGHT;
	_angle = 0;
	_calmTime = 1;
	_lastSkillTime = 0;
	return true;
}

bool Hero::checkSkillStatus()
{
	auto nowTime = GetCurrentTime() / 1000.f;

	if ( _lastSkillTime + _calmTime >= nowTime)
		return false;
	return true;
}

void Hero::castSkill() {}

void Hero::heroMove(const Vec2& targetPosition)
{
	Direction oldDirection = _actordirection;
	_angle = ccpToAngle(targetPosition);
	updateDirection();
	auto direction = targetPosition;
	auto newPosition = getPosition() + direction * getCurrentSpeed();
	setPosition(newPosition);
	stopMove();
}

void Hero::stopMove()
{
	stopAllActions();
	switch (_actordirection)
	{
	case Direction::LEFT:
		setTexture(StringUtils::format("%sLeft.png", _heroName.getCString(), _heroName.getCString()));
		break;
	case Direction::RIGHT:
		setTexture(StringUtils::format("%sRight.png", _heroName.getCString(), _heroName.getCString()));
		break;
	}
}

/*
void Hero::Attack()
{
	auto nowTime = GetCurrentTime() / 1000.f;
	if (nowTime - _lastAttackTime < getMinAttackInterval())
	{
		return;
	}
	changeCurrentMagic(getCurrentMagic() - getMagicPoint());
	_lastAttackTime = nowTime;
}*/
