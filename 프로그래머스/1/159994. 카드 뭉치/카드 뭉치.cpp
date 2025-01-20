#include <string>
#include <vector>
#include <algorithm>
using namespace std;



// 문제 다시 보니 한번뽑고 2번뽑는게 아닌 해당 배열에 원하는 단어가 있으면 계속 뽑기 가능
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    //문자를 담아 둘 공간
    vector<string> cardvec;
    vector<string> tempcards; //  cards 1 , 2 를 잠시 담아둘 그릇    
    string answer = "";
       
    
    vector<vector<string>> vecs = { cards1 , cards2 };
    tempcards = cards1;
    int i = 0;            
    int tempi = 0; // 전의 배열에서 i의 값 저장
    int j = 0;
    int index = 0;
    while(goal.size() > cardvec.size())
    {
        //같은 지 비교
        if (tempcards.size() > i && tempcards[i] == goal[j])
        {
            cardvec.push_back(tempcards[i++]);
            j++;
        }
        else 
        {
            swap(i, tempi);
            index = index == vecs.size() - 1 ? 0 : ++index;
            tempcards = vecs[index];
            //다른 배열에서도 없다면 바로 return "NO";
            if (tempcards[i] != goal[j])
            {
                answer = "No";
                return answer;
            }
        }                        
        
    }

    if (equal(cardvec.begin(), cardvec.end(), goal.begin()))
    {
        answer = "Yes";

    }
    else {
        answer = "No";
    }
    
    return answer;
}