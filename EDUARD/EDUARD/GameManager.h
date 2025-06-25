#pragma once
#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"
#include "Level_4.h"
#include "Level_5.h"
#include "Text.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


class Level_1;
class Level_2;
class Level_3;
class Level_4;
class Level_5;


class GameManager
{
public:
    static Shop shop;

    static Level_1 Level1;
    static Level_2 Level2;
    static Level_3 Level3;
    static Level_4 Level4;
    static Level_5 Level5;

    static void CompleteLevel1();
    static void CompleteLevel2();
    static void CompleteLevel3();
    static void CompleteLevel4();

    static void StartLevel1();
    static void StartLevel2();
    static void StartLevel3();
    static void StartLevel4();
    static void StartLevel5();
    static void Win();
    static void Lose();
};


