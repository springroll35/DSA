#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n;
int X;

bool cmp(ii a, ii b) {
    if (abs(X - a.fi) < abs(X - b.fi)) return 1;
    if (abs(X - a.fi) == abs(X - b.fi) && a.sc < b.sc) return 1;
    return 0;
}

void process() {
    cin >> n >> X;
    ii a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i].fi;
        a[i].sc = i;
    }
    sort(a,a+n,cmp);
    for(auto x : a) cout << x.fi << " ";
    cout << endl;
    


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