#include "PlayerController.h"
#include <Windows.h>

int PlayerController::Influence = 60;
int PlayerController::HP = 100;
int PlayerController::Money = 5000;
int PlayerController::Gun = 9;
int PlayerController::Grenade = 0;
int PlayerController::RPG = 0;

void PlayerController::InfoPlayer()
{
    if (HP <= 0) {
        std::cout << Text::GetText("player", "lowHPWarning") << std::endl;
        GameManager::Lose();
        return;
    }

    if (Influence < 30) {
        std::cout << Text::GetText("player", "lowInfluenceWarning") << std::endl;
        GameManager::Lose();
        return;
    }

    // Вывод основной информации
    std::cout << Text::GetText("player", "statsTitle") << std::endl;
    std::cout << Text::GetText("player", "influence") << " " << Influence << std::endl;
    std::cout << Text::GetText("player", "hp") << " " << HP << std::endl;
    std::cout << Text::GetText("player", "money") << " " << Money << std::endl;

    // Вывод инвентаря
    if (Gun > 0 || Grenade > 0 || RPG > 0) {
        std::cout << Text::GetText("player", "inventoryTitle") << std::endl;
        if (Gun > 0) {
            printf((Text::GetText("player", "gun") + "\n").c_str(), Gun);
        }
        if (Grenade > 0) {
            printf((Text::GetText("player", "grenade") + "\n").c_str(), Grenade);
        }
        if (RPG > 0) {
            printf((Text::GetText("player", "rpg") + "\n").c_str(), RPG);
        }
    }
    else {
        std::cout << Text::GetText("player", "emptyInventory") << std::endl;
    }
}

// Getters
int PlayerController::getInfluence() { return Influence; }
int PlayerController::getHP() { return HP; }
int PlayerController::getMoney() { return Money; }
int PlayerController::getGun() { return Gun; }
int PlayerController::getGrenade() { return Grenade; }
int PlayerController::getRPG() { return RPG; }

// Setters
int PlayerController::setInfluence(int x)
{
    Influence = x;
    if (Influence < 30) {
        printf((Text::GetText("player", "influenceWarning") + "\n").c_str(), Influence);
        GameManager::Lose();
    }
    return Influence;
}

int PlayerController::setHP(int x)
{
    HP = x;
    if (HP <= 0) {
        HP = 0;
        std::cout << Text::GetText("player", "lowHPWarning") << std::endl;
        GameManager::Lose();
    }
    return HP;
}

int PlayerController::setMoney(int x)
{
    Money = x;
    return Money;
}

int PlayerController::setGun(int x)
{
    Gun = x;
    return Gun;
}

int PlayerController::setGrenade(int x)
{
    Grenade = x;
    return Grenade;
}

int PlayerController::setRPG(int x)
{
    RPG = x;
    return RPG;
}
