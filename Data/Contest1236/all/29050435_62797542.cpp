#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <time.h>
#include <stdlib.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/__gcd((a),(b))
#define clr(x) x.clear()
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vi>
#define mp make_pair
#define hell 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(),a.end()

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

using namespace std;
using namespace __gnu_pbds;

int main()
{
    IOS
    int n;
    cin>>n;
    int cst=n*n;
    int arr[cst+1];
    int ctr=1;
    bool flag=true;
    for(int i=1;i<=cst;i++)
    {
        arr[i]=ctr;
        if(flag)
        ctr++;
        else
            ctr--;
        if(ctr==n+1)
        {
            ctr--;
            flag=false;
        }
        if(ctr==0)
        {
            ctr++;
            flag=true;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cst;j++)
        {
            if(arr[j]==i)
                cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
