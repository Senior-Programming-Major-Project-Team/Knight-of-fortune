#include"TommyGun.h"

#include"cocos2d.h"

#include"constnumber.h"



USING_NS_CC;



TommyGun* TommyGun::create(HelloWorld* combatScene, std::string weaponName, Hero* hero)

{

	TommyGun* tommyGun = new(std::nothrow)TommyGun;
	

	if (tommyGun->init(combatScene, weaponName, hero))

	{

		tommyGun->autorelease();

		return tommyGun;

	}

	else

	{

		CC_SAFE_DELETE(tommyGun);

		return nullptr;

	}

}



bool TommyGun::init(HelloWorld* combatScene, std::string weaponName, Hero* hero)

{

	if (!longRangeWeapon::init(combatScene, weaponName, hero))

	{

		return false;

	}

	/*auto visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();*/

	//创建冲锋枪精灵

	//auto spTommyGun = Sprite::create(weaponName);

	//设置锚点位置，坐标位置，target并添加

	setAnchorPoint(Point(0.5, 0.7));

	setPosition(hero->getPositionX()-50,hero->getPositionY()-80);

	setTag(TOMMY_GUN);

	//hero->addChild(tommyGun);

	_attackPoint = 5;

	_magicPoint = 180;

	_critRate = 0.3;

	_weaponName = "TommyGun";

	_hero = hero;

	//this->scheduleUpdate();



	//子弹发射

	//计划任务



	//this->schedule(schedule_selector(tommyGun::touchupdate), 0.5);

	//this->schedule(schedule_selector(tommyGun::moveBullet), 0.1);



	return true;





}





bool TommyGun::onTouchBegan(Touch* touch, Event* unused_event)

{

	targetX = touch->getLocation().x;

	targetY = touch->getLocation().y;

	//auto spTommyGun = this->getChildByTag(TOMMY_GUN);

	Vec2 shootVector(targetX -getPositionX(), targetY - getPositionY());

	Vec2 detalVector = shootVector.getNormalized(); //方向单位向量

	float angle = atan2(detalVector.y, detalVector.x);

	float degree = CC_RADIANS_TO_DEGREES(angle);

	float rotateSpeed = 2 * M_PI;

	float rotateTime = angle / 2 * M_PI;

	setRotation(-degree);

	return true;

}

void TommyGun::onTouchMoved(Touch* touch, Event* unused_event)

{



}

void TommyGun::onTouchEnded(Touch* touch, Event* unused_event)

{

	auto visibleSize = Director::getInstance()->getVisibleSize();

	//auto spTommyGun = this->getChildByTag(15);
	targetX = touch->getLocation().x;

	targetY = touch->getLocation().y;

	//Vec2 shootVector(targetX - getPositionX(), targetY - getPositionY());

	//Vec2 detalVector = shootVector.getNormalized(); //方向单位向量

	Vec2 shootVector(targetX - getPositionX(), targetY - getPositionY());

	Vec2 detalVector = shootVector.getNormalized(); //方向单位向量*/

	Vec2 overVector = detalVector * 2000;//超出屏幕的（注定要被清除）点

	

	Sprite* Bullet = Sprite::create("Bullet.png");

	Sprite* Bullet2 = Sprite::create("Bullet.png");

	Sprite* Bullet3 = Sprite::create("Bullet.png");
	
	

	//Vec2 bulletPosition = this->convertToWorldSpace(Bullet->getPosition());

	Bullet->setPosition(90,30);

	Bullet2->setPosition(110, 30);

	Bullet3->setPosition(130, 30);

	//Vec2 bullet1Position = getPosition() + Bullet->getPosition();

	//Vec2 bullet2Position = getPosition() + Bullet2->getPosition();

	//Vec2 bullet3Position = getPosition() + Bullet3->getPosition();
	
	/*Bullet->setPosition(getPositionX(), getPositionY());

	Bullet2->setPosition(getPositionX(), getPositionY() );

	Bullet3->setPosition(getPositionX() , getPositionY());*/
	/*Bullet->setPosition(spTommyGun->getPositionX() + 30 * detalVector.x, spTommyGun->getPositionY() + 30 * detalVector.y);
	Bullet2->setPosition(spTommyGun->getPositionX() + 50 * detalVector.x, spTommyGun->getPositionY() + 50 * detalVector.y);
	Bullet3->setPosition(spTommyGun->getPositionX() + 70 * detalVector.x, spTommyGun->getPositionY() + 70 * detalVector.y);
	*/
	//Vec2 offVector1 =bullet1Position+ overVector;//同上

	//Vec2 offVector2 =bullet2Position +overVector;

	//Vec2 offVector3 = bullet3Position+overVector;

	float flySpeed = 200;//飞行速度

	float flyTime = overVector.getLength() / flySpeed;//飞行时间

	auto moveTo = MoveTo::create(flyTime, ccp(2000,0));

	auto moveTo2 = MoveTo::create(flyTime, ccp(2000, 0));

	auto moveTo3 = MoveTo::create(flyTime, ccp(2000, 0));

	this->addChild(Bullet);

	this->addChild(Bullet2);

	this->addChild(Bullet3);

	this->allBullet.pushBack(Bullet);

	this->allBullet.pushBack(Bullet2);

	this->allBullet.pushBack(Bullet3);

	Bullet->runAction(moveTo);

	Bullet2->runAction(moveTo2);

	Bullet3->runAction(moveTo3);

	for (int i = 0; i < allBullet.size(); i++)

	{

		auto nowBullet = allBullet.at(i);

		if (nowBullet->getPositionY() > Director::getInstance()->getWinSize().height)

		{

			nowBullet->removeFromParent();

			allBullet.eraseObject(nowBullet);

			i--;

		}

	}



}



void TommyGun::openFire(HelloWorld* combatScene)

{

	if (_attackPoint <= 0)

		return;

	//创建一个触摸监听

	EventListenerTouchOneByOne* touch = EventListenerTouchOneByOne::create();

	/*touch->setSwallowTouches(true);

	touch->setEnabled(true);*/

	touch->onTouchBegan = CC_CALLBACK_2(TommyGun::onTouchBegan, this);

	touch->onTouchMoved = CC_CALLBACK_2(TommyGun::onTouchMoved, this);

	touch->onTouchEnded = CC_CALLBACK_2(TommyGun::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);

	consumeMagic(combatScene);

}



void TommyGun::consumeMagic(HelloWorld* combatScene)

{

	_magicPoint -= 1;

}

void TommyGun::update(float t)
{
	setPosition(_hero->getPositionX(), _hero->getPositionY()-20);

	for (int i = 0; i < allBullet.size(); i++)

	{

		auto nowBullet = allBullet.at(i);

		if (nowBullet->getPositionY() > Director::getInstance()->getWinSize().height)

		{

			nowBullet->removeFromParent();

			allBullet.eraseObject(nowBullet);

			i--;

		}

	

	}

}