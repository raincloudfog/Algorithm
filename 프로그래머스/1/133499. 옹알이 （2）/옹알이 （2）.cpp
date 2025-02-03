#include <string>
#include <vector>

using namespace std;

//문자열을 담고있는 words
//매개변수 문자에서 해당되는 글자수를 체크


//예외 1 문자 순서대로 확인 했더니 yemawoo처럼 문자 순서가 다를 수 있는 경우를 생각 하지 못했음.
//재귀로 함수 확인 해보려했지만 yeye와 같이 한번 중첩 된 경우를 생각 해보니  생각 한 방식으로 는 힘들 것이라 판단
//아.... 연속해서 같은 단어였다.. 즉 ayayeaya는 된다는거다..

bool CheckWord(const string text, const vector<string>& words) {

    //text.empty() : 비어있는지 확인 , text.length() < 1
    if (text.empty())
        return false;

    string temptext = text;
    string lastWord; // 마지막으로 체크한 단어
    vector<string> tempwords = words;


    while (!temptext.empty())
    {

        bool match = false; // 단어와 매치가 너무안되면 삭제용
        for (int i = 0; i < tempwords.size(); i++)
        {            
            const string& currentWord = tempwords[i];
            int wordsLangth = currentWord.length();

            if (temptext.substr(0, wordsLangth) == currentWord 
                && lastWord != currentWord) // 마지막으로 비교했던 언어가 연속으로 비교되지 않도록
            {
                match = true; //한번이라도 매치가 되면 다음 문장찾아주기
                //tempwords.erase(tempwords.begin() + i); // 중첩되면 안되니 삭제해주기
                //단어가 연속으로 중첩시 안되는거였다
                lastWord = currentWord;
                temptext = temptext.substr(wordsLangth, temptext.length());
                continue;
            }
        }

        //하나도 매치가 안되었다는 뜻으로 없는 단어로 만들어 졌음
        if (match == false)
        {
            return false;
        }
    }

    return temptext.empty();

}

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> words = { "aya" , "ye" , "woo", "ma" };


    for (int i = 0; i < babbling.size(); i++)
    {
        if (CheckWord(babbling[i], words))
            answer++;
    }



    return answer;
}