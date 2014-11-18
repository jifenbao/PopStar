#ifndef _ANIMATION_LAYER_H_
#define _ANIMATION_LAYER_H_

#include "cocos2d.h"
#include <CCSpriteBatchNode.h>
#include "chipmunk.h"
#include "CCPhysicsSprite.h"
USING_NS_CC;
USING_NS_CC_EXT;
class AnimationLayer:public Layer
{
public:
	virtual bool init();
	AnimationLayer(cpSpace *_space);

    static AnimationLayer *create(cpSpace *_space);

	Size		m_szWinSize;
	Point		m_ptStart;

	SpriteBatchNode *spriteSheet;
	RepeatForever      *runningAction;
	PhysicsSprite   *sprite;
	 cpSpace 				   *space;
	 cpBody                  *body;
	 cpShape                 *shape;
};

#endif
