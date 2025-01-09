#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dele(vector<int> arr, vector<int> commands)
{
    //arr.begin() + commands[0] -1하면 범위 벗어나는 오류 남.
    // 그런데 변수로 지정해주고 하면 오류 안남.
    // 시작과 끝 인덱스 확인
    int start = commands[0] - 1;
    int end = commands[1];
    int index = commands[2] - 1;

    // 범위 체크 벡터범위넘어감
    if (start < 0 || end > arr.size() || index < 0 || index >= (end - start)) {
        throw out_of_range("Index is out of range");
    }

    vector<int> temp(arr.begin() + start ,arr.begin() + end);

    sort(temp.begin(), temp.end());



    return temp[index];
    
}


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    //자르기
    for (int i = 0; i < commands.size(); i++)
    {
        answer.push_back( dele(array, commands[i]));
    }
    
    return answer;
}