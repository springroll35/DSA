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
    std::vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n-1; i++) cin >> b[i];
    for(int i = 0; i < n-1; i++) {
        if (a[i] != b[i]) {
            cout << i+1 << endl;
            return;
        }
    }
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