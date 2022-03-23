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

int n,k;

string bigSum(string a, string b, int k) {
    int len = max(a.length(), b.length());
    while (a.length() < len) a = "0"+a;
    while (b.length() < len) b = "0"+b;
    string ans = "";
    int rem = 0;
    for (int i = len-1; i >= 0; i--) {
        int digit = (a[i]-'0') + (b[i]-'0') + rem;
        rem = digit/k;
        ans = char(digit % k + '0') + ans;
    }
    if (rem > 0) ans = char(rem + '0') + ans;
    return ans;
}


void process() {
    string s, x;
    cin >> k >> s >> x;
    cout << bigSum(s, x, k) << endl;
    
    
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