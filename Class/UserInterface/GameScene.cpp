#include "GameScene.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

Scene* GameScene::createScene()
{
    // ����һ����������
    auto scene = Scene::create();
    // ���������
    auto layer = GameScene::create();
    // ��GameMenu����Ϊ�ӽڵ���ӵ�����
    scene->addChild(layer);
    // ���س�������
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
	// ���õ�ͼ�Ĵ�С, �����ʼ����ͼ
		int began = 1, end = 5;
	//��ʼ����ͼ
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

	//���û���
	auto baseLayer = _map->getLayer("Base");
	baseLayer->setZOrder(0);

	_mapInformation = MapInfo(_map);

	//ʹ����ײ�������ϰ����㲻�ɼ�
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

