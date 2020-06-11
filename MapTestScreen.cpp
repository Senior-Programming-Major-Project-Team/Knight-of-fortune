#include "MapTestScreen.h"
#include "SimpleAudioEngine.h"
#include <cmath>

USING_NS_CC;

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


bool  MapTest::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	_visibleSize = Director::getInstance()->getVisibleSize();
	_origin = Director::getInstance()->getVisibleOrigin();
	
	//	test();

	initMapLayer();

	
	return true;
}


void  MapTest::initMapLayer()
{
	//设置地图的大小
	_map = TMXTiledMap::create("mapOne.tmx");
	auto size = _map->getBoundingBox().size;
	_map->setAnchorPoint(Vec2::ZERO);
	_map->setPosition(Vec2::ZERO);

	//设置基层
	auto baseLayer = _map->getLayer("Base");
	baseLayer->setZOrder(0);

	_mapInformation = MapInfo(_map);
	/*_blueSoldierPathPoints = SoldierPath::create("data/BluePathPoints.txt", _mapInformation);
	_redSoldierPathPoints = SoldierPath::create("data/RedPathPoints.txt", _mapInformation);
	_aiHeroPathPoints = SoldierPath::create("data/AIHeroPathPoints.txt", _mapInformation);
	_actors.pushBack(_blueSoldierPathPoints);
	_actors.pushBack(_redSoldierPathPoints);
	_actors.pushBack(_aiHeroPathPoints);*/

	auto collisionLayer = _map->getLayer("collision");
	collisionLayer->setVisible(false);
    auto boxesLayer= _map->getLayer("boxes");
	boxesLayer->setVisible(false);

	this->addChild(_map, 0, TAG_MAP);
}

Scene* MapTest::createScene()
{
	return MapTest::create();
}


void  MapTest::updateMap()
{

}






Vec2 MapTest::getPositionInMap(const Vec2& mousePosition)
{
	return mousePosition - _map->getPosition();
}
