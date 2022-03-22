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

string s, s1;
string ans[20005], ans2[20005];
ll lt[20];
ll ds[10005],ds2[10005];

ll stringToNum(string s) {
	ll sum = 0;
	for(int i = 0; i < s.length(); i++) {
		ll tmp = (ll) s[i] - 48;
		sum += tmp * lt[s.length()-i-1];
	}
	return sum;
}

string convert(string s) {
	string x = "";
	for(int i = 0; i < s.length()-1; i++) {
		if (s[i] == '+' && s[i+1] == ' ') continue;
		if (s[i] == ' ' && s[i-1] == '+') continue;
		x += s[i];
	}
	return x+s[s.length()-1];
}

void process() {
	string x, x1;
	getline(cin, x);
	getline(cin, x1);
	string s = convert(x), s1 = convert(x1);
	int dem = 0, dem2 = 0;
	string cur = "";
	//cout << s << ' ' << s1;
	for(int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cur += s[i];
		}
		else if (s[i] == ' ' || s[i] == '*') {
			ans[dem++] = cur;
			//cout << cur << ' ';
			cur = "";
		}
	}
	ans[dem++] = cur;
	cur = "";
	for(int i = 0; i < s1.length(); i++) {
		if (s1[i] >= '0' && s1[i] <= '9') {
			cur += s1[i];
		}
		else if (s1[i] == ' ' || s1[i] == '*') {
			ans2[dem2++] = cur;
			cur = "";
		}
	}
	ans2[dem2++] = cur;
	for(int i = 0; i <= 10000; i++) ds[i] = ds2[i] = 0;
	for(int i = 0;i < dem-1; i += 2) {
		ll hs = stringToNum(ans[i]);
		ll bac = stringToNum(ans[i+1]);
		ds[bac] = hs;
	}
	for(int i = 0; i < dem2-1; i += 2) {
		ll hs = stringToNum(ans2[i]);
		ll bac = stringToNum(ans2[i+1]);
		ds2[bac] = hs;
	}
	//for(int i = 0; i < dem; i++) cout << ans[i] << ' ';
	//cout << stringToNum(ans[0]);
	//cout << ans[1];
	ll sum[10005];
	int vt = 0;
	for(int i = 10000; i >= 0; i--) {
		sum[i] = ds[i] + ds2[i];
		if (sum[i]) vt = i;
	}
	for(int i = 10000; i > vt; i--) {
		if (sum[i]) cout << sum[i] << "*x^" << i << " + ";
	}
	cout << sum[vt] << "*x^" << vt << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    lt[0] = 1;
    for(int i = 1; i <= 18; i++) lt[i] = lt[i-1]*10;
    int test;
    cin >> test;
    cin.ignore();
    while(test--) {
        process();
    }
    

    return 0;
}