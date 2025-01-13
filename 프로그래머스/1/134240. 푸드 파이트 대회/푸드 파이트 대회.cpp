#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//문제이해
//0번 물
//나머지 인덱스 음식의 개수
//결과값은 가운데0을 기준으로 좌우로 나열
//정답의 길이가 3이상인 경우만 입력 

//홀수인경우 -1해줄것
//food[0]은 수웅이가 준비한 물의 양이며, 항상 1입니다.

void answerintChange(vector<int> foods, int& answerint){
    for(int i = 0; i < foods.size() ; i++)
    {
        int exchangeNum = foods[i] * (10 * i);
        answerint += exchangeNum;
    }
}


string solution(vector<int> food) {
     //음식이 담길 곳
     string answer = "";
     string tempanswer = "";

     //음식만 담아두기
     for (int i = 1; i < food.size(); i++)
     {
         int num = food[i];
         //홀수인 경우 
         if (num % 2 != 0)
         {
             num--;

         }

         //오류 발생 할수 있으니
         int foodlength = num != 0 ? num / 2 : 0;

         for (int j = 0; j < foodlength; j++)
         {
             tempanswer += to_string(i);
         }
     }

     answer +=  tempanswer+ "0";
     reverse(tempanswer.begin(), tempanswer.end());
     answer += tempanswer;






 

                                   
    return answer;
}