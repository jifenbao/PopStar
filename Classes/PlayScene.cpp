#include "PlayScene.h"
#include "BackgroundLayer.h"
#include "AnimationLayer.h"
#include "StatusLayer.h"
#include "GlobalUtils.h"
USING_NS_CC;



// c function for chipmunk
static void postStepRemove(cpSpace *space, cpShape *shape, void *param)
{
	//这里是runner和rock或者coin撞到后到回调函数，目前先空着

//    ObjectManager *objectManager = (ObjectManager *)param;
//    switch (shape->collision_type) {
//        case SpriteTagcoin:
//            CCNotificationCenter::sharedNotificationCenter()->postNotification(NOTIFI_MEET_COIN);
//            objectManager->remove((CCSprite *)shape->data);
//            break;
//        case SpriteTagrock:
//            CCNotificationCenter::sharedNotificationCenter()->postNotification(NOTIFI_MEET_ROCK);
//            break;
//        default:
//            break;
//    }
}


static int collisionCoinBegin(cpArbiter* arb, cpSpace* space,	void* data)
{
		// we get shapes here, so postStepRemove's second param is cpShape
	    CP_ARBITER_GET_SHAPES(arb, a, b);
	    //a is runner and b is coin or rock
	    cpSpaceAddPostStepCallback(space, (cpPostStepFunc)postStepRemove, b, data);
	    return 0;

}

static  int collisionRockBegin(cpArbiter* arb, cpSpace* space,	void* data)
{
	CCLog("game over");
}

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


    //创建一个新的层，把background和animation层加进来

    gameLayer = Layer::create();

    BackgroundLayer *bkLayer = BackgroundLayer::create(this->space);
    gameLayer->addChild(bkLayer,0,background);
    
    AnimationLayer *anLayer = AnimationLayer::create(this->space);
    gameLayer->addChild(anLayer, 0, animation);

    addChild(gameLayer);

    StatusLayer * sLayer = StatusLayer::create();
    addChild(sLayer, 0, Status);


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

    //设置chipmunk到冲突检测处理函数,这里是runner和金币到冲突检测
    cpSpaceAddCollisionHandler(space, runner,coin,collisionCoinBegin,NULL,NULL,NULL,NULL);

    //设置chipmunk到冲突检测处理函数,这里是runner和石头到冲突检测
    cpSpaceAddCollisionHandler(space, runner,rock,collisionRockBegin,NULL,NULL,NULL,NULL);


}

void PlayScene::update(float dt)
{
		// chipmunk step
	    cpSpaceStep(this->space, dt);

	    AnimationLayer *aLayer = (AnimationLayer *)this->gameLayer->getChildByTag(animation);
	    int eyeX = aLayer->getEyeX();

	    this->gameLayer->setPosition(ccp(-eyeX,0));
}
