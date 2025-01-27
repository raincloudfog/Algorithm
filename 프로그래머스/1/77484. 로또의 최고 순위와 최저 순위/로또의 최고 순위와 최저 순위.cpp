#include <string>
#include <vector>

using namespace std;


//이번에는 이진 탐색 트리 이용
//win_nums , 인덱스 , 비교할 값
bool FindValue(const vector<int> nums,  const int value, int index = 0)
{
    if (index >= nums.size())
    {
        return false; // 인덱스가 범위 벗어남.
    }

    if (nums[index] == value)
        return true; // 값찾으면 true;

    
        
    // 왼쪽 오른쪽 노드 탐색 후 하나라도 트루라면 맞는게 있다는거니까 or 사용
    return FindValue(nums, value, (2 * index + 1)) || FindValue(nums, value, (2 * index + 2));
}


vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;


    //처음 부터 6등으로 정해놓고 --로 1등으로 만들어주면 어떨까
    //아니면 7로 정해놓고 -6 하면 1이니 7 나중에 count 가 7이면 6으로 변경 해주는 방식
    int lank = 7;
    int count = 0;
    // 비교는 찾았는데 최고 최소값이 문제다. 
    // 아니다 현재값 +  n 만 해주면 된다!
    // 선형 탐색에서 이진 탐색으로 변경
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
            count++;
        if (FindValue(win_nums, lottos[i]))
            lank--;
    }


    lank = lank == 7 ? 6 : lank;
    int best = lank - count > 0 ? lank - count : 1;
    answer.push_back(best);
    answer.push_back(lank);

        return answer;
}