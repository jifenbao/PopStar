#include "AnimationLayer.h"
#include "CCActionInterval.h"
#include "CCSpriteFrameCache.h"
#include <CCVector.h>
#include <CCAnimation.h>
#include "GlobalUtils.h"
#include <CCPhysicsSprite.h>

AnimationLayer* AnimationLayer::create(cpSpace *_space)
{
	AnimationLayer *animation = new AnimationLayer(_space);
	animation->autorelease();
	return animation;
}

AnimationLayer::AnimationLayer(cpSpace *_space)
{
	this->space = _space;
	init();
}

bool AnimationLayer::init()
{
	bool bRet = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("running.plist");
		spriteSheet = SpriteBatchNode::create("running.png");

		addChild(spriteSheet);

		//init running action
		Vector< SpriteFrame * > animFrames;

		for(int i = 0; i < 8; i++)
		{
			String str = String::createWithFormat("runner%d.png",i)->getCString();

			SpriteFrame*  frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str.getCString());
			animFrames.pushBack(frame);
		}

		Animation *animation = Animation::createWithSpriteFrames(animFrames, 0.1);
		runningAction = RepeatForever::create(Animate::create(animation));


		//sprite = Sprite::createWithSpriteFrameName("runner0.png");
		//sprite->setPosition(ccp(80,85));

		sprite = PhysicsSprite::createWithSpriteFrameName("runner0.png");
		auto contentSize = sprite->getContentSize();

		//初始化身体
        this->body = cpBodyNew(1,cpMomentForBox(1, contentSize.width, contentSize.height));
        this->body->p = cpv(GlobalUtils::g_runnerStartX, GlobalUtils::g_groundHeight + contentSize.height/2);
		cpBodyApplyImpulse(this->body,cpv(150,0), cpv(0,0));
		cpSpaceAddBody(this->space, this->body);

		//init shape
        this->shape = cpBoxShapeNew(this->body,contentSize.width-14,contentSize.height);
        cpSpaceAddShape(this->space, this->shape);

        sprite->setCPBody(this->body);


        sprite->runAction(runningAction);
        spriteSheet->addChild(sprite);

        scheduleUpdate();

        bRet = true;
    }while(0);
	return bRet;
}


int AnimationLayer::getEyeX()
{
    return sprite->getPositionX() - GlobalUtils::g_runnerStartX;
}
