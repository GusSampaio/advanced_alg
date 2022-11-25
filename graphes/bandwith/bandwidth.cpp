//Student: Gustavo Sampaio Lima
//ID: 12623992

#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define MAXFLOW 100000

int g[MAX][MAX];
int cpy[MAX][MAX];
int path[MAX];

int nodes_amnt = 0;

bool bfs(int src, int dest){
    memset(path, 0, sizeof(path));
    path[src] = -1;

    vector<bool> v(nodes_amnt, false);
    queue<int> q;
    q.push(src);
    v[src] = true;
    while(!q.empty()){
        int curr = q.front(); q.pop();

        if(curr == dest)
            return true;
        
        for(int i = 0; i < nodes_amnt; i++){
            if(cpy[curr][i] > 0 && v[i] == false){
                v[i] = true;
                q.push(i);
                path[i] = curr;
            }
        }
    }

    return false;
}

int ff(int src, int dest){
    memcpy(cpy, g, sizeof(g));

    int flow = 0, maxFlow = 0;

    while(bfs(src, dest)){
        flow = MAXFLOW; 
        for(int i = dest; i != src; i = path[i]){
            int j = path[i];
            flow = min(flow, cpy[j][i]);
        }

        for(int i = dest; i != src; i = path[i]){
            int j = path[i];
            cpy[j][i] -= flow;
            cpy[i][j] += flow;
        }

        maxFlow += flow;
    }

    return maxFlow;
}

int main(){
	cin >> nodes_amnt;
	int source = 0, destiny = 0, connections = 0, network_amnt = 1; 
    while(true){ 
        memset(g, 0, sizeof(g));
        cin >> source >> destiny >> connections;

        int from = 0, to = 0, cap = 0;
        for(int i = 0; i < connections; i++){
            cin >> from >> to >> cap;
            from -= 1;
            to -= 1;
            g[from][to] += cap;
            g[to][from] += cap;
        }
        cout<<"Network " << network_amnt << endl;
        cout << "The bandwidth is " << ff(source-1, destiny-1) << ".";
        
        cin >> nodes_amnt;
        if(nodes_amnt == 0) break;
        else cout << endl << endl;
        network_amnt += 1;
    }
    return 0;
}