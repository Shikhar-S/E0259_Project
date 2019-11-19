#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;

const double pi = acos(-1);
const int N = 1e6 + 6, mod = 998244353, M = 1e7 + 7;
const ll MAX = 5e18;

int n, c[N][3], u, v, cl[3] = {0, 1, 2}, ans[10][N], id;
vector<int> g[N];
ll s = MAX, pc[10];

void dfs(int u, int p = 0, int x = 0){
    ans[id][u] = cl[x];
    for(int i : g[u])
        if(i != p)
            dfs(i, u, (x + 1) % 3);
}

ll clc(int j){
    ll ret = 0;
    for(int i = 1; i <= n; i++)
        ret += c[i][ans[j][i]];
    return ret;
}

int main()
{
    scanf("%d", &n);
    for(int j = 0; j < 3; j++)
        for(int i = 1; i <= n; i++)
            scanf("%d", &c[i][j]);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        if(g[i].size() > 2)
            return puts("-1");
        if(g[i].size() == 1)
            u = i;
    }
    do{
        dfs(u);
        pc[id] = clc(id);
        s = min(s, pc[id]);
        id++;
    }while(next_permutation(cl, cl + 3));
    for(int i = 0; i < id; i++){
        if(pc[i] != s)
            continue;
        printf("%lld\n", s);
        for(int j = 1; j <= n; j++)
            printf("%d ", ans[i][j] + 1);
        break;
    }
    return 0;
}
