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
	int Killers = 0;
	Shop& shop;
	Enemies enemy;
	int spent;
public:
	Level_5(Shop& shopRef) : shop(shopRef), enemy(100), spent(0) {}

	void StartLevel();
	void Meeting();
	void AttackChapo();
	void Friend();
	void Trap();
	void AttackPlane();
	void AttackPlane2();
	void TrapStrategy();
	//void NeutralPlace();
	//void NeutralPlace2();
	void TrapMargo();
	void DeathMargo();
	void Surveillance();
	void AttackStrategy();
	void AttackStrategy2();
	void AttackStrategy3();
	void IfDefense();
	void HowContinue();
	void RPGorGrenade();
};
