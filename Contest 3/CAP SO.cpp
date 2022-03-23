#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e3+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

bool cmp(ii x, ii y) {
    return x.sc < y.sc;
}

void process() {
    int n;
    cin >> n;
    std::vector<ii> a(n);
    std::vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) cin >> a[i].fi >> a[i].sc;
    sort(all(a), cmp);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j].sc < a[i].fi) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(all(dp)) << endl;
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