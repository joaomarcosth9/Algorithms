#include <bits/stdc++.h>

using namespace std;

void build_graph(int nodes, int edges, vector<set<int>> &V){
    int a, b;
    for (int i = 0; i < edges; i++){
        cin >> a >> b;
        V[a].insert(b);
        V[b].insert(a);
    }
}

void DFS(int nodes, vector<set<int>> &V){ 
    for (int i = 0; i < nodes; i++){

    }
}

int main(){
     
    return 0;
}
