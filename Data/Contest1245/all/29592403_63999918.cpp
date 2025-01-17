#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <cmath>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <functional>

using namespace std;

#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define PI 3.14159265358979323846
#define ABS(a) ((a)<0?-(a):(a))
const long long MOD = 1000000007;
const long long LLONG = 9223372036854775807;
const int N = 250000;
const double EPS = 0.0001;

//std::vector<std::vector<int>> v;
void mult22(long long matrres[2][2], long long matrmult[2][2], long long mod)
{
	long long tmatr[2][2];
	tmatr[0][0] = (matrres[0][0] * matrmult[0][0]) % mod + (matrres[0][1] * matrmult[1][0]) % mod;
	tmatr[0][1] = (matrres[0][0] * matrmult[0][1]) % mod + (matrres[0][1] * matrmult[1][1]) % mod;
	tmatr[1][1] = (matrres[1][0] * matrmult[0][1]) % mod + (matrres[1][1] * matrmult[1][1]) % mod;
	tmatr[1][0] = (matrres[1][0] * matrmult[0][0]) % mod + (matrres[1][1] * matrmult[1][0]) % mod;
	matrres[0][0] = (tmatr[0][0]) % mod;
	matrres[1][0] = (tmatr[1][0]) % mod;
	matrres[1][1] = (tmatr[1][1]) % mod;
	matrres[0][1] = (tmatr[0][1]) % mod;
}

long long fibo(long long n, long long mod)
{
	if (n == 0)return 0;
	long long matr[2][2];
	matr[0][0] = 0;
	matr[1][0] = 1;
	matr[1][1] = 1;
	matr[0][1] = 1;
	long long multmatr[2][2];
	multmatr[0][0] = 0;
	multmatr[1][0] = 1;
	multmatr[1][1] = 1;
	multmatr[0][1] = 1;
	n = n - 1;
	while (n > 0)
	{
		if (n & 1)
			mult22(matr, multmatr, mod);
		mult22(multmatr, multmatr, mod);
		n >>= 1;
	}
	return(matr[0][1]);
}

long long myNpow(long long a, long long n, long long mod)
{
	long long multi = a % mod;
	long long res = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			res *= multi;
			res %= mod;
		}
		multi *= multi;
		multi %= mod;
		n >>= 1;
	}
	return res;
}

bool issqr(int k)
{
	int t = (int)sqrt(k);
	return (t * t) == k;
}

void multNN(long long* matrres, long long* matrmult, long long mod, int n)
{
	long long* tmatr = (long long*)malloc(n * n * 8);
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			tmatr[i * n + j] = 0;
			for (k = 0; k < n; k++)
			{
				tmatr[i * n + j] += matrres[i * n + k] * matrmult[k * n + j];
				tmatr[i * n + j] %= mod;
			}
		}

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			matrres[i * n + j] = tmatr[i * n + j];
	free(tmatr);
}

void matrPOW(long long* matrres, int n, long long pow, long long mod)
{
	long long* multmatr = (long long*)malloc(n * n * 8);
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			multmatr[i * n + j] = matrres[i * n + j];
	pow = pow - 1;
	while (pow > 0)
	{
		if (pow & 1)
			multNN(matrres, multmatr, mod, n);
		multNN(multmatr, multmatr, mod, n);
		pow >>= 1;
	}
}

double calcdet33(double* matr)
{
	double res = 0;
	res += matr[0] * matr[4] * matr[8];
	res += matr[1] * matr[5] * matr[6];
	res += matr[2] * matr[3] * matr[7];
	res -= matr[2] * matr[4] * matr[6];
	res -= matr[1] * matr[3] * matr[8];
	res -= matr[0] * matr[5] * matr[7];
	return res;
}

class Longnum
{
public:

	vector < long long > c;

	Longnum()
	{
		c.push_back(0);
	}
	Longnum(int n)
	{
		for (int i =0; i < n; i++)
			c.push_back(0);
	}

	~Longnum()
	{
		c.clear();
		c.shrink_to_fit();
	}

	int slongsub(vector<long long>& temp, vector<long long>& b)
	{
		long long carry = 0;
		vector<long long> a(temp);
		for (size_t i = 0; i < b.size() || carry; ++i) {
			a[i] -= carry + (i < b.size() ? b[i] : 0);
			carry = a[i] < 0;
			if (carry)  a[i] += slongbase;
		}
		if (carry)
			return -1;
		else
		{
			while (a.size() > 1 && a.back() == 0)
				a.pop_back();
			temp = a;
			return 0;
		}
	}

