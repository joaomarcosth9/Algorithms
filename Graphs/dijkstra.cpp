#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
typedef pair<int,int> pi;

const int MAX = 1e5;

int vis[MAX];
int ans[MAX];
vector<pi> V[MAX];
priority_queue<pi, vector<pi>, greater<pi>> pq;

void showpq(){
    // Funcao que printa a priority queue
    priority_queue<pi, vector<pi>, greater<pi>> pq1 = pq;
    while(!pq1.empty()){
        cout << "\t(" << pq1.top().first << ',' << pq1.top().second << ")";
        pq1.pop();
    }
    cout << endl;
}

void dijkstra(int node){
    do {
        while(vis[node]){
            if(pq.empty()) return;
            pq.pop();
            showpq();
            node = pq.top().second;
        }
        vis[node]++;
        cout << "Visiting node: " << node << endl;
        for(int i = 0; i < V[node].size(); i++){
            pq.push({V[node][i].first+ans[node], V[node][i].second});
            if(ans[V[node][i].second] > V[node][i].first+ans[node]){
                ans[V[node][i].second] = V[node][i].first+ans[node];
            }
        }
        node = pq.top().second;
        showpq();
        pq.pop();
        showpq();
    } while (!pq.empty());
}

int main(){
    int n, e; cin >> n >> e;
    for(int i = 0; i < e; i++){
        int a, b, c; cin >> a >> b >> c;
        V[a].push_back({c,b});
        V[b].push_back({c,a});
    }
    int node; cin >> node;
    for(int i = 1; i <= n; i++){
        if(i==node) ans[i] = 0; else ans[i] = INT_MAX;
    }
    dijkstra(node);
    for(int i = 1; i <= n; i++){
        cout << "Node " << i << ": " << ans[i] << endl;
    }
    return 0;
}
