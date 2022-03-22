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
    for(int i = 0; i <= (n - 1) / 2; i++) {
        if (x[i] != x[n - i - 1]) return 0;
    }
    return 1;
}

void print() {
    for(int i = 0; i < n; i++) {
        cout << x[i] << ' ';
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