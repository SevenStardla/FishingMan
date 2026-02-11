#pragma once
#include "../chat/ChatManager.h"
#include "GameState.h"
#include "raylib.h"

class GameManager
{
public:
    void Init();
    void Update();
    void Render();
    void ShowResult();

private:
    ChatManager chatManager;
    GameState currentState = GameState::BOOT;
    Font koreanFont; // 한글 폰트 추가

    // Update
    void UpdateBoot();
    void UpdatePhoneHome();
    void UpdateChatList();
    void UpdateChatRoom();
    void UpdateAnalysis();
    void UpdateResult();

    // Render
    void DrawBoot();
    void DrawPhoneHome();
    void DrawChatList();
    void DrawChatRoom();
    void DrawAnalysis();
    void DrawResult();
    void DrawEnding();
};

