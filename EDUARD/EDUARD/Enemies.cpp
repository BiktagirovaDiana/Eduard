#include "Enemies.h"
#include <iostream>

Enemies::Enemies(int initialHP) : EnemyHP(initialHP) {}


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
    EnemyHP -= totalDamage;

    if (EnemyHP < 0) {
        EnemyHP = 0;
    }
}

void Enemies::applyTrapDamage()
{
    EnemyHP -= 20;
    if (EnemyHP < 0) EnemyHP = 0;
}

int Enemies::getHP() const
{
    return EnemyHP;
}

void Enemies::setHP(int hp)
{
    EnemyHP = hp;
    if (EnemyHP < 0) {
        EnemyHP = 0;
    }
}

