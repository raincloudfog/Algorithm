#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//먼저 칠해야 할곳 범위 최소 부터 최대값 구하기
// 나눠주거나 더해주느
//문제는 만약 1번부터 8번즉 끝과 끝이 비어있으면 어떻게할까
//예로들면 8개의 공간에 1번 8번 비어있고 붓길이 1이면 
//1번하고 8번해야 되니 인덱스 위치로 이동하고 붓칠하고 붓칠하고 1번끝났으니 2번위치로 갔다면


int solution(int n, int m, vector<int> section) {
    int answer = 0;

    int finishPlace = 0;

    int index = 0;
    while (index < section.size() && finishPlace < n)
    {
        //만약 인덱스보다 넘었을경우 를 안적어줬다..
        if (section[index]   > finishPlace)
        {
            finishPlace = section[index];
            finishPlace--; // 여기서 1씩 감소 시켜주기 이유 m -1 일 경우 m == 1일 수 도 있음
            //아래에서 할경우 도 마찬가지            

            index++;
        }
        else {
            // 해당 숫자보다 큰 값을 가진 첫번째 요소 찾는 함수 알고리즘
            auto it = std::upper_bound(section.begin(), section.end(), finishPlace);
            // 이미 정렬 되어있으니 바로 사용가능

            if (it != section.begin())
            {
                //큰 숫자가 있는 인덱스로 이동
                index = distance(section.begin(), it);
                cout  << index << " ";
            }

            if (index >= section.size())
                break;
            finishPlace = section[index];
            finishPlace--; // 여기서 1씩 감소 시켜주기 이유 m -1 일 경우 m == 1일 수 도 있음
            //아래에서 할경우 도 마찬가지            

            index++;
        }


        finishPlace += m ; // 2번부터 시작 2 3 4 5  
        answer++;
        cout << finishPlace << endl;
    }

    return answer;
}