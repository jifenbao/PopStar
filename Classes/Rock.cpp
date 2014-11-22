#include "Rock.h"

Rock::Rock(SpriteBatchNode *spriteSheet, cpSpace *space, cpVect p)
{
    this->space = space;
    this->_mapIndex = 0;

    this->sprite = PhysicsSprite::createWithSpriteFrameName("rock.png");
    cpBody *body = cpBodyNewStatic();

    cpVect pVect;
    pVect.x = p.x;
    pVect.y = this->sprite->getContentSize().height / 2 +GlobalUtils::g_groundHeight;

    cpBodySetPos(body,pVect);

    sprite->setCPBody(body);

    this->shape = cpBoxShapeNew(body,sprite->getContentSize().width, sprite->getContentSize().height);

    this->shape->collision_type = rock;

    cpSpaceAddStaticShape(space,shape);

    spriteSheet->addChild(sprite);
}


Rock *Rock::create(SpriteBatchNode *spriteSheet, cpSpace *space, cpVect p)
{
	Rock *rock = new Rock(spriteSheet,space,p);
	rock->autorelease();
	return rock;
}

void Rock::removeFromParent()
{
    cpSpaceRemoveStaticShape(this->space,this->shape);
    this->shape = NULL;

    this->sprite->removeFromParent();
    this->sprite = NULL;
}

cpShape *Rock::getShape()
{
    return this->getShape();
}
