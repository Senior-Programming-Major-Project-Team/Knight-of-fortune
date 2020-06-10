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
	MovingActor::initstate(combatScene, actorcamp);
	return true;
}

void MovingActor::initstate(HelloWorld* combatScene, Camp actorcamp)
{
	setCombatScene(combatScene);
	_actorState->init();
	setActorCamp(actorcamp);
	setActorWeapon1(nullptr);
	setActorWeapon2(nullptr);
}

void MovingActor::die()
{
	_actorState->setAlreadyDead(true);
}

void MovingActor::Damage(INT32 damage)
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

void MovingActor::Recover()
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
	if (_angle <= 4 * MINDEGREE || _angle > 12 * MINDEGREE)
	{
		_actordirection = Direction::RIGHT;
	}
	else if (_angle <= 12 * MINDEGREE)
	{
		_actordirection = Direction::LEFT;
	}
}

void MovingActor::startAnimation(){}

void MovingActor::moveTo(const Vec2& targetPosition)
{
	auto oldDirection = _actordirection;
	_angle = ccpAngle(getPosition(), targetPosition);
	updateDirection();
	if (_actordirection != oldDirection)
	{
		startAnimation();
	}
	auto direction = ccpNormalize(ccpSub(targetPosition, getPosition()));
	auto newPosition = ccpAdd(getPosition(), ccpMult(direction, _actorState->getCurrentSpeed()));
	setPosition(newPosition);
}

void MovingActor::Attack() {};

void MovingActor::Buff() {};
