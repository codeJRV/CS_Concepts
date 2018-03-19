//#include <bits/stdc++.h>
//
//using namespace std;
//
//
////More debugging required :(
//
//vector <int> bfs(int n, int m, vector < vector<int> > edges, int s) {
//    // Complete this function
//
//    bool visited[n];
//    for(int i = 0; i <n; i++) visited[i] = false;
//
//    list<int> queue;
//
//    vector<vector<int> > adj(n+1);
//    vector<int> result;
//    for(int i = 0; i <n; i++) result.push_back(-1);
//
//    for(int edges_i = 0;edges_i < m;edges_i++){
//        int u = edges[edges_i][0];
//        int v = edges[edges_i][1];
//        adj[u].push_back(v);
//
//    }
//
//    visited[s-1]  = true;
//    result[s-1] = 0;
//    queue.push_back(s);
//
//    vector<int>::iterator itr;
//
//    while(!queue.empty()) {
//        int w = queue.front();
//        queue.pop_front();
//        if (!adj[w].empty()) {
//            for (itr = adj[w].begin(); itr != adj[w].end(); ++itr) {
//                int u = *itr;
//                if (!visited[u - 1]) {
//                    visited[u - 1] = true;
//                    queue.push_back(u);
//
//                    if (u == s)
//                        result[u - 1] = 1;
//                    else
//                        result[u - 1] = result[w - 1] + 1;
//
//                }
//            }
//
//        }
//    }
//
//    int j =n;
//    while(j--)
//        if(result[j]!= -1)
//            result[j] = result[j]*6;
//
//    result.erase(result.begin() + s-1);
//    return result;
//
//
//
//
//
//}
//
//int main() {
//    int q;
//    cin >> q;
//    for(int a0 = 0; a0 < q; a0++){
//        int n;
//        int m;
//        cin >> n >> m;
//        vector< vector<int> > edges(m,vector<int>(2));
//        for(int edges_i = 0;edges_i < m;edges_i++){
//            for(int edges_j = 0;edges_j < 2;edges_j++){
//                cin >> edges[edges_i][edges_j];
//            }
//        }
//        int s;
//        cin >> s;
//        vector <int> result = bfs(n, m, edges, s);
//        for (ssize_t i = 0; i < result.size(); i++) {
//            cout << result[i] << (i != result.size() - 1 ? " " : "");
//        }
//        cout << endl;
//
//
//    }
//    return 0;
//}