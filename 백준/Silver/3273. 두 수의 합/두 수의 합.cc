#include <iostream>
#define ll long long
using namespace std;

int N, K, tmp;
ll ret, cnt[2'000'001];
int main() {
    cin >> N;
    while (N--) cin >> tmp, cnt[tmp]++;
    cin >> K;
    for (int i = 1; i <= K / 2; i++) {
        if (i == K - i) {
            ret += cnt[i] * (cnt[K - i] - 1) / 2;
        }
        else ret += cnt[i] * cnt[K - i];
    }
    cout << ret;
}