#include <cstdlib> //abs사용

using namespace std;

//price 를 count 만큼 곱해주면서 더해줌
//현재 돈 과 비교함

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    for (size_t i = 1; i <= count; i++)
    {
        answer += price * i;
    }


    //가격이 부족하지 않다면 
    // 0,  만약 부족하다면 부족한 값을 절대값으로 바꿔주기
    answer = money - answer >= 0 ? 0 : abs(money - answer);

    return answer;
}