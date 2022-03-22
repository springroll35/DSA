#include <bits/stdc++.h>

using namespace std;

#define fi "inp.inp"
#define ll long long

typedef pair<int,int> II;

const int maxn = 1005;
const ll mod = 1e9+7;

int n;

void process() {
    cin >> n;
    std::vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll sum1 = 0, sum2 = a[0];
    for(int i = 1; i < n; i++) {
        ll tmp = max(sum1, sum2);
        sum2 = sum1 + a[i];
        sum1 = tmp;
    }
    cout << max(sum1, sum2) << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}