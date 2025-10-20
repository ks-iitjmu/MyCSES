#include <bits/stdc++.h>
using namespace std;

long long countOnes(long long n) {
long long count = 0;
for (long long i = 0; (1LL << i) <= n; i++) {
long long cycle_len = 1LL << (i + 1);
long long full_cycles = (n + 1) / cycle_len;
count += full_cycles * (1LL << i);

```
    long long remainder = (n + 1) % cycle_len;
    count += max(0LL, remainder - (1LL << i));
}
return count;
```

}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

```
long long n;
cin >> n;
cout << countOnes(n) << "\n";
return 0;
```

}
