#include <Geode/Geode.hpp>
#include "VideoPlayer.hpp"
#include <Geode/modify/MenuLayer.hpp>
using namespace geode::prelude;

class $modify(MenuLayer)
{
	void onMyProfile(cocos2d::CCObject* sender)
	{
		videoplayer::VideoPlayer* intro = videoplayer::VideoPlayer::create(Mod::get()->getResourcesDir() / "intro.mpg", false);

		auto VideoScene = CCScene::create();

		CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
		intro->setPosition(screenSize / 2);
		intro->fillSize(screenSize);
		VideoScene->addChild(intro, 9999);

		CCDirector::sharedDirector()->pushScene(VideoScene);
	}
};