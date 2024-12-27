#include <string>
#include <vector>

using namespace std;

//먼저 글자의 갯수 찾고
// 홀수면 -1하고  /= 2 해주고  +1 해주면 그위 찾을수 있을 것 같음
// 짝수면 /= 2 해주고 그 값에서 +1 만큼 글자 찾기

string findst(string s){
    
    auto stsize = s.length();
    int stsize_even_number = 1;
    
    //짝수면
    if(stsize %2 == 0)
    {
        stsize /= 2;
        stsize_even_number = 2;
}
    else{
        //홀수 일 경우
        stsize -= 1 ;
        stsize /= 2 ;         
        stsize += 1;
 }
    //인덱스 가 0부터 시작하니 -1해주기
    string A = s.substr(stsize-1, stsize_even_number);
    
    return A;
    
}


string solution(string s) {
    string answer = findst(s);
    return answer;
}