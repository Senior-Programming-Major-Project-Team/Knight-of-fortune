#include"HandGun.h"
#include"constnumber.h"



HandGun* HandGun::create(HelloWorld* combatScene, std::string weaponName, Hero* hero)
{
	HandGun* handGun = new(std::nothrow)HandGun;
	if (handGun->init(combatScene, weaponName,hero))
	{
		handGun->autorelease();
		return handGun;
	}
	else
	{
		CC_SAFE_DELETE(handGun);
		return nullptr;
	}
}

bool HandGun::init(HelloWorld* combatScene, std::string weaponName, Hero* hero)
{
	
	/*auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();*/
	//创建冲锋枪精灵
	auto spHandGun = Sprite::create(weaponName);
	//设置锚点位置，坐标位置，target并添加
	spHandGun->setAnchorPoint(Point(0.5, 0.7));
	spHandGun->setPosition(hero->getPosition());
	spHandGun->setTag(HAND_GUN);
	combatScene->addChild(spHandGun);
	_attackPoint = 2;
	_magicPoint = 300;
	_critRate = 0.1;
	_weaponName = "HandGun";
	//this->scheduleUpdate();

	//子弹发射
	//计划任务

	//this->schedule(schedule_selector(tommyGun::touchupdate), 0.5);
	//this->schedule(schedule_selector(tommyGun::moveBullet), 0.1);

	return true;


}


bool HandGun::onTouchBegan(Touch* touch, Event* unused_event)
{
	targetX = touch->getLocation().x;
	targetY = touch->getLocation().y;
	auto spHandGun = this->getChildByTag(HAND_GUN);
	Vec2 shootVector(targetX - (spHandGun->getPositionX()), targetY - spHandGun->getPositionY());
	Vec2 detalVector = shootVector.getNormalized(); //方向单位向量
	float angle = atan2(detalVector.y, detalVector.x);
	float degree = CC_RADIANS_TO_DEGREES(angle);
	float rotateSpeed = 2 * M_PI;
	float rotateTime = angle / 2 * M_PI;
	spHandGun->setRotation(-degree);
	return true;
}
void HandGun::onTouchMoved(Touch* touch, Event* unused_event)
{

}
void HandGun::onTouchEnded(Touch* touch, Event* unused_event)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto spHandGun = this->getChildByTag(HAND_GUN);
	Vec2 shootVector(targetX - (spHandGun->getPositionX()), targetY - spHandGun->getPositionY());
	Vec2 detalVector = shootVector.getNormalized(); //方向单位向量
	Vec2 overVector = detalVector * 1000;//超出屏幕的（注定要被清除）点
	Sprite* Bullet = Sprite::create("bullet1.png");
	
	Bullet->setPosition(spHandGun->getPositionX() + 30 * detalVector.x, spHandGun->getPositionY() + 30 * detalVector.y);

	Vec2 offVector1 = Bullet->getPosition() + overVector;//同上
	
	float flySpeed = 200;//飞行速度
	float flyTime = overVector.getLength() / flySpeed;//飞行时间
	auto moveTo = MoveTo::create(flyTime, offVector1);
	
	this->addChild(Bullet);
	
	this->allBullet.pushBack(Bullet);
	
	Bullet->runAction(moveTo);
	
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

void HandGun::openFire(HelloWorld* combatScene)
{
	
	if (_magicPoint <= 0)
		return;
	//创建一个触摸监听
	EventListenerTouchOneByOne* touch = EventListenerTouchOneByOne::create();
	/*touch->setSwallowTouches(true);
	touch->setEnabled(true);*/
	touch->onTouchBegan = CC_CALLBACK_2(HandGun::onTouchBegan, this);
	touch->onTouchMoved = CC_CALLBACK_2(HandGun::onTouchMoved, this);
	touch->onTouchEnded = CC_CALLBACK_2(HandGun::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touch, this);
	consumeMagic(combatScene);
}

void HandGun::consumeMagic(HelloWorld* combatScene)
{
	_magicPoint -= 1;
}

