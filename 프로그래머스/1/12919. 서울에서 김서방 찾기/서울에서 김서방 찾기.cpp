#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    
    int a = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin(); //인덱스 확인        
    
    answer += to_string(a);
    answer += "에 있다";
    
    return answer;
}