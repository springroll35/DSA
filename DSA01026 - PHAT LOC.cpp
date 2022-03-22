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
int x[maxn];

void init() {
    for(int i = 0; i < n; i++) {
        x[i] = 0;
    }
}

bool check(int x[]) {
    if (n < 6) return false;
    if (x[0] != 1 || x[n-1]) return false;
    for(int i = 0; i < n-1; i++) {
        if (x[i] && x[i+1]) {
            return false;
        }
    }
    for (int i = 0; i < n-3; i++) {
        if (x[i] == 0 && x[i+1] == 0 && x[i+2] == 0 && x[i+3] == 0) {
            return false;
        }
    }
    return true;
}

void print() {
    for(int i = 0; i < n; i++) {
        if (x[i]) cout << 8;
        else cout << 6;
    }
    cout << endl;
}

void process() {
    cin >> n;
    init();
    while(1) {
        if (check(x)) {
            print();
        }
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