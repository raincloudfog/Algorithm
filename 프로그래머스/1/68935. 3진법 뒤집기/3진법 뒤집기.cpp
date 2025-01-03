#include <string>
#include <vector>
#include <algorithm> //reverse
#include <cmath> // pow

using namespace std;

//이진법 구하기를 이해하기
//흠 10을 2로나누고 몫5를 또 나누고를 반복하면서 몫을 2로 계속나누다가
//몫이 0이되면 멈춤 0101 순서 이걸 뒤집으면1010 이10임
//3진법도 마찬가질거라 믿음


//먼저 3진법
//0이 맨앞으로 올수있으니 문자열 혹은 배열로 저장하기


int solution(int n) {
    int answer = 0;

    vector<int> vec;

    //3진법이니 0 1 2 보다 클경우는 계속 반복하기
    // n >2 하면안됨 왜냐면 몫이 1이라도 나올 수 있으니

    while (true)
    {
        if (n <= 0)
        {
            break;
        }
        //cout << n;
        //3의 나머지값
        //넣어주기
        //나눠주기
        int a = n % 3;
        vec.push_back(a);
        n = n / 3;
    }


    //거꾸로 뒤집고 다시 계산    
    //reverse(vec.begin(), vec.end());

    int c = 0;
    int size = vec.size();


    for (int i = size - 1; i >= 0; i--, c++)
    {
        //맨 끝부터 pow(vec[i] , 3);
        answer += vec[i] * pow(3, c);
    }


    return answer;
}