///Ma-ia-hii
///Ma-ia-huu
///Ma-ia-hoo
///Ma-ia-haa
///X4

///Alo, Salut, Sunt Eu, un Haiduc
///Si Te Rog, Iubirea mea Primeste Fericirea
///Alo, Alo, Sunt Eu, Picasso
///Ti-am dat beep
///Si Sunt Voinic
///Dar Sa Stii Nu-ti Cer Nimic

///Vrei sa pleci dar nu ma, nu ma iei
///nu ma, nu ma iei, nu ma, nu ma, nu ma iei
///Nu Ma, Nu Ma Iei, nu ma, nu ma, nu ma iei
///Chipul tau si dragostea din tei
///Mi-amintesc de ochii tai

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define DIM (long long)100007
#define INF (long long)1000000007
#define fi first
#define se second
#define x1 sfhshfd
#define y1 sfhs321321hfd
#define glhf ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define GG cout << " OPANA " << endl;

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef tree<ll,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> SATANA;



ll t,n,m,res1,res2;
ll a[DIM];
ll b[DIM];
int main()
{
    glhf;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    sort(a+1,a+n+1);


    for(int i=1; i<=n/2; i++){
        res1+=a[i];
    }
    for(int i=n/2+1; i<=n; i++){
        res2+=a[i];
    }
    cout << res1*res1+res2*res2 << endl;




























    return 0;
}
