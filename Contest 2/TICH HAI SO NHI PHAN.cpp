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

int n;

void process() {
    string s, x;
    cin >> s >> x;
    ll num1 = 0, num2 = 0, cnt = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        num1 += (1 << cnt) * 1ll * (s[i] - '0');
        cnt++;
    }
    cnt = 0;
    for(int i = x.size()-1; i >= 0; i--) {
        num2 += (1 << cnt) * 1ll * (x[i] - '0');
        cnt++;
    }
    cout << num1*num2 << endl;
    
    
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