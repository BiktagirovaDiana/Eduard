#include "Level_1.h"
#include "Text.h"

void Level_1::StartLevel()
{
    int choice = 0;
    PlayerController::InfoPlayer();
    std::cout << Text::GetText("level1", "helloPablo1") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        DestroyEnemy();
        break;
    case 2:
        Negotiations();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        StartLevel();
        break;
    }
}

void Level_1::DestroyEnemy()
{
    int choice = 0;
    std::cout << Text::GetText("level1", "strategy1") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        shop.BuyOrNot();
        PeopleDesert();
        break;
    case 2:
        shop.BuyOrNot();
        EnemysLair();
        break;
    case 3:
        std::cout << Text::GetText("level1", "nothing") << std::endl;
        DestroyEnemy();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        DestroyEnemy();
        break;
    }
}

void Level_1::Negotiations()
{
    int choice = 0;
    std::cout << Text::GetText("level1", "negotiations") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::GetMoney() >= 2000) {
            std::cout << Text::GetText("level1", "winNegotiations1") << std::endl;
            PlayerController::SetInfluence(PlayerController::GetInfluence() - 15);
            PlayerController::SetMoney(PlayerController::GetMoney() - 2000);
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        if (PlayerController::GetMoney() >= 1000) {
            std::cout << Text::GetText("level1", "winNegotiations2") << std::endl;
            PlayerController::SetInfluence(PlayerController::GetInfluence() - 10);
            PlayerController::SetMoney(PlayerController::GetMoney() - 1000);
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 3:
        std::cout << Text::GetText("level1", "loseNegotiations") << std::endl;
        GameManager::Lose();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        Negotiations();
        break;
    }
    PlayerController::InfoPlayer();
}

void Level_1::PeopleDesert()
{
    int choice = 0;
    std::cout << Text::GetText("level1", "peopleDesert") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::GetMoney() >= 700) {
            Killers = 2;
            PlayerController::SetMoney(PlayerController::GetMoney() - 700);
            StrategyDesert();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        if (PlayerController::GetMoney() >= 750) {
            Killers = 2;
            PlayerController::SetMoney(PlayerController::GetMoney() - 750);
            StrategyDesert();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 3:
        if (PlayerController::GetMoney() >= 1100) {
            Killers = 4;
            PlayerController::SetMoney(PlayerController::GetMoney() - 1100);
            StrategyDesert();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 4:
        if (PlayerController::GetMoney() >= 1500) {
            Killers = 4;
            PlayerController::SetMoney(PlayerController::GetMoney() - 1500);
            StrategyDesert();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        PeopleDesert();
        break;
    }
}

void Level_1::StrategyDesert()
{
    int choice = 0;
    std::cout << Text::GetText("level1", "strategyDesert") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::GetGun() >= 4) {
            std::cout << Text::GetText("level1", "desertAttack") << std::endl;
            enemy.takeDamage(1, 4);
            PlayerController::SetGun(PlayerController::GetGun() - 4);
            LoseOrWin();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        if (PlayerController::GetGun() >= 4) {
            std::cout << Text::GetText("level1", "desertDefense") << std::endl;
            enemy.takeDamage(1, 4);
            PlayerController::SetGun(PlayerController::GetGun() - 4);
            PlayerController::SetHP(PlayerController::GetHP() - 20);
            LoseOrWin();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        StrategyDesert();
        break;
    }
    PlayerController::InfoPlayer();
}

void Level_1::LoseOrWin()
{
    if (Killers == 4)
    {
        if (PlayerController::GetGun() >= 4) {
            std::cout << Text::GetText("level1", "survive") << std::endl;
            enemy.takeDamage(1, 4);
            PlayerController::SetGun(PlayerController::GetGun() - 4);
            std::cout << Text::GetText("level1", "win1") << std::endl;
            PlayerController::SetMoney(PlayerController::GetMoney() + 1000);
            PlayerController::SetInfluence(PlayerController::GetInfluence() + 10);
            PlayerController::SetHP(PlayerController::GetHP() + 20);
            GameManager::CompleteLevel1();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
    }
    else {
        std::cout << Text::GetText("level1", "death1") << std::endl;
        GameManager::Lose();
    }
    PlayerController::InfoPlayer();
}

void Level_1::EnemysLair()
{
    int choice = 0;
    std::cout << Text::GetText("level1", "peopleLair") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::GetMoney() >= 700) {
            Killers = 2;
            PlayerController::SetMoney(PlayerController::GetMoney() - 700);
            StrategyLair();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        if (PlayerController::GetMoney() >= 900) {
            Killers = 3;
            PlayerController::SetMoney(PlayerController::GetMoney() - 900);
            StrategyLair();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 3:
        if (PlayerController::GetMoney() >= 1200) {
            Killers = 4;
            PlayerController::SetMoney(PlayerController::GetMoney() - 1200);
            StrategyLair();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        EnemysLair();
        break;
    }
}

void Level_1::StrategyLair()
{
    if (PlayerController::GetGun() >= 2) {
        PlayerController::SetGun(PlayerController::GetGun() - 2);
        PlayerController::SetHP(PlayerController::GetHP() - 15);

        int choice = 0;
        std::cout << Text::GetText("level1", "attackLair") << std::endl;
        enemy.takeDamage(1, 2);
        PlayerController::InfoPlayer();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            shop.BuyOrNot();
            PeopleDesert();
            break;
        case 2:
            if (PlayerController::GetMoney() >= 3000) {
                std::cout << Text::GetText("level1", "win2") << std::endl;
                PlayerController::SetInfluence(PlayerController::GetInfluence() - 15);
                PlayerController::SetMoney(PlayerController::GetMoney() - 3000);
                GameManager::CompleteLevel1();
            }
            else {
                std::cout << Text::GetText("common", "beforeLose") << std::endl;
                GameManager::Lose();
            }
            break;
        default:
            std::cout << Text::GetText("common", "defaultButton") << std::endl;
            StrategyLair();
            break;
        }
    }
    else {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::Lose();
    }
    PlayerController::InfoPlayer();
}
