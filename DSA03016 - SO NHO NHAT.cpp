#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ull unsigned long long
#define fi first
#define sc second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl "\n"

const int maxn = 1e3+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

ll a, b;

void process() {
    cin >> a >> b;
    if (a > 9*b || a < 1 || b < 1) {
        cout << -1 << endl;
        return;
    }
    string k;
    k.resize(b,'0');
    ll n = b-1;
    while(n > 0 && a > 9) {
        k[n] = '9';
        a -= 9;
        n--;
    }
    if (n == 0) {
        k[0] = a + '0';
        cout << k << endl;
        return;
    }
    k[0] = '1';
    for(int i = 1; i < n; i++)  k[i] = '0';
    k[n] = a - 1 + '0';
    cout << k << endl;

   
    
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