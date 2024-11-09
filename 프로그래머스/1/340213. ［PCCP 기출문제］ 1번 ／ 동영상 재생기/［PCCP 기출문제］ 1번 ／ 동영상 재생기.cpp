#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// "mm:ss" 형식의 문자열을 분과 초로 변환하는 함수
pair<int, int> parseTime(const string& timeStr) {
    int minutes, seconds;
    char colon; 
    istringstream ss(timeStr);
    ss >> minutes >> colon >> seconds;
    return {minutes, seconds}; // 분과 초를 pair로 반환
}

// 분과 초를 "mm:ss" 형식의 문자열로 변환하는 함수
string formatTime(int minutes, int seconds) {
    ostringstream oss;
    oss << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds;
    return oss.str();
}

// 주어진 분과 초에 n초를 더하거나 빼는 함수
pair<int, int> adjustTime(int minutes, int seconds, int adjustBy) {
    seconds += adjustBy;
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    } else if (seconds < 0) {
        minutes -= (abs(seconds) / 60) + 1;
        seconds = 60 + (seconds % 60);
    }
    return {minutes, seconds};
}

// 두 시간을 비교하는 함수
bool isWithinRange(pair<int, int> currentTime, pair<int, int> startTime, pair<int, int> endTime) {
    if (currentTime.first > startTime.first || 
       (currentTime.first == startTime.first && currentTime.second >= startTime.second)) {
        if (currentTime.first < endTime.first || 
           (currentTime.first == endTime.first && currentTime.second <= endTime.second)) {
            return true;
        }
    }
    return false;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    // 비디오 길이와 현재 위치, 오프닝 구간을 시간으로 변환
    pair<int, int> videoTime = parseTime(video_len);
    pair<int, int> currentTime = parseTime(pos);
    pair<int, int> opStartTime = parseTime(op_start);
    pair<int, int> opEndTime = parseTime(op_end);

    // 오프닝 구간에 있으면 바로 오프닝 끝으로 이동
    if (isWithinRange(currentTime, opStartTime, opEndTime)) {
        currentTime = opEndTime;
    }

    // 명령어 처리
    for (int i = 0; i < commands.size(); i++) {
        string currentCommand = commands[i];

        if (currentCommand == "next") {
            // 10초 후로 이동
            currentTime = adjustTime(currentTime.first, currentTime.second, 10);
            // 영상의 마지막 위치를 넘지 않도록 제한
            if (currentTime.first > videoTime.first || 
                (currentTime.first == videoTime.first && currentTime.second > videoTime.second)) {
                currentTime = videoTime;
            }
        } 
        else if (currentCommand == "prev") {
            // 10초 전으로 이동
            currentTime = adjustTime(currentTime.first, currentTime.second, -10);
            // 영상의 처음 위치를 넘지 않도록 제한
            if (currentTime.first < 0) {
                currentTime = {0, 0};
            }
        }

        // 명령 실행 후 다시 오프닝 구간에 있으면 오프닝 끝으로 이동
        if (isWithinRange(currentTime, opStartTime, opEndTime)) {
            currentTime = opEndTime;
        }
    }

    // 최종 위치를 "mm:ss" 형식으로 변환하여 반환
    return formatTime(currentTime.first, currentTime.second);
}
