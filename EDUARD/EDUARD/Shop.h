#pragma once
#include "PlayerController.h"
#include "Text.h"

class Shop
{
private:
    static int level_;
    static int priceGun_;
    static int priceCartridges_;
    static int priceGrenade_;
    static int priceRPG_;

public:
    static void InfoShop();
    static void ChoiceBuy();
    static void BuyOrNot();
    static void BuyCartridges();
    static void BuyGrenade();
    static void BuyRPG();
};