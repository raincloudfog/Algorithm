#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    
    //일단 정수를 나눠줘서 한 자리 수로 만들어 주려함
    //그걸 벡터에 저장후 비교하면 좋을 것 같음
    
    vector<int> arr;
    
    while(n > 0)
    {        
        int A = n % 10;
        arr.push_back(A);
        
        //이미 한 자리수 구했으니 n을 10으로 나눠줘서 자리수 줄이기
        n /= 10;
}

    
    //다 구했으니 sort 사용
    
    sort(arr.begin() ,arr.end(), compare);
    
    
    for(int i = 0; i < arr.size(); i++)
    {
        
        //벡터의 앞부터 더해줌
        answer += arr[i];
        //마지막 자리 가기전까지는 *= 10을 해줘서 자리수 늘리기
        answer= i ==  arr.size() -1 ? answer : answer * 10;
        
}
    
    
    
    return answer;
}