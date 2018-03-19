#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> bfs(int n, int m, int s, vector<vector<int> > edges)
{
    vector<int> result;
    for(int i=0; i<n-1; i++)
        result.push_back(-1);

    // do bfs

    bool visited[n];
    for(int i=0; i<n; i++)
        visited[i] = false;
    
    list<int> queue;

    visited[s] = true;

    queue.push_back(s);

    while(!queue.empty())
    {
        s = queue.front();
        cout<<s<<" ";      //for debugging
        queue.pop_front();
        int dist = 0;

        vector<int>::iterator i;
        for(i = edges[s].begin(); i!= edges[s].end(); ++i)
        {
            if(!visited[*i]) 
            {
                queue.push_back(*i);
                result[*i] = dist + 1;
            }

        }
        ++dist;

    }



    //

    for(int i=0; i<n-1; i++){
        if(result[i]!= -1)
            result[i] = result[i]*6;
    }

    return result;

}

int main()
{
    int q; 
    cin >> q;

    while (q--)
    {
        int m, n;
        cin >>n >>m;

        vector<vector<int> > edges(m,vector<int> (2));
        
        for(int i =0 ; i< m; i++)
            for (int j=0; j<2; j++)
                cin>>edges[i][j];

        int s;
        cin>>s;

        vector<int> result  = bfs(n,m,s,edges);
        for (int i =0 ; i< result.size(); i++)
            cout<<result[i]<<" : ";

    }

    return 0;
}