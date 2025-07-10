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
    static void InfoPlayer();

    // Getters
    static int GetInfluence();
    static int GetHP();
    static int GetMoney();
    static int GetGun();
    static int GetGrenade();
    static int GetRPG();

    // Setters
    static int SetInfluence(int x);
    static int SetHP(int x);
    static int SetMoney(int x);
    static int SetGun(int x);
    static int SetGrenade(int x);
    static int SetRPG(int x);
};

