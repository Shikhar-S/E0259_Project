/* author Dc-HITMAN */
        //    #pragma GCC optimize ("Ofast")
        //    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
        //    #pragma GCC optimize("unroll-loops")
        /*#pragma warning(disable:4996)
            #pragma comment(linker, "/stack:200000000")*/
            //#pragma GCC optimize ("-ffloat-store")
        
            #include<iostream>
            #include<bits/stdc++.h>
            #include<stdio.h>
            using namespace std;
                //#define TRACE
        
                //#ifdef TRACE
            /*    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
                template <typename Arg1>
                void __f(const char* name, Arg1&& arg1){
                    cerr << name << " : " << arg1 << std::endl;
                }
                template <typename Arg1, typename... Args>
                void __f(const char* names, Arg1&& arg1, Args&&... args){
                    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
                }
                //#else
                //#define trace(...)
            //    #endif*/
        
                #define rep(i, n)    for(int i = 0; i < (n); ++i)
                #define repA(i, a, n)  for(int i = a; i <= (n); ++i)
                #define repD(i, a, n)  for(int i = a; i >= (n); --i)
                #define trav(a, x) for(auto& a : x)
                #define all(x) x.begin(), x.end()
                #define sz(x) (int)(x).size()
                #define fill(a)  memset(a, 0, sizeof (a))
                #define fst first
                #define snd second
                #define mp make_pair
                #define pb push_back
                typedef long  double ld;
                typedef long long int ll;
                typedef pair<int, int> pii;
                typedef vector<int> vi;
        
            
       struct UF {
                    vi e;
                    UF(int n) : e(n, -1) {}
                    bool same_set(int a, int b) { return find(a) == find(b); }
                    int size(int x) { return -e[find(x)]; }
                    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
                    void join(int a, int b) {
                        a = find(a), b = find(b);
                        if (a == b) return;
                        if (e[a] > e[b]) swap(a, b);
                        e[a] += e[b]; e[b] = a;
                    }
            };
            //int st[1000000][24];
ll p=1000000007;
//int x=10002;
ll power(long long int a, ll b)
{
    if(!b)
        return 1;
    long long int ans = power(a, b/2);
    ans = (ans*ans)%p;
    if(b%2)
        ans = (ans*a)%p;
    return ans;
}
//pair<bool,int> temp4[2000001];

int main() {
   cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n,m;
    cin>>n>>m;
    if(n<m)swap(n,m);
    ll dp[n+1][2][2];
    fill(dp);
    ll dp1[m+2][2][2];
    fill(dp1);
    for(int i=1;i<=n;i++){
        if(i==1){
            dp[i][0][0]=0;
            dp[i][0][1]=1;
            dp[i][1][0]=0;
            dp[i][1][1]=0;
        }
        else{
            dp[i][0][0]=dp[i-1][0][1];
            dp[i][0][1]=(dp[i-1][1][0]+dp[i-1][1][1])%p;

            dp[i][1][1]=dp[i-1][1][0];
            dp[i][1][0]=(dp[i-1][0][1]+dp[i-1][0][0])%p;
        }
    }

    for(int i=1;i<=m;i++){
        if(i==1){
            dp1[i][0][0]=0;
            dp1[i][0][1]=1;
            dp1[i][1][0]=0;
            dp1[i][1][1]=0;
        }
        else{
            dp1[i][0][0]=dp1[i-1][0][1];
            dp1[i][0][1]=(dp1[i-1][1][0]+dp1[i-1][1][1])%p;

            dp1[i][1][1]=dp1[i-1][1][0];
            dp1[i][1][0]=(dp1[i-1][0][1]+dp1[i-1][0][0])%p;
        }
    }
    ll a,b,c,d,e,f;
    a=0;
    a=dp[n][1][0]+dp[n][1][1]+dp[n][0][1]+dp[n][0][0];
    a=a%p;
    b=dp1[m][1][0]+dp1[m][1][1]+dp1[m][0][1]+dp1[m][0][0];
    //cout<<a<<endl;
    a=(a+b+p-1)%p;
    //if(n==m)exit(-1);
    a=(a*2ll)%p;
    cout<<a<<endl;
}    