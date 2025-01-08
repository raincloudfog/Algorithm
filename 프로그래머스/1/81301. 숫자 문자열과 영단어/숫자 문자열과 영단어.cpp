#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;




int solution(string s) {
     int answer = 0;

 string n = "";


 vector<string> NumS =
 {
     "zero", "one","two", "three", "four", "five"
         ,"six", "seven", "eight", "nine"
 };

 int SizeS = s.length();
 

 string t = "";

 for (char c : s)
 {
     

     if (std::isdigit(c)) // 숫자인경우
     {
         n += c;
     }
     else if(std::isalpha(c) ) //알파벳 인경우
     {
         t += c; // 배열에서 못찾았으니 다시 글자 생성
     }

     auto it = find(NumS.begin(), NumS.end(), t);

     if (it != NumS.end())
     {
         t.clear(); // 글자 찾았으니 초기화
         int index = distance(NumS.begin(), it); // 인덱스 찾기
         n += to_string(index);
     }

 }

 answer = stoi(n);

 

    
    
    return answer;
}