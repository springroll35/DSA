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

int n, p, s;
std::vector<int> v, isPrime(300, 0), tmp;
std::vector<std::vector<int> > ans;

void seive() {
   isPrime[0] = isPrime[1] = 1;
   for(int i = 2; i*i <= 300; i++) {
       if(isPrime[i] == 0) {
           for(int j = i*i; j <= 300; j += i) isPrime[j] = 1;
       }
   }
   for (int i = 0; i <= 300; i++) {
       if(isPrime[i] == 0) v.pb(i);
   }
}

void Try(int i, int sum, int cnt, std::vector<int> tmp) {
    if (sum > s || cnt > n) return;
    if (cnt == n) {
        if (sum == s) {
            ans.pb(tmp);
            return;
        }
    }
    for(int j = i; j < v.size(); j++) {
        if (sum+v[j] <= s) {
            tmp.pb(v[j]);
            Try(j+1, sum+v[j], cnt+1, tmp);
            tmp.pop_back();
        }
    }
}

void process() {
    cin >> n >> p >> s;
    ans.clear();
    int pos = upper_bound(all(v), p) - v.begin();
    Try(pos, 0, 0, tmp);
    cout << ans.size() << endl;
    for(auto x : ans) {
        for(auto y : x) cout << y << ' ';
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

    seive();
    int test;
    cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}