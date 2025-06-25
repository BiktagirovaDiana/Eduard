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
    int Killers = 0;
    Shop& shop;
    Enemies enemy;
    int spent;

public:
    Level_2(Shop& shopRef) : shop(shopRef), enemy(60), spent(0) {}

    void StartLevel();
    // �����
    void Attack();
    // �������
    void Trap();
    // �����������
    void PeopleAttack();
    void AttackPlace();
    void StrategyAttack();
    // ��������� �����
    void ContinueStrat();
    void FinalPart();
};
