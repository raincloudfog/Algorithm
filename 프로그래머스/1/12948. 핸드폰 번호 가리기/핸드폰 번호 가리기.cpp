#include <string>
#include <vector>

using namespace std;

//길이 찾기
// 자리수 나누기


string replace(string st) {

    size_t length = st.length();

    string lastword = st.substr(length - 4, 4);

    string newword = "";

    for (int i = 0;i < length - 4; i++)
    {
        newword += "*";
    }

    newword += lastword;
    return newword;
}


string solution(string phone_number) {
    string answer = replace(phone_number);
    return answer;
}