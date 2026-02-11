#include "ChatManager.h"
#include "../data/ChatData.h"


void ChatManager::LoadTestData()
    {
        chatRooms = ChatData::CreateTestScenario();
    }

ChatRoom& ChatManager::GetCurrentRoom()
    {
        return chatRooms[currentRoomIndex];
    }

std::vector<ChatRoom>& ChatManager::GetRooms()
    {
        return chatRooms;
    }

void ChatManager::SetCurrentRoom(int index)
    {
        if (index >= 0 && index < (int)chatRooms.size())
        {
            currentRoomIndex = index;
        }
    }

int ChatManager::GetCurrentRoomIndex() const
    {
        return currentRoomIndex;
    }

int ChatManager::GetRoomCount() const
    {
        return static_cast<int>(chatRooms.size());
    }