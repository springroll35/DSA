#include<bits/stdc++.h>

using namespace std;

#define fi "inp.inp"
#define fo "out.out"
#define ll long long
#define fr first
#define sc second

typedef pair<int,int> ii;

const int maxn=1e3+1;
const ll mod = 1e9+7;


ll n,k;

vector<vector<ll>>  mul(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>>  ans=a;
	for(int i=0;i<a.size();i++) {
	    for(int j=0;j<a.size();j++) {
			ans[i][j] = 0;
			for(int k=0;k<a.size();k++) {
				ans[i][j]+=a[i][k]*b[k][j];
				ans[i][j]%=mod;
			}
		}
	}
	return ans;
}

vector<vector<ll>>  powermod(vector<vector<ll>>  a, ll b) {
	if (b == 1) return a;
	vector<vector<ll>>  tmp=powermod(a,b/2);
	if (b & 1) return mul(tmp,mul(tmp,a));
	return mul(tmp,tmp);
}

void  process(){
    cin >> n >> k;
    vector<vector<ll>> a(n,vector<ll> (n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cin >> a[i][j];
    }
    vector<vector<ll>> ans(0,vector<ll> (0));
    ans=powermod(a,k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cout << ans[i][j] << " ";
        cout << endl;
    }
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


