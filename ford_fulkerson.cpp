#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

bool bfs(vector<vector<int>> rGraph, int s, int t, vector<int> &parent);

int fordFlukerson(vector <vector<int>> g, int s, int t){
    vector <vector<int>> rGraph = g;
    
    vector <int> parent(g.size(), 0);
    
    int max_flow = 0;
    while(bfs(rGraph, s, t, parent)){
        int bottle_nack = INT_MAX;
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            bottle_nack = min(rGraph[u][v], bottle_nack);
        }
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            rGraph[u][v] -= bottle_nack;
            rGraph[v][u] += bottle_nack;
        }
        max_flow += bottle_nack;
    }
    return max_flow;
}

bool bfs(vector<vector<int>> rGraph, int s, int t, vector<int> &parent){
    int n = parent.size();
    vector <bool> vis(n, false);
    
    queue <int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;
    
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++){
            if(vis[v] == false && rGraph[u][v] > 0){
                if(v == t){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                vis[v] = true;
                parent[v] = u;
            }
        }
    }
    return false;
}

int main()
{
    vector <vector<int>> g = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    cout << "Max-Flow from 0 to 5 is: " << fordFlukerson(g, 0, 5);
    // TC: O(Max-Flow*Copmexity of bfs).
    // TC: O(Max-Flow*number_of_edges).
    return 0;
}
