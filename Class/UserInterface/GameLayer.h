#ifndef _GameLayer
#define _GameLayer

#include"cocos2d.h"

USING_NS_CC;
class GameLayer :public Layer
{
public:
	void TouchPaushButton();
	CCRenderTexture* renderTexture;
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameLayer);
};
#endif // !_GameLayer
