#include <iostream>
#include "../Enemies/EyeEnemy.hpp"
#include "../SettingsManager/SettingsManager.hpp"
#include "../SpriteContoller/SpriteController.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest.h"

TEST_SUITE("Enemy Tests") {
  TEST_CASE("calculateTowardsVector Test") {
	SettingsManager settingsManager("../../../src/Tests/settingsForTests.toml");
	SpriteController spriteController(settingsManager);
	EyeEnemy enemy(
		{10, 10},
		spriteController.spriteArrays["enemy_move"],
		spriteController.spriteArrays["enemy_attack"],
		spriteController.spriteArrays["enemy_hit"],
		spriteController.spriteArrays["enemy_death"], 100,
		100,
		toml::find<std::string>(settingsManager.SoundSettings, "enemy_hit"),
		2 * 30);
	auto result = enemy.calculateTowardsVector({15,15});
	CHECK(result==sf::Vector2f{70.710678, 70.710678});
  }
}
