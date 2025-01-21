#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//먼저 각각 학생들의 찍는 방식 배열
//answers의 갯수가 최대 10000개 라고하니 재귀할려면 잘만들어야할것 같고
//이진 탐색 트리로 도전?
//해당 노드를 안만들고 중간으로 나누는 방법 이아니라 그냥 정렬 할필요도없고


//몇문제 맞췄는지 전달
//잠시만 그냥 하나부터 다 찾는것 보다 
//answers의 Studnet.size() -1 만큼의 인덱스만 하는게 나으려나 
int FindAnswer(vector<int> answers, vector<int> Student) {

    int correct_Answer = 0;
    int answerIndex = 0;
    int studentIndex = 0;

    auto VectorReturn = [&](int& i) {
        if (Student.size() <= i)        
            i = 0;                

        return Student[i++];
        };

    while (answerIndex != answers.size())
    {
        if (answers[answerIndex++] == VectorReturn(studentIndex))
        {
            //맞은 점수 한개씩 증가
            correct_Answer++;
        }
    }

    return correct_Answer;

}

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> Student1 = {
        1, 2, 3, 4, 5
    };
    vector<int> Student2 = {
        2, 1, 2, 3, 2, 4, 2, 5
    };
    vector<int> Student3 = {
        3, 3, 1, 1, 2, 2, 4, 4, 5, 5
    };

    vector<int> correct_Answers = {
         FindAnswer(answers,Student1),
         FindAnswer(answers, Student2),
         FindAnswer(answers, Student3)
    };
    
    //배열의 최대값 찾기 방법
    auto maxVec = max_element(correct_Answers.begin(), correct_Answers.end());

    for (int i = 0; i < correct_Answers.size(); i++)
    {
        //현재 맥스값과 동일한 값들 전부 찾기
        if (*maxVec == correct_Answers[i]) {
            answer.push_back(i + 1);
        }
    }    
    return answer;
}