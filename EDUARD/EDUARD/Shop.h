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
    static void infoShop();
    static void choiceBuy();
    static void buyOrNot();
    static void buyCartridges();
    static void buyGrenade();
    static void buyRPG();
};