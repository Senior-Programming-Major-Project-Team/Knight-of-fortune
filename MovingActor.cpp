#include "MovingActor.h"

USING_NS_CC;

MovingActor* MovingActor::create(HelloWorld* combatScene, const std::string& filename, Camp actorcamp)
{
	MovingActor* sprite = new (std::nothrow) MovingActor;
	if (sprite && sprite->init(combatScene, filename, actorcamp))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool MovingActor::init(HelloWorld* combatScene, const std::string& filename, Camp actorcamp)
{
	if (!Sprite::initWithFile(filename))
		return false;
	MovingActor::initstate(actorcamp);
	return true;
}

void MovingActor::initstate(Camp actorcamp)
{
	setActorCamp(actorcamp);
	setActorWeapon1(nullptr);
	setActorWeapon2(nullptr);
	_actorState->init();
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
		this->scheduleOnce(schedule_selector(MovingActor::MagicRecover), 1.0f);
	while (_actorState->getCurrentArmor() < _actorState->getMaxArmor())
		this->scheduleOnce(schedule_selector(MovingActor::MagicRecover), 1.0f);
}

void MovingActor::MagicRecover(float dt)
{
	_actorState->changeCurrentMagic( _actorState->getCurrentMagic() + 10);
}

void MovingActor::ArmorRecover(float dt)
{
	_actorState->changeCurrentArmor(_actorState->getCurrentArmor() + 1);
}

void MovingActor::updateDirection()
{
	if (_angle <= 2 * MINDEGREE || _angle > 14 * MINDEGREE)
	{
		_actordirection = Direction::RIGHT;
	}
	else if (_angle <= 6 * MINDEGREE)
	{
		_actordirection = Direction::UP;
	}
	else if (_angle <= 10 * MINDEGREE)
	{
		_actordirection = Direction::LEFT;
	}
	else if (_angle <= 14 * MINDEGREE)
	{
		_actordirection = Direction::DOWN;
	}
}

void MovingActor::startAnimation(){}

void MovingActor::moveTo(const Vec2& targetPosition)
{
	auto oldDirection = _actordirection;
	_angle = ccpAngle(getPosition(), targetPosition);
	updateDirection();
	auto direction = ccpNormalize(ccpSub(targetPosition, getPosition()));
	if (_actordirection != oldDirection)
	{
		startAnimation();
	}
	auto newPosition = ccpAdd(getPosition(), ccpMult(direction, _actorState->getCurrentSpeed());
	setPosition(newPosition);
}

void MovingActor::Attack() {};

void MovingActor::Buff() {};
