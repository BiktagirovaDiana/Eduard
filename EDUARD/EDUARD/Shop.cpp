#include "Shop.h"
#include <Windows.h>

int Shop::Level = 1;
int Shop::PriceGun = 800;
int Shop::PriceCartridges = 500;
int Shop::PriceGrenade = 1500;
int Shop::PriceRPG = 2000;

void Shop::InfoShop()
{
    std::cout << Text::GetText("shop", "shopTitle") << std::endl;

    // Патроны
    std::cout << Text::GetText("shop", "cartridgesTitle") << std::endl;
    printf((Text::GetText("shop", "cartridgesPrice") + "\n").c_str(), PriceCartridges);

    // Гранаты
    if (Level >= 2) {
        std::cout << Text::GetText("shop", "grenadesAvailable") << std::endl;
        std::cout << Text::GetText("shop", "grenadesCount") << std::endl;
        printf((Text::GetText("shop", "grenadesPrice") + "\n").c_str(), PriceGrenade);
    }
    else {
        std::cout << Text::GetText("shop", "grenadesLocked") << std::endl;
    }

    // РПГ
    if (Level >= 4) {
        std::cout << Text::GetText("shop", "rpgAvailable") << std::endl;
        std::cout << Text::GetText("shop", "rpgCount") << std::endl;
        printf((Text::GetText("shop", "rpgPrice") + "\n").c_str(), PriceRPG);
    }
    else {
        std::cout << Text::GetText("shop", "rpgLocked") << std::endl;
    }
}

void Shop::ChoiceBuy()
{
    std::cout << Text::GetText("shop", "buyPrompt") << std::endl;
    std::cout << Text::GetText("shop", "buyOption1") << std::endl;
    std::cout << Text::GetText("shop", "buyOption2") << std::endl;
    std::cout << Text::GetText("shop", "buyOption3") << std::endl;

    int choice = 0;
    std::cin >> choice;

    switch (choice) {
    case 1: BuyCartridges(); break;
    case 2: BuyGrenade(); break;
    case 3: BuyRPG(); break;
    default: ChoiceBuy(); break;
    }
}

void Shop::BuyOrNot()
{
    std::cout << Text::GetText("shop", "buyWeaponPrompt") << std::endl;
    std::cout << Text::GetText("shop", "buyOptionNo") << std::endl;
    std::cout << Text::GetText("shop", "buyOptionYes") << std::endl;

    int choice = 0;
    std::cin >> choice;

    switch (choice) {
    case 1: break;
    case 2: InfoShop(); ChoiceBuy(); break;
    default: BuyOrNot(); break;
    }
}

void Shop::BuyCartridges()
{
    if (PlayerController::getMoney() >= PriceCartridges) {
        PlayerController::setMoney(PlayerController::getMoney() - PriceCartridges);
        PlayerController::setGun(PlayerController::getGun() + 8);
        std::cout << Text::GetText("shop", "cartridgesBought") << std::endl;
    }
    else {
        std::cout << Text::GetText("shop", "notEnoughMoney") << std::endl;
    }
}

void Shop::BuyGrenade()
{
    if (Level >= 2) {
        if (PlayerController::getMoney() >= PriceGrenade) {
            PlayerController::setMoney(PlayerController::getMoney() - PriceGrenade);
            PlayerController::setGrenade(PlayerController::getGrenade() + 4);
            std::cout << Text::GetText("shop", "grenadesBought") << std::endl;
        }
        else {
            std::cout << Text::GetText("shop", "notEnoughMoney") << std::endl;
        }
    }
}

void Shop::BuyRPG()
{
    if (Level >= 4) {
        if (PlayerController::getMoney() >= PriceRPG) {
            PlayerController::setMoney(PlayerController::getMoney() - PriceRPG);
            PlayerController::setRPG(PlayerController::getRPG() + 3);
            std::cout << Text::GetText("shop", "rpgBought") << std::endl;
        }
        else {
            std::cout << Text::GetText("shop", "notEnoughMoney") << std::endl;
        }
    }
}
