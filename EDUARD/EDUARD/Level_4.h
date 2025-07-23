#pragma once
#include "Text.h"
#include "PlayerController.h"
#include "GameManager.h"
#include "Shop.h"
#include "Enemies.h"

class Shop;

class Level_4
{
	int killers_ = 0;
	Shop& shop_;
	Enemies enemy_;
	int spent_;

private:
	Text text_;
public:
	Level_4(Shop& shopRef) : shop_(shopRef), enemy_(60), spent_(0) {}
	void StartLevel();
	void PreparationForSearch();
	void PreparationForSearch2();
	void ImmediateAttack();
	void Raid();
	void WaitRaid();
};