#include <string>
#include <vector>

using namespace std;

//숫자 교환
void tem(int& a, int& b)
{
    if (a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
}

vector<int> solution1(vector<int>& arr, int divisor) {
    vector<int> answer;

//숫자가 나누어 떨어지는 지 확인후 추가
    for (int i : arr)
    {
        if (i % divisor == 0)
            answer.push_back(i);
    }
    
    //0개면 -1반환 // 아닌경우 오름차순 정렬
    if (answer.size() == 0)
        answer.push_back(-1);
    else
    {
        //i번째를 j번째들과 비교후 정렬
        for (int i = 0;i < answer.size(); i++)
        {
            for (int j  = i; j < answer.size(); j++)
            {
                tem(answer[i], answer[j]);
            }
        }
    }

    return answer;
}

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer = solution1(arr, divisor);
    return answer;
}