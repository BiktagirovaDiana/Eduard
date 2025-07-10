#include "Level_4.h"
#include "GameManager.h"
#include "Shop.h"

void Level_4::StartLevel()
{
    int choice = 0;
    PlayerController::InfoPlayer();
    std::cout << Text::GetText("level4", "helloPablo4") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        PreparationForSearch();
        break;
    case 2:
        std::cout << Text::GetText("level4", "buyOff") << std::endl;
        GameManager::Lose();
        break;
    case 3:
        Raid();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        StartLevel();
        break;
    }
}

void Level_4::PreparationForSearch()
{
    int choice = 0;
    std::cout << Text::GetText("level4", "peaceful") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        PreparationForSearch2();
        break;
    case 2:
        GameManager::Lose();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        PreparationForSearch();
        break;
    }
}

void Level_4::PreparationForSearch2()
{
    int choice = 0;
    std::cout << Text::GetText("level4", "peaceful2") << std::endl;
    std::cin >> choice;
    std::cout << Text::GetText("level4", "winPolice") << std::endl;
    GameManager::Win();
    GameManager::CompleteLevel4();
}

void Level_4::Raid()
{
    int choice = 0;
    std::cout << Text::GetText("level4", "attackPolice") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        ImmediateAttack();
        break;
    case 2:
        WaitRaid();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        Raid();
        break;
    }
}

void Level_4::ImmediateAttack()
{
    std::cout << Text::GetText("level4", "warning") << std::endl;

    if (PlayerController::getGrenade() < 6 || PlayerController::getRPG() < 3) {
        shop.BuyOrNot();

        if (PlayerController::getGrenade() < 6 || PlayerController::getRPG() < 3) {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
            return;
        }
    }

    int choice = 0;
    std::cout << Text::GetText("level4", "trap") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getRPG() >= 3) {
            PlayerController::setRPG(PlayerController::getRPG() - 3);
            enemy.takeDamage(3, 3);
            std::cout << Text::GetText("level4", "policeWin") << std::endl;
            GameManager::Lose();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        if (PlayerController::getGrenade() >= 6) {
            PlayerController::setGrenade(PlayerController::getGrenade() - 6);
            enemy.takeDamage(6, 6);
            std::cout << Text::GetText("level4", "policeWin") << std::endl;
            GameManager::Lose();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        ImmediateAttack();
        break;
    }
}

void Level_4::WaitRaid()
{
    int choice = 0;
    std::cout << Text::GetText("level4", "search") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        PreparationForSearch();
        break;
    case 2:
        std::cout << Text::GetText("level4", "fight") << std::endl;
        GameManager::Lose();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        WaitRaid();
        break;
    }
}
