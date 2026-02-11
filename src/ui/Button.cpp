#include "Button.h"

Button::Button(Rectangle r, const std::string& t) : rect(r), text(t) {}

bool Button::Draw(const Font& font)
    {
        Vector2 mouse = GetMousePosition();
        bool hovered = CheckCollisionPointRec(mouse, rect);
        bool clicked = hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        // 버튼 배경
        DrawRectangleRec(rect, hovered ? DARKGRAY : GRAY);

        // 테두리
        DrawRectangleLinesEx(rect, 2, BLACK);

        // 텍스트 중앙 정렬
        int fontSize = 20;
        Vector2 textSize = MeasureTextEx(font, text.c_str(), fontSize, 2);
        DrawTextEx(font, text.c_str(),
                {rect.x + (rect.width - textSize.x) / 2.0f, rect.y + (rect.height - textSize.y) / 2.0f},
                fontSize, 2, WHITE);

        return clicked;
    }

