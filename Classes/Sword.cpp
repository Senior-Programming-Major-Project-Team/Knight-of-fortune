#include"Sword.h"
#include"constnumber.h"



Sword* Sword::create(HelloWorld* combatScene, std::string weaponName, Hero* hero)
{
	Sword* sword = new(std::nothrow)Sword;
	if (sword->init(combatScene, weaponName, hero))
	{
		sword->autorelease();
		return sword;
	}
	else
	{
		CC_SAFE_DELETE(sword);
		return nullptr;
	}
}

bool Sword::init(HelloWorld* combatScene, std::string weaponName, Hero* hero)
{

	/*auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();*/
	//创建冲锋枪精灵
	auto spSword = Sprite::create(weaponName);
	//设置锚点位置，坐标位置，target并添加
	spSword->setAnchorPoint(Point(0.5, 0.7));
	spSword->setPosition(hero->getPosition());
	spSword->setTag(SWORD);
	combatScene->addChild(spSword);
	_attackPoint = 4;
	_magicPoint = 0;
	_critRate = 0.15;
	_attackRadius = 100;
	_weaponName = "Sword";
	//this->scheduleUpdate();

	//子弹发射
	//计划任务

	//this->schedule(schedule_selector(tommyGun::touchupdate), 0.5);
	//this->schedule(schedule_selector(tommyGun::moveBullet), 0.1);

	return true;


}


bool Sword::onTouchBegan(Touch* touch, Event* unused_event)
{
	targetX = touch->getLocation().x;
	targetY = touch->getLocation().y;
	auto spSword = this->getChildByTag(SWORD);
	Vec2 shootVector(targetX - (spSword->getPositionX()), targetY - spSword->getPositionY());
	Vec2 detalVector = shootVector.getNormalized(); //方向单位向量
	float angle = atan2(detalVector.y, detalVector.x);
	float degree = CC_RADIANS_TO_DEGREES(angle);
	float rotateSpeed = 2 * M_PI;
	float rotateTime = angle / 2 * M_PI;
	spSword->setRotation(-degree);
	return true;
}
void Sword::onTouchMoved(Touch* touch, Event* unused_event)
{

}
void Sword::onTouchEnded(Touch* touch, Event* unused_event)
{
	
}

void Sword::attack(HelloWorld* combatScene)
{

	
	//创建一个触摸监听
	EventListenerTouchOneByOne* touch = EventListenerTouchOneByOne::create();
	/*touch->setSwallowTouches(true);
	touch->setEnabled(true);*/
	touch->onTouchBegan = CC_CALLBACK_2(Sword::onTouchBegan, this);
	touch->onTouchMoved = CC_CALLBACK_2(Sword::onTouchMoved, this);
	touch->onTouchEnded = CC_CALLBACK_2(Sword::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);
	
}



