#pragma execution_character_set("utf-8")//ʹ��������������ʾ
#include "AudioControl.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

Scene* AudioControl::createScene() {
    // ����һ����������
    auto scene = Scene::create();
    // ���������
    auto layer = AudioControl::create();
    // ��GameSet����Ϊ�ӽڵ���ӵ�����
    scene->addChild(layer);
    // ���س�������
    return scene;
}

bool AudioControl::init() {
    // ���ø����init����
    if (!Layer::init()) {
        return false;
    }
    // ����豸�ɼ���ͼ��С
    Size visibleSize = Director::getInstance()->getVisibleSize();
    // �������������֡��ı������Ϊ��ǰ����ӽڵ�
    auto background = Sprite::create("background.png");
    if (background)
    {
        background->setScaleX(visibleSize.width / background->getTextureRect().getMaxX());
        background->setScaleY(visibleSize.height / background->getTextureRect().getMaxY());
        background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    }
    this->addChild(background);
    auto music_text = Text::create("��������", "Arial", 16);
    music_text->setPosition(Vec2(visibleSize.width * 0.25, visibleSize.height * 0.7));
    this->addChild(music_text);

    // ����һ��������
    auto music_slider = Slider::create();
    // ���û�����������
    music_slider->loadBarTexture("sliderTrack.png");
    // ���û������Ĺ�������
    music_slider->loadSlidBallTextures("SliderThumb.png", "SliderThumb.png", "");
    // ���ô��������Ľ���������
    music_slider->loadProgressBarTexture("sliderProgress.png");
    // ��ȡ֮ǰ���õı�����������
    float musicPercent = UserDefault::getInstance()->getFloatForKey("musicPercent");
    // ����ǵ�һ�ν������ó��������ñ������ֻ�����Ĭ�ϳ�ʼֵΪ100
    if (musicPercent == 0.0f) {
        musicPercent = 100.0f;
    }
    // ���ñ������ֻ������ĳ�ʼֵ
    music_slider->setPercent(musicPercent);
    music_slider->setPosition(Vec2(visibleSize.width * 0.6, visibleSize.height * 0.7));
    // ����¼�������,����������������
    music_slider->addEventListener([=](Ref* pSender, Slider::EventType type) {
        // ������İٷֱȷ����仯ʱ
        if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            // ��û������ٷֱ�
            int percent = music_slider->getPercent();
            // ���ñ�������ֵΪ�������ٷֱ�/100
            SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(float(percent) / 100);
            // �洢���õı�������ֵ
            UserDefault::getInstance()->setFloatForKey("musicPercent", percent);
        }
    });
    this->addChild(music_slider);
    // ��������Ч�������ı������Ϊ��ǰ����ӽڵ�
    auto sound_text = Text::create("��Ч����", "Arial", 16);
    sound_text->setPosition(Vec2(visibleSize.width * 0.25, visibleSize.height * 0.5));
    this->addChild(sound_text);

    // ����һ��������
    auto effects_slider = Slider::create();
    // ���û�����������
    effects_slider->loadBarTexture("sliderTrack.png");
    // ���û������Ĺ�������
    effects_slider->loadSlidBallTextures("SliderThumb.png", "SliderThumb.png", "");
    // ���ô��������Ľ���������
    effects_slider->loadProgressBarTexture("sliderProgress.png");
    // ��ȡ֮ǰ���õ���Ч����
    float effectPercent = UserDefault::getInstance()->getFloatForKey("effectPercent");
    // ����ǵ�һ�ν������ó�����������Ч������Ĭ�ϳ�ʼֵΪ100
    if (effectPercent == 0.0f) {
        effectPercent = 100.0f;
    }
    // ������Ч�������ĳ�ʼֵ
    effects_slider->setPercent(effectPercent);
    effects_slider->setPosition(Vec2(visibleSize.width * 0.6, visibleSize.height * 0.5));
    // ����¼�������,������Ч����
    effects_slider->addEventListener([=](Ref* pSender, Slider::EventType type) {
        // ������İٷֱȷ����仯ʱ
        if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            // ��û������ٷֱ�
            int percent = effects_slider->getPercent();
            // ���ñ�����Чֵ
            SimpleAudioEngine::getInstance()->setEffectsVolume(float(percent) / 100);
            // �洢���õı�������ֵ
            UserDefault::getInstance()->setFloatForKey("effectPercent", percent);
        }
    });
    this->addChild(effects_slider);

    // ���������ء���ť�����ʱ����returnToMenu����
    auto close_button = Button::create("AutoControlExit.png");
    float ButtonPic0 = 45 * 9;
    float fSize = visibleSize.width > visibleSize.height ? visibleSize.width : visibleSize.height;
    close_button->setScaleX(fSize / ButtonPic0);
    close_button->setScaleY(fSize / ButtonPic0);
    close_button->setPosition(Vec2(visibleSize.width*9 / 10, visibleSize.height * 0.9));
    close_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            // �л���MenuScene����
            auto transition = TransitionSlideInL::create(2.0, GameMenu::createScene());
            Director::getInstance()->replaceScene(transition);
        }
    });
    this->addChild(close_button);
    return true;
}


