#pragma once
#include "PlayerController.h"
#include "Text.h"

class Shop
{
private:
    static int Level;
    static int PriceGun;
    static int PriceCartridges;
    static int PriceGrenade;
    static int PriceRPG;

public:
    static void InfoShop();
    static void ChoiceBuy();
    static void BuyOrNot();
    static void BuyCartridges();
    static void BuyGrenade();
    static void BuyRPG();
};