#include <string>
#include <vector>

using namespace std;

//글자 "수" ,"박" 따로 만듦
//for문으로 반복하면서 홀수일경우 "박" 짝수일경우 "수" 

string solution(int n) {
    string answer = "";

    string a = "수";

    string b = "박";


    for (int i = 0; i < n; i++)
    {
        //0포함 짝수
        if (i % 2 == 0)
        {
            answer += a;
        }
        else
        {
            answer += b;
        }
    }

    return answer;
}