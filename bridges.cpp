vector<int> g[N]; 
vector<pair<int, int>> bridges;
vector<int> cutpoints;
vector<bool> visited;
vector<int> tin, low;
int timer;
void IS_BRIDGE(int v,int to){
    bridges.push_back({v,to});
}
void IS_CUTPOINT(int x){
    //can be called multiple times for same x, use set or bool vector instead
    cutpoints.push_back(x);
    return;
}
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
    	    if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_bridges(int n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
