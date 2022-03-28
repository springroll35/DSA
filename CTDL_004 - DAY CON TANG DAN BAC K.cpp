#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 105;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

int n, k;
ll ans = 0;
int a[maxn], b[maxn];

void Try(int pos, int pos2) {
	if (pos2 == k) {
		ans++;
		return;
	}
	for(int i = pos+1; i < n; i++) {
		if(a[i] >= a[pos]) {
			b[pos2 + 1] = a[i];
			Try(i, pos2 + 1); 
		}
	}
}

void process() {
    cin >> n >> k;
    ans = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
    	Try(i, 1);
    }
    cout << ans << endl;
    
    
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