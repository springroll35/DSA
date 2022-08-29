#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(k) k.begin(), k.end()
#define fi first
#define sc second
#define pb push_back
#define endl "\n"

const int maxn = 1e4+1;
const ll mod = 1e9+7;
typedef pair<int,int> ii;

string operator*(string a, int b) {
    if (a == "0" || b == 0) return "0";
    int n = a.length();
    string c(n, '0');
    int nho = 0;
    for (int i = n - 1; i >= 0; i--) {
        nho += (a[i] - '0') * b;
        c[i] = nho % 10 + '0';
        nho /= 10;
    }
    if (nho > 0)
        c = to_string(nho) + c;
    return c;
}

void process() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = n + 2; i <= 2 * n; i++) v.push_back(i);
    for (int i = 2; i <= n; i++) {
        int tmp = i;
        for (int j = 0; j < v.size() && tmp > 1; j++) {
            int gcd = __gcd(v[j], tmp);
            tmp /= gcd;
            v[j] /= gcd;
        }
    }
    string ans = "1";
    for (int i = 0; i < v.size(); i++) ans = ans * v[i];
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