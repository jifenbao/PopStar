#ifndef ROCK_H
#define ROCK_H

#include "cocos2d.h"
#include "chipmunk.h"
#include "extensions/physics-nodes/CCPhysicsSprite.h"
#include "GlobalUtils.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Rock:public Object
{
public:
    Rock(SpriteBatchNode *spriteSheet, cpSpace *space, cpVect p);


    cpSpace        *space;
    PhysicsSprite  *sprite;
    cpShape        *shape;
    int            _mapIndex;
};

#endif // ROCK_H
