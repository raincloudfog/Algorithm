#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include <map>

using namespace std;

//이번에도 클래스를 이용할까 싶다
//물론 그냥 함수로도 되지만 연습하기 위해
//스트링이 담겨있는 Key클래스 그 key를 관리하는 keymanager

//원소의 길이가 100개 이하라 그걸 전부 배열에 담아두는건 무리다.


class Key
{

private:
    string _key;
public:

    Key() {}
    Key(string key) : _key(key) {}


    int GetKeyNumber(char ch) {

        auto findKey = find(_key.begin(), _key.end(), ch);

        if (findKey != _key.end())
        {
            return distance(_key.begin(), findKey) + 1;
        }

        return -1;
    }
};

class KeyManager 
{
public:
    unique_ptr<vector<Key>> _keys;
    
    KeyManager() : _keys(make_unique<vector<Key>>())
    {
        
    }


    void AddKey(Key key)
    {
        _keys->push_back(key);
    }

     int FindKeyIndex(const char& S)
     {
         int fastNumber = -1;


         for (int i = 0;i < _keys->size();i++)
         {
             int Num = _keys->at(i).GetKeyNumber(S);

             if ((fastNumber == -1 || Num < fastNumber )&& Num != -1)
            {
                fastNumber = Num;
            }
             if (fastNumber == 1)
             {
                 return fastNumber;
             }
         }

         return fastNumber;

     }

    ~KeyManager() {
        
    }

};





vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size() , -1);

    //100개 이하의 원소라지만 동일한 문자가 있을 것이기때문에
    //(문자 * 최소값) 해주면 시간 절약 할 수 있을 것이다.
    vector<map<char, int>> targetMaps;    


    KeyManager manager;

    //여기서 궁금한것중하나가 
    //지역 변수에서 벗어나면 없어진다고 생각했었다. 
    // 하지만 값복사가 될거라고는 생각도안했다..   
    for (string i : keymap)
    {
        manager.AddKey(Key(i));
    }

    for (int i = 0; i < targets.size(); i++)
    {
        targetMaps.push_back(map<char, int>());
        //targetMaps[i]
    }

    for (int i = 0; i < targetMaps.size(); i++)
    {
        for (int j = 0; j < targets[i].size(); j++)
        {
            //가독성이 안좋아보이긴하는데 바꿀까 생각중
            targetMaps[i][targets[i][j]]++;
        }
    }

    //맵의 first (키 )값을 
    for (int i = 0; i < targetMaps.size(); i++)
    {
        map<char, int>& tempmap = targetMaps[i];
        for (auto c : tempmap)
        {
            //설계의 중요성
            
            if (manager.FindKeyIndex(c.first) != -1)
            {
                 answer[i] = answer[i] == -1 ? 
                     (manager.FindKeyIndex(c.first) * c.second)+ answer[i] + 1 : manager.FindKeyIndex(c.first) * c.second + answer[i];
                
            }
            else{
                answer[i] = -1;
                break;
}
        }
    }

    

    return answer;
}