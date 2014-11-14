#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class BackgroundLayer:public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(BackgroundLayer);
	
	Size		m_szWinSize;
	Point		m_ptCenter;
};

#endif
