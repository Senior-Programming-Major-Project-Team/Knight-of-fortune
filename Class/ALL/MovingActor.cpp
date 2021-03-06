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
	_maxArmor = ARMOR;
	_currentArmor = ARMOR;
	_maxMagic = MAGIC;
	_currentMagic = MAGIC;
	_maxHealth = HEALTH;
	_currentHealth = HEALTH;
	_currentSpeed = SPEED;
	_minAttackInterval = MIN_ATTACK_INTERVAL;
	_attackRadius = ATTACK_RADIUS;
	_alreadyDead = false;
	setActorCamp(actorcamp);
	_actordirection = Direction::RIGHT;
	_angle = 0;
	_lastAttackTime = 0;
}

void MovingActor::changeMaxHealth(float newMaxHealth)
{
	auto oldMaxHealth = _maxHealth;
	setMaxHealth(newMaxHealth);
	setCurrentHealth(_currentHealth + newMaxHealth - oldMaxHealth);
}

void MovingActor::changeMaxAromr(float newMaxArmor)
{
	auto oldMaxArmor = _maxArmor;
	setMaxArmor(newMaxArmor);
	setCurrentArmor(_currentArmor + newMaxArmor - oldMaxArmor);
}

void MovingActor::changeCurrentHealth(float newCurrentHealth)
{
	if (newCurrentHealth <= 0)
	{
		setCurrentHealth(0);
		die();
	}	
	else if (newCurrentHealth >= _maxHealth)
		setCurrentHealth(_maxHealth);
	else
		setCurrentHealth(newCurrentHealth);
}

void MovingActor::changeCurrentMagic(float newCurrentMagic)
{
	if (newCurrentMagic <= 0)
		setCurrentMagic(0);
	else if (newCurrentMagic >= _maxMagic)
		setCurrentMagic(_maxMagic);
	else
		setCurrentMagic(newCurrentMagic);
}

void MovingActor::changeCurrentArmor(float newCurrentArmor)
{
	if (newCurrentArmor <= 0)
	{
		setCurrentArmor(0);
		changeCurrentHealth(getCurrentHealth() + newCurrentArmor);
	}
	else if (newCurrentArmor >= _maxArmor)
	{
		setCurrentArmor(_maxArmor);
	}
	else
		setCurrentArmor(newCurrentArmor);
}


void MovingActor::die()
{
	setAlreadyDead(true);
}

void MovingActor::Damage(float damage)
{
	changeCurrentArmor(getCurrentArmor() - damage);
}

void MovingActor::Recover()
{
	this->scheduleOnce(schedule_selector(MovingActor::ArmorRecover), 1.0f);
}

void MovingActor::ArmorRecover(float dt)
{
	changeCurrentArmor(getCurrentArmor() + 2);
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
