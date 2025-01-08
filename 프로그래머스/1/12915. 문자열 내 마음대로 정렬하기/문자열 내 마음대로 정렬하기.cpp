#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//중간글자를 비교 

vector<string> solution(vector<string> strings, int n) {
      vector<string> answer = strings;
    
//     vector<char> middlechar;
    

//     int a = 0;
//     int number = strings.size();



//     while (a  < number)
//     {
//         //문자열과 새로만든 벡터의 사이즈가 같지 않을때까지 반복
//         answer.push_back(strings[a]);
//         middlechar.push_back(strings[a][n]);
//         a++;
//     }

//     for (int i = 0; i < number; i++)
//     {
//         for (int j = i + 1; j < number; j++)
//         {
//             if (middlechar[i] > middlechar[j]) {
//                 string temps = answer[i];
//                 answer[i] = answer[j];
//                 answer[j] = temps;
//             }
//             else if (middlechar[i] == middlechar[j]) {
//                 sort(answer.begin() + i, answer.begin() + j + 1);
//             }
//         }
//     }
    
    //위 코드는 sort부분에서 여러개를 비교하는게 아니여서 안되는듯함
    //그리고 sort 사용법중 함수를 매개변수로 받을 수 있는거 확인
    //람다식 응용
    
    //& 해도 되고 &n해도됨 모든 외부함수를 사용가능한건지 확인용도
    sort(answer.begin(), answer.end(), [&](string &a,string&b)
    {
        if(a[n] != b[n])
        {
            return a[n] < b[n]; // 같을경우는 비교
        } 
        return a < b; //  글자가 같지않은경우는 사전순 정렬
});
    
    return answer;
}