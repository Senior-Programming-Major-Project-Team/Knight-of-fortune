#include "MapInfo.h"
USING_NS_CC;
MapInfo::MapInfo(TMXTiledMap* map)
{
	_mapSize = map->getMapSize();
	_tileSize = map->getTileSize();

	auto collisionLayer = map->getLayer("collision");
	auto boxesLayer = map->getLayer("boxes");



	_collisionBoard = DyaDicVector(_mapSize.x, std::vector<bool>(_mapSize.y, false));//vector的初始化形式……
	_boxesBoard = DyaDicVector(_mapSize.x, std::vector<bool>(_mapSize.y, false));


	//以下存储初步转换了y坐标的颠倒

	//地图碰撞信息的存储,运用空白gid值为0
	for (int i = 0; i < _mapSize.x; i++)
	{
		for (int j = 0; j < _mapSize.y; j++)
		{
			if (collisionLayer->getTileGIDAt(Vec2(i, j)) > 0)
			{
				_collisionBoard[i][_mapSize.y - 1 - j] = true;

			}
		}
	}

	//箱子信息的存储
	for (int i = 0; i < _mapSize.x; i++)
	{
		for (int j = 0; j < _mapSize.y; j++)
		{
			if (boxesLayer->getTileGIDAt(Vec2(i, j)) > 0)
			{
				_boxesBoard[i][_mapSize.y - 1 - j] = true;

			}
		}
	}

}

PointINT MapInfo::getGridPoint(const Vec2& position) const
{
	return PointINT(static_cast<INT32>(position.x / _tileSize.x), static_cast<INT32>((position.y) / _tileSize.y));
}

void MapInfo::removeBoxesMessage(const Vec2& aPosition)
{
	auto centralGridPoint = getGridPoint(aPosition);
	//判断是不是箱子
	if (_boxesBoard[centralGridPoint.x][centralGridPoint.y] == true)
	{
		//如果是箱子将障碍数组里面标记为可用
		_collisionBoard[centralGridPoint.x][centralGridPoint.y] = false;
		//将箱子数组标记为可用
		_boxesBoard[centralGridPoint.x][centralGridPoint.y] = false;


	}
	//不是就return
	else
	{
		return;
	}


	//将箱子移除
//layer1->setTileGID(0, Vec2(x, y));//设置为0就置空了
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
	auto gridPos = getGridPoint(position);//转化成格子坐标

	return _boxesBoard[gridPos.x][gridPos.y];
}
