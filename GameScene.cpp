#include "GameScene.h"
#include "ui/CocosGUI.h"
#include<stdlib.h>
USING_NS_CC;
using namespace ui;

Scene* GameScene::createScene()
{
	return GameScene::create();
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
	return true;
}
bool GameScene::init()
{
    if (!Scene::init()||!initMapLayer()||!InitEnemy())
    {
        return false;
    }
	this->addChild(ShowState::createLayer());
    //AddTransferMatriax();
 }
Vec2 GameScene::RandomGeneration()
{
	srand((unsigned int) time(NULL));
	auto Size = Director::getInstance()->getVisibleSize();
	float x = ((float)rand() / RAND_MAX) * Size.width;
	float y = ((float)rand() / RAND_MAX) * Size.height;
	if (!_mapInformation.checkCollision(Vec2(x, y))&&!_mapInformation.checkBoxes(Vec2(x,y)))
		return Vec2(x, y);
	else return RandomGeneration();
}
std::vector<int> GameScene::EnemyNumberGeneration()
{
	int NumberOfSheavesAZ = RoundNumber();
	std::vector<int>target;
    int PigNumber, LanceGoblinNumber, FlowerNumber, HandGoblinNumber;
	srand((unsigned int)time(NULL));
	int TotalEnemy=(NumberOfSheavesAZ+1)*5;
	int AverageEnemy = TotalEnemy / 4;
	switch (TotalEnemy%4)
	{
	case 0:
	case 1:
		 PigNumber = AverageEnemy  + rand() % 2*NumberOfSheavesAZ -NumberOfSheavesAZ ;
		 LanceGoblinNumber = AverageEnemy + rand() % 2 * NumberOfSheavesAZ - NumberOfSheavesAZ;
		 FlowerNumber = AverageEnemy + rand() % 2 * NumberOfSheavesAZ - NumberOfSheavesAZ;
		 HandGoblinNumber = TotalEnemy - PigNumber - LanceGoblinNumber - FlowerNumber; break;
	case 2:
		PigNumber = AverageEnemy + rand() % 2 * NumberOfSheavesAZ - NumberOfSheavesAZ+1;
		LanceGoblinNumber = AverageEnemy + rand() % 2 * NumberOfSheavesAZ - NumberOfSheavesAZ;
		FlowerNumber = AverageEnemy + rand() % 2 * NumberOfSheavesAZ - NumberOfSheavesAZ;
		HandGoblinNumber = TotalEnemy - PigNumber - LanceGoblinNumber - FlowerNumber; break;
	case 3:
		PigNumber = AverageEnemy + rand() % 2 * NumberOfSheavesAZ - NumberOfSheavesAZ+1;
		LanceGoblinNumber = AverageEnemy + rand() % 2 * NumberOfSheavesAZ - NumberOfSheavesAZ+1;
		FlowerNumber = AverageEnemy + rand() % 2 * NumberOfSheavesAZ - NumberOfSheavesAZ;
		HandGoblinNumber = TotalEnemy - PigNumber - LanceGoblinNumber - FlowerNumber; break;
	}
	target.push_back(PigNumber);
	target.push_back(LanceGoblinNumber);
	target.push_back(FlowerNumber);
	target.push_back(HandGoblinNumber);
	return target;
}
bool GameScene::InitEnemy()
{
	std::vector<int> EnemyNumber = EnemyNumberGeneration();
	for (int i = 0; i < EnemyNumber[0]; i++)
	{
		auto ANewEnemy = Pig::create(this, "Pig", ENEMY);
		ANewEnemy->setPosition(RandomGeneration());
		this->addChild(ANewEnemy,ENEMY);
	}
	for (int i = 0; i < EnemyNumber[1]; i++)
	{
		auto ANewEnemy = LanceGoblin::create(this, "LanceGoblin", ENEMY);
		ANewEnemy->setPosition(RandomGeneration());
		this->addChild(ANewEnemy,ENEMY);
	}
	for (int i = 0; i < EnemyNumber[2]; i++)
	{
		auto ANewEnemy = Flower::create(this, "Flower", ENEMY);
		ANewEnemy->setPosition(RandomGeneration());
		this->addChild(ANewEnemy,ENEMY);
	}
	for (int i = 0; i < EnemyNumber[3]; i++)
	{
		auto ANewEnemy = HandGunGoblin::create(this, "HandGunblin", ENEMY);
		ANewEnemy->setPosition(RandomGeneration());
		this->addChild(ANewEnemy,ENEMY);
	}
	return true;
}
