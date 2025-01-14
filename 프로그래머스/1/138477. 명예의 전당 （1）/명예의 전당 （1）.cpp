#include <string>
#include <vector>
#include <algorithm>
using namespace std;




vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> Vec;


   for (int i = 0; i < score.size(); i++)
   {
        Vec.push_back(score[i]);        
        sort(Vec.begin(), Vec.end(), greater<int>());
        if (Vec.size() > k)
        {
            //맨뒤 제거
            Vec.pop_back();
        }

        answer.push_back(Vec.back());
    }
    
    return answer;
}