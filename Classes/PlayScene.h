#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include <CCVector.h>
#include "chipmunk.h"

USING_NS_CC;

class PlayScene : public cocos2d::Scene
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // a selector callback
    void menuStartCallback(cocos2d::Ref* pSender);
    
    //初始化物理引擎
    void initPhysics();

    //按时更新
    void update(float dt);

    // implement the "static create()" method manually
    CREATE_FUNC(PlayScene)

    cpSpace *space;

    cocos2d::Layer   *gameLayer;



};

#endif // __POPSTAR_SCENE_H__
