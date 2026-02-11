#pragma once

// 게임의 전체 흐름 상태
enum class GameState
{
    BOOT,        // 게임 시작, 타이틀 또는 로딩
    PHONE_HOME, // 휴대폰 홈 화면
    CHAT_LIST,  // 채팅방 목록
    CHAT_ROOM,  // 개별 채팅방 진행
    ANALYSIS,   // 의심 포인트 분석
    RESULT,     // 결과 화면
    ENDING      // 엔딩 / 종료
};
