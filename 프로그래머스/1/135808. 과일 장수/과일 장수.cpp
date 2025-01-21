#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//결국 한번 순회를해서 최저품질을 찾아야 된다. 
//탐색인것. // 아직 3 과 9 , 3 과 10  정도이니 간단한 탐색해도 괜찮을 것 같다.
//아니면 정렬을 해놓고 큰 숫자 위주로 해도 될 것 같다!


// k 등급  m  판매해야할 갯수 score 판매 가능한 사과의 수
// 사과를 score / m 만큼 판매하되 최대한 이득을 얻을 수 있게끔 하기
int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    //복사해주고
    vector<int> tempS(score);    
    
    //먼저 정렬 해주기
    sort(tempS.begin(), tempS.end());

    //최저값을 저장용도 m개를 꺼내면서 값변경후 minNum * m으로 가격 정할것
    int minNum = 1;
    //오른쪽 부터 m개 씩 빼주기 
    while (tempS.size() >= m)
    {
        for (int i = 0; i < m; i++)
        {
            //큐나 스택을 생각해봤는데 정렬 되는지 확인안해봤으니 나중에 해볼것
            //뒤의 숫자를 빼주기            
            minNum = tempS.back();
            tempS.pop_back();
        }
        answer += minNum * m;
    }

    return answer;
}