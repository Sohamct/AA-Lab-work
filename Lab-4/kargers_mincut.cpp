#include <bits/stdc++.h>
using namespace std;

#define N 4
int graph[N][N] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int count_edges(){
    int count = 0;
    int i, j;
    for(i=0; i < N; i++){
        for(j = i+1; j < N; j++){
            if(graph[i][j] == 1)
                count++;
        }
    }
    return count;
}

void create_edges(int edges[][2]){
    int x = 0;
    for(int i=0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(graph[i][j] == 1){
                edges[x][0] = i;
                edges[x][1] = j;
                x++;
            }
        }
    }
}

int find(int x, int parent[]){
    if(x == parent[x])
        return x;
    else
        parent[x] = find(parent[x], parent);
        return parent[x];
}

void Union(int a, int b, int parent[]){
    a = find(a, parent);
    b = find(b, parent);
    parent[b] = a;
}

int main(){
    int min = INT_MAX;
    int m = count_edges();
    int edges[m][2];
    create_edges(edges);
    
    int parent[N];
    for(int i=0; i < N; i++){
        parent[i] = i;
    }
    srand(0);
    int n = N;
    int counter = 100 * N * N;
    while(counter--){
        while(n > 2){
            int x = rand() % m;
            int u = edges[x][0];
            int v = edges[x][1];
            
            int set1 = find(u, parent);
            int set2 = find(v, parent);
            
            if(set1 != set2){
                Union(u, v, parent);
                n--;
            }
        }
        
        int ans = 0;
        for(int i=0; i < m; i++){
            int u = find(edges[i][0], parent);
            int v = find(edges[i][1], parent);
            
            if(u != v){
                ans++;
            }
        }
        
        if(min > ans){
            min = ans;
        }
    }
    
    
    cout << "Min Cut: " << min << endl;

    return 0;
}