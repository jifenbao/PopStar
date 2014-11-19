#include "Rock.h"

Rock::Rock(SpriteBatchNode *spriteSheet, cpSpace *space, cpVect p)
{
    this->space = space;
    this->_mapIndex = 0;

    this->sprite = PhysicsSprite::createWithSpriteFrameName("rock.png");
    cpBody *body = cpBodyNewStatic();

    cpBodySetPos(body,cpVect(p.x,this->sprite->getContentSize().height / 2 +GlobalUtils::g_groundHeight));
}
