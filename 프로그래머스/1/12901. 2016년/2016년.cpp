#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(int a, int b) {
     
    int Month = 1; int day = - 1; // 1월 1일 기준 에서 1월 이 31일 더해주면 32가 되니 1일 빼주기
    string answer = "";
    vector<string> Week = {  "FRI" , "SAT" ,"SUN", "MON","TUE","WED", "THU" };
    string NewWeek = Week[5];

    map<int, int>* M_Months = new map<int, int >();

    for (int i = 1; i <= 12; i++)
    {

        if (i % 2 == 0)
        {
            if (i == 2)
            {
                M_Months->insert(pair<int,int>(i, 29 ));
            }
            else {
                int x = i; int y = i > 7 ? 31 : 30;
                M_Months->insert(pair<int, int>(i, y ));
            }
        }
        else {
            int x = i; int y = i > 7 ? 30 : 31;
            M_Months->insert(pair<int, int>(i, y));
        }
    }


    while (Month != a)
    {
        day += M_Months->at(Month);
        Month++;
    }

    // 1월 1일 이여야됨.
    // 
    day += b;
    //b만큼 나누고 남은값 
    int testa = day % 7;
    answer = Week[testa];



    return answer;
}