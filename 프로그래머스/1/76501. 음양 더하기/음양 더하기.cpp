#include <string>
#include <vector>

using namespace std;

//절대값 사인 비교 
//false 면 * -1해주기

int solution1(vector<int> absolutes, vector<bool> signs)
{
    //합계값
    int result = 0;
    
    for(int i = 0; i < absolutes.size(); i++)
    {
        if(signs[i] == false)
            absolutes[i] *= -1;
        result += absolutes[i];
}
    
    return result;
    
}



int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;
    answer = solution1(absolutes,signs);
    return answer;
}