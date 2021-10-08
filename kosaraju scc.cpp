vector<int> g[N], gr[N];
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;
    for (int x : g[v]) {
        if (!used[x])
            dfs1(x);
    }
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (int x : gr[v]) {
        if (!used[x])
            dfs2(x);
    }
}

for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    gr[y].push_back(x);
}
used.assign(n, false);
for (int i = 0; i < n; i++) {
    if (!used[i])
        dfs1 (i);
}
used.assign(n, false);
vector<vector<int>> components;
for (int i = 0; i < n; i++) {
    int v = order[n - 1 - i];
    if (!used[v]) {
        dfs2 (v);
        components.push_back(component);
        component.clear();
    }
}   
