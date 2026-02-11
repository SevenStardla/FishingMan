#pragma once
#include <string>
#include <vector>

enum class SuspiciousType
    {
        None,
        TONE_MISMATCH, // 말투 불일치
        RELATION_ERROR, // 관계 오류
        TIME_INCONSISTENT, // 시간 불일치
        LINK_INDUCEMENT, // 링크 유도
        OVER_URGENT// 과도한 긴급성
    };

struct Message
    {
        std::string sender; // 보낸 사람
        std::string text; // 메세지 내용

        bool isFromFisher; // 정답 판정용 (플레이어는 모름)
        std::vector<SuspiciousType> clues; // 단서 목록

        bool isSelected = false; // 플레이어가 메세지를 클릭했는지
    };