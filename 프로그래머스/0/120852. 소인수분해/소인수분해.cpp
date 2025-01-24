#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {    
    //나누기 값들
    int deint = 2;
    vector<int> devec;
    while (n > 1)
    {
        if (n % deint == 0)
        {
            n /= deint;
            if(find(devec.begin(), devec.end(), deint) == devec.end()) 
               {
                   devec.push_back(deint);               
               }                              
            deint = 2;
        }
        else{
            deint++;
        }
    }

    sort(devec.begin(), devec.end());
    
    return devec;
}