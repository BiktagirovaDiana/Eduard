#include "Level_3.h"
#include "Text.h"

void Level_3::StartLevel()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "helloPablo3") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        Meeting();
        break;
    case 2:
        NoMeeting();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        StartLevel();
        break;
    }
}

void Level_3::Meeting()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "meeting") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        Shooting();
        break;
    case 2:
        Spy();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        Meeting();
        break;
    }
}

void Level_3::NoMeeting()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "refusal") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        Meeting();
        break;
    case 2:
        std::cout << Text::GetText("level3", "loseRefusal") << std::endl;
        GameManager::Lose();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        NoMeeting();
        break;
    }
}

void Level_3::Spy()
{
    if (PlayerController::getMoney() >= 700)
    {
        PlayerController::setMoney(PlayerController::getMoney() - 700);
        PlayerController::InfoPlayer();
        int choice = 0;
        std::cout << Text::GetText("level3", "spy") << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            CleverSpy();
            break;
        case 2:
            std::cout << Text::GetText("level3", "stupidSpy") << std::endl;
            shop.BuyOrNot();
            Shooting();
            break;
        default:
            std::cout << Text::GetText("common", "defaultButton") << std::endl;
            Spy();
            break;
        }
    }
    else
    {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::Lose();
    }
}

void Level_3::CleverSpy()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "cleverSpy") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        Shooting();
        break;
    case 2:
        if (PlayerController::getGun() >= 6)
        {
            PlayerController::setGun(PlayerController::getGun() - 6);
            enemy.takeDamage(1, 6);
            PlayerController::InfoPlayer();
            std::cout << Text::GetText("level3", "cleverSpy2") << std::endl;
            Laboratory();
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        GameManager::Lose();
        break;
    }
}

void Level_3::Shooting()
{
    if (PlayerController::getMoney() >= 1200)
    {
        PlayerController::setMoney(PlayerController::getMoney() - 1200);
        PlayerController::InfoPlayer();

        shop.BuyOrNot();

        int choice = 0;
        std::cout << Text::GetText("level3", "strategy3") << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            if (PlayerController::getGun() >= 6)
            {
                PlayerController::setGun(PlayerController::getGun() - 6);
                PlayerController::InfoPlayer();
                enemy.takeDamage(1, 6);
                Laboratory();
            }
            else
            {
                std::cout << Text::GetText("common", "defaultButton") << std::endl;
                GameManager::Lose();
            }
            break;
        case 2:
            if (PlayerController::getGrenade() >= 3)
            {
                PlayerController::setGrenade(PlayerController::getGrenade() - 3);
                enemy.takeDamage(2, 3);
                PlayerController::InfoPlayer();
                Laboratory();
            }
            else
            {
                std::cout << Text::GetText("common", "beforeLose") << std::endl;
                GameManager::Lose();
            }
            break;
        default:
            std::cout << Text::GetText("common", "defaultButton") << std::endl;
            Shooting();
            break;
        }
    }
    else
    {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::Lose();
    }
}

void Level_3::Laboratory()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "laboratory") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        KidnapScientists();
        break;
    case 2:
        std::cout << Text::GetText("level3", "killScientists") << std::endl;
        GameManager::Lose();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        Laboratory();
        break;
    }
}

void Level_3::KidnapScientists()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "kidnapScientists") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << Text::GetText("level3", "winCheap") << std::endl;
        GameManager::CompleteLevel1();
        break;
    case 2:
        std::cout << Text::GetText("level3", "winExpensive") << std::endl;
        GameManager::CompleteLevel1();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        KidnapScientists();
        break;
    }
}