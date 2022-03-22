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

vector<string> init(ll n) { 
    vector<string> preCubes; 
    for (ll i = 1; i*i*i <= n; i++) { 
        ll c = i*i*i; 
        string s = to_string(c); 
        preCubes.pb(s); 
    } 
    return preCubes; 
} 

string findLargestCube(string num, vector<string> preCubes) { 
    reverse(preCubes.begin(), preCubes.end()); 
    for (auto x : preCubes) { 
        string s = x; 
        ll len = s.length(); 
        ll id = 0; 
        ll n = num.length(); 
        for (auto j : num)  { 
            if (j == s[id]) id++; 
            if (len == id) return s;           
        } 
    } 
    return "-1"; 
} 

void process() {
    ll n;
    cin >> n;
    vector<string> preCubes = init(n); 
    string num = to_string(n); 
    string ans = findLargestCube(num, preCubes); 
    cout << ans << endl;
    
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