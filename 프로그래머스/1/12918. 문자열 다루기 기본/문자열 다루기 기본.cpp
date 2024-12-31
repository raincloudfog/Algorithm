#include <string>
#include <vector>

using namespace std;

//변환이 되는지 안되는지 확인 하는 게 필요함 알고리즘

//try - catch 예외 발생에서 예외 발생시 catch가 실행 
//catch에서 오류문 으로 정할수 있다고함 
//std::stoi는 문자열의 숫자로 해석 가능한 부분을 찾아 그 부분까지 변환함 즉 문자가 섞여있다면 문자 앞 숫자까지만


//regex 
//문자열 내에서 특정 패턴을 찾거나, 문자열을 검사하고, 대체하는 데 사용한다고함.

//문자열 사이즈 비교해서 변환 되도 그래도면 true // 문제는 글자수 하나일경우 어떻하지
//혹시 4와 6이여야만 되나

bool solution(string s) {
        bool answer = true;

        int num = 0;
        size_t sizeS =  s.length();
        size_t sizeN = 0;

        if (sizeS != 4 && sizeS != 6)
        {
            return false;
        }

        try {
            num = stoi(s, &sizeN);

        }
        catch (...)
        {
            return false;
        }
        answer = sizeS == sizeN;

        return answer;
}