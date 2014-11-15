#include "AnimationLayer.h"
#include "CCActionInterval.h"

bool AnimationLayer::init()
{
	bool bRet = false;

	do
	{
		CC_BREAK_IF(!Layer::init());

		m_szWinSize = Director::sharedDirector()->getWinSize();

		m_ptStart = ccp(80,85);
		auto pRunner = Sprite::create("runner.png");
		pRunner->setPosition(m_ptStart);

		//create move action
		auto actionTo = MoveTo::create(2.0, ccp(300, 85));
		pRunner->runAction(Sequence::create(actionTo,NULL));

		addChild(pRunner);

		bRet = true;
	}while(0);
	return bRet;
}
