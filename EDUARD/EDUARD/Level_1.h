#pragma once
#include "Text.h"
#include "PlayerController.h"
#include "GameManager.h"
#include "Enemies.h"
#include "Shop.h"

class Shop;

class Level_1
{
private:
    int killers_ = 0;
    Shop& shop_;
    Enemies enemy_;
    int spent_;

public:
    Level_1(Shop& shopRef) : shop_(shopRef), enemy_(40), spent_(0) {}

    void startLevel();
    // ���������
    void destroyEnemy();
    void negotiations();
    // ��� � �������
    void peopleDesert();
    void strategyDesert();
    void loseOrWin();
    // ��� � ������ �����
    void enemysLair();
    void strategyLair();
};
