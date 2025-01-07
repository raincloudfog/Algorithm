#include <string>
#include <vector>
#include <algorithm>


using namespace std;

//중간 지점을 찾는 게 맞을까생각중

//30 40 50 60 70 80

//여기서 중간 지점 정하고  -1 인덱스하면 그게 평균보다 아래가 되지않을까 직사각형이라 예를들면

//솔직히 인간적으로 80 70이 될수도 있을 수 도 있으니 이방식은 아닌거같다 60, 50 이 문제에있음.

//여기서 문제 다시보니 사이즈는 정해져 있다 그러므로 나와있는숫자의 중간은 아닌것 같다.

// 생각해보니 정렬을 사용하면 될거 같다. 30 70 처럼 거꾸로 되어있는게 있으니 정렬 해주어서 

//전부 한쪽이 큰거면 된다.


int solution(vector<vector<int>> sizes) {
    int answer = 0;

    //가장 큰수와 작은수 구하기 (가로 세로)
    int A=0 , B = 0;

    //2차 배열도 포문에서 간단히 사용할 수 있다고 한다!
    for (auto& i : sizes)
    {
        sort(i.begin(), i.end());
        A = A < *i.begin() ? *i.begin() : A;
        B = B < *(i.end()-1) ? *(i.end()-1) : B;
    }
    
    answer = A * B;
    
    /*for (size_t i = 0; i < sizes.size(); i++)
    {
        sort(sizes[i].begin(), sizes[i].end());
    }*/
    
    return answer;
}