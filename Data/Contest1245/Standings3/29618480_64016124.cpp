#include <cstdio>
#include <cstring>

using namespace std;

const int N = 100'009;

char s[N];
int f[N];

int main() {
  scanf("%s", s + 1);
  int n = (int)strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'w' || s[i] == 'm') {
      puts("0");
      return 0;
    }
  }
  const int mod = 1'000'000'007;
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i - 1];
    if ((s[i] == 'u' || s[i] == 'n') && s[i] == s[i - 1]) {
      f[i] += f[i - 2];
    }
    f[i] %= mod;
  }
  printf("%d\n", f[n]);
}
