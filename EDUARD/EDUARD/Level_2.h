#pragma once
#include "Text.h"
#include "PlayerController.h"
#include "GameManager.h"
#include "Shop.h"
#include "Enemies.h"

class Shop;

class Level_2
{
private:
    int killers_ = 0;
    Shop& shop;
    Enemies enemy_;
    int spent_;

public:
    Level_2(Shop& shopRef) : shop(shopRef), enemy_(60), spent_(0) {}

    void startLevel();
    // �����
    void attack();
    // �������
    void trap();
    // �����������
    void peopleAttack();
    void attackPlace();
    void strategyAttack();
    // ��������� �����
    void continueStrat();
    void finalPart();
};
