#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
//#define int ll

#ifdef HNO2
#define IOS
#else
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#endif // HNO2

int t;
int n;
string s;

int32_t main()
{
    IOS
    cin>>t;
    while (t--)
    {
        cin>>n>>s;
        int now=inf;
        for (int i=0;i<n;i++)
           if (s[i]=='1') now=min({now,i,n-1-i});
        if (now==inf) cout<<n<<endl;
        else cout<<2*n-2*now<<endl;
    }
}

