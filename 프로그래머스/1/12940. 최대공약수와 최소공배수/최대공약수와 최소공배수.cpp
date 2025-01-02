#include <string>
#include <vector>

using namespace std;

//최대 공약수 부터
//큰수를 작은 수로 나누고 
//나머지가 0이아니면 그 나머지 값으로 작은값(몫)을 나누기를 반복
//나머지가 0이 나오면 나눴던 몫이 최대 공약수

vector<int> solution(int n, int m) {
    vector<int> answer;

    //먼저 A 와 B 만들어줌
    //int A , B = 0;
    int A = n;
    int B = m;
    //int C = 0; // 최대 공약수
    //혹시 왼쪽이 더 큰수 일 수 있으니
    if (A > B)
    {
        int temp = A;
        A = B;
        B = temp;
    }

    //바로 0이 나올수 있으니 do - while로 변경
    //아 여기서 do에서 먼저 실행해서 B 와 A가 
    // 바뀌어서 while 조건 에서 충족됨 그러므로 push_back이 없이 그냥 진행
    //true로 바꿔서 조건 해당 시 탈출로 변경
    while (true)
    {
        //나머지값 구하기
        int a = B % A;

        if (a == 0)
        {
            //0이나오면 끝
            answer.push_back(A);
            break;
        }
        //큰수는 몫 값으로 변환
        B = A;
        //작은 수는 나머지값으로 변환
        A = a;
        //후 반복
    } 


    //최소 공배수 
    //최대 공약수를 미리 구하고 
    //(a 값 * b값) / a,b의 최대 공약수
    //새로 지정보다는 재활용
    A = n;
    B = m;

    int b = (A * B) / answer[0];
    answer.push_back(b);

    return answer;
}