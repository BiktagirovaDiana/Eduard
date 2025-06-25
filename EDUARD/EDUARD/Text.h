#pragma once
#include <nlohmann/json.hpp>
#include <string>

class Text {
public:
    static void LoadTexts(const std::string& filePath);
    static std::string GetText(const std::string& level, const std::string& key);

private:
    static nlohmann::json texts;
};
