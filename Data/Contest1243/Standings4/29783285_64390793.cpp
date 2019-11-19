#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <cstring>
#include <numeric>
#include <stack>
#include <iomanip>
using namespace std;

#define inf 200000000000000
#define mod 1000000007
#define eps 1e-7
#define PI 3.1415926535897932385

#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",mark)
#define sl(mark) scanf("%lld",&mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define setinf(mark) memset(mark,0x3f,sizeof(mark))

#define mp make_pair
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

#ifndef KaalaNamak
#define endl '\n'
#define trace(...)
#define start_routine() 
#define end_routine()
#endif

signed main() {
    start_routine();
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout<<fixed<<setprecision(10);
    int t=1;
    // cin>>t;
    #ifdef KaalaNamak
        t=7;
    #endif
    while(t--){
        int n;
        cin>>n;
        int c=0;
        int x=n;
        int p;
        if(n%2==0){
            c++;
            p=2;
            while(n%2==0) n=n/2;
        }
        for(int i=3;(i*i)<=n;i+=2){
            if(n%i==0){
                c++;
                p=i;
                while(n%i==0) n=n/i;
            }
            if(c>=2) break;
        }
        if(n>2){
            c++;
            p=n;
        }
        trace(c);
        if(c>=2){
            cout<<"1";
        }
        else if(c==1){
            cout<<p;
        }
        else cout<<n;
        cout<<endl;

    }
    end_routine();

}