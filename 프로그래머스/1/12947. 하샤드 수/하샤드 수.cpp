#include <string>
#include <vector>

using namespace std;

//나눴을 때 나머지가 없을경우 true
bool compare(int a , int b){
    return a % b == 0;
}

bool solution(int x) {
    bool answer = true;
    
    //int arr[2] ={0};    
    vector<int> arr;
    
    int y = x;
    
    while(y > 0)
    {
        //끝 자리수 하나씩 저장
        int a = y % 10;
        arr.push_back(a);
        y /= 10;
        
}
    
    int Test = 0;
    
    for(int a : arr)
    {
        Test += a;
    }

    answer = compare(x, Test);
    
    
    
    return answer;
}