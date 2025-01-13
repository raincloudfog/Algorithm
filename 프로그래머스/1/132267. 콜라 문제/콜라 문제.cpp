#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    //소유하고 있는 콜라빈병
    int All_bottle = n;



    //병이 a개 이상일 경우 
    while (All_bottle >= a)
    {
        //현재 남은 병 교체용
        int Temp_Bottle = 0;

        //교체한 병의 갯수
        int Finshed_Bottle = All_bottle / a;

        //b개의 병을 주는것
        Finshed_Bottle *= b;
        
        Temp_Bottle = Finshed_Bottle;


        // 교체가 불가능한 병
        if (All_bottle % a != 0)
        {
            int Odd_Bottle = All_bottle % a;       
            Temp_Bottle += Odd_Bottle;
        }

        All_bottle = Temp_Bottle;

        //몇병 교체 받음
        answer += Finshed_Bottle;
    }


    return answer;
}