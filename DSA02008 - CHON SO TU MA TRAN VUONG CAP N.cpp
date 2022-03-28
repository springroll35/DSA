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
int a[maxn][maxn];
std::vector<int> x(maxn), vis(maxn, 0);
std::vector<std::vector<int> > ans;

void print() {
    int sum = 0;
    std::vector<int> tmp;
    for(int i = 0; i < n; i++) {
        sum += a[i][x[i]];
        tmp.pb(x[i]);
    }
    if(sum == k) {
        ans.pb(tmp);
    }
}

void Try(int i) {
    for(int j = 0; j < n; j++) {
        if(!vis[j]) {
            vis[j] = 1;
            x[i] = j;
            if(i == n-1) 
                print();
            else
                Try(i+1);
            vis[j] = 0;
        }
    }

}


void process() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    Try(0);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j]+1 << ' ';
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

    int test = 1;
    //cin >> test;
    while(test--) {
        process();
    }
    

    return 0;
}