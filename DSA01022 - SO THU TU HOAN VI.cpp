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

bool check(vector<int> a, vector<int> b) {
    for(int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void process() {
    cin >> n;
    vector<int> a(n), b(n);
    //a.clear(); b.clear();
    ll cnt = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = i+1;
    }
    if (check(a, b)) {
        cout << 1 << endl;
        return;
    }
    while (next_permutation(b.begin(),b.end())) {
        cnt++;
        if (check(a, b)) break;
        //for(int i = 0; i < n; i++) cout << b[i] << ' ';
        //cout << endl;
    }
    cout << cnt << endl;
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