#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    void Permute(string input)
    {
        map <char, int> countMap;
        for( auto s : input )
        {
            if( countMap.find(s) == countMap.end())
                countMap[s] = 1;
            else
                countMap[s] += 1;
        } 

        char *str  = new char[countMap.size()];
        int *count = new int[countMap.size()];
        int index =0;
        for(auto itr : countMap)
        {
            str[index] = itr.first;
            count[index] = itr.second;
            index++;

        }

        char *result =  new char[input.size()];
        permuteUtil(str,countMap.size(), count,result,input.size(),0);




    }


    void permuteUtil(char str[], int str_size, int count[], char result[], int result_size, int level)
    {
        if (level == result_size)
        {
            cout<<result<<endl;
            return;
        }

        for (int i = 0; i < str_size; ++i)
        {
            if (count[i] == 0){
                continue;
            }
            result[level] = str[i];
            count[i]--;
            permuteUtil(str,str_size,count, result,result_size, level+1);
            count[i]++;
        }
    }
};

int main()
{
    Solution s;
    s.Permute("abd");
    return 0;
}