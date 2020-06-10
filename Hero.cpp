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
	setTexture(StringUtils::format("pictures\\hero\\%s\\%sright1.png", heroName.c_str(), heroName.c_str()));
	setPosition(Vec2(0, 0));
	_actorState->init();
	_heroName = heroName;
	_actorcamp = Camp::ME;
	_actordirection = Direction::LEFT;
	_angle = 0;
	_calmTime = 30;
	_lastSkillTime = 0;
	_actorWeapon1 = nullptr;
	_actorWeapon2 = nullptr;
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

void Hero::heroMove()
{
	auto nowTime = GetCurrentTime() / 1000.f;
	if (nowTime - _lastAttackTime <= _actorState->getMinAttackInterval())
	{
		return;
	}
	Direction oldDirection = _actordirection;
	updateDirection();
	if (_actordirection != oldDirection)
	{
		startAnimation();
	}
	/*auto direction = ccpNormalize(ccpSub(targetPosition, getPosition()));
	auto newPosition = ccpAdd(getPosition(), ccpMult(direction, _actorState->getCurrentSpeed()));
	setPosition(newPosition);*/
}

void Hero::startAnimation()
{
	stopAllActions();
	auto animation = Animation::create();
	switch (_actordirection)
	{
	case Direction::RIGHT:
		animation = AnimationCache::getInstance()->getAnimation(StringUtils::format("%sMoveRight", _heroName.getCString()));
		break;
	case Direction::LEFT:
		animation = AnimationCache::getInstance()->getAnimation(StringUtils::format("%sMoveLeft", _heroName.getCString()));
		break;
	}
	animation->setDelayPerUnit(0.15f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	runAction(RepeatForever::create(animate));
}

void Hero::stopMove()
{
	auto nowTime = GetCurrentTime() / 1000.f;
	if (nowTime - _lastAttackTime < _actorState->getMinAttackInterval())
	{
		return;
	}
	stopAllActions();
	switch (_actordirection)
	{
	case Direction::LEFT:
		setTexture(StringUtils::format("", _heroName.getCString(), _heroName.getCString()));
		break;
	case Direction::RIGHT:
		setTexture(StringUtils::format("", _heroName.getCString(), _heroName.getCString()));
		break;
	}
	_actordirection = Direction::NO;
}

Weapon* Hero::pickupWeapon(Weapon* weapon)
{
	Weapon* tempWeapon = _actorWeapon1;
	_actorWeapon1 = weapon;
	return tempWeapon;
}

void Hero::changeWeapon()
{
	CC_SWAP(_actorWeapon1, _actorWeapon2, Weapon*);
}
