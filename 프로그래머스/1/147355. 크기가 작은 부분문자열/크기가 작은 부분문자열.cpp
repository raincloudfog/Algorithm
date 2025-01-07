#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    vector<long long>  vec;

   //먼저 p의 길이 구하기
    int pLeng = p.length();
    long long intP = stoll(p); 


    for (size_t i = 0; i <= t.length() - pLeng; i++)
    {
        //문자열로 나눠주고 
        //정수 변환 
        string newtext = t.substr(i,  pLeng );
        long long inti = stoll(newtext);
       // vec.push_back(inti);

        if(inti <= intP)
        {
            answer++;
        }
    }


    return answer;
}