#include <string>
#include <vector>

using namespace std;


//곱셈
void multiNum(long long& Num)
{
    Num *= 3;
    Num += 1;

}

//나눗셈
void DeNum(long long& Num){
    Num /= 2;

}


int solution1(int a) {
    int answer = 0;
    
    //정수 최대값을 넘어감..
    long long  Num = a;

    if (Num == 1)
        return 0;


    while(Num != 1)
    {
        if (answer >= 500)
            return -1;

        if (Num % 2 == 0)
        {
            DeNum(Num);

            answer++;
        }
        else if (Num % 2 != 0)
        {
            multiNum(Num);

            answer++;
        }
    }


    return answer;
}

int solution(int num) {
    int answer = solution1(num);
    return answer;
}