#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;



int32_t main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, r, p, s;
        string st;
        cin >> n >> r >> p >> s >> st;
        vector<char> an(n);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(st[i] == 'R' && p){
                p--;
                cnt++;
                an[i] = 'P';
            }
            if(st[i] == 'P' && s){
                s--;
                cnt++;
                an[i] = 'S';
            }
            if(st[i] == 'S' && r){
                r--;
                cnt++;
                an[i] = 'R';
            }
        }
        if(cnt * 2 >= n){
            cout << "YES\n";
            for(int i = 0; i < n; i++){
                if(!an[i]){
                    if(p) an[i] = 'P', p--;
                    else if(r) an[i] = 'R', r--;
                    else if(s) an[i] = 'S', s--;
                }
            }
            for(auto u : an) cout << u; cout << endl;
        }
        else cout << "NO\n";
    }
    return 0;
}
