#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define sc second
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;

void process() {
    int n;
    cin >> n;
    int a[n];

    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    vector<int> u,v;
    u.clear(); v.clear();
    for(int i=0;i<=(n-1)/2;i++) u.push_back(a[i]);
    for(int i=(n-1)/2+1;i<n;i++) v.push_back(a[i]);
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++) {
        cout << v[i] << " " << u[i] << " ";
    }
    if (n & 1) cout << u[u.size()-1];
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