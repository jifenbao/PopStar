#include "BackgroundLayer.h"
#include "AnimationLayer.h"
#include "GlobalUtils.h"

bool BackgroundLayer::init()
{
		bool bRet = false;
		
		do 
		{
			CC_BREAK_IF(!Layer::init());

            this->mapIndex = 0;
            this->mapWidth = 1;

            this->map00 = TMXTiledMap::create("map00.tmx");
            addChild(this->map00);

            this->mapWidth = this->map00->getContentSize().width;

            this->map01 = TMXTiledMap::create("map01.tmx");
            this->map01->setPosition(ccp(this->mapWidth,0));
            addChild(this->map01);

            scheduleUpdate();
		
			bRet = true;
		}while(0);
		return bRet;
}



bool BackgroundLayer::checkAndReload(float eyeX)
{
    int newMapIndex = (int)(eyeX/this->mapWidth);
    if(newMapIndex == this->mapIndex)
    {
        return false;
    }

    if(0 == newMapIndex % 2)
    {
        this->map01->setPositionX(this->mapWidth*(newMapIndex+1));
    }
    else
    {
        this->map00->setPositionX(this->mapWidth*(newMapIndex+1));
    }

    this->mapIndex = newMapIndex;

    return true;
}

void BackgroundLayer::update(float dt)
{
    AnimationLayer *animationLayer = (AnimationLayer*)this->getParent()->getChildByTag(GlobalUtils::Animation);
    int eyeX = animationLayer->getEyeX();

    this->checkAndReload(eyeX);
}
