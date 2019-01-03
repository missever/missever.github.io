//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
#define NN 2010
using namespace std;
struct egd {
    int from,to,flow,cost;
};
vector<egd> edge;
vector<int> G[NN];
//int max_flow; //定义流量最多为max_flow
int d[NN],p[NN],a[NN],inq[NN];
//最短路算法标记 路径记录 flow记录 队列标记
void init() {
    edge.clear();
    for(int i = 0; i < NN; i++) G[i].clear();
}

void addedge(int from,int to,int flow,int cost) {
    edge.push_back(egd{from,to,flow,cost});
    edge.push_back(egd{to,from,0,-cost});
    unsigned int i;
    i = edge.size();
    G[from].push_back(i-2);
    G[to].push_back(i-1);
}

bool ford(int s,int t,int &flow,int &cost) {
    int i,u;
    for(i = 0; i < NN; i++) d[i] = MAX;
    memset(inq,0,sizeof(inq));
    d[s] = 0;
    inq[s] = 1;
    p[s] = 0;
    a[s] = MAX;
    queue<int>qq;
    while(!qq.empty()) qq.pop();
    qq.push(s);
    while(!qq.empty()) {
        u=qq.front();
        qq.pop();
        inq[u] = 0;
        for(i = 0; i < (int)G[u].size(); i++) {
            egd &e = edge[G[u][i]];
            if(e.flow > 0 && d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost;
                p[e.to] = G[u][i];
                a[e.to] = min(a[u],e.flow);
                if(!inq[e.to]) {
                    qq.push(e.to);
                    inq[e.to] = 1;
                }
            }
        }
    }
    if(d[t] == MAX)  return false;
    flow += a[t];
    cost += a[t]*d[t];
//    if(flow > max_flow) {
//        cost -= d[t] * (flow - max_flow);
//        flow = max_flow;
//        return false;
//    }
    u = t;
    while(u != s) {
        edge[p[u]].flow -= a[t];
        edge[p[u]^1].flow += a[t];
        u = edge[p[u]].from;
    }
    return true;
}


int mincost(int s,int t) {
    int flow,cost;
    flow = cost = 0;
    while(ford(s,t,flow,cost));
    return cost;
}

int main() {
    return 0;
}
