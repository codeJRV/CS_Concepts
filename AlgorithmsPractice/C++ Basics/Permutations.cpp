#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Not really the permutations problem


class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<vector<char> > block;
        
        char placeholder = '*';
        for (int i = 0; i< numRows;++i)
        {
            
            vector <char> row;
            for (int j =0; j < s.size()-1; j++)
            {
                row.push_back(placeholder);
            }
            
            block.push_back(row);
        }
        
        int i =0;
        int j= 0;
        int loc =  0;
        bool down = true;
        
        while(loc < s.size())
        {
            
            cout<<"i "<<i<<" J "<<j<<"Letter : "<<s[loc]<<endl ;
            block[i][j] = s[loc];
            
            if (down)
            {
                if (i < numRows-1)
                    {++ i;
                    //cout<<"here";
                    }
                else
                {
                    down = false;
                    i = i -1;
                    j = j + 1;
                    
                }
            }
            else
            {
                if(i != 0)
                {
                    i = i -1;
                    j = j + 1;
                }
                else
                {
                    down = true;
                    ++i;
                }
            }
            ++loc;
            

            
        }
        
         string result;
        
        for ( int i = 0; i < block.size(); ++i)
        {
            for( int j =0 ; j < block[i].size();++j)
            {
                if ( block[i][j] != placeholder)
                    result += block[i][j];
                //cout << block[i][j]<<"*";
            }
            cout<<endl;
        }
        
        return result;
        
    }
};


int main()
{
    Solution s;
    cout << s.convert("AB", 1);
    return 0;
}