	void add(int b)
	{
		long long carry = 0;
		for (size_t i = 0; i < c.size() || carry; ++i) {
			if (i == c.size())
				c.push_back(0);
			c[i] += carry + (i > 0 ? 0 : b);
			carry = c[i] >= slongbase;
			if (carry)  c[i] -= slongbase;
		}
	}

	void mult( long long b)
	{
		long long carry = 0;
		for (size_t i = 0; i < c.size() || carry; ++i) {
			if (i == c.size())
				c.push_back(0);
			long long cur = carry + c[i] * 1ll * (b % slongbase);
			carry = cur / slongbase + c[i] * (b / slongbase);
			c[i] = int(cur % slongbase);
		}
		while (c.size() > 1 && c.back() == 0)
			c.pop_back();
	}

	void longmult(Longnum b)
	{
		Longnum n(c.size() + b.c.size());

		for (size_t i = 0; i < c.size(); ++i)
			for (int j = 0, carry = 0; j < (int)b.c.size() || carry; ++j) {
				long long cur = n.c[i + j] + c[i] * 1ll * (j < (int)b.c.size() ? b.c[j] : 0) + carry;
				n.c[i + j] = int(cur % slongbase);
				carry = int(cur / slongbase);
			}
		while (n.c.size() > 1 && n.c.back() == 0)
			n.c.pop_back();
		c = n.c;
	}

	int slongcomp(vector<int> a, vector<int> b)
	{
		if (a.size() != b.size())
			return (a.size() > b.size() ? 1 : -1);
		else
		{
			for (int i = a.size() - 1; i >= 0; i--)
				if (a[i] != b[i])
					return (a[i] > b[i] ? 1 : -1);
			return 0;
		}
	}

	/*void slongdel(vector<int>& b)
	{
		vector<int> temp, temp2;
		vector<int> res;
		for (int i = 0; i < c.size() - b.size(); i++)
		{
			temp.push_back(0);
			res.push_back(0);
		}
		res.push_back(0);
		for (int i = 0; i < b.size(); i++)
			temp.push_back(b[i]);

		for (int i = c.size() - b.size(); i >= 0; i--)
		{
			temp2 = temp;
			res[i] = (c[c.size() - 1] / temp[temp.size() - 1]);
			slongmult(temp, c[c.size() - 1] / temp[temp.size() - 1]);
			if (slongcomp(temp, c) > 0)
			{
				slongsub(temp, temp2);
				res[i]--;
			}
			slongsub(c, temp);
			temp.clear();
			for (int j = 1; j < temp2.size(); j++)
				temp.push_back(temp2[i + 1]);
		}
		if (c.size() > 1 || c[0] > 0)
		{
			res[0] += 1;
			int carry = res[0] / slongbase;
			int i = 0;
			while (carry)
			{
				res[i] %= slongbase;
				i++;
				if (i == res.size())
					res.push_back(0);
				res[i] += carry;
				carry = res[i] / slongbase;
			}
		}
		c = res;
		return;
	}*/

	void slongprint()
	{
		printf("%lldd", c.empty() ? 0 : c.back());
		for (int i = (int)c.size() - 2; i >= 0; --i)
			printf("%09lld", c[i]);
		printf(" ");
	}

private:

	const long long slongbase = 1000 * 1000 * 1000;
};

