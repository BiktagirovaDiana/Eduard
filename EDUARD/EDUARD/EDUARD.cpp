#include "Text.h"
#include "GameManager.h"
#include <windows.h>

int main() {
    // Установка кодировки консоли на UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Загрузка текстов из JSON
    Text::LoadTexts("texts.json");

    GameManager::StartLevel1();
    return 0;
}