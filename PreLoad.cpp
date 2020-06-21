#include "PreLoad.h"
#include<vector>
#include<Hero.h>
#include<MapInfo.h>
#include<HelloWorldScene.h>
//#include<knight.h>

USING_NS_CC;
extern std::string SWhatHasYouChooseToBeYourHero;
Hero* HWhatHasYouChooseToBeYourHero;

Scene* PreLoad::createScene() {
    auto scene = Scene::create();
    auto layer = PreLoad::create();
   scene->addChild(layer);
   return scene;
}

bool PreLoad::init() 
{
    // ���ø����init����
    if (!Layer::init()) {
        return false;
    }
    // ����豸�ɼ���ͼ��С
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //���ñ���ͼƬ
    auto background = Sprite::create("PreLoadBackground.png");
    if (background)
    {
        background->setScaleX(visibleSize.width / background->getTextureRect().getMaxX());
        background->setScaleY(visibleSize.height / background->getTextureRect().getMaxY());
        background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    }
    this->addChild(background);
    auto barSprite = Sprite::create("sliderTemp.png");
    // ��ʼ��һ��ProgressTimer����������
    _progress = ProgressTimer::create(barSprite);
    // setPercentage:0.0f����ʾ��δ�����κ���Դ����������Ļ�Ͼ���ʲôҲ������
    _progress->setPercentage(0.0f);
    // ����ͼƬ��С��ϵ����scale���ó�0.5������Сһ��
    _progress->setScale(0.5f);
    // ���ý�������������ʼλ�ã�Ĭ����ͼƬ���е�
    // �����Ҫ��ʾ�����ҵ�һ������Ч��������ĳ�(0,y)
    _progress->setMidpoint(Point(0.0f, 0.5f));
    // barChangeRate��ʾ�Ƿ�ı�ˮƽ���ߴ�ֱ����ı��������ó�1��ʾ�ı䣬0��ʾ���ı�
    _progress->setBarChangeRate(Point(1.0f, 0.f));
    // kCCProgressTimerTypeBar��ʾΪ���ν�����
    _progress->setType(ProgressTimer::Type::BAR);
    // ���ý�����λ������Ļ����
    _progress->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    // �����������Ϊ��ǰ����ӽڵ�
    this->addChild(_progress);
     return true;
}

void PreLoad::onEnterTransitionDidFinish() {
    // ���ø����onEnter����
    // ����preloadResources.plist�����ļ�,��ȡ�ļ��е���Ϸ��Դ�����б�����һ��ValueMap����
    std::vector<std::string> musics, effects;
    musics.push_back("Background.mp3");
    effects.push_back("Gun.wav");
    // ͨ��keyֵȡ��ÿ�ֲ�ͬ������Դ��ValueVector����
    //ValueVector spriteSheets = map.at("Picture").asValueVector();
    // ���ValueVector�����size��ӵõ���Ҫ���ص���Դ������
    _sourceCount =  effects.size() + musics.size();//spriteSheets.size() +
    // ���ý��������´���=100/��Ҫ���ص���Դ����
    _progressInterval = 100 / _sourceCount;
    // ���μ�����Դ
    loadMusic(musics);
    loadEffect(effects);
    //loadSpriteSheets(spriteSheets);
}

// ���ر�������
void PreLoad::loadMusic(std::vector<std::string> musicFiles) {
    for (int i = 0;i<musicFiles.size();i++)
    {
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic(musicFiles[i].c_str());
        progressUpdate();
    }
}

// ��������
void PreLoad::loadEffect(std::vector<std::string> EffectFiles) {
    for (int i = 0; i < EffectFiles.size(); i++)
    {
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic(EffectFiles[i].c_str());
        progressUpdate();
    }
}

// ���ؾ����
//void PreLoad::loadSpriteSheets(ValueVector spriteSheets) {
    /* �ú����������plist�ļ�������ͬ����׺Ϊ.png������ͼƬ���Ѹ�plist������spriteFrame��Ϣ��ȡ����
     ��֮��Ĵ����п���ͨ��
     Sprite::createWithSpriteFrameName(const std::string& spriteFrameName)������ȡ��Ӧ�ľ���֡
        ������airfightSheet.plist��ӦairfightSheet.png
     */
    /*for (Value& v : spriteSheets) {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(v.asString().c_str());
        progressUpdate();
    }
}*/

// ���������º���
void PreLoad::progressUpdate() {
    // ÿ�ε��øú���˵������һ����Դ���Լ�������Դ����
    if (--_sourceCount) {
        // ���ý������ٷֱ�
        _progress->setPercentage(100.0f - (_progressInterval * _sourceCount));
    }
    else {
        // ProgressFromTo�����Խ����ķ�ʽ��ʾͼƬ
        // ��һ��������ʾ����0.5�룬�ڶ���������ʾ�������ٷֱȿ�ʼ��������������ʾһֱ��100
        auto pft = ProgressFromTo::create(0.5f, _progress->getPercentage(), 100);
        // ������һ��CallFunc����
        auto callFunc = CallFunc::create([=] {
            // ��������Դ��ɣ��ӳ�2����ת����Ϸ������
            auto delay = DelayTime::create(2.0f);
            auto callFunc = CallFunc::create([] {
                Director::getInstance()->replaceScene(HelloWorld::createScene());
            });
            auto action = Sequence::create(delay, callFunc, NULL);
            this->runAction(action);
        });
        auto action = Sequence::create(pft, callFunc, NULL);
        // ������ִ�ж���
        _progress->runAction(action);
    }
}
