#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string num[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> mylist;

void GenerateAllPermutations(string s, int k, string b)
{

    if (k == s.size())
    {
        mylist.push_back(b);
    }
    else
    {
        int index = (int)s[k]-(int)'0' - 2;
        for (int i = 0; i < num[index].size(); i++)
        {
            b.push_back(num[index][i]);
            GenerateAllPermutations(s, k + 1, b);
            b.pop_back();
        }
    }
}

int main()
{
    string number = "235";
    GenerateAllPermutations(number, 0, "");
    for (auto itr : mylist)
    {
        cout << itr<<endl;
        
    }
}