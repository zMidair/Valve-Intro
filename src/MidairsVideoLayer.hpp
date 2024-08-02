#include <Geode/Geode.hpp>
using namespace geode::prelude;
class MidairsVideoLayer
{
    private:
        static inline CCScene* nextScene;
        static inline LoadingLayer* _loadingLayer;
        static inline bool firstTime = true;
        static inline bool finished = false;
    public:
        static void play(CCScene* scene, CCScene* after, LoadingLayer* ldLayer)
        {
            if(firstTime)
            {
                firstTime = false;
                _loadingLayer = ldLayer;

                videoplayer::VideoPlayer* intro = videoplayer::VideoPlayer::create(Mod::get()->getResourcesDir() / "intro.mpg", false);

                CCSize screenSize = CCDirector::sharedDirector()->getWinSize();
                intro->setPosition(screenSize / 2);
                intro->fillSize(screenSize);
                scene->addChild(intro, 9999);

                CCDirector::get()->replaceScene(scene);
                nextScene = after;
            }
        }
        static void onVideoFinished()
        {
            finished = true;
            log::info("video finished");
            CCDirector::get()->pushScene(nextScene);
            nextScene->release();
            _loadingLayer->release();
        }
        static bool hasFinished()
        {
            return finished;
        }
};