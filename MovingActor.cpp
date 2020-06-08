#include "MovingActor.h"
#include "cocos2d.h"

USING_NS_CC;

MovingActor* MovingActor::create(const std::string& filename, Camp actorcamp)
{
	MovingActor* sprite = new (std::nothrow) MovingActor();
	if (sprite && sprite->init(filename, actorcamp))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool MovingActor::init(const std::string& filename, Camp actorcamp)
{
	if (!Sprite::initWithFile(filename))
		return false;
	setActorCamp(actorcamp);
	_actorState->init();
	return true;
}

void MovingActor::die()
{
	_actorState->setAlreadyDead(true);
}

void MovingActor::damage(INT32 damage)
{
	if (_actorState->changeCurrentArmor(_actorState->getCurrentArmor() - damage) < 0)
	{
		_actorState->changeCurrentHealth(damage - _actorState->getCurrentArmor());
	}
	if (_actorState->getCurrentHealth() <= 0)
	{
		die();
	}
}

void MovingActor::recover()
{
	while (_actorState->getCurrentMagic() < _actorState->getMaxMagic())
		this->scheduleOnce(schedule_selector(MagicRecover), 1.0f);	
	while (_actorState->getCurrentArmor() < _actorState->getMaxArmor())
		this->scheduleOnce(schedule_selector(MagicRecover), 1.0f);
}

void MovingActor::MagicRecover(float dt)
{
	_actorState->changeCurrentMagic( _actorState->getCurrentMagic() + 10);
}

void MovingActor::ArmorRecover(float dt)
{
	_actorState->changeCurrentArmor(_actorState->getCurrentArmor() + 1);
}

void MovingActor::Attack() {};

void MovingActor::Buff() {};

void MovingActor::GetWeapon() {};
