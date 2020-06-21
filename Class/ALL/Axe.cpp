#include"Axe.h"
#include"constnumber.h"



Axe* Axe::create(HelloWorld* combatScene, std::string weaponName, Hero* hero)
{
	Axe* axe = new(std::nothrow)Axe;
	if (axe->init(combatScene, weaponName, hero))
	{
		axe->autorelease();
		return axe;
	}
	else
	{
		CC_SAFE_DELETE(axe);
		return nullptr;
	}
}

bool Axe::init(HelloWorld* combatScene, std::string weaponName, Hero* hero)
{

	if (!ShortRangeWeapon::init(combatScene, weaponName, hero))

	{

		return false;

	}

	/*auto visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();*/

	//创建SWORD精灵

	//auto spTommyGun = Sprite::create(weaponName);

	//设置锚点位置，坐标位置，target并添加

	setAnchorPoint(Point(0, 0.5));

	setPosition(hero->getPositionX() - 70, hero->getPositionY() - 100);

	setTag(AXE);

	//hero->addChild(spSword);
	_attackPoint = 5;
	_magicPoint = 0;
	_critRate = 0.15;
	_attackRadius = 100;
	_weaponName = "Axe";
	_weaponType = WType::AXEW;
	_hero = hero;



	//this->scheduleUpdate();



	//子弹发射

	//计划任务



	//this->schedule(schedule_selector(tommyGun::touchupdate), 0.5);

	//this->schedule(schedule_selector(tommyGun::moveBullet), 0.1);



	return true;






}


bool Axe::onTouchBegan(Touch* touch, Event* unused_event)
{
	targetX = touch->getLocation().x;

	targetY = touch->getLocation().y;


	Vec2 shootVector(targetX - getPositionX(), targetY - getPositionY());

	Vec2 detalVector = shootVector.getNormalized(); //方向单位向量

	float angle = atan2(detalVector.y, detalVector.x);

	float degree = CC_RADIANS_TO_DEGREES(angle);

	float rotateSpeed = 2 * M_PI;

	float rotateTime = angle / 2 * M_PI;

	setRotation(-degree);

	return true;
}
void Axe::onTouchMoved(Touch* touch, Event* unused_event)
{

}
void Axe::onTouchEnded(Touch* touch, Event* unused_event)
{

}

void Axe::attack(HelloWorld* combatScene)
{


	//创建一个触摸监听
	EventListenerTouchOneByOne* touch = EventListenerTouchOneByOne::create();

	/*touch->setSwallowTouches(true);

	touch->setEnabled(true);*/

	touch->onTouchBegan = CC_CALLBACK_2(Axe::onTouchBegan, this);

	touch->onTouchMoved = CC_CALLBACK_2(Axe::onTouchMoved, this);

	touch->onTouchEnded = CC_CALLBACK_2(Axe::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);

}

void Axe::update(Vector<Enemy*> _enemies)
{
	setTexture("Axe_1.png");

	setPosition(_hero->getPositionX() - 5, _hero->getPositionY() - 10);




	for (int i = 0; i < _enemies.size(); i++)

	{

		auto nowEnemy = _enemies.at(i);




		if (((this->convertToWorldSpace(Point(0, 0)).distance(nowEnemy->getPosition())) < 50) && nowEnemy->getAlreadyDead() == false)

		{
			nowEnemy->Damage(_attackPoint);

		}



	}

}