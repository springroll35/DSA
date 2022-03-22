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

void process() {
    // sinh day gray do dai n
    cin >> n;
    vector<string> ans;
    ans.clear();
    // tao day gray do dai 1
    ans.pb("0");
    ans.pb("1");
    for(int i = 2; i < (1 << n); i <<= 1) {
        // tao day dao nguoc day gray hien co roi them vao day ket qua
        for(int j = i-1; j >= 0; j--) ans.pb(ans[j]);
        // them 0 vao dau nua day xuoi
        for(int j = 0; j < i; j++) ans[j] = '0' + ans[j];
        // them 1 vao dau nua day nguoc
        for(int j = i; j < 2*i; j++) ans[j] = '1' + ans[j];
    }
    for(auto x : ans) cout << x << ' ';
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