#include <Geode/Geode.hpp>
#include "VideoPlayer.hpp"
#include "MidairsVideoLayer.hpp"
#include <Geode/modify/LoadingLayer.hpp>
using namespace geode::prelude;

class $modify(LoadingLayer)
{

	virtual bool init(bool p0)
	{
		MidairsVideoLayer::play(this);
		return true;
	}
};