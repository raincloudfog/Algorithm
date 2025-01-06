#include <string>
#include <vector>

using namespace std;

//맵 사용
// 반복문에서 맵에서 탐색 하기
// 별로긴해도 3중 반복문 을 사용하는 것 외에는 당장 안떠오름


// 수정
//곂치지않게 하기
//함수에서 해당 인덱스를 기준으로 비교

//배열과 인덱스를가져와서 비교하기
int quest(vector<int> vec, int index)
{
    int count = 0;
    for (size_t i = index + 1; i < vec.size(); i++)
    {
        if (i != index)
        {
            for (size_t j = i+1; j < vec.size(); j++)
            {
                if (vec[index] + vec[i] + vec[j] == 0) {
                    count++;
                }
            }
        }
    }
    //cout << count << "함수 에서는 이럼";
    return count;
}


int solution(vector<int> number) {
    int answer = 0;
    
    for (size_t i = 0; i < number.size(); i++)
{
    answer += quest(number, i);
}
    
    return answer;
}