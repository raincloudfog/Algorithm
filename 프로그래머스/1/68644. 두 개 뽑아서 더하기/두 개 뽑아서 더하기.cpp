#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i+1; j < numbers.size(); j++)
        {
            int n = numbers[i];
            int k = numbers[j];
            auto it = find(answer.begin(), answer.end(), (n + k));
            if (it == answer.end())
            {
                answer.push_back(n + k);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}