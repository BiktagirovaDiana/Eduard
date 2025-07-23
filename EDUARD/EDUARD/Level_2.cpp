#include "Level_2.h"
#include "Text.h"

void Level_2::startLevel()
{
    int choice = 0;

    std::cout << Text::GetText("level2", "helloPablo2") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        attack();
        break;
    case 2:
        std::cout << Text::GetText("level2", "payOff") << std::endl;
        attack();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        startLevel();
        break;
    }
}

void Level_2::attack()
{
    shop.buyOrNot();
    PlayerController::infoPlayer();
    int choice = 0;
    std::cout << Text::GetText("level2", "strategy2") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        trap();
        break;
    case 2:
        peopleAttack();
        break;
    case 3:
        std::cout << Text::GetText("level2", "payOff") << std::endl;
        peopleAttack();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        attack();
        break;
    }
}

void Level_2::trap()
{
    int choice = 0;
    std::cout << Text::GetText("level2", "chooseTrap") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << Text::GetText("level2", "trap1") << std::endl;
        PlayerController::setInfluence(PlayerController::getInfluence() - 15);
        PlayerController::infoPlayer();
        peopleAttack();
        break;
    case 2:
        std::cout << Text::GetText("level2", "trap2") << std::endl;
        enemy_.applyTrapDamage();
        peopleAttack();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        break;
    }
}

void Level_2::peopleAttack()
{
    int choice = 0;
    std::cout << Text::GetText("level2", "peopleAttack") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getMoney() >= 800) {
            killers_ = 4;
            PlayerController::setMoney(PlayerController::getMoney() - 800);
            PlayerController::infoPlayer();
            attackPlace();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 2:
        if (PlayerController::getMoney() >= 1200) {
            killers_ = 6;
            PlayerController::setMoney(PlayerController::getMoney() - 1200);
            PlayerController::infoPlayer();
            attackPlace();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 3:
        if (PlayerController::getMoney() >= 1600) {
            killers_ = 8;
            PlayerController::setMoney(PlayerController::getMoney() - 1600);
            PlayerController::infoPlayer();
            attackPlace();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        peopleAttack();
        break;
    }
}

void Level_2::attackPlace()
{
    int choice = 0;
    std::cout << Text::GetText("level2", "attackPlace") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << Text::GetText("level2", "restaurant") << std::endl;
        strategyAttack();
        break;
    case 2:
        std::cout << Text::GetText("level2", "desert") << std::endl;
        strategyAttack();
        break;
    case 3:
        std::cout << Text::GetText("level2", "station") << std::endl;
        PlayerController::setInfluence(PlayerController::getInfluence() - 20);
        PlayerController::infoPlayer();
        strategyAttack();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        attackPlace();
        break;
    }
}

void Level_2::strategyAttack()
{
    int choice = 0;
    std::cout << Text::GetText("level2", "strategyAttack") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << Text::GetText("level2", "attackFirst") << std::endl;
        if (PlayerController::getGun() >= 4) {
            PlayerController::setGun(PlayerController::getGun() - 4);
            enemy_.takeDamage(1, 4);
            PlayerController::infoPlayer();
            continueStrat();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 2:
        PlayerController::setHP(PlayerController::getHP() - 15);
        if (PlayerController::getGun() >= 2) {
            PlayerController::setGun(PlayerController::getGun() - 2);
            enemy_.takeDamage(1, 2);
            PlayerController::infoPlayer();
            continueStrat();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        strategyAttack();
        break;
    }
}

void Level_2::continueStrat()
{
    int choice = 0;
    std::cout << Text::GetText("level2", "continueStrat") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getGrenade() >= 2) {
            PlayerController::setGrenade(PlayerController::getGrenade() - 2);
            enemy_.takeDamage(2, 2);
            PlayerController::infoPlayer();
            std::cout << Text::GetText("level2", "ifGrenade") << std::endl;
            finalPart();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 2:
        if (PlayerController::getGun() >= 4) {
            PlayerController::setGun(PlayerController::getGun() - 4);
            enemy_.takeDamage(1, 4);
            PlayerController::infoPlayer();
            std::cout << Text::GetText("level2", "ifGuns") << std::endl;
            finalPart();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        continueStrat();
        break;
    }
}

void Level_2::finalPart()
{
    if (enemy_.GetHP() <= 0) {
        std::cout << Text::GetText("level2", "winL2Short") << std::endl;
        PlayerController::setMoney(PlayerController::getMoney() + 2000);
        PlayerController::setInfluence(PlayerController::getInfluence() + 20);
        PlayerController::setHP(PlayerController::getHP() + 20);
        PlayerController::infoPlayer();
        GameManager::completeLevel3();
    }
    else {
        int choice = 0;
        std::cout << Text::GetText("level2", "finalPart") << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            if (PlayerController::getGun() >= 4)
            {
                PlayerController::setGun(PlayerController::getGun() - 4);
                enemy_.takeDamage(1, 4);
                std::cout << Text::GetText("level2", "winL2") << std::endl;
                PlayerController::setMoney(PlayerController::getMoney() + 2000);
                PlayerController::setInfluence(PlayerController::getInfluence() + 10);
                PlayerController::setHP(PlayerController::getHP() + 20);
                PlayerController::infoPlayer();
                GameManager::completeLevel3();
            }
            else
            {
                std::cout << Text::GetText("common", "beforeLose") << std::endl;
                GameManager::lose();
            }
            break;
        case 2:
            if (PlayerController::getGrenade() >= 2) {
                PlayerController::setGrenade(PlayerController::getGrenade() - 2);
                enemy_.takeDamage(2, 2);
                std::cout << Text::GetText("level2", "winL2") << std::endl;
                PlayerController::setMoney(PlayerController::getMoney() + 2000);
                PlayerController::setHP(PlayerController::getHP() + 20);
                PlayerController::infoPlayer();
                GameManager::completeLevel3();
            }
            else {
                std::cout << Text::GetText("common", "beforeLose") << std::endl;
                GameManager::lose();
            }
            break;
        default:
            std::cout << Text::GetText("common", "defaultButton") << std::endl;
            finalPart();
            break;
        }
    }
}
