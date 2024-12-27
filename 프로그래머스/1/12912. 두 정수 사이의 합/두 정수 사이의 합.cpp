#include <string>
#include <vector>

using namespace std;

//혹시 longlong으로 하면
long long solution3(int& a, int& b)
{
	long long  start, end;

	if (a < b)
	{
		start = a;
		end = b;
	}
	else {
		start = b;
		end = a;
	}

	long long  result = 0;

	for (int i = start; i <= end; i++)
	{
		result += i;
	}

	return result;
}


long long solution(int a, int b) {
    long long answer = 0;
    
    
    
    answer = solution3(a,b);
    
    return answer;
}