#ifndef _STATUS_LAYER_H_
#define _STATUS_LAYER_H_

#include "cocos2d.h"
#include <CCLabelTTF.h>

USING_NS_CC;

class StatusLayer:public Layer
{
public:
	virtual bool init();
	CREATE_FUNC(StatusLayer);

	LabelTTF*		labelCoin;
	LabelTTF*    	labelMeter;
	int         coins;
};

#endif
