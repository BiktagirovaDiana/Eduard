#include "Level_5.h"
#include "GameManager.h"
#include "Shop.h"

void Level_5::startLevel()
{
    int choice = 0;
    PlayerController::infoPlayer();
    std::cout << Text::GetText("level5", "helloPablo5") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        meeting();
        break;
    case 2:
        attackChapo();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        startLevel();
        break;
    }
}

void Level_5::meeting()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "meeting") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        GameManager::lose();
        break;
    case 2:
        attackChapo();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        meeting();
        break;
    }
}

void Level_5::attackChapo()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "attackChapo") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        Friend();
        break;
    case 2:
        trap();
        break;
    case 3:
        attackPlane();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        attackChapo();
        break;
    }
}

void Level_5::Friend()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "friend") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        attackPlane();
        break;
    case 2:
        attackPlane();
        break;
    case 3:
        attackChapo();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        Friend();
        break;
    }
}

void Level_5::trap()
{
    std::cout << Text::GetText("level5", "trap") << std::endl;
    attackChapo();
}

void Level_5::attackPlane()
{
    if (PlayerController::getMoney() < 1500) {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::lose();
        return;
    }

    int choice = 0;
    std::cout << Text::GetText("level5", "attackPlane") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        PlayerController::setMoney(0);
        attackPlane2();
        break;
    case 2:
        PlayerController::setMoney(PlayerController::getMoney() - 1500);
        attackPlane2();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        attackPlane();
        break;
    }
}

void Level_5::attackPlane2()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "attackPlane2") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        trapStrategy();
        break;
    case 2:

        // ?????????????? ?????? ??? case 2
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        attackPlane2();
        break;
    }
}

void Level_5::trapStrategy()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "trapStrategy") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        trapMargo();
        break;
    case 2:
        attackStrategy();
        break;
    case 3:
        surveillance();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        trapStrategy();
        break;
    }
}

void Level_5::trapMargo()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "trapMargo") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        deathMargo();
        break;
    case 2:
        shop_.buyOrNot();
        attackStrategy();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        trapMargo();
        break;
    }
}

void Level_5::deathMargo()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "deathMargo") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getRPG() >= 5)
        {
            PlayerController::setRPG(PlayerController::getRPG() - 5);
            enemy_.takeDamage(3, 5);
            std::cout << Text::GetText("level5", "winSad") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 2:
        if (PlayerController::getGrenade() >= 10)
        {
            PlayerController::setGrenade(PlayerController::getGrenade() - 10);
            enemy_.takeDamage(2, 10);
            std::cout << Text::GetText("level5", "winSad") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 3:
        if (PlayerController::getGun() >= 20)
        {
            PlayerController::setGun(PlayerController::getGun() - 20);
            enemy_.takeDamage(1, 20);
            std::cout << Text::GetText("level5", "winSad") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        deathMargo();
        break;
    }
}

void Level_5::surveillance()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "surveillance") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getRPG() >= 5)
        {
            PlayerController::setRPG(PlayerController::getRPG() - 5);
            enemy_.takeDamage(3, 5);
            std::cout << Text::GetText("level5", "winShort") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 2:
        if (PlayerController::getGrenade() >= 10)
        {
            PlayerController::setGrenade(PlayerController::getGrenade() - 10);
            enemy_.takeDamage(2, 10);
            std::cout << Text::GetText("level5", "winShort") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 3:
        if (PlayerController::getGun() >= 20)
        {
            PlayerController::setGun(PlayerController::getGun() - 20);
            enemy_.takeDamage(1, 20);
            std::cout << Text::GetText("level5", "winShort") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        surveillance();
        break;
    }
}

void Level_5::attackStrategy()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "attackStrategy") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        attackStrategy2();
        break;
    case 2:
        attackStrategy2();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        attackStrategy();
        break;
    }
}

void Level_5::attackStrategy2()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "attackStrategy2") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        attackStrategy3();
        break;
    case 2:
        attackStrategy3();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        attackStrategy2();
        break;
    }
}

void Level_5::attackStrategy3()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "attackStrategy3") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        ifDefense();
        break;
    case 2:
        std::cout << Text::GetText("level5", "ifAttack") << std::endl;
        howContinue();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        attackStrategy3();
        break;
    }
}

void Level_5::ifDefense()
{
    if (PlayerController::getGun() >= 4) {
        std::cout << Text::GetText("level5", "ifDefense") << std::endl;
        PlayerController::setGun(PlayerController::getGun() - 4);
        PlayerController::setHP(PlayerController::getHP() - 20);
        enemy_.takeDamage(1, 4);
        howContinue();
    }
    else {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::lose();
    }
}

void Level_5::howContinue()
{
    if (PlayerController::getHP() > 0) {
        int choice = 0;
        std::cout << Text::GetText("level5", "howContinue") << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            if (PlayerController::getGun() >= 8) {
                PlayerController::setGun(PlayerController::getGun() - 8);
                PlayerController::setHP(PlayerController::getHP() - 20);
                enemy_.takeDamage(1, 8);
                std::cout << Text::GetText("level5", "ifPatrons") << std::endl;
                GameManager::lose();
            }
            else {
                std::cout << Text::GetText("level5", "poorPreparation") << std::endl;
                GameManager::lose();
            }
            break;
        case 2:
            if (PlayerController::getRPG() >= 2) {
                PlayerController::setRPG(PlayerController::getRPG() - 2);
                PlayerController::setHP(PlayerController::getHP() - 20);
                enemy_.takeDamage(3, 2);
                rpgOrGrenade();
            }
            else {
                std::cout << Text::GetText("level5", "poorPreparation") << std::endl;
                GameManager::lose();
            }
            break;
        case 3:
            if (PlayerController::getGrenade() >= 4) {
                PlayerController::setGrenade(PlayerController::getGrenade() - 4);
                PlayerController::setHP(PlayerController::getHP() - 20);
                enemy_.takeDamage(2, 4);
                rpgOrGrenade();
            }
            else {
                std::cout << Text::GetText("level5", "poorPreparation") << std::endl;
                GameManager::lose();
            }
            break;
        default:
            std::cout << Text::GetText("common", "defaultButton") << std::endl;
            howContinue();
            break;
        }
    }
    else
    {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::lose();
    }
}

void Level_5::rpgOrGrenade()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "rpgOrGrenade") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getGun() >= 3) {
            PlayerController::setGun(PlayerController::getGun() - 3);
            enemy_.takeDamage(1, 3);
            std::cout << Text::GetText("level5", "noRPG") << std::endl;
            GameManager::lose();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 2:
        if (PlayerController::getGrenade() >= 3) {
            PlayerController::setGrenade(PlayerController::getGrenade() - 3);
            enemy_.takeDamage(2, 3);
            std::cout << Text::GetText("level5", "noRPG") << std::endl;
            GameManager::lose();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    case 3:
        if (PlayerController::getRPG() >= 2) {
            PlayerController::setRPG(PlayerController::getRPG() - 2);
            enemy_.takeDamage(3, 2);
            PlayerController::setInfluence(PlayerController::getInfluence() + 100);
            PlayerController::setMoney(PlayerController::getMoney() + 1000);
            PlayerController::setHP(100);
            std::cout << Text::GetText("level5", "winFinal") << std::endl;
            GameManager::win();
        }
        else {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        rpgOrGrenade();
        break;
    }
}
