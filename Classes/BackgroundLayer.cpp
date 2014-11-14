#include "BackgroundLayer.h"

bool BackgroundLayer::init()
{
		bool bRet = false;
		
		do 
		{
			CC_BREAK_IF(!Layer::init());

			m_szWinSize = Director::sharedDirector()->getWinSize();
			
			m_ptCenter = ccp(m_szWinSize.width / 2, m_szWinSize.height / 2);
            auto pBackGround = Sprite::create("PlayBG.png");
            pBackGround->setPosition(m_ptCenter);
            
            addChild(pBackGround);
		
			bRet = true;
		}while(0);
		return bRet;
}
