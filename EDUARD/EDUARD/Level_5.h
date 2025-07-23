#pragma once
#include "Text.h"
#include "PlayerController.h"
#include "GameManager.h"
#include "Enemies.h"
#include "Shop.h"

class GameManager;
class Shop;

class Level_5
{
private:
	int killers_ = 0;
	Shop& shop_;
	Enemies enemy_;
	int spent_;
public:
	Level_5(Shop& shopRef) : shop_(shopRef), enemy_(100), spent_(0) {}

	void startLevel();
	void meeting();
	void attackChapo();
	void Friend();
	void trap();
	void attackPlane();
	void attackPlane2();
	void trapStrategy();
	void trapMargo();
	void deathMargo();
	void surveillance();
	void attackStrategy();
	void attackStrategy2();
	void attackStrategy3();
	void ifDefense();
	void howContinue();
	void rpgOrGrenade();
};
