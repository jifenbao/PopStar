#include "BackgroundLayer.h"
#include "AnimationLayer.h"
#include "GlobalUtils.h"
#include "Coin.h"
#include "Rock.h"


BackgroundLayer* BackgroundLayer::create(cpSpace *_space)
{
    BackgroundLayer *bkGround = new BackgroundLayer(_space);
    bkGround->autorelease();
    return bkGround;
}


BackgroundLayer::BackgroundLayer(cpSpace *_space)
{
    this->space = _space;
    this->objects = CCArray::create();
    init();
}


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



            //create spriteSheet
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("background.plist");

            this->spriteSheet = SpriteBatchNode::create("background.png");

            addChild(spriteSheet);

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

    this->removeObjects(newMapIndex-1);
    this->mapIndex = newMapIndex;

    return true;
}

void BackgroundLayer::update(float dt)
{
    AnimationLayer *animationLayer = (AnimationLayer*)this->getParent()->getChildByTag(animation);
    int eyeX = animationLayer->getEyeX();

    this->checkAndReload(eyeX);
}

void BackgroundLayer::loadObjects(TMXTiledMap *_map, int _mapIndex)
{

	TMXObjectGroup *coinGroup = _map->getObjectGroup("coin");
	ValueVector coinVector = coinGroup->getObjects();

	for (const auto v : coinVector)
	{
		const ValueMap dict = v.asValueMap();
		int x = dict.at("x").asInt();
		int y = dict.at("y").asInt();

		Coin *coin = Coin::create(this->spriteSheet,this->space,cpv(x + this->mapWidth * _mapIndex,y));
		coin->_mapIndex = _mapIndex;
		this->objects->addObject(coin);
	}



    //add rocks
	TMXObjectGroup *rockGroup = _map->getObjectGroup("rock");
	ValueVector rockVector = rockGroup->getObjects();

	for (const auto v : rockVector)
	{
		const ValueMap dict = v.asValueMap();
		int x = dict.at("x").asInt();
		int y = dict.at("y").asInt();

		Rock *rock = Rock::create(this->spriteSheet,this->space,cpv(x + this->mapWidth * _mapIndex,y));
		rock->_mapIndex = _mapIndex;
		this->objects->addObject(rock);
	}

}


void BackgroundLayer::removeObjects(int _mapIndex)
{
	for(int i = 0; i < this->objects->count(); i++)
	{
		Coin *coin = (Coin*)this->objects->getObjectAtIndex(i);
		if(_mapIndex == coin->_mapIndex)
		{
			coin->removeFromParent();
		}
	}
}
