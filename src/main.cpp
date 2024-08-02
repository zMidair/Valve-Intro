#include <Geode/Geode.hpp>
#include "VideoPlayer.hpp"
#include "MidairsVideoLayer.hpp"
#include <Geode/modify/LoadingLayer.hpp>
using namespace geode::prelude;

class $modify(LoadingLayer)
{
	void loadAssets()
	{
		LoadingLayer::loadAssets();
		/*
		CCScene* scene = CCScene::create();
		CCScene* running = CCDirector::get()->getRunningScene();
		running->retain();
		this->retain();
		MidairsVideoLayer::play(scene, running, this);
		*/
	}
};