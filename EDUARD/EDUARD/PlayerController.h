#pragma once
#include "GameManager.h"
#include "Text.h"

class PlayerController
{
private:
    static int influence_;
    static int hp_;
    static int money_;
    static int gun_;
    static int grenade_;
    static int rpg_;

public:
    static void infoPlayer();

    // Getters
    static int getInfluence();
    static int getHP();
    static int getMoney();
    static int getGun();
    static int getGrenade();
    static int getRPG();

    // Setters
    static int setInfluence(int x);
    static int setHP(int x);
    static int setMoney(int x);
    static int setGun(int x);
    static int setGrenade(int x);
    static int setRPG(int x);
};

