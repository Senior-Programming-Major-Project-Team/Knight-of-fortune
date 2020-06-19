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

	/*auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();*/
	//创建冲锋枪精灵
	auto spAxe = Sprite::create(weaponName);
	//设置锚点位置，坐标位置，target并添加
	spAxe->setAnchorPoint(Point(0.5, 0.7));
	spAxe->setPosition(hero->getPosition());
	spAxe->setTag(AXE);
	hero->addChild(spAxe);
	_attackPoint = 4;
	_magicPoint = 0;
	_critRate = 0.15;
	_attackRadius = 100;
	_weaponName = "Axe";
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
	auto spAxe = this->getChildByTag(AXE);
	Vec2 shootVector(targetX - (spAxe->getPositionX()), targetY - spAxe->getPositionY());
	Vec2 detalVector = shootVector.getNormalized(); //方向单位向量
	float angle = atan2(detalVector.y, detalVector.x);
	float degree = CC_RADIANS_TO_DEGREES(angle);
	float rotateSpeed = 2 * M_PI;
	float rotateTime = angle / 2 * M_PI;
	spAxe->setRotation(-degree);
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

	if (_magicPoint <= 0)
		return;
	//创建一个触摸监听
	EventListenerTouchOneByOne* touch = EventListenerTouchOneByOne::create();
	/*touch->setSwallowTouches(true);
	touch->setEnabled(true);*/
	touch->onTouchBegan = CC_CALLBACK_2(Axe::onTouchBegan, this);
	touch->onTouchMoved = CC_CALLBACK_2(Axe::onTouchMoved, this);
	touch->onTouchEnded = CC_CALLBACK_2(Axe::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);

}



