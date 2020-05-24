#include "AudioControl.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

Scene* AudioControl::createScene() {
    // 创建一个场景对象
    auto scene = Scene::create();
    // 创建层对象
    auto layer = AudioControl::create();
    // 将GameSet层作为子节点添加到场景
    scene->addChild(layer);
    // 返回场景对象
    return scene;
}

bool AudioControl::init() {
    // 调用父类的init方法
    if (!Layer::init()) {
        return false;
    }
    // 获得设备可见视图大小
    Size visibleSize = Director::getInstance()->getVisibleSize();
    // 创建“背景音乐”文本并添加为当前层的子节点
    auto music_text = Text::create("Background music", "Arial", 32);
    music_text->setPosition(Vec2(visibleSize.width * 0.25, visibleSize.height * 0.7));
    this->addChild(music_text);

    // 创建一个滑动条
    auto music_slider = Slider::create();
    // 设置滑动条的纹理
    music_slider->loadBarTexture("slider.png");
    // 设置滑动条的滚轮纹理
    music_slider->loadSlidBallTextures("SliderBar.png", "SliderBar.png", "");
    // 设置处理滑动条的进度条纹理
    music_slider->loadProgressBarTexture("slider.png");
    // 获取之前设置的背景音乐音量
    float musicPercent = UserDefault::getInstance()->getFloatForKey("musicPercent");
    // 如果是第一次进入设置场景，设置背景音乐滑动条默认初始值为100
    if (musicPercent == 0.0f) {
        musicPercent = 100.0f;
    }
    // 设置背景音乐滑动条的初始值
    music_slider->setPercent(musicPercent);
    music_slider->setPosition(Vec2(visibleSize.width * 0.6, visibleSize.height * 0.7));
    // 添加事件监听器,调整背景音乐音量
    music_slider->addEventListener([=](Ref* pSender, Slider::EventType type) {
        // 当滑块的百分比发生变化时
        if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            // 获得滑动条百分比
            int percent = music_slider->getPercent();
            // 设置背景音乐值为滑动条百分比/100
            SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(float(percent) / 100);
            // 存储设置的背景音乐值
            UserDefault::getInstance()->setFloatForKey("musicPercent", percent);
        }
    });
    this->addChild(music_slider);
    // 创建“音效音量”文本并添加为当前层的子节点
    auto sound_text = Text::create("Sound Effect", "Arial", 32);
    sound_text->setPosition(Vec2(visibleSize.width * 0.25, visibleSize.height * 0.5));
    this->addChild(sound_text);

    // 创建一个滑动条
    auto effects_slider = Slider::create();
    // 设置滑动条的纹理
    effects_slider->loadBarTexture("slider.png");
    // 设置滑动条的滚轮纹理
    effects_slider->loadSlidBallTextures("SliderBar.png", "SliderBar.png", "");
    // 设置处理滑动条的进度条纹理
    effects_slider->loadProgressBarTexture("slider.png");
    // 获取之前设置的音效音量
    float effectPercent = UserDefault::getInstance()->getFloatForKey("effectPercent");
    // 如果是第一次进入设置场景，设置音效滑动条默认初始值为100
    if (effectPercent == 0.0f) {
        effectPercent = 100.0f;
    }
    // 设置音效滑动条的初始值
    effects_slider->setPercent(effectPercent);
    effects_slider->setPosition(Vec2(visibleSize.width * 0.6, visibleSize.height * 0.5));
    // 添加事件监听器,调整音效音量
    effects_slider->addEventListener([=](Ref* pSender, Slider::EventType type) {
        // 当滑块的百分比发生变化时
        if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            // 获得滑动条百分比
            int percent = effects_slider->getPercent();
            // 设置背景音效值
            SimpleAudioEngine::getInstance()->setEffectsVolume(float(percent) / 100);
            // 存储设置的背景音乐值
            UserDefault::getInstance()->setFloatForKey("effectPercent", percent);
        }
    });
    this->addChild(effects_slider);

    // 创建“返回“按钮，点击时调用returnToMenu函数
    auto return_button = Button::create("button.png");
    return_button->setPosition(Vec2(visibleSize.width - return_button->getContentSize().width / 2,
        return_button->getContentSize().height / 2));
    return_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            // 切换到MenuScene场景
            auto transition = TransitionSlideInL::create(2.0, GameMenu::createScene());
            Director::getInstance()->replaceScene(transition);
        }
    });
    return true;
}


