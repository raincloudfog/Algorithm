#include <string>
#include <vector>
#include <sstream>

using namespace std;

//문제 잘못이해함 ""까지 포함된 글자였음. 
//알파벳 26자 가아닌 공백으로 단어를나누고 거기서 인덱스 필요
//공백을 제거하지말아야될듯하다 오류가 ..

string solution(string s) {
    string answer = "";

    vector<string> textV;

    // 글자 나눈걸 담을 그릇
    // stringstream ss(s);
    // string word;


    int textlength = 0;
    int currentindex = 0;

    for (char c : s)
    {
        //알파벳 이니까
        if (isalpha(c)) {
            if (currentindex % 2 == 0)
            {
                answer += toupper(c);
            }
            else{
                answer += tolower(c);
            }

            currentindex++;
        }
        else{
            //공백 
            answer += c;
            currentindex = 0;
        }
    }



    return answer;
}
