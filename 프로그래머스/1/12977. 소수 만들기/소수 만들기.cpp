#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//이번에는 i부터 j  k 더해주는것 보다는 다른 방식을 하고싶다.
//버블 정렬 같은 코드를 안쓰고싶다는것 for i 안에 for j 
// 1. 그냥 해당 배열에 있는 숫자들 전부 3개의 숫자로 더하고 고르기
// 2. 결과는 생각안해봤지만 배열에 모든 숫자를 더해보고 값 생각하기 
// 1 2 3 4 = 10 아.. 2 3 5 7 이니까 6이상의 숫자중 소수만 을 고르면 되지않을까?
// 1 2 7 6 4 = 20 아래에 소수는 7 부터 20, 7 11 13 17 19  힘들것 같다.
// 숫자들은 정렬 되있진 않다 그러니 맨 앞이 최소값이 아닐 수가 있다.
// 그러면 알고리즘에서 min값 구하는것 있는 걸로안다.
// 3. 최소값을 찾아서 다른 숫자 2개 씩 더해주고 다 더한후 erase
// 반복문을 통해서 배열이 3개 이상일 경우에만 반복
// 뭔가 잘하는 사람들은 코드 신기하게 만들었는데 방법이 없나 싶은데 이게 맞는진 모르겠다
// 4. nums의 size - 1 이 최대 갯수라 생각하고
// 내부 값들을 전부 더해주면 1번예는 9== (7-1) , 최대갯수  4 - 1 == 3
// 3이지만 5이상이여야되니 7 하나만
// 2번 예제 19 == 20-1 , 5-1 ==4  어라?바로 달린다
// 하지만 10이하일경우 가 문제다 7 만 선택하면 되니 값이 10이하면 1개로 바꾸면된다!
bool IsPrime(int number)
{
    //소수 차기 ,나눠지지 않으면 소수 
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;

}

int solution(vector<int> nums) {

    vector<int> tempNum(nums);
    int answer = 0;

    vector<int> results;

    for (int i = 0; i < tempNum.size() ; i ++)
    {
        for (int j = i + 1; j < tempNum.size() ; j++)
        {
            for (int k = j + 1; k < tempNum.size() ; k++)
            {
                int sum = tempNum[i] + tempNum[j] + tempNum[k];
                results.push_back(sum);
            }
        }
        cout << i << endl;
    }


    for (int i : results)
    {
        cout << i << endl;
        if (IsPrime(i))
        {
            answer++;
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    

    return answer;
}


// //적용 하려다 안한 과거
// int FindPrimeNumber(vector<int> Nums) {

//     if (Nums.size() < 3)
//     {
//         return 0;
//     }

//     int answer = 0;
//     int midindex;

//     if (Nums.size() % 2 == 0)
//     {
//         midindex = (Nums.size() / 2) - 1;
//     }
//     else {
//         midindex = Nums.size() / 2;
//     }

//     //배열 크기 결정
//     vector<int> left;
//     vector<int> right;
    
//     copy(Nums.begin(), Nums.begin() + midindex, left);
//     copy(Nums.begin() + midindex + 1, Nums.end(), right);

//     return answer;
// }

// int SubVectorValue(vector<int> Nums) {

//     if (Nums.size() < 3)
//     {
//         return 0;
//     }
    

// }
