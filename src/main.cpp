#include <Geode/Geode.hpp>
#include <Geode/modify/GJDifficultySprite.hpp>

using namespace geode::prelude;

class $modify(GJDifficultySprite) {
	void updateFeatureState(GJFeatureState state) {

		if (!Mod::get()->getSettingValue<bool>("enabled")) return GJDifficultySprite::updateFeatureState(state);

		int val = (int)state;

		if (val >= 0 && val <= 4) {
			int64_t newVal = Mod::get()->getSettingValue<int64_t>("mythic" + std::to_string(val));
			return GJDifficultySprite::updateFeatureState((GJFeatureState)(newVal));
		}

		else return GJDifficultySprite::updateFeatureState(state);
	}
};
