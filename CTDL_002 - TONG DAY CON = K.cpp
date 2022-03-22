#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n;
ll k, ans = 0;
ll a[maxn];
int x[maxn];

void init() {
    for(int i = 0; i < n; i++) {
        x[i] = 0;
    }
}

void print() {
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        if (x[i]) sum += a[i];
    }
    if (sum == k) {
        ans++;
        for (int i = 0; i < n; i++) {
            if (x[i]) {
                cout << a[i] << ' ';
            }
        }
        cout << endl;
    }
}

void process() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    init();
    while(1) {
        print();
        int i = n - 1;
        bool ok = true;
        while(i >= 0 && x[i]) {
            x[i] = 0;
            i--;
        }
        if (i >= 0) x[i] = 1;
        else ok = false;
        if (ok == false) break;
    }
    cout << ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}