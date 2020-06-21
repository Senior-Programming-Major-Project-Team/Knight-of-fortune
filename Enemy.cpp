#include "Enemy.h"
#include "cocos2d.h"

USING_NS_CC;

Enemy* Enemy::create(HelloWorld* combatScene, std::string enemyName, Camp actorcamp)
{
	Enemy* enemy = new(std::nothrow)Enemy;
	if (enemy && enemy->init(combatScene, enemyName, actorcamp))
	{
		enemy->autorelease();
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return nullptr;
}

bool Enemy::init(HelloWorld* combatScene, std::string enemyName, Camp actorcamp)
{
	if (!Sprite::init())
	{
		return false;
	}
	initEnemyData(combatScene, enemyName, actorcamp);
	return true;
}

void Enemy::initEnemyData(HelloWorld* combatScene, std::string enemyName, Camp camp)
{
	_combatScene = combatScene;
	setTexture(StringUtils::format("%sRight.png", enemyName.c_str(), enemyName.c_str()));
	_maxArmor = 0;
	_currentArmor = 0;
	_maxMagic = 0;
	_currentMagic = 0;
	_maxHealth = HEALTH;
	_currentHealth = HEALTH;
	_currentSpeed = SPEED;
	_minAttackInterval = MIN_ATTACK_INTERVAL;
	_attackRadius = ATTACK_RADIUS;
	_alreadyDead = false;
	_lastTimeDead = false;
	_enemyName = enemyName;
	_actorcamp = camp;
	_actordirection = Direction::RIGHT;
	_angle = 0;
	_lastAttackTime = 0;
}

void Enemy::enemyMove(const Vec2& targetPosition)
{
	Direction oldDirection = _actordirection;
	_angle = ccpToAngle(targetPosition);
	updateDirection();
	auto direction = targetPosition;
	auto newPosition = getPosition() + direction * getCurrentSpeed();
	//setPosition(newPosition);
	if (newPosition.x >= 200 && newPosition.y >= 200 && newPosition.x <= 700 && newPosition.y <= 700)
		runAction(MoveTo::create(5, newPosition));
	stopMove();
}

void Enemy::stopMove()
{
	//stopAllActions();
	switch (_actordirection)
	{
	case Direction::LEFT:
		setTexture(StringUtils::format("%sLeft.png", _enemyName.getCString(), _enemyName.getCString()));
		break;
	case Direction::RIGHT:
		setTexture(StringUtils::format("%sRight.png", _enemyName.getCString(), _enemyName.getCString()));
		break;
	}
}

void Enemy::automove()
{
	srand(time(0) + rand());
	Point point;
	point.x = CCRANDOM_0_1() * 2 - 1;
	point.y = CCRANDOM_0_1() * 2 - 1;
	enemyMove(point);
}

void Enemy::Attack(Hero* hero, Enemy* enemy)
{
	auto nowTime = GetCurrentTime() / 1000.f;
	if (nowTime - _lastAttackTime < _minAttackInterval)
	{
		return ;
	}
	_lastAttackTime = nowTime;
}

void Enemy::die() 
{
	setAlreadyDead(true);
}