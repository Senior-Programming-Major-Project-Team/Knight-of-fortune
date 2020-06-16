#include "GameScene.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

Scene* GameScene::createScene()
{
    // 创建一个场景对象
    auto scene = Scene::create();
    // 创建层对象
    auto layer = GameScene::create();
    // 将GameMenu层作为子节点添加到场景
    scene->addChild(layer);
    // 返回场景对象
    return scene;
}

void GameScene::AddTransferMatriax()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    auto TransferMatrix = ParticleSystemQuad::create("TransferMatrix.plist");
    TransferMatrix->setPosition(visibleSize / 2);
    TransferMatrix->setScale(0.5);
    this->addChild(TransferMatrix);
	
}

bool GameScene::initMapLayer()
{
	// 设置地图的大小, 随机初始化地图
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
	auto boxesLayer = _map->getLayer("boxes");
	boxesLayer->setVisible(false);

	this->addChild(_map, 0, TAG_MAP);
}
bool GameScene::init()
{
    if (!Layer::init()||!initMapLayer())
    {
        return false;
    }
	this->addChild(ShowState::createLayer());
    //AddTransferMatriax();
 }

