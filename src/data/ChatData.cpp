#include "ChatData.h"

std::vector<ChatRoom> ChatData::CreateTestScenario()
    {
        std::vector<ChatRoom> rooms;

        // 가족 채팅방
        ChatRoom family;
        family.roomName = "엄마";
        family.actualPhisher = false;

        family.messages.push_back({
            "엄마",
            "현준아 밥은 먹었니?",
        });


        family.messages.push_back({
            "엄마",
            "요즘 왜 연락이 없니 걱정된다.",
        });

        rooms.push_back(family);

        // -----------------------------
        // 2️⃣ 친구 채팅방 (피싱범 포함)
        // -----------------------------
        ChatRoom friendRoom;
        friendRoom.roomName = "민수";
        friendRoom.actualPhisher = true; // 🔥 정답

        friendRoom.messages.push_back({
            "민수",
            "야 너 사고 났다며 괜찮아?"
        });

        friendRoom.messages.push_back({
            "민수",
            "이거 네 보험 관련 서류래 빨리 확인해봐 http://fake-link.kr"
        });

        friendRoom.messages.push_back({
            "민수",
            "지금 당장 확인 안 하면 큰일 난다"
        });

        rooms.push_back(friendRoom);

        return rooms;
    }