class SeTree
{
public:
	SeTree() {}
	~SeTree() {}
	void build(int a, int l, int r, int*inp)
	{
		int m = (l + r + 1) / 2;
		vup[a] = 0;
		if (l != r)
		{
			build(a * 2, l, m - 1, inp);
			build(a * 2 + 1, m, r, inp);
			v[a] = (v[a * 2 + 1] * (r - m + 1) + v[a * 2] * (m - l)) / (double)(r - l + 1);
		}
		else
			v[a] = (double)(inp[l]);
	}
	void  update(int a, int l, int r, double k, int lr, int rr)
	{
		if ((lr == l) && (rr == r))
		{
			v[a] = k;
			vup[a] = 1;
		}
		else
		{
			int m = (l + r + 1) / 2;
			if (vup[a])
			{
				v[a * 2 + 1] = v[a];
				vup[a * 2 + 1] = 1;
				v[a * 2] = v[a];
				vup[a * 2] = 1;
				vup[a] = 0;
			}
			if (rr < m)
			{
				update(a * 2, l, m - 1, k, lr, rr);
			}
			else
			{
				if (lr >= m)
				{
					update(a * 2 + 1, m, r, k, lr, rr);
				}
				else
				{
					update(a * 2, l, m - 1, k, lr, m - 1);
					update(a * 2 + 1, m, r, k, m, rr);
				}
			}
			v[a] = (v[a * 2 + 1] * (r - m + 1) + v[a * 2] * (m - l)) / (double)(r - l + 1);
		}
	}
	double getav(int a, int l, int r, int lr, int rr)
	{
		if (vup[a] || (l == lr && r == rr))
			return v[a];
		else
		{
			int m = (l + r + 1) / 2;
			if (rr < m)
			{
				return getav(a * 2, l, m - 1, lr, rr);
			}
			else
			{
				if (lr >= m)
					return getav(a * 2 + 1, m, r, lr, rr);
				else
				{
					return (getav(a * 2 + 1, m, r, m, rr) * (rr - m + 1) + getav(a * 2, l, m - 1, lr, m - 1) * (m - lr)) / (double)(rr - lr + 1);
				}
			}
		}
	}
	double get(int a, int l, int r, int i)
	{
		if (vup[a]||(l==r))
			return v[a];
		else
		{
			int m = (l + r + 1) / 2;
			if (i < m)
			{
				return get(a * 2, l, m - 1, i);
			}
			else
			{
				return get(a * 2 + 1, m, r, i);
			}
		}
	}

private:

	bool vup[N * 4];
	double v[N * 4];
};

long long  gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

void eratosfen(char* erat, int n)
{
	int sr = (int)ceil(sqrt(n + 1)), i, j;
	erat[0] = erat[1] = 0;
	erat[2] = 0;
	for (i = 3; i <= n; i++)
		erat[i] = i % 2;
	for (i = 3; i*i <= n; i++)
		for (j = i * i; j <= n; j += i)
			erat[j] = 0;
}


long long findp(long long& a)
{
	long long r = (long long)ceil(sqrt(a)) + 1000;
	long long l = r - 2000;
	if (l < 0)
		l = 0;
	while (r > l)
	{
		long long m = (r + l + 1) / 2;
		if (m * m > a)
			r = m - (long long)1;
		else
			if (m * m == a)
			{
				a = 0;
				return m;
			}
			else
				l = m + (long long)1;
	}
	if (l * l < a)
		l++;
	a = l * l - a;
	return l;
}

int popcount32(int x)
{
	const int m1 = 0x55555555; //binary: 0101...
	const int m2 = 0x33333333; //binary: 00110011..
	const int m4 = 0x0f0f0f0f; //binary:  4 zeros,  4 ones ...
	const int m8 = 0x00ff00ff; //binary:  8 zeros,  8 ones ...
	const int m16 = 0x0000ffff; //binary: 16 zeros, 16 ones ...
	x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
	x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
	x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
	x += x >> 8;  //put count of each 16 bits into their lowest 8 bits
	x += x >> 16;  //put count of each 32 bits into their lowest 8 bits
	return x & 0x7f;
}


void GUsolve()
{
	int T, n, k, s, f,t;
	long long sum = 0, tp, m,p;
	scanf("%i", &T);
	for (int t = 0; t < T; t++)
	{

		scanf("%i %i", &n, &k);
		if (k % 2)
			printf("0\n");
		else
		{
			sum = 0;
			for (int i = 1; i <= k / 2; i++)
			{
				tp = myNpow((myNpow(2, i, MOD)), n / (i * 2), MOD);
				p = n % (i * 2);
				if (p == i)
				{
					m = 2 * (myNpow(2, i, MOD) - 1) + 2 * (myNpow(2, i - 1, MOD) - 1) + 1;
				}
				else
				{
					if (p > i)
						m = (myNpow(2, p - i, MOD) + myNpow(2, i, MOD)) * (p - i - 1) + 2 * myNpow(2, p - i, MOD) * (myNpow(2, 2 * i - p + 1, MOD) - 1);
					else
						if (p > 0)
							m = 2 * (myNpow(2, p + 1, MOD) - 1) + 1 * (i - p - 1) + myNpow(2, p, MOD) * (i - p - 1);//todo: top platoe, bottom ones
						else
							m = i*2;
				}
				tp *= m;
				tp %= MOD;
				sum += tp;

			}
			sum %= MOD;
			printf("%I64d\n", sum);
		}
	}
}
/*
3
2 1
2 2
3 2

1
1000 6

76279056

590626098
*/

