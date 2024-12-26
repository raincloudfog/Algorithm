#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    double a = sqrt(n);


    //소수점이 있는지 확인 하는 코드
    if (a - (int)a != 0)
        answer = -1;
    else
        answer = ++a * a;
    
    return answer;
}