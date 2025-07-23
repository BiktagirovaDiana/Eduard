#include "Level_1.h"
#include "Text.h"

void Level_1::startLevel()
{
    int choice = 0;
    PlayerController::infoPlayer();
    std::cout << Text::GetText("level1", "helloPablo1") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        destroyEnemy();
        break;
    case 2:
        negotiations();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        startLevel();
        break;
    }
}

void Level_1::destroyEnemy()
{
    int choice = 0;
    std::cout << Text::GetText("level1", "strategy1") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        shop_.buyOrNot();
        peopleDesert();
        break;
    case 2:
        shop_.buyOrNot();
        enemysLair();
        break;
    case 3:
        std::cout << Text::GetText("level1", "nothing") << std::endl;
        destroyEnemy();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        destroyEnemy();
        break;
    }
}

void Level_1::negotiations()
{
    int choice = 0;
    std::cout << Text::GetText("level1", "negotiations") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getMoney() >= 2000) {
            std::cout << Text::GetText("level1", "winNegotiations1") << std::endl;
            PlayerController::setInfluence(PlayerController::getInfluence() - 15);
            PlayerController::setMoney(PlayerController::getMoney() - 2000);
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 2:
        if (PlayerController::getMoney() >= 1000) {
            std::cout << Text::GetText("level1", "winNegotiations2") << std::endl;
            PlayerController::setInfluence(PlayerController::getInfluence() - 10);
            PlayerController::setMoney(PlayerController::getMoney() - 1000);
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 3:
        std::cout << Text::GetText("level1", "loseNegotiations") << std::endl;
        GameManager::lose();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        negotiations();
        break;
    }
    PlayerController::infoPlayer();
}

void Level_1::peopleDesert()
{
    int choice = 0;
    std::cout << Text::GetText("level1", "peopleDesert") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getMoney() >= 700) {
            killers_ = 2;
            PlayerController::setMoney(PlayerController::getMoney() - 700);
            strategyDesert();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 2:
        if (PlayerController::getMoney() >= 750) {
            killers_ = 2;
            PlayerController::setMoney(PlayerController::getMoney() - 750);
            strategyDesert();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 3:
        if (PlayerController::getMoney() >= 1100) {
            killers_ = 4;
            PlayerController::setMoney(PlayerController::getMoney() - 1100);
            strategyDesert();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 4:
        if (PlayerController::getMoney() >= 1500) {
            killers_ = 4;
            PlayerController::setMoney(PlayerController::getMoney() - 1500);
            strategyDesert();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        peopleDesert();
        break;
    }
}

void Level_1::strategyDesert()
{
    int choice = 0;
    std::cout << Text::GetText("level1", "strategyDesert") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getGun() >= 4) {
            std::cout << Text::GetText("level1", "desertAttack") << std::endl;
            enemy_.takeDamage(1, 4);
            PlayerController::setGun(PlayerController::getGun() - 4);
            loseOrWin();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 2:
        if (PlayerController::getGun() >= 4) {
            std::cout << Text::GetText("level1", "desertDefense") << std::endl;
            enemy_.takeDamage(1, 4);
            PlayerController::setGun(PlayerController::getGun() - 4);
            PlayerController::setHP(PlayerController::getHP() - 20);
            loseOrWin();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        strategyDesert();
        break;
    }
    PlayerController::infoPlayer();
}

void Level_1::loseOrWin()
{
    if (killers_ == 4)
    {
        if (PlayerController::getGun() >= 4) {
            std::cout << Text::GetText("level1", "survive") << std::endl;
            enemy_.takeDamage(1, 4);
            PlayerController::setGun(PlayerController::getGun() - 4);
            std::cout << Text::GetText("level1", "win1") << std::endl;
            PlayerController::setMoney(PlayerController::getMoney() + 1000);
            PlayerController::setInfluence(PlayerController::getInfluence() + 10);
            PlayerController::setHP(PlayerController::getHP() + 20);
            GameManager::completeLevel1();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
    }
    else {
        std::cout << Text::GetText("level1", "death1") << std::endl;
        GameManager::lose();
    }
    PlayerController::infoPlayer();
}

void Level_1::enemysLair()
{
    int choice = 0;
    std::cout << Text::GetText("level1", "peopleLair") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getMoney() >= 700) {
            killers_ = 2;
            PlayerController::setMoney(PlayerController::getMoney() - 700);
            strategyLair();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 2:
        if (PlayerController::getMoney() >= 900) {
            killers_ = 3;
            PlayerController::setMoney(PlayerController::getMoney() - 900);
            strategyLair();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 3:
        if (PlayerController::getMoney() >= 1200) {
            killers_ = 4;
            PlayerController::setMoney(PlayerController::getMoney() - 1200);
            strategyLair();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        enemysLair();
        break;
    }
}

void Level_1::strategyLair()
{
    if (PlayerController::getGun() >= 2) {
        PlayerController::setGun(PlayerController::getGun() - 2);
        PlayerController::setHP(PlayerController::getHP() - 15);

        int choice = 0;
        std::cout << Text::GetText("level1", "attackLair") << std::endl;
        enemy_.takeDamage(1, 2);
        PlayerController::infoPlayer();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            shop_.buyOrNot();
            peopleDesert();
            break;
        case 2:
            if (PlayerController::getMoney() >= 3000) {
                std::cout << Text::GetText("level1", "win2") << std::endl;
                PlayerController::setInfluence(PlayerController::getInfluence() - 15);
                PlayerController::setMoney(PlayerController::getMoney() - 3000);
                GameManager::completeLevel1();
            }
            else {
                std::cout << Text::GetText("common", "beforeLose") << std::endl;
                GameManager::lose();
            }
            break;
        default:
            std::cout << Text::GetText("common", "defaultButton") << std::endl;
            strategyLair();
            break;
        }
    }
    else {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::lose();
    }
    PlayerController::infoPlayer();
}
