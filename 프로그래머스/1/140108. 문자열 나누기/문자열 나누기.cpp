#include <string>
#include <vector>

using namespace std;

//문제가 더러운건지 내가 읽는 능력이 약한건지 이해하기 힘들었지만
//같은 문자의 숫자 만큼 옆의 숫자를 인정함
//그런데 3번 예제 처럼 aaab 여기서 이미 a는 3이지만 bba에서 a가 하나더나왔으니까 + 1
//aaabbacc 는 a = 4 , b = 2 , c = 2 으로 a = b + c 니까 성립


int solution(string s) {
    int answer = 0;

    vector<string> countS;

    //초기화
    char lastword = s[0];
    int LastWordCount = 0;

    int differentNumber = 0;

   /* int CountedNumber = 0;
    int strCount = 0;*/

    for (int i = 0; i < s.size(); i++)
    {
        ////
        //if (CountedNumber >= strCount)
        //{
        //}

        // - 단어일경우 처음 부터시작
        if (lastword == '-')
        {
            lastword = s[i];
        }
         
        //단어가 같을경우 Count 증가 , 아닐경우 감소
        if (lastword == s[i])
        {
            LastWordCount++;
        }
        else {
            LastWordCount--;
        }

        //단어숫자 전부 소모시
        if (LastWordCount <= 0)
        {
            //해당 인덱스 번호 
            //단어 나누기
            string subS = s.substr(differentNumber, i);
            countS.push_back(subS);
            differentNumber = i;
            lastword = '-';
        }

        if (LastWordCount > 0 && i == s.size() - 1)
        {
            string subS = s.substr(differentNumber, i);
            countS.push_back(subS);
        }
    }

    return countS.size() == 0 ? 1 : countS.size();
}