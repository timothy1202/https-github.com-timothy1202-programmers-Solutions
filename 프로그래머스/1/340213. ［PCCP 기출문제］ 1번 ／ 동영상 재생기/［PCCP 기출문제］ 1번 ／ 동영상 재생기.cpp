#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 분:초 문자열을 초(second) 단위 정수로 바꾸는 함수 (split 대신 substr 사용)
int to_sec(string t) {
    // 01:23 이라면
    // t.substr(0, 2)는 앞의 "01" (분)
    // t.substr(3, 2)는 뒤의 "23" (초)
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int v_len = to_sec(video_len);
    int p = to_sec(pos);
    int s = to_sec(op_start);
    int e = to_sec(op_end);

    // 1. 시작하자마자 오프닝 구간 체크
    if (p >= s && p <= e) p = e;

    // 2. 명령어 처리
    for (string cmd : commands) {
        if (cmd == "prev") p = max(0, p - 10);
        else p = min(v_len, p + 10);
        
        // 이동할 때마다 오프닝 구간 체크
        if (p >= s && p <= e) p = e;
    }

    // 3. 결과 포맷팅 (다시 "mm:ss" 형태로 만들기)
    string mm = to_string(p / 60);
    string ss = to_string(p % 60);
    
    // 1자리수면 앞에 0 붙이기
    if (mm.length() < 2) mm = "0" + mm;
    if (ss.length() < 2) ss = "0" + ss;
    
    return mm + ":" + ss;
}