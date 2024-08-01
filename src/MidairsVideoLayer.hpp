#include <Geode/Geode.hpp>
using namespace geode::prelude;
class MidairsVideoLayer
{
    private:
        static inline LoadingLayer* parentLayer;
        static inline videoplayer::VideoPlayer* intro;
        static inline bool firstTime = true;
        static inline bool finished = false;
    public:
        static void play(LoadingLayer* layer)
        {
            if(firstTime)
            {
                firstTime = false;
                parentLayer = layer;

                intro = videoplayer::VideoPlayer::create(Mod::get()->getResourcesDir() / "intro.mpg", false);

                CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
                intro->setPosition(screenSize / 2);
                intro->fillSize(screenSize);
                layer->addChild(intro, 9999);
            }
        }
        static void onVideoFinished()
        {
            finished = true;
            log::info("video finished");
            intro->setVisible(false);
        }
        static bool hasFinished()
        {
            return finished;
        }
};