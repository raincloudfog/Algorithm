#include <string>
#include <vector>

using namespace std;

//맵 을 만들어서 키 값 쌍을 만들어줌 (int ,bool)
// 약수를 구하는 함수를 만들어줍니다.
//포문으로 left 부터 right 까지 돌아줍니다.
//약수를 구하는 함수를 사용하여 약수의 개수가 짝수면 true 아니면 false;

//적어보니 맵도 필요없음 그냥 약수를 구하는 함수를 만들어서 짝수인지확인 하고 더하거나 빼면 됨.



//약수의 개수가 짝수인지 확인하는 함수
bool measure(int A) {
    

    int answer = 0;

    for (int i = 1; i <= A; i++)
    {
        //나눠서 떨어지는 값이 0인경우
        //answer로 체크
        if (A % i == 0)
        {
            answer++;
        }
    }

    return answer % 2 == 0;


}


int solution(int left, int right) {
    int answer = 0;
    
     for (int i = left; i <= right; i++)
    {
        //짝수면 더해주기
        if (measure(i)) {
            answer += i;
        }
        //홀수면 빼기
        else {
            answer -= i;
        }
    }
    
    return answer;
}