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
const int row[] = {0, 1};
const int col[] = {1, 0};
const string ch[] = {"R", "D"};
typedef pair<int,int> ii;

int n, k;
std::vector<int> x(maxn), sum(maxn);
std::vector<std::vector<int> > ans;

void print(int k) {
    std::vector<int> tmp;
    for(int i = 1; i <= k; i++) {
        tmp.pb(x[i]);
    }
    ans.pb(tmp);
}

void Try(int i) {
    for(int j = min(n-sum[i-1], x[i-1]); j >= 1 ; j--) {
        x[i] = j;
        sum[i] = sum[i-1] + j;
        if(sum[i] == n)
            print(i);
        else
            Try(i+1);
    }
}

void process() {
    ans.clear();
    cin >> n;
    x[0] = n;
    sum[0] = 0;
    Try(1);
    cout << ans.size() << endl;
    for(auto v : ans) {
        cout << '(';
        for(int i = 0; i < v.size()-1; i++) cout << v[i] << ' ';
        cout << v[v.size()-1] << ") ";
    }
    cout << endl;
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