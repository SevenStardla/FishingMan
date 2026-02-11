#pragma once
#include <vector>
#include "ChatRoom.h"

class ChatManager
    {
        public:
            int GetCurrentRoomIndex() const;
            int GetRoomCount() const;
            ChatRoom& GetCurrentRoom();
            std::vector<ChatRoom>& GetRooms();
            void SetCurrentRoom(int index);
            void LoadTestData();

        private:
            std::vector<ChatRoom> chatRooms;
            int currentRoomIndex = 0;
    };