#include "MapInfo.h"
USING_NS_CC;
MapInfo::MapInfo(TMXTiledMap* map)
{
	_mapSize = map->getMapSize();
	_tileSize = map->getTileSize();

	auto collisionLayer = map->getLayer("collision");
	auto boxesLayer = map->getLayer("boxes");



	_collisionBoard = DyaDicVector(_mapSize.x, std::vector<bool>(_mapSize.y, true));//vector�ĳ�ʼ����ʽ����
	_boxesBoard = DyaDicVector(_mapSize.x, std::vector<bool>(_mapSize.y, true));
	
	//��ͼ��ײ��Ϣ�Ĵ洢,���ÿհ�gidֵΪ0
	for (int i = 0; i < _mapSize.x; ++i)
	{
		for (int j = 0; j < _mapSize.y; ++j)
		{
			if (collisionLayer->getTileGIDAt(Vec2(i, j)) > 0)
			{
				_collisionBoard[i][_mapSize.y - 1 - j] = false;

			}
		}
	}

	//������Ϣ�Ĵ洢
	for (int i = 0; i < _mapSize.x; ++i)
	{
		for (int j = 0; j < _mapSize.y; ++j)
		{
			if (boxesLayer->getTileGIDAt(Vec2(i, j)) > 0)
			{
				_boxesBoard [i][_mapSize.y - 1 - j] = false;

			}
		}
	}

}

PointINT MapInfo::getGridPoint(const Vec2& position) const
{
	return PointINT(static_cast<INT32>(position.x / _tileSize.x), static_cast<INT32>((position.y) / _tileSize.y));
}	

void MapInfo::removeTowerCollision(const Vec2& towerPosition)
{
	auto centralGridPoint = getGridPoint(towerPosition);
	for (auto i = -3; i < 4; ++i)
	{
		for (auto j = -3; j < 4; ++j)
		{
			_collisionBoard[centralGridPoint.x + i][centralGridPoint.y + j] = true;
		}
	}
}

Vec2 MapInfo::getPrecisePosition(const PointINT& girdPoint) const
{
	return Vec2(girdPoint.x * _tileSize.x + _tileSize.x / 2, girdPoint.y * _tileSize.y + _tileSize.y / 2);
}

bool MapInfo::checkCollision(const Vec2& position) const
{
	auto gridPos = getGridPoint(position);

	return _collisionBoard[gridPos.x][gridPos.y];
}

bool MapInfo::checkBoxes(const Vec2& position) const
{
	auto gridPos = getGridPoint(position);

	return _boxesBoard[gridPos.x][gridPos.y];
}

