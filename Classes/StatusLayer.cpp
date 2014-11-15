#include "StatusLayer.h"
#include <CCMenuItem.h>

bool StatusLayer::init()
{
	bool bRet = false;

			do
			{
				CC_BREAK_IF(!Layer::init());

				auto m_szWinSize = Director::sharedDirector()->getWinSize();

				labelCoin = LabelTTF::create("Coins:0", "Helvetica", 20);
				labelCoin->setFontFillColor(Color3B::BLACK);
				MenuItemLabel* mil1 = CCMenuItemLabel::create(labelCoin);
				mil1->setPosition(ccp(70, m_szWinSize.height - 20));
				addChild(mil1);

				labelMeter = LabelTTF::create("0M", "Helvetica", 20);
				labelMeter->setFontFillColor(Color3B::BLACK);
				MenuItemLabel* mil2 = CCMenuItemLabel::create(labelMeter);
				mil2->setPosition(ccp(m_szWinSize.width - 70, m_szWinSize.height - 20));
				addChild(mil2);


				bRet = true;
			}while(0);
			return bRet;
}
