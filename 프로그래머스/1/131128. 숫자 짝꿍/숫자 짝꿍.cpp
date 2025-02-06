#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


//어느 순간부터 비교 ,탐색의 비율이 점점 커지는 것 같다.
//자리수는 3 ,000 , 000 으로 1개부터 7개 까지 비교 하면될것 같다. 이정도면 
// 적당한 반복문도 괜찮을 듯 하다.
// 짝꿍 찾으면 한번 정렬 해준 다음 값을 더해주면 될 거 같다.
// 시간초과가 몇개 있었다 수정

int CheckValue(int num1, int num2)
{
    int N = 0;
    if (num1 > num2)
    {
        //당장은 더좋은게 생각안나니 빠르게
        int a = num1 - num2;
        N = num1 - a;
    }
    else if (num1 < num2)
    {
        int a = num2 - num1;
        N = num2 - a;
    }
    else {
        N = num1;
    }
    return N;
}


string solution(string X, string Y) {
    string answer = "";

    unordered_map<char, int> count1;
    unordered_map<char, int> count2;

    vector<int> Number;

    for (char c: X)
    {
        count1[c]++;
    }

    for (char c : Y)
    {
        count2[c]++;
    }

    //두문자의 값을 빼주면 어떨까 

    

    for (auto count : count1)
    {
        char c = count.first;
        //cout << c << endl;
        if (count2.find(c) != count2.end())
        {
           
            int n = CheckValue(count1[c], count2[c]);
            for (int i = 0; i < n; i++)
            {
                Number.push_back(c - '0');
            }
        }
    }

   
    

    if(!Number.empty())
{
    sort(Number.begin(), Number.end(), greater<int>());

    for (int i : Number)
    {
        answer += i + '0';
    }
    if (Number[0] == 0)
    {
        answer = '0';
    }
}
     if (Number.empty())
     {
         answer = "-1";
     }

    return answer;
}