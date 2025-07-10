#include "PlayerController.h"
#include <Windows.h>

int PlayerController::influence_ = 60;
int PlayerController::hp_ = 100;
int PlayerController::money_ = 5000;
int PlayerController::gun_ = 9;
int PlayerController::grenade_ = 0;
int PlayerController::rpg_ = 0;

void PlayerController::InfoPlayer()
{
    if (hp_ <= 0) {
        std::cout << Text::GetText("player", "lowHPWarning") << std::endl;
        GameManager::Lose();
        return;
    }

    if (influence_ < 30) {
        std::cout << Text::GetText("player", "lowInfluenceWarning") << std::endl;
        GameManager::Lose();
        return;
    }

    // Вывод основной информации
    std::cout << Text::GetText("player", "statsTitle") << std::endl;
    std::cout << Text::GetText("player", "influence") << " " << influence_ << std::endl;
    std::cout << Text::GetText("player", "hp") << " " << hp_ << std::endl;
    std::cout << Text::GetText("player", "money") << " " << money_ << std::endl;

    // Вывод инвентаря
    if (gun_ > 0 || grenade_ > 0 || rpg_ > 0) {
        std::cout << Text::GetText("player", "inventoryTitle") << std::endl;
        if (gun_ > 0) {
            printf((Text::GetText("player", "gun") + "\n").c_str(), gun_);
        }
        if (grenade_ > 0) {
            printf((Text::GetText("player", "grenade") + "\n").c_str(), grenade_);
        }
        if (rpg_ > 0) {
            printf((Text::GetText("player", "rpg") + "\n").c_str(), rpg_);
        }
    }
    else {
        std::cout << Text::GetText("player", "emptyInventory") << std::endl;
    }
}

// Getters
int PlayerController::GetInfluence() { return influence_; }
int PlayerController::GetHP() { return hp_; }
int PlayerController::GetMoney() { return money_; }
int PlayerController::GetGun() { return gun_; }
int PlayerController::GetGrenade() { return grenade_; }
int PlayerController::GetRPG() { return rpg_; }

// Setters
int PlayerController::SetInfluence(int x)
{
    influence_ = x;
    if (influence_ < 30) {
        printf((Text::GetText("player", "influenceWarning") + "\n").c_str(), influence_);
        GameManager::Lose();
    }
    return influence_;
}

int PlayerController::SetHP(int x)
{
    hp_ = x;
    if (hp_ <= 0) {
        hp_ = 0;
        std::cout << Text::GetText("player", "lowHPWarning") << std::endl;
        GameManager::Lose();
    }
    return hp_;
}

int PlayerController::SetMoney(int x)
{
    money_ = x;
    return money_;
}

int PlayerController::SetGun(int x)
{
    gun_ = x;
    return gun_;
}

int PlayerController::SetGrenade(int x)
{
    grenade_ = x;
    return grenade_;
}

int PlayerController::SetRPG(int x)
{
    rpg_ = x;
    return rpg_;
}
