#include <string>
#include <vector>

using namespace std;

//2차원 배열을 받아서 2차원 배열의 인덱스 끼리 더한다
//그걸 출력한다.

//2차원 배열꺼내는 건 arr1[1][1]; 이런식일 거고

//흐음 이중 포문으로 만들어주고 j 포문에서 일단예시부터
//arr[i][j]; 이런식으로 i번째의 j끼리 더해주면어떨가




vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {

        //포문에서 사용할 벡터생성
        vector<int> A;
        for (int j = 0; j < arr1[i].size(); j++)
        {
            //첫번째 배열안에 요소들끼리더해주기
            int B = arr1[i][j] + arr2[i][j];
            A.push_back(B); // 그러고 다한값 넣어주기           
        }
        //여기서 answer에 넣어주는 방식 생각
        answer.push_back(A);
    }

    
    return answer;
}