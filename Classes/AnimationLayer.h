#ifndef _ANIMATION_LAYER_H_
#define _ANIMATION_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class AnimationLayer:public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(AnimationLayer);

	Size		m_szWinSize;
	Point		m_ptStart;
};

#endif
