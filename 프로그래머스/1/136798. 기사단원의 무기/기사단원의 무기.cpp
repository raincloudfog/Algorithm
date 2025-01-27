#include <string>
#include <vector>
#include <iostream>

using namespace std;

//후우 11 12 13 14 15 16 18 24 25 시간 초과
//number의 갯수가 100000까지니 약수 개수 구하는게 시간이오래걸리는것같다.
//1 번 리미트 이상 되면 멈추고 파워 2로 고정
//2 번 재밌어보이는 재귀함수 


//어쩌다보니 약수 공부 
// 약수로 나눠진다는건 결국 약수끼리 곱해야 되는거였단걸 이 당연한걸 지금 깨달았다.

// 약수의 개수 전달
int Measure(int number, int limit, int power) {

    if (number == 1) return 1;

    int answer = 0;

    //약수의 개수와 덧셈 (에서 참조)
    //포문의 초기화를 2번쓸수 가있었고 ,  >> : 2진법 으로 뒤로 가면 해당 값에절반!!! 이된다 
    /*for (int i = 1, last =  num >> 1; i <= last; i++)
    {
        if (num % i == 0) {
           answer++;
        }
    }*/
    
    //나누기 값들
    /*int deint = 1;
    vector<int> devec;
    while (num >= deint)
    {
        if (num % deint == 0)
        {
            num /= deint;
            devec.push_back(deint);
            deint = 2;
        }
        else{
            deint++;
        }
    }*/

    //여기서는 i * i 사실상 중간 약수 지점 구하는 것
    for (int i = 1; i*i <= number; i++)
    {
        if (number % i == 0)
        {
            answer++;
            //여기서 약수와 곱해줬어야될 약수 찾기 (1, 5/1) 이런식으로 상반되는 숫자 
            if(i != number / i)
            {
                answer++;
            }
        }
    }

    
    return answer > limit ? power: answer;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    vector<int> Soldier;

    //약수 개수 저장
    for (int i = 1; i <= number; i++)
    {
        Soldier.push_back(Measure(i, limit, power));
        cout<< Measure(i, limit, power) << " ";
    }

    for (int i : Soldier)
    {
        if (i > limit)
        {
            i = power;
        }
        answer += i;
    }
    

    return answer;
}