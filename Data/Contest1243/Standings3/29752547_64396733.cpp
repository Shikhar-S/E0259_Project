      #pragma comment(linker, "/stack:200000000")
        #pragma GCC optimize ("Ofast")
        #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
        #include <iostream>
        #include <iomanip>
        #include <sstream>
        #include <cstring>
        #include <vector>
        #include <deque>
        #include <queue>
        #include <set>
        #include <map>
        #include <valarray>
        #include <iterator>
        #include <functional>
        #include <limits>
        #include <algorithm>
        #include <numeric>
        #include <cmath>
        #include <cassert>
        #include <unordered_map>
        #include <unordered_set>
        #include <stack>
        using namespace std;
        #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
         #define trace(x) cerr << #x << ": " << x << " " << endl;
     
        typedef int64_t ll;
     
        #define endl '\n'
        #define int ll
        ll mod=1e9+7;
        ll mod1=1e9+5;
        ll power(ll a,ll b)
        {
            if(b==0) return 1;
            else if(b%2==0)
                return power((((a%mod)*(a%mod))%mod),b/2)%mod;
            else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
        }
        
     int32_t main()
        {
            IOS
        #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);    
    freopen("output.txt", "w", stdout);
        #endif
        
           
         int n;
    cin >> n;
    vector<int>del;
    for(int i=2; i*i<=n; i++)
        if (n%i == 0) {
            del.push_back(i);
            if (i * i != n)
                del.push_back(n / i);
        }
    del.push_back(n); 
    int ans = 0;
    for(int i=0;i<del.size();++i)
        ans = __gcd(ans, del[i]);
    cout << ans << endl;



        }