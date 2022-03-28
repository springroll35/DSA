#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n, k;

void process() {
    cin >> n >> k;
    std::vector<int> a(k+1), b(k+1);
    for(int i = 1; i <= k; i++) cin >> a[i];
    bool ok = true;
    for(int i = 1; i <= k; i++) {
        if(a[i] != n-k+i) {
            ok = false;
            break;
        }
    }
    a[0] = -1;
    b = a;
    for(int i = k; i >= 0; i--) {
        if(a[i] != n-k+i) {
            a[i]++;
            for(int j = i+1; j <= k; j++) a[j] = a[i]+j-i;
            break;
        }
    }
    int ans = 0;
    for(int i = 1; i <= k; i++) {
        int cnt = 0;
        for(int j = 1; j <= k; j++) {
            if(a[i] == b[j])
                cnt++;
        }
        ans += cnt == 0;
    }
    cout << (ok ? k : ans) << endl;
    
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