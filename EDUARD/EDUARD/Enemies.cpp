#include "Enemies.h"
#include <iostream>

Enemies::Enemies(int initialHP) : enemyHP_(initialHP) {}


void Enemies::takeDamage(int weaponType, int ammoSpent) {
    int damagePerUnit = 0;


    switch (weaponType)
    {
    case 1:
        damagePerUnit = 5;
        break;
    case 2:
        damagePerUnit = 10;
        break;
    case 3:
        damagePerUnit = 20;
        break;
    default:
        return;
    }


    int totalDamage = damagePerUnit * ammoSpent;
    enemyHP_ -= totalDamage;

    if (enemyHP_ < 0) {
        enemyHP_ = 0;
    }
}

void Enemies::applyTrapDamage()
{
    enemyHP_ -= 20;
    if (enemyHP_ < 0) enemyHP_ = 0;
}

int Enemies::GetHP() const
{
    return enemyHP_;
}

void Enemies::SetHP(int hp)
{
    enemyHP_ = hp;
    if (enemyHP_ < 0) {
        enemyHP_ = 0;
    }
}

