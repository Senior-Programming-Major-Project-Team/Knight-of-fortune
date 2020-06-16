﻿#include "MapTestScreen.h"
#include "SimpleAudioEngine.h"
#include <cmath>
#include<stdlib.h>
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
	//设置地图的大小,随机初始化地图
	int began = 1, end = 5;
	//初始化地图
	srand(time(0));
	int select = rand() % 5 + 1;
	
	switch (select)
	{
	case 1:_map = TMXTiledMap::create("mapOne.tmx"); break;
	case 2:_map = TMXTiledMap::create("mapTwo.tmx"); break;
	case 3:_map = TMXTiledMap::create("mapThree.tmx"); break;
	case 4:_map = TMXTiledMap::create("mapFour.tmx"); break;
	case 5:_map = TMXTiledMap::create("mapFive.tmx"); break;
	}

	
	auto size = _map->getBoundingBox().size;
	_map->setAnchorPoint(Vec2::ZERO);
	_map->setPosition(Vec2::ZERO);

	//设置基层
	auto baseLayer = _map->getLayer("Base");
	baseLayer->setZOrder(0);

	_mapInformation = MapInfo(_map);

	//使得碰撞检测层与障碍检测层不可见
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