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

int n,k;
int x[maxn];
vector<string> v;

void init() {
    for(int i = 0; i < n; i++) {
        x[i] = 0;
    }
}

bool check(int x[]) {
    bool ok = false;
    int cnt = 0, vt;
    for(int i = 0; i < n; i++) {
        if (x[i] == 0) {
            cnt++;
            if (cnt == k) {
                ok = true;
                vt = i;
                break;
            }
        }
        else cnt = 0;
    }
    for (int i = vt+1; i < n; i++) {
        if (x[i] == 0) {
            cnt++;
            if (cnt >= k) {
                ok = false;
                break;
            }
        }
        else cnt = 0;
    }
    return ok;
}

void print() {
    string s;
    for(int i = 0; i < n; i++) {
        if (x[i]) s += 'B';
        else s += 'A';
    }
    v.pb(s);
}

void process() {
    cin >> n >> k;
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
    cout << v.size() << endl;
    for(auto x : v) {
        cout << x << endl;
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