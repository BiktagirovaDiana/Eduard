#include "Level_3.h"
#include "Text.h"

void Level_3::startLevel()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "helloPablo3") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        meeting();
        break;
    case 2:
        noMeeting();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        startLevel();
        break;
    }
}

void Level_3::meeting()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "meeting") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        shooting();
        break;
    case 2:
        spy();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        meeting();
        break;
    }
}

void Level_3::noMeeting()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "refusal") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        meeting();
        break;
    case 2:
        std::cout << Text::GetText("level3", "loseRefusal") << std::endl;
        GameManager::lose();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        noMeeting();
        break;
    }
}

void Level_3::spy()
{
    if (PlayerController::getMoney() >= 700) {
        PlayerController::setMoney(PlayerController::getMoney() - 700);
        PlayerController::infoPlayer();
        int choice = 0;
        std::cout << Text::GetText("level3", "spy") << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            cleverSpy();
            break;
        case 2:
            std::cout << Text::GetText("level3", "stupidSpy") << std::endl;
            shop_.buyOrNot();
            shooting();
            break;
        default:
            std::cout << Text::GetText("common", "defaultButton") << std::endl;
            spy();
            break;
        }
    }
    else {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::lose();
    }
}

void Level_3::cleverSpy()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "cleverSpy") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        shooting();
        break;
    case 2:
        if (PlayerController::getGun() >= 6) {
            PlayerController::setGun(PlayerController::getGun() - 6);
            enemy_.takeDamage(1, 6);
            PlayerController::infoPlayer();
            std::cout << Text::GetText("level3", "cleverSpy2") << std::endl;
            laboratory();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        GameManager::lose();
        break;
    }
}

void Level_3::shooting()
{
    if (PlayerController::getMoney() >= 1200) {
        PlayerController::setMoney(PlayerController::getMoney() - 1200);
        PlayerController::infoPlayer();

        shop_.buyOrNot();

        int choice = 0;
        std::cout << Text::GetText("level3", "strategy3") << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            if (PlayerController::getGun() >= 6) {
                PlayerController::setGun(PlayerController::getGun() - 6);
                PlayerController::infoPlayer();
                enemy_.takeDamage(1, 6);
                laboratory();
            }
            else {
                std::cout << Text::GetText("common", "defaultButton") << std::endl;
                GameManager::lose();
            }
            break;
        case 2:
            if (PlayerController::getGrenade() >= 3) {
                PlayerController::setGrenade(PlayerController::getGrenade() - 3);
                enemy_.takeDamage(2, 3);
                PlayerController::infoPlayer();
                laboratory();
            }
            else {
                std::cout << Text::GetText("common", "beforeLose") << std::endl;
                GameManager::lose();
            }
            break;
        default:
            std::cout << Text::GetText("common", "defaultButton") << std::endl;
            shooting();
            break;
        }
    }
    else {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::lose();
    }
}

void Level_3::laboratory()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "laboratory") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        kidnapScientists();
        break;
    case 2:
        std::cout << Text::GetText("level3", "killScientists") << std::endl;
        GameManager::lose();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        laboratory();
        break;
    }
}

void Level_3::kidnapScientists()
{
    int choice = 0;
    std::cout << Text::GetText("level3", "kidnapScientists") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << Text::GetText("level3", "winCheap") << std::endl;
        GameManager::completeLevel1();
        break;
    case 2:
        std::cout << Text::GetText("level3", "winExpensive") << std::endl;
        GameManager::completeLevel1();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        kidnapScientists();
        break;
    }
}