#include <string>
#include <vector>

using namespace std;

//글자를 나눠주고
//벡터에 혹은 새로운 string에 저장



void sort1(char& a, char& b) {

    if (a < b)
    {
        char temp = a;
        a = b;
        b = temp;
    }
 }


string solution(string s) {
    string answer = s;

        //str도 사이즈가 됨    
        //!! 중요 !! size_t타입은 0보다 작아질 수 없음. 0네서 더 감소못하고 언더플로우 발생해서 매우 큰!!! 값으로 나옴
        //무한루프발생..

        //for (size_t i = str.size(); i > 0; i--) {
        //   
        //    //문자열도 인덱스가 사용됨
        //    //문자열에 더해주기
        //    //끝 문자열 부터 실행하니 -1 로 인덱스 맞춰줌.
        //    answer += str[i - 1];        
        //}

    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = i; j < s.size(); j++)
        {
            sort1(answer[i], answer[j]);
        }
    }

return answer;
}