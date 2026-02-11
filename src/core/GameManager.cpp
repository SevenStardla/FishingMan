#include <iostream>
#include "GameManager.h"
#include "raylib.h"
#include <vector>

void GameManager::Init()
    {
        // 한글 폰트 로드
        koreanFont = LoadFont("resources/fonts/static/NotoSansKR-Regular.ttf");
        SetTextureFilter(koreanFont.texture, TEXTURE_FILTER_BILINEAR);

        chatManager.LoadTestData();
        currentState = GameState::CHAT_LIST;
    }

void GameManager::ShowResult()
    {
    const auto& rooms = chatManager.GetRooms();

    std::cout << "\n=== 결과 ===\n";
    for (const auto& room : rooms)
            {
                std::cout << room.roomName << " : ";
                if (room.playerMarkedSuspicious == room.actualPhisher)
                    {
                        std::cout << "정답\n";
                    }
                else
                    {
                        std::cout << "오답\n";
                    }
            }
    }


void GameManager::Update()
    {
        switch (currentState)
        {
            case GameState::BOOT:       UpdateBoot(); break;
            case GameState::PHONE_HOME: UpdatePhoneHome(); break;
            case GameState::CHAT_LIST:  UpdateChatList(); break;
            case GameState::CHAT_ROOM:  UpdateChatRoom(); break;
            case GameState::ANALYSIS:   UpdateAnalysis(); break;
            case GameState::RESULT:     UpdateResult(); break;
            case GameState::ENDING:     break;
        }
    }


void GameManager::UpdateChatList()
    {
        auto& rooms = chatManager.GetRooms();

        for (int i = 0; i <rooms.size(); ++i)
            {
                if(IsKeyPressed(KEY_ONE + i))
                    {
                        chatManager.SetCurrentRoom(i);
                        currentState = GameState::CHAT_ROOM;
                    }
            }
    }

void GameManager::DrawChatRoom()

    {
        ChatRoom& room = chatManager.GetCurrentRoom();

        DrawTextEx(koreanFont, room.roomName.c_str(), {20, 20}, 22, 2, YELLOW);

        int y = 60;
        for (const Message& msg : room.messages)
        {
            if (msg.isSelected)
                DrawRectangle(15, y - 5, 770, 45, DARKGRAY);

            DrawTextEx(koreanFont, msg.sender.c_str(), {20, (float)y}, 16, 2, SKYBLUE);
            DrawTextEx(koreanFont, msg.text.c_str(), {40, (float)(y + 18)}, 18, 2, WHITE);

            y += 50;
        }
    }
void GameManager::DrawChatList()
    {
        DrawTextEx(koreanFont, "채팅 목록", {20, 20}, 24, 2, YELLOW);

        auto& rooms = chatManager.GetRooms();
        int y = 80;

        for (int i = 0; i < rooms.size(); ++i)
        {
            std::string line = std::to_string(i + 1) + ". " + rooms[i].roomName;
            DrawTextEx(koreanFont, line.c_str(), {40, (float)y}, 20, 2, WHITE);
            y += 40;
        }

        DrawTextEx(koreanFont, "숫자 키를 눌러 채팅방 선택", {20, 500}, 16, 2, GRAY);
    }
void GameManager::UpdateChatRoom()
    {
        ChatRoom& room = chatManager.GetCurrentRoom();

        Vector2 mouse = GetMousePosition();
        bool clicked = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

        int y = 60;

        for (auto& msg : room.messages)
            {
                Rectangle msgRect = {20.0f, (float)y, 760.0f, 40.0f};

                if (clicked && CheckCollisionPointRec(mouse, msgRect))
                    {
                        msg.isSelected = !msg.isSelected;
                    }
            }

        for (auto& msg : room.messages)
            {
                if (!msg.isSelected)
                    {
                        continue;
                    }
                if (IsKeyPressed(KEY_T))
                    {
                        msg.clues.push_back(SuspiciousType::TONE_MISMATCH);
                    }
            }
    }

void GameManager::Render()
    {
        switch (currentState)
        {
        case GameState::BOOT:
            DrawBoot();
            break;

        case GameState::PHONE_HOME:
            DrawPhoneHome();
            break;

        case GameState::CHAT_LIST:
            DrawChatList();
            break;

        case GameState::CHAT_ROOM:
            DrawChatRoom();
            break;

        case GameState::ANALYSIS:
            DrawAnalysis();
            break;

        case GameState::RESULT:
            DrawResult();
            break;

        case GameState::ENDING:
            DrawEnding();
            break;
        }
    }




// ------임시 구현 --------------
void GameManager::UpdateBoot() {}
void GameManager::UpdatePhoneHome() {}
void GameManager::UpdateAnalysis() {}
void GameManager::UpdateResult() {}
void GameManager::DrawBoot() {}
void GameManager::DrawPhoneHome() {}
void GameManager::DrawAnalysis() {}
void GameManager::DrawResult() {}
void GameManager::DrawEnding() {}
