#include<bits/stdc++.h>

using namespace std;

#define fi "inp.inp"
#define fo "out.out"
#define ll long long
#define fr first
#define sc second

typedef pair<int,int> ii;

const int maxn=1e3+5;
const ll mod = 1e9+7;

int n,k;

void  process(){
    cin >> n >> k;
    vector<ll> ans;
    ans.push_back(1);
    ll sum=0;
    for (int i=1;i<=k;i++) {
        sum=(sum+ans.back()) % mod;
        ans.push_back(sum);
    }
    if (n <= k) {
        cout << ans[n] << endl;
        return;
    }
    for (int i=k+1;i<=n;i++) {
        ans.push_back((2*ans.back() % mod-ans[i-k-1] % mod + mod) % mod);
    }
    cout << ans.back() << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    int test;
    cin >> test;
    while (test--) {
        process();
    }


    return 0;
}




