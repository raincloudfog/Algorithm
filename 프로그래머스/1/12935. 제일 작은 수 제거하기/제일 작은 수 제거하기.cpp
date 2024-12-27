#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//signal: segmentation fault (core dumped) 배열 잘못써서
// 범위 초과 , 음수 인덱스 참조
// 포인터를 잘못 사용해서
// 내림 차순 시도

//배열 순차적으로 돌면서 i보다 i+1 작으면 바꿔주는걸로
//예 1 3 2 4
// 가장 작은 수1 오른쪽 보다 작으니 계속 2보다 작으니 계속 4보다 작으니 계속





vector<int> solution1(vector<int> arr)
{
    if(arr.size() <= 1)
    {   vector<int> newarr = {-1};
        return newarr;
     }
    
    //왼쪽값부터 사용
    int min = arr[0];
    
    for(int i = 0; i < arr.size(); i++)
    {        
        if(min > arr[i])
        {
            //min보다작으니 교체
            min = arr[i];
        }
    }
    
    //min위치의 인덱스 찾기
    auto fd = find(arr.begin(), arr.end(), min) - arr.begin();
    
    //찾으면 제거
    arr.erase(arr.begin() + fd);
    
    return arr;
    
    
    

}


vector<int> solution(vector<int> arr) {
    vector<int> answer = solution1(arr);
    return answer;
}