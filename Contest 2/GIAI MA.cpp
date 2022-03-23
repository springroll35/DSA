#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e5+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

void process() {
    string s;
    cin >> s;
    int n = s.length();
    std::vector<ll> dp(n+1,0);
    if (s[0] == '0') {
        cout << 0 << endl;
        return;
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if (s[i-1] == '0') {
            if (s[i-2] != '1' && s[i-2] != '2') {
                dp[n-1] = 0;
                break;
            }
            else {
                dp[i] = dp[i-2];
            } 
        }
        else if (s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6') {
            dp[i] = dp[i-1] + dp[i-2];
        }
        else dp[i] = dp[i-1];
    }
    cout << dp[n] << endl;
    
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
    cin.ignore();
    while(test--) {
        process();
    }
    

    return 0;
}