//复杂度sqrt(V)*E

const int maxn = 1005;
vector<int>g[maxn];
int mx[maxn], my[maxn];
queue<int>q;
int dx[maxn], dy[maxn];
bool vis[maxn], vx[maxn];

bool ff(int u) {
    vx[u] = 1;
    for(auto v : g[u]) {
        if(!vis[v] && dy[v] == dx[u] + 1) {
            vis[v] = 1;
            if(!my[v] || ff(my[v])) {
                mx[u] = v;
                my[v] = u;
                return true;
            }
        }
    }
    return false;
}

int match(int n) {
    memset(mx, 0, sizeof(mx));
    memset(my, 0, sizeof(my));
    int ans = 0;
    while(1) {
        bool flag = 0;
        while(!q.empty()) q.pop();
        memset(dx, 0, sizeof(dx));
        memset(dy, 0, sizeof(dy));
        for(int i = 1; i <= n; i++) {
            if(!mx[i]) q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto v : g[u]) {
                if(!dy[v]) {
                    dy[v] = dx[u] + 1;
                    if(my[v]) {
                        dx[my[v]] = dy[v] + 1;
                        q.push(my[v]);
                    } else flag = 1;
                }
            }
        }
        if(!flag) break;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++) {
            if(!mx[i] && ff(i)) ans++;
        }
    }
	//构造点覆盖的解
	// !vx[i] 和 vis[i] 为解的点集
	/*
    memset(vis, 0, sizeof(vis));
    memset(vx, 0, sizeof(vx));
    for(int i = 1; i <= n; i++) {
        if(!mx[i]) ff(i);
    }
	for(i = 1;i <= r; i++) {   //左边的点集
        if(!vx[i]) printf(" r%d",i);
    }
    for(i = 1;i <= c; i++) {   //右边的点集
        if(vis[i]) printf(" c%d",i);
    }
	*/
    return ans;
}