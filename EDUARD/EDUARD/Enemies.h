#pragma once

class Enemies
{
private:
    int EnemyHP;

public:

    Enemies(int initialHP);

    void takeDamage(int weaponType, int ammoSpent);
    int getHP() const;
    void setHP(int hp);
    void applyTrapDamage();
};
