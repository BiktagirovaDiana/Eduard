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

    static Level_1 level1;
    static Level_2 level2;
    static Level_3 level3;
    static Level_4 level4;
    static Level_5 level5;

    static void completeLevel1();
    static void completeLevel2();
    static void completeLevel3();
    static void completeLevel4();

    static void startLevel1();
    static void startLevel2();
    static void startLevel3();
    static void startLevel4();
    static void startLevel5();
    static void win();
    static void lose();
};


