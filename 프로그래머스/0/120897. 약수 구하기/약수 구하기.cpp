#include <string>
#include <vector>

using namespace std;

int Measure(int num) {
     if (num == 1) return 1;
    
    int answer = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0) {
            answer++;
        }
    }
    return answer; 
}

vector<int> solution(int n) {
    vector<int> answer;
    
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0) {
            answer.push_back(i);
        }
    }
    
    return answer;
}