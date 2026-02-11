#pragma once
#include "raylib.h"
#include <string>

class Button
    {
        public:
            Button(Rectangle r, const std::string& t);

            // Draw 시 폰트를 전달
            bool Draw(const Font& font);

        private:
            Rectangle rect;
            std::string text;
    };
