#include "Level_2.h"
#include "Text.h"

void Level_2::StartLevel()
{
    int choice = 0;

    std::cout << Text::GetText("level2", "helloPablo2") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        Attack();
        break;
    case 2:
        std::cout << Text::GetText("level2", "payOff") << std::endl;
        Attack();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        StartLevel();
        break;
    }
}

void Level_2::Attack()
{
    shop.BuyOrNot();
    PlayerController::InfoPlayer();
    int choice = 0;
    std::cout << Text::GetText("level2", "strategy2") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        Trap();
        break;
    case 2:
        PeopleAttack();
        break;
    case 3:
        std::cout << Text::GetText("level2", "payOff") << std::endl;
        PeopleAttack();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        Attack();
        break;
    }
}

void Level_2::Trap()
{
    int choice = 0;
    std::cout << Text::GetText("level2", "chooseTrap") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << Text::GetText("level2", "trap1") << std::endl;
        PlayerController::SetInfluence(PlayerController::GetInfluence() - 15);
        PlayerController::InfoPlayer();
        PeopleAttack();
        break;
    case 2:
        std::cout << Text::GetText("level2", "trap2") << std::endl;
        enemy.applyTrapDamage();
        PeopleAttack();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        break;
    }
}

void Level_2::PeopleAttack()
{
    int choice = 0;
    std::cout << Text::GetText("level2", "peopleAttack") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::GetMoney() >= 800) {
            Killers = 4;
            PlayerController::SetMoney(PlayerController::GetMoney() - 800);
            PlayerController::InfoPlayer();
            AttackPlace();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        if (PlayerController::GetMoney() >= 1200) {
            Killers = 6;
            PlayerController::SetMoney(PlayerController::GetMoney() - 1200);
            PlayerController::InfoPlayer();
            AttackPlace();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 3:
        if (PlayerController::GetMoney() >= 1600) {
            Killers = 8;
            PlayerController::SetMoney(PlayerController::GetMoney() - 1600);
            PlayerController::InfoPlayer();
            AttackPlace();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        PeopleAttack();
        break;
    }
}

void Level_2::AttackPlace()
{
    int choice = 0;
    std::cout << Text::GetText("level2", "attackPlace") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << Text::GetText("level2", "restaurant") << std::endl;
        StrategyAttack();
        break;
    case 2:
        std::cout << Text::GetText("level2", "desert") << std::endl;
        StrategyAttack();
        break;
    case 3:
        std::cout << Text::GetText("level2", "station") << std::endl;
        PlayerController::SetInfluence(PlayerController::GetInfluence() - 20);
        PlayerController::InfoPlayer();
        StrategyAttack();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        AttackPlace();
        break;
    }
}

void Level_2::StrategyAttack()
{
    int choice = 0;
    std::cout << Text::GetText("level2", "strategyAttack") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << Text::GetText("level2", "attackFirst") << std::endl;
        if (PlayerController::GetGun() >= 4) {
            PlayerController::SetGun(PlayerController::GetGun() - 4);
            enemy.takeDamage(1, 4);
            PlayerController::InfoPlayer();
            ContinueStrat();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        PlayerController::SetHP(PlayerController::GetHP() - 15);
        if (PlayerController::GetGun() >= 2) {
            PlayerController::SetGun(PlayerController::GetGun() - 2);
            enemy.takeDamage(1, 2);
            PlayerController::InfoPlayer();
            ContinueStrat();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        StrategyAttack();
        break;
    }
}

void Level_2::ContinueStrat()
{
    int choice = 0;
    std::cout << Text::GetText("level2", "continueStrat") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::GetGrenade() >= 2) {
            PlayerController::SetGrenade(PlayerController::GetGrenade() - 2);
            enemy.takeDamage(2, 2);
            PlayerController::InfoPlayer();
            std::cout << Text::GetText("level2", "ifGrenade") << std::endl;
            FinalPart();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        if (PlayerController::GetGun() >= 4) {
            PlayerController::SetGun(PlayerController::GetGun() - 4);
            enemy.takeDamage(1, 4);
            PlayerController::InfoPlayer();
            std::cout << Text::GetText("level2", "ifGuns") << std::endl;
            FinalPart();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        ContinueStrat();
        break;
    }
}

void Level_2::FinalPart()
{
    if (enemy.GetHP() <= 0) {
        std::cout << Text::GetText("level2", "winL2Short") << std::endl;
        PlayerController::SetMoney(PlayerController::GetMoney() + 2000);
        PlayerController::SetInfluence(PlayerController::GetInfluence() + 20);
        PlayerController::SetHP(PlayerController::GetHP() + 20);
        PlayerController::InfoPlayer();
        GameManager::CompleteLevel3();
    }
    else {
        int choice = 0;
        std::cout << Text::GetText("level2", "finalPart") << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            if (PlayerController::GetGun() >= 4)
            {
                PlayerController::SetGun(PlayerController::GetGun() - 4);
                enemy.takeDamage(1, 4);
                std::cout << Text::GetText("level2", "winL2") << std::endl;
                PlayerController::SetMoney(PlayerController::GetMoney() + 2000);
                PlayerController::SetInfluence(PlayerController::GetInfluence() + 10);
                PlayerController::SetHP(PlayerController::GetHP() + 20);
                PlayerController::InfoPlayer();
                GameManager::CompleteLevel3();
            }
            else
            {
                std::cout << Text::GetText("common", "beforeLose") << std::endl;
                GameManager::Lose();
            }
            break;
        case 2:
            if (PlayerController::GetGrenade() >= 2) {
                PlayerController::SetGrenade(PlayerController::GetGrenade() - 2);
                enemy.takeDamage(2, 2);
                std::cout << Text::GetText("level2", "winL2") << std::endl;
                PlayerController::SetMoney(PlayerController::GetMoney() + 2000);
                PlayerController::SetHP(PlayerController::GetHP() + 20);
                PlayerController::InfoPlayer();
                GameManager::CompleteLevel3();
            }
            else {
                std::cout << Text::GetText("common", "beforeLose") << std::endl;
                GameManager::Lose();
            }
            break;
        default:
            std::cout << Text::GetText("common", "defaultButton") << std::endl;
            FinalPart();
            break;
        }
    }
}