int pars[10000], pacou,n,m,cm,rc = 0,deg[10000];

vector<int> frags[10000];

void treeparse(int a)
{
	int l = 1, d, v,u;
	set<pair<int, int>> topar;
	for (int i = 0; i < n; i++)
		topar.insert({ 0,i });
	while (topar.size() > 0&&(rc<2*n-1))
	{
		d = topar.begin()->first;
		v = topar.begin()->second;
		printf("? %i\n", v + 1);
		fflush(stdout);
		scanf("%i", &u);
		u--;
		if (!pars[v])
		{
			if (!pars[u])
			{
				frags[rc].push_back(v);
				frags[rc].push_back(u);
				rc++;
			}
		}
	}
}

void C8solve()
{
	scanf("%i %i", &n, &m);
	pacou = 1;
	for (int i = 1; i < n; i++)
	{
		pars[i] = 0;
		deg[i] = 0;
	}
	pars[0] = 1;
	treeparse(1);
	if (pacou == n)
		printf("+\n");
	else
		printf("-\n");
}

void B8solve()
{
	string s,lo;
	cin >> s;
	int n,csum,targ,cards[70], nplus, nminus;
	scanf("%i", &n);
	for (int i = 0; i < n; i++)
	{
		csum = 0;
		for (int j = 0; j < 64; j++)
		{
			scanf("%i", cards+j);
			if (cards[j])
				csum ^= j;
		}
		if (s[0] == 'M')
		{
			scanf("%i", &targ);
			targ--;
			nplus =targ^csum;
			cards[nplus] ^= 1;
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 8; k++)
					printf("%i ", cards[j * 8 + k]);
				printf("\n");
			}
			printf("---\n");
		}
		else
		{
			printf("%i\n", csum + 1);
			cin >> lo;
		}
	}
}

