#pragma once

class Enemies
{
private:
    int enemyHP_;

public:

    Enemies(int initialHP);

    void takeDamage(int weaponType, int ammoSpent);
    int GetHP() const;
    void SetHP(int hp);
    void applyTrapDamage();
};
