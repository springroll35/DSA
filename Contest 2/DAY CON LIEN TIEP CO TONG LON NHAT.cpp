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
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = 0, ans = -1e9;
    for(int x : a) {
        sum += x;
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }
    cout << ans << endl;
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