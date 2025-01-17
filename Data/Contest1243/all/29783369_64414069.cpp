#include <cstdio>

using namespace std;

int main() {
  long long n;
  scanf("%lld", &n);
  long long x = 2;
  while (x * x <= n) {
    if (n % x == 0) {
      break;
    }
    ++x;
  }
  if (x * x > n) {
    printf("%lld\n", n);
    return 0;
  }
  while (n % x == 0) {
    n /= x;
  }
  printf("%lld\n", n == 1 ? x : 1);
}
