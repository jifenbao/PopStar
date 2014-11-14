#include "PlayScene.h"
#include "BackgroundLayer.h"
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
    //add 3 layers
   
   BackgroundLayer *bkLayer = BackgroundLayer::create();
    addChild(bkLayer);
    
    
    
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
