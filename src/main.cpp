#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>

using namespace geode::prelude;

// Writes the save file to disk. Only ever called when leaving a level,
// never during gameplay, so it can't cause mid-run lag.
static void saveNow() {
	if (auto* app = AppDelegate::get()) {
		app->trySaveGame(false);
	}
}

// Quitting via the pause menu
class $modify(SaveOnQuitPlayLayer, PlayLayer) {
	void onQuit() {
		PlayLayer::onQuit();
		if (Mod::get()->getSettingValue<bool>("save-on-quit")) {
			saveNow();
		}
	}
};

// Leaving via the level complete screen's menu button
class $modify(SaveOnMenuEndLevelLayer, EndLevelLayer) {
	void onMenu(CCObject* sender) {
		EndLevelLayer::onMenu(sender);
		if (Mod::get()->getSettingValue<bool>("save-on-end-screen")) {
			saveNow();
		}
	}
};
