#include <string>
#include <vector>

using namespace std;

//벡터 간단하게 점의 위치 혹은 방향과 크기
//내적은 두벡터를 이용해서 만든 각도 구하기


int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    
    //두벡터 곱한것 을 더해주기
    for(int i = 0;i < a.size() ; i++)
    {
        answer += a[i] * b[i];
    }
    return answer;
}