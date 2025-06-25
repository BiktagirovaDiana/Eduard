#include "Level_5.h"
#include "GameManager.h"
#include "Shop.h"

void Level_5::StartLevel()
{
    int choice = 0;
    PlayerController::InfoPlayer();
    std::cout << Text::GetText("level5", "helloPablo5") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        Meeting();
        break;
    case 2:
        AttackChapo();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        StartLevel();
        break;
    }
}

void Level_5::Meeting()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "meeting") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        GameManager::Lose();
        break;
    case 2:
        AttackChapo();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        Meeting();
        break;
    }
}

void Level_5::AttackChapo()
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
        Trap();
        break;
    case 3:
        AttackPlane();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        AttackChapo();
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
    case 2:
        AttackPlane();
        break;
    case 3:
        AttackChapo();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        Friend();
        break;
    }
}

void Level_5::Trap()
{
    std::cout << Text::GetText("level5", "trap") << std::endl;
    AttackChapo();
}

void Level_5::AttackPlane()
{
    if (PlayerController::getMoney() < 1500)
    {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::Lose();
        return;
    }

    int choice = 0;
    std::cout << Text::GetText("level5", "attackPlane") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        PlayerController::setMoney(0);
        AttackPlane2();
        break;
    case 2:
        PlayerController::setMoney(PlayerController::getMoney() - 1500);
        AttackPlane2();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        AttackPlane();
        break;
    }
}

void Level_5::AttackPlane2()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "attackPlane2") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        TrapStrategy();
        break;
    case 2:
        // ?????????????? ?????? ??? case 2
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        AttackPlane2();
        break;
    }
}

void Level_5::TrapStrategy()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "trapStrategy") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        TrapMargo();
        break;
    case 2:
        // ??????????? ?? ??????????? ??????????
        break;
    case 3:
        Surveillance();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        TrapStrategy();
        break;
    }
}

void Level_5::TrapMargo()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "trapMargo") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        DeathMargo();
        break;
    case 2:
        shop.BuyOrNot();
        AttackStrategy();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        TrapMargo();
        break;
    }
}

void Level_5::DeathMargo()
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
            enemy.takeDamage(3, 5);
            std::cout << Text::GetText("level5", "winSad") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        if (PlayerController::getGrenade() >= 10)
        {
            PlayerController::setGrenade(PlayerController::getGrenade() - 10);
            enemy.takeDamage(2, 10);
            std::cout << Text::GetText("level5", "winSad") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 3:
        if (PlayerController::getGun() >= 20)
        {
            PlayerController::setGun(PlayerController::getGun() - 20);
            enemy.takeDamage(1, 20);
            std::cout << Text::GetText("level5", "winSad") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        DeathMargo();
        break;
    }
}

void Level_5::Surveillance()
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
            enemy.takeDamage(3, 5);
            std::cout << Text::GetText("level5", "winShort") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        if (PlayerController::getGrenade() >= 10)
        {
            PlayerController::setGrenade(PlayerController::getGrenade() - 10);
            enemy.takeDamage(2, 10);
            std::cout << Text::GetText("level5", "winShort") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 3:
        if (PlayerController::getGun() >= 20)
        {
            PlayerController::setGun(PlayerController::getGun() - 20);
            enemy.takeDamage(1, 20);
            std::cout << Text::GetText("level5", "winShort") << std::endl;
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        Surveillance();
        break;
    }
}

void Level_5::AttackStrategy()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "attackStrategy") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    case 2:
        AttackStrategy2();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        AttackStrategy();
        break;
    }
}

void Level_5::AttackStrategy2()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "attackStrategy2") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    case 2:
        AttackStrategy3();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        AttackStrategy2();
        break;
    }
}

void Level_5::AttackStrategy3()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "attackStrategy3") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        IfDefense();
        break;
    case 2:
        std::cout << Text::GetText("level5", "ifAttack") << std::endl;
        HowContinue();
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        AttackStrategy3();
        break;
    }
}

void Level_5::IfDefense()
{
    if (PlayerController::getGun() >= 4)
    {
        std::cout << Text::GetText("level5", "ifDefense") << std::endl;
        PlayerController::setGun(PlayerController::getGun() - 4);
        PlayerController::setHP(PlayerController::getHP() - 20);
        enemy.takeDamage(1, 4);
        HowContinue();
    }
    else
    {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::Lose();
    }
}

void Level_5::HowContinue()
{
    if (PlayerController::getHP() > 0)
    {
        int choice = 0;
        std::cout << Text::GetText("level5", "howContinue") << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            if (PlayerController::getGun() >= 8)
            {
                PlayerController::setGun(PlayerController::getGun() - 8);
                PlayerController::setHP(PlayerController::getHP() - 20);
                enemy.takeDamage(1, 8);
                std::cout << Text::GetText("level5", "ifPatrons") << std::endl;
                GameManager::Lose();
            }
            else
            {
                std::cout << Text::GetText("level5", "poorPreparation") << std::endl;
                GameManager::Lose();
            }
            break;
        case 2:
            if (PlayerController::getRPG() >= 2)
            {
                PlayerController::setRPG(PlayerController::getRPG() - 2);
                PlayerController::setHP(PlayerController::getHP() - 20);
                enemy.takeDamage(3, 2);
                RPGorGrenade();
            }
            else
            {
                std::cout << Text::GetText("level5", "poorPreparation") << std::endl;
                GameManager::Lose();
            }
            break;
        case 3:
            if (PlayerController::getGrenade() >= 4)
            {
                PlayerController::setGrenade(PlayerController::getGrenade() - 4);
                PlayerController::setHP(PlayerController::getHP() - 20);
                enemy.takeDamage(2, 4);
                RPGorGrenade();
            }
            else
            {
                std::cout << Text::GetText("level5", "poorPreparation") << std::endl;
                GameManager::Lose();
            }
            break;
        default:
            std::cout << Text::GetText("common", "defaultButton") << std::endl;
            HowContinue();
            break;
        }
    }
    else
    {
        std::cout << Text::GetText("common", "beforeLose") << std::endl;
        GameManager::Lose();
    }
}

void Level_5::RPGorGrenade()
{
    int choice = 0;
    std::cout << Text::GetText("level5", "rpgOrGrenade") << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (PlayerController::getGun() >= 3)
        {
            PlayerController::setGun(PlayerController::getGun() - 3);
            enemy.takeDamage(1, 3);
            std::cout << Text::GetText("level5", "noRPG") << std::endl;
            GameManager::Lose();
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 2:
        if (PlayerController::getGrenade() >= 3)
        {
            PlayerController::setGrenade(PlayerController::getGrenade() - 3);
            enemy.takeDamage(2, 3);
            std::cout << Text::GetText("level5", "noRPG") << std::endl;
            GameManager::Lose();
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    case 3:
        if (PlayerController::getRPG() >= 2)
        {
            PlayerController::setRPG(PlayerController::getRPG() - 2);
            enemy.takeDamage(3, 2);
            PlayerController::setInfluence(PlayerController::getInfluence() + 100);
            PlayerController::setMoney(PlayerController::getMoney() + 1000);
            PlayerController::setHP(100);
            std::cout << Text::GetText("level5", "winFinal") << std::endl;
            GameManager::Win();
        }
        else
        {
            std::cout << Text::GetText("common", "beforeLose") << std::endl;
            GameManager::Lose();
        }
        break;
    default:
        std::cout << Text::GetText("common", "defaultButton") << std::endl;
        RPGorGrenade();
        break;
    }
}
