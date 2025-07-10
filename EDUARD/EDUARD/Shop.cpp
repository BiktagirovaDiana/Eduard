#include "Shop.h"
#include <Windows.h>

int Shop::level_ = 1;
int Shop::priceGun_ = 800;
int Shop::priceCartridges_ = 500;
int Shop::priceGrenade_ = 1500;
int Shop::priceRPG_ = 2000;

void Shop::InfoShop()
{
    std::cout << Text::GetText("shop", "shopTitle") << std::endl;

    // Патроны
    std::cout << Text::GetText("shop", "cartridgesTitle") << std::endl;
    printf((Text::GetText("shop", "cartridgesPrice") + "\n").c_str(), priceCartridges_);

    // Гранаты
    if (level_ >= 2) {
        std::cout << Text::GetText("shop", "grenadesAvailable") << std::endl;
        std::cout << Text::GetText("shop", "grenadesCount") << std::endl;
        printf((Text::GetText("shop", "grenadesPrice") + "\n").c_str(), priceGrenade_);
    }
    else {
        std::cout << Text::GetText("shop", "grenadesLocked") << std::endl;
    }

    // РПГ
    if (level_ >= 4) {
        std::cout << Text::GetText("shop", "rpgAvailable") << std::endl;
        std::cout << Text::GetText("shop", "rpgCount") << std::endl;
        printf((Text::GetText("shop", "rpgPrice") + "\n").c_str(), priceRPG_);
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
    if (PlayerController::getMoney() >= priceCartridges_) {
        PlayerController::setMoney(PlayerController::getMoney() - priceCartridges_);
        PlayerController::setGun(PlayerController::getGun() + 8);
        std::cout << Text::GetText("shop", "cartridgesBought") << std::endl;
    }
    else {
        std::cout << Text::GetText("shop", "notEnoughMoney") << std::endl;
    }
}

void Shop::BuyGrenade()
{
    if (level_ >= 2) {
        if (PlayerController::getMoney() >= priceGrenade_) {
            PlayerController::setMoney(PlayerController::getMoney() - priceGrenade_);
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
    if (level_ >= 4) {
        if (PlayerController::getMoney() >= priceRPG_) {
            PlayerController::setMoney(PlayerController::getMoney() - priceRPG_);
            PlayerController::setRPG(PlayerController::getRPG() + 3);
            std::cout << Text::GetText("shop", "rpgBought") << std::endl;
        }
        else {
            std::cout << Text::GetText("shop", "notEnoughMoney") << std::endl;
        }
    }
}
