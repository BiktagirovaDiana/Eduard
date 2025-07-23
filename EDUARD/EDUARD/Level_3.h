#pragma once
#include "Text.h"
#include "PlayerController.h"
#include "GameManager.h"
#include "Enemies.h"
#include "Shop.h"

class Shop;

class Level_3
{
private:
	Shop& shop_;
	Enemies enemy_;
	int spent_;
public:
	Level_3(Shop& shopRef) : shop_(shopRef), enemy_(30), spent_(0) {}

	void startLevel();
	void meeting();
	void noMeeting();
	void shooting();
	void spy();
	void cleverSpy();
	void laboratory();
	void kidnapScientists();
};
