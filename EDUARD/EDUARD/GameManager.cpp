#include "GameManager.h"

Shop GameManager::shop;
Level_1 GameManager::Level1(GameManager::shop);
Level_2 GameManager::Level2(GameManager::shop);
Level_3 GameManager::Level3(GameManager::shop);
Level_4 GameManager::Level4(GameManager::shop);
Level_5 GameManager::Level5(GameManager::shop);

void GameManager::StartLevel1() {
    Level1.StartLevel();
}

void GameManager::StartLevel2() {
    Level2.StartLevel();
}

void GameManager::StartLevel3() {
    Level3.StartLevel();
}

void GameManager::StartLevel4() {
    Level4.StartLevel();
}

void GameManager::StartLevel5() {
    Level5.StartLevel();
}

void GameManager::Win() {
    std::cout << "Ты победил :D" << std::endl;
}

void GameManager::Lose() {
    std::cout << "Ты проиграл" << std::endl;
}

void GameManager::CompleteLevel1() {
    StartLevel2();
}

void GameManager::CompleteLevel2() {
    StartLevel3();
}

void GameManager::CompleteLevel3() {
    StartLevel4();
}

void GameManager::CompleteLevel4() {
    StartLevel5();
}
