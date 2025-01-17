#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
#ifndef __FASTPOW_INCLUDED_
#define __FASTPOW_INCLUDED_
template <typename T> constexpr T fpow_eq(T& x, long long y, T identity = 1) {
    for(; y > 0; x *= x, y >>= 1) if(y & 1) identity *= x;
    return x = identity;
}
template <typename T> constexpr T fpow(T x, long long y, T identity = 1) { return fpow_eq(x, y, identity); }
#endif
#ifndef __FASTPOW_INCLUDED_
#include "Math - Fast Pow.cpp"
#endif
#ifdef __TOTIENT_INCLUDED_
template <int M, int PHI_M = phi(M)> struct modint {
#else
template <int M, int PHI_M> struct modint {
#endif
    static constexpr int MOD = M;
    int val;
    constexpr modint() : val(0) {}
    constexpr modint(int x) : val(x % M) { val += val < 0 ? M : 0; }
    constexpr modint(long long x) : modint(int(x % M)) {}
    constexpr explicit operator int() const { return val; }
    constexpr bool operator==(const modint& y) const { return val == y.val; }
    constexpr bool operator!=(const modint& y) const { return val != y.val; }
    constexpr bool operator< (const modint& y) const { return val <  y.val; }
    constexpr bool operator<=(const modint& y) const { return val <= y.val; }
    constexpr bool operator> (const modint& y) const { return val >  y.val; }
    constexpr bool operator>=(const modint& y) const { return val >= y.val; }
    constexpr modint& operator=(const modint& y) { val = y.val; return *this; }
    constexpr modint& operator+=(const modint& y) { val += y.val; val -= val >= M ? M : 0; return *this; }
    constexpr modint& operator-=(const modint& y) { val -= y.val; val += val <  0 ? M : 0; return *this; }
    constexpr modint& operator*=(const modint& y) { val = ll(val) * y.val % M; return *this; }
    constexpr modint& operator/=(const modint& y) { val = ll(val) * fpow(y, PHI_M - 1).val % M; return *this; }
    constexpr modint& operator^=(ll y) { fpow_eq(*this, y); return *this; }
    constexpr modint operator+(const modint& y) const { return modint(*this) += y; }
    constexpr modint operator-(const modint& y) const { return modint(*this) -= y; }
    constexpr modint operator*(const modint& y) const { return modint(*this) *= y; }
    constexpr modint operator/(const modint& y) const { return modint(*this) /= y; }
    constexpr modint operator^(ll y) const { return modint(*this) ^= y; }
    constexpr modint operator-() const { return modint(0) -= *this; }
    constexpr modint operator~() const { return modint(1) /= *this; }
    constexpr modint& operator++() { val = val == M - 1 ? 0 : val + 1; return *this; }
    constexpr modint& operator--() { val = val == 0 ? M - 1 : val - 1; return *this; }
    constexpr modint operator++(int) { modint m = *this; ++(*this); return m; }
    constexpr modint operator--(int) { modint m = *this; --(*this); return m; }
    friend constexpr modint operator+(long long x, const modint& y) { return modint(x) + y; }
    friend constexpr modint operator*(long long x, const modint& y) { return modint(x) * y; }
    friend constexpr modint operator-(long long x, const modint& y) { return modint(x) - y; }
    friend constexpr modint operator/(long long x, const modint& y) { return modint(x) / y; }
    friend ostream& operator<<(ostream& os, const modint& m) { return os << m.val; }
    friend istream& operator>>(istream& is, modint& m) { ll val; is >> val; m = modint(val); return is; }
};
constexpr int M = 1'000'000'007;
using mint = modint<M, M - 1>;
mint operator""_m(unsigned long long int x) { return mint(ll(x)); }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<mint> C(s.size() + 1);
    for(int i = s.size(); i >= 0; i--) {
        if(i == s.size()) {
            C[i] = 1;
        } else if(s[i] == 'm' or s[i] == 'w') {
            C[i] = 0;
        } else if(i + 1 < s.size() and ((s[i] == 'n' and s[i+1] == 'n') or (s[i] == 'u' and s[i+1] == 'u'))) {
            C[i] = C[i + 1] + C[i + 2];
        } else {
            C[i] = C[i + 1];
        }
    }
    cout << C[0] << endl;
    return 0;
}
