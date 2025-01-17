# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int) 1e5 + 1;

int q;
int n;
string s, t;
map < char, int > m, a, b;
int main(){
	cin >> q;
	while(q--){
		vector < pair < int , int > > ans;
		ans.clear();
		for(char i = 'a'; i <= 'z'; i++){
			m[i] = 0;
		}
		cin >> n >> s >> t;
		for(int i = 0; i < n; i++){
			m[s[i]]++;
			m[t[i]]++;
		}
		int ok = 1;
		for(char i = 'a'; i <= 'z'; i++){
			if(m[i] % 2){
				ok = 0;
				break;
			}
		}
		if(!ok){
			cout << "No\n";
		}
		else {
			while(s != t){
				if(ans.size() > n + n){
					break;
				}
				for(int i = 0; i < n; i++){
					if(s[i] == t[i]){
						continue;
					}
					for(int j = 0; j < n; j++){
						if(i == j || s[j] == t[j]){
							continue;
						}
						if(t[i] == t[j]){
							swap(s[i], t[j]);
							ans.push_back({i, j});
							break;
						}
					}
				}
				for(int i = 0; i < n; i++){
					if(s[i] != t[i]){
						swap(s[i], t[i]);
						ans.push_back({i, i});
						break;
					}
				}
			}
			if((int)ans.size() > n + n){
				cout << "No\n";
				continue;
			}
			if(s == t){
				cout << "Yes\n";
				cout << (int)ans.size() << "\n";
				for(pair < int , int > i : ans){
					cout << i.first  + 1 << " " << i.second + 1<< "\n";
				}
			}
			else {
				cout << "No\n";
			}
		}
	}
	return 0;
}