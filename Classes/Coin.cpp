#include "Coin.h"

Coin::Coin(SpriteBatchNode *spriteSheet, cpSpace *space, cpVect p)
{
    this->space = space;
    _mapIndex = 0;

    //加载金币的动画
    Vector< SpriteFrame * > animFrames;

    for (int i = 0; i < 8; i++)
    {
        String *str = String::createWithFormat("coin%d.png",i);
        SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str->getCString());

        animFrames.pushBack(frame);
    }


    Animation *animation = Animation::createWithSpriteFrames(animFrames,0.2);

    RepeatForever *action = RepeatForever::create(Animate::create(animation));

    this->sprite = PhysicsSprite::createWithSpriteFrameName("coin0.png");

    //初始化物理引擎
    float radius = 0.95 * this->sprite->getContentSize().width/2;
    cpBody *body = cpBodyNewStatic();
    cpBodySetPos(body, p);

    sprite->setCPBody(body);


    this->shape = cpCircleShapeNew(body,radius,cpvzero);

    this->shape->collision_type = coin;
    //这个应该是设置冲突检测生效的
    this->shape->sensor = true;

    cpSpaceAddStaticShape(this->space,this->shape);

    this->sprite->runAction(action);

    spriteSheet->addChild(this->sprite,1);

}


Coin* Coin::create(SpriteBatchNode *spriteSheet, cpSpace *space, cpVect p)
{
    Coin *coin = new Coin(spriteSheet,space,p);
    coin->autorelease();

    return coin;
}


void Coin::removeFromParent()
{
    cpSpaceRemoveStaticShape(this->space,this->shape);
    this->shape = NULL;

    this->sprite->removeFromParent();
    this->sprite = NULL;
}

cpShape *Coin::getShape()
{
    return this->shape;
}
