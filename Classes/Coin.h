#ifndef COIN_H
#define COIN_H

#include "cocos2d.h"
#include "chipmunk.h"
#include "extensions/physics-nodes/CCPhysicsSprite.h"
#include "GlobalUtils.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Coin: public Object
{
public:

cpSpace        *space;
PhysicsSprite  *sprite;
cpShape        *shape;
int            _mapIndex;

Coin(SpriteBatchNode *spriteSheet, cpSpace *space, cpVect p);

void removeFromParent();

cpShape *getShape();

};

#endif // COIN_H