void K9solve()
{
	//map<int,int>sticks;
	vector<int> stickstemp;
	int a, T,triangles[4][3],ntria,b,c,mindiff[12],fl;
	int sticks[12], nstick,taken[12], ntriangles[4][3], nntria;
	scanf("%i", &T);
	for (int t = 0; t < T; t++)
	{
		ntria = 0;
		stickstemp.clear();
		for (int i = 0; i < 12; i++)
		{
			scanf("%i", &a);
			/*if (sticks.find(a) == sticks.end())
				sticks[a] = 1;
			else
				sticks[a]++;*/
			//a = rand() % 1000000000;
			stickstemp.push_back(a);
		}
		sort(stickstemp.begin(), stickstemp.end());
		
		mindiff[11] = MOD;
		for (int i = 10; i >= 0; i--)
		{
			mindiff[i] = min(stickstemp[i + 1] - stickstemp[i], mindiff[i + 1]);
		}
		fl =0;
		nstick = 0;
		for (int i = 0; i < 10; i++)
		{
			if (stickstemp[i] > mindiff[i + 1])
			{
				fl = 1;
			}
			if (fl)
			{
					sticks[nstick] = stickstemp[i];
					nstick++;
			}
		}
		sticks[nstick] = stickstemp[10];
		nstick++;
		sticks[nstick] = stickstemp[11];
		while (nstick >= 2 && sticks[nstick] - sticks[nstick - 1] > sticks[nstick - 2])
			nstick--;
		nstick++;
		if (nstick > 2)
		{
			for (int i = 0; i < nstick; i++)
				taken[i] = 0;
			for (int i = 1; i < nstick - 1; i++)
			{
				fl = 0;
				c = (sticks[i + 1] - sticks[i]);
				for (int j = 0; j < i&&!fl; j++)
				{
					if (!taken[j] && sticks[j] > c)
					{
						taken[j] = 1;
						taken[i] = 1;
						taken[i + 1] = 1;
						triangles[ntria][0] = sticks[j];
						triangles[ntria][1] = sticks[i];
						triangles[ntria][2] = sticks[i + 1];
						ntria++;
						i += 2;
						fl = 1;
					}
				}
			}
			if ((nstick > 5) && (ntria < (nstick / 3)))
			{

				unordered_map<int, int> possib[4];
				for (int i = 1; i < nstick - 1; i++)
				{
					for (int k = i + 1; k < nstick; k++)
					{
						c = (sticks[k] - sticks[i]);
						for (int j = 0; j < i; j++)
						{
							if (sticks[j] > c)
							{
								possib[0].insert({ (1 << i) + (1 << k) + (1 << j),0 });
							}
						}
					}
				}
				int mn;
				if (possib[0].size() < 1)
					mn = -1;
				else
					mn = 0;
				for (int i = 0; i < 3 && possib[i].size()>0; i++)
				{
					for (auto it = possib[i].begin(); it != possib[i].end(); it++)
					{
						for (auto it2 = possib[0].begin(); it2 != possib[0].end(); it2++)
						{
							if ((it->first ^ it2->first) == (it->first | it2->first))
							{
								possib[i + 1][(it->first | it2->first)] = it->first;
								mn = i + 1;
							}
						}
					}
				}
				if (mn >= ntria)
				{
					int sum, cur;
					sum = possib[mn].begin()->first;
					ntria = mn+1;

					for (int i = 0; i <= mn; i++)
					{
						cur = sum ^ possib[mn - i][sum];
						int cnt = 0;
						for (int j = 0; j < 12 && cnt < 3; j++)
						{
							if (cur & (1 << j))
							{
								triangles[i][cnt] = sticks[j];
								cnt++;
							}
						}
						sum ^= cur;
						possib[mn - i].clear();
					}
				}

			}

			printf("Case #%i: %i\n", t + 1, ntria);
			for (int i = 0; i < ntria; i++)
			{
				printf("%i %i %i\n", triangles[i][0], triangles[i][1], triangles[i][2]);
			}
		}
		else
		{
			printf("Case #%i: 0\n", t + 1);
		}
		/*for (int i = 0; i < 12; i++)
		{
			scanf("%i", &a);
			if (sticks.find(a) == sticks.end())
				sticks[a] = 1;
			else
				sticks[a]++;
		}
		while (sticks.size() > 0)
		{
			a = sticks.rbegin()->first;
			sticks[a]--;
			if (sticks.rbegin()->second > 0)
				b = sticks.rbegin()->first;
			else
			{
				if (sticks.size() > 1)
				{
					auto it = sticks.rbegin();
					it++;
					b = it->first;
				}
				else
					break;
			}
			sticks[b]--;
			if (sticks[a] < 1)
				sticks.erase(a);
			if (a != b && sticks[b] < 1)
				sticks.erase(b);
			auto it = sticks.upper_bound(a - b);
			if (it != sticks.end())
			{
				c = it->first;
				it->second--;
				if (it->second < 1)
					sticks.erase(it);
				triangles[ntria][0] = a;
				triangles[ntria][1] = b;
				triangles[ntria][2] = c;
				ntria++;
			}
			else
			{
				if (sticks.find(b) == sticks.end())
					sticks[b] = 1;
				else
					sticks[b]++;
			}
		}
		printf("Case #%i: %i\n", t + 1, ntria);
		for (int i = 0; i < ntria; i++)
		{
			printf("%i %i %i\n", triangles[i][0], triangles[i][1], triangles[i][2]);
		}
		sticks.clear();*/
	}
}

/*
5
1 2 1 3 1 4 1 5 1 6 1 7
1 2 3 4 5 6 7 8 9 10 11 12
1 2 3 5 8 13 21 34 55 89 144 233
2 3 6 15 27 59 72 83 121 159 201 234
2 2 4 8 16 32 64 128 256 512 1024 1281
*/

int lprcomp(long long a, long long b, long long c)
{
	long long au = a / 1000000000, ab = a % 1000000000,bu= b / 1000000000, bb = b % 1000000000;
	long long ru = au * bu + (ab * bu + au * bb) / 1000000000;
	long long rb = ((ab * bu + au * bb) % 1000000000) * 1000000000 + ab * bb;
	if ((ru > 0)||(rb>c))
		return 1;
	else
		if (rb < c)
			return -1;
		else
			return 0;
}

long long funcmax(long long n, long long k)
{
	long long t = 1;
	while (t < n)
	{
		if (lprcomp(t, k, n) <= 0)
			t *= k;
		else
			return min(n, t + k - 1);
		t += k - 1;
	}
	return  min(n, t);
}

