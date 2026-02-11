#pragma once
#include <string>
#include <vector>
#include "Message.h"

struct ChatRoom
    {
        std::string roomName; // 채팅방 이름
        std::vector<Message> messages; // 메세지 목록

        bool playerMarkedSuspicious = false; // 플레이어 판단
        bool actualPhisher = false; // 이 방에 피싱범 존재 여부
    };

// playerMarkedSuspicious 플레이어 선택 기록
// actualPhiser 정답 데이터


