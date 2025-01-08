#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {

     string answer = "";



     int size = s.length();



        
    for (char i : s)
    {
        if (i >= 65 && i <= 90)
        {
            answer += i + n > 90 ?  (i + n) -26 : i + n;
            
        }
        else if (i >= 97 && i <= 122)
        {
            answer += i + n > 122 ? (i + n) - 26 : i + n;
        }
        else {
            answer += i;
        }
    }

    return answer;
}