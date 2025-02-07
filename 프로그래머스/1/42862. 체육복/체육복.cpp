#include <string>
#include <vector>
#include <map>

using namespace std;

//클래스 구현해도되는 지모르지만 클래스 구현해보자
//reserve의 학생과 로스트 학생을 가져와야겠다.

class Student
{

private:
    int Number;
    int count;
public:
    Student() : Number(0), count(1) {} // 기본 생성자 추가

    Student(int Num) : Number(Num), count(1) {}

    const int GetCount()
    { 
        return count; 
    }

    bool IsZero()
    {
        return count == 0;
    }

    bool IsSpare() {
        return count == 2;
    }

    void Lost() {
        count = (count - 1) > 0 ?  count - 1 : 0;
    }

    void Plus() {
        count++;
    }

    void Reserve(Student& num1)
    {
        if (count <= 1)
        {
            return;
        }

        if (num1.count == 0)
        {
            num1.Plus();
            this->Lost();
            return;
        }
    }

    void Reserve(Student& num1, Student& num2 )
    {
        if (count <= 1)
        {
            return;
        }

        if (num1.count == 0)
        {
            num1.Plus();
            this->Lost();
            return;
        }

        if (num2.count == 0)
        {
            num2.Plus();
            this->Lost();
            return;
        }

    }
};


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;    
    map<int, Student> StudentClass;

   for (int i = 1; i <= n; i++)
{
    StudentClass.insert({ i,  Student(i) });
}

   for (int num : lost)
    {
        //벡터에서 찾지않고 map으로 탐색 
        if (StudentClass.find(num) != StudentClass.end())
        {
            //잃어버림
            StudentClass[num].Lost();
        }
    }

    for (int num : reserve)
    {
        //벡터에서 찾지않고 map으로 탐색 
        if (StudentClass.find(num) != StudentClass.end())
        {
            StudentClass[num].Plus();
        }
    }

    for (int i = 1; i <= n; i++)
{
    if (i == 1)
    {
        StudentClass[i].Reserve(StudentClass[i + 1]);
    }
    else if (i == n )
    {
        StudentClass[i].Reserve(StudentClass[i - 1]);
    }
    else {
        StudentClass[i].Reserve(StudentClass[i - 1], StudentClass[i + 1]);
    }
}


    for (int i = 1; i <= n; i++)
    {
        if (StudentClass[i].IsZero() == false)
        {
            answer++;
        }
    }
    return answer;
}