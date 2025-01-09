#include <string>
#include <vector>

using namespace std;

//해당 문자열 안에서 , 해당 문자를 찾는데 , num 째 까지의 길이 동안

int  check(string A, char B, int num)
{
    int last_position = -1;

    for (int i = 0; i < num; i++)
    {
        if (A[i] == B)
        {
            last_position = i;
            
        }
    }

    //-1이아니면 있다는거니까
    if (last_position != -1)
    {
        last_position = num - last_position;
    }

    return last_position;
}

vector<int> solution(string s) {
    vector<int> answer;
    
     for (size_t i = 0; i < s.length(); i++)
     {
         answer.push_back(check(s,s[i], i));
     }
    
    return answer;
}