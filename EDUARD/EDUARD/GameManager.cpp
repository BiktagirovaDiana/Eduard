#include "GameManager.h"

Shop GameManager::shop;
Level_1 GameManager::level1(GameManager::shop);
Level_2 GameManager::level2(GameManager::shop);
Level_3 GameManager::level3(GameManager::shop);
Level_4 GameManager::level4(GameManager::shop);
Level_5 GameManager::level5(GameManager::shop);

void GameManager::startLevel1() {
    level1.startLevel();
}

void GameManager::startLevel2() {
    level2.startLevel();
}

void GameManager::startLevel3() {
    level3.startLevel();
}

void GameManager::startLevel4() {
    level4.StartLevel();
}

void GameManager::startLevel5() {
    level5.startLevel();
}

void GameManager::win() {
    std::cout << "Ты победил :D" << std::endl;
}

void GameManager::lose() {
    std::cout << "Ты проиграл" << std::endl;
}

void GameManager::completeLevel1() {
    startLevel2();
}

void GameManager::completeLevel2() {
    startLevel3();
}

void GameManager::completeLevel3() {
    startLevel4();
}

void GameManager::completeLevel4() {
    startLevel5();
}
