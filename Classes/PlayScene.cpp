#include "PlayScene.h"
#include "BackgroundLayer.h"
#include "AnimationLayer.h"
#include "StatusLayer.h"
#include "GlobalUtils.h"
USING_NS_CC;

Scene* PlayScene::scene()
{
    Scene * scene = NULL;
	do
	{
		// 'scene' is an autorelease object
		scene = Scene::create();
		CC_BREAK_IF(!scene);

	} while (0);

	return scene;
}

// on "init" you need to initialize your instance
bool PlayScene::init()
{
	//初始化物理引擎
	initPhysics();

    //add 3 layers
   
   BackgroundLayer *bkLayer = BackgroundLayer::create();
    addChild(bkLayer);
    
    AnimationLayer *anLayer = AnimationLayer::create(this->space);
    addChild(anLayer);
    
    StatusLayer * sLayer = StatusLayer::create();
    addChild(sLayer);


    //调度更新
    scheduleUpdate();

    return true;
}


void PlayScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void PlayScene::menuStartCallback(Ref* pSender)
{
	CCLog("clicked, the scene will be changed");
}


void PlayScene::initPhysics()
{
    //chipmunk的api，创建一个新的空间
    space = cpSpaceNew();

    //设置物理世界的重力
    space->gravity = cpv(0, -350);

    //定义跑库用到地面，从物理空间新建一个静态SegmentShape
    cpShape * wallBottom = cpSegmentShapeNew(space->staticBody,
                                        cpv(0, GlobalUtils::g_groundHeight),
                                        cpv(GlobalUtils::g_MAX_LONG, GlobalUtils::g_groundHeight),
                                        0);

    //把这个shape加入到物理空间里面
    cpSpaceAddStaticShape(space, wallBottom);
}


void PlayScene::update(float dt)
{
		// chipmunk step
	    cpSpaceStep(this->space, dt);
}
