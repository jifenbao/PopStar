#ifndef _BACKGROUND_LAYER_H_
#define _BACKGROUND_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class BackgroundLayer:public Layer
{
public:
	virtual bool init();
    CREATE_FUNC(BackgroundLayer)
	
	Size		m_szWinSize;
	Point		m_ptCenter;

    TMXTiledMap *map00;
    TMXTiledMap *map01;

    int         mapWidth;
    int         mapIndex;



    bool checkAndReload(float eyeX);

    void update(float dt);

};

#endif