long long funclm(long long n, long long k)
{
	long long ans=0;
	while (n > 0)
	{
		ans += n % k;
		n /= k;
		if (n > 0)
			ans++;
	}
	ans--;
	return ans;
}

long long funcfind(long long l, long long r, long long k)
{
	if (r>l&&r>2&&r % k == 0)
		r--;
	if (r > l)
	{
		long long lm = min(funcfind(l / k, r / k, k) * k + k - 1, r);
		long long lm1 = funclm(lm, k);
		for (long long i = lm+1; i <= r; i++)
			if (funclm(i, k) > lm1)
			{
				lm = i;
				long long lm1 = funclm(lm, k);
			}
		return lm;
	}
	else
		return l;
}

void HGsolve()
{
	int a, y,miny,maxy, n, max = -1,cur;
	unordered_map<int, int> lefts, rights;
	scanf("%i", &n);
	for (int i = 0; i < n; i++)
	{
		miny = 1000000;
		maxy = -1000000;
		for (int j = 0; j < 3; j++)
		{
			scanf("%i %i", &a, &y);
			if (y < miny)
				miny = y;
			if (y > maxy)
				maxy = y;
		}
		if (lefts.find(miny) == lefts.end())
			lefts[miny] = 1;
		else
			lefts[miny]++;
		if (rights.find(maxy) == rights.end())
			rights[maxy] = 1;
		else
			rights[maxy]++;
	}
	cur = 0;
	maxy = 0;
	for (int i = -1000000; i <= 1000000; i++)
	{
		if (lefts.find(i) != lefts.end())
			cur += lefts[i];
		if (cur > max)
		{
			max = cur;
			maxy = i;
		}
		if (rights.find(i) != rights.end())
			cur -= rights[i];
	}
	printf("%i\n", max);
}

void HHsolve() {
	long long  n;
	cin >> n;
	const long long MOD = 1e9 + 7;
	long long t = 0;
	vector<long long> a(n+1);
	long long p = 1;
	vector<long long> q(n + 1);
	q[0] = 1;
	q[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		q[i] = (q[i - 1] * i) % MOD;
	}

	if (n == 1) { cout << 1; return; }
	for(long long i = n; i >n/2; i--) {
		a[i] = a[n - i] = p;
		p = (p*i);
		p %= MOD;
	}
	for (long long i = 0; i <= n; i++) {
		t = (t + (q[n] * myNpow((q[i] * q[n - i]), MOD - 2, MOD) * max(n - i, 1LL))) % MOD;
	}
	cout << t;
}

void HIsolve()
{
	long long a, n;
	long long mod = 1e9 + 7;
	scanf("%I64d %I64d", &a, &n);
	a %= mod;
	a += mod;
	long long mult = a, res[2][2] = { {2,a},{2,a} };
	n = abs(n);
	while (n > 0)
	{
		mult %= mod;
		for (int i = 0; i < 4; i++)
			res[i >> 1][i & 1] %= mod;
		res[n & 1][0] = mult * res[n & 1][0] - res[1 ^ (n & 1)][1];
		res[n & 1][1] = mult * res[n & 1][1] - res[1 ^ (n & 1)][0];
		mult = mult * mult - 2;
		n >>= 1;
	}
	res[1][0] %= mod;
	printf("%I64d\n", res[1][0]);
}

unordered_set<string> strings;
vector<bool> parsd;
string base;
string s;

void stringgen()
{
	if (s.size() < base.size())
	{
		for (int i = 0; i < base.size(); i++)
			if (!pars[i])
			{
				pars[i] = 1;
				s.push_back(base[i]);
				stringgen();
				s.pop_back();
				pars[i] = 0;
			}
	}
	else
		strings.insert(s);
}

void solve10()
{
	strings.clear();
	cin >> base;
	parsd.resize(base.size(),0);
	stringgen();
	auto itn = strings.begin();
	auto it = itn;
	while (itn!=strings.end())
	{
		it = itn;
		itn++;
		int i;
		for (i = 0; i < (it->size()-1); i++)
		{
			if ((*it)[i] == (*it)[i + 1])
			{
				strings.erase(it);
				break;
			}
		}

	}
	printf("%i\n", strings.size());
}

int main()
{
	int a, b, t;
	scanf("%i", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%i %i", &a, &b);
		if (gcd(a, b) == 1)
			printf("finite\n");
		else
			printf("infinite\n");
	}
	return 0;
}
