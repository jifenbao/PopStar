#ifndef _BACKGROUND_LAYER_H_
#define _BACKGROUND_LAYER_H_

#include "cocos2d.h"
#include "chipmunk.h"
USING_NS_CC;

class BackgroundLayer:public Layer
{
public:
	virtual bool init();
	BackgroundLayer(cpSpace *_space);

	static BackgroundLayer *create(cpSpace *_space);
	
	Size		m_szWinSize;
	Point		m_ptCenter;

    TMXTiledMap *map00;
    TMXTiledMap *map01;

    int         mapWidth;
    int         mapIndex;

    cpSpace         *space;
    SpriteBatchNode *spriteSheet;
    CCArray         *objects;

    bool checkAndReload(float eyeX);

    void update(float dt);

    void loadObjects(TMXTiledMap *_map, int _mapIndex);

    void removeObjects(int _mapIndex);

    void removeObjectByShape(cpShape *_shape);

};

#endif
