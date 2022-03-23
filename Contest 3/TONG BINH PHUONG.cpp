#include<bits/stdc++.h>

using namespace std;

#define fi "inp.inp"
#define fo "out.out"
#define ll long long
#define fr first
#define sc second

typedef pair<int,int> ii;

const int maxn=1e4+5;
const ll mod = 1e9+7;;

int n;
vector<int> dp(maxn,1e9);

void init() {
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=10000;i++) {
        int k=(i+1) >> 1;
        int x=sqrt(i);
        if (x*x == i) dp[i]=1;
        else {
            for(int j=1;j<=k;j++) dp[i]=min(dp[i],dp[j]+dp[i-j]);
        }
    }
}

void  process(){
    cin >> n;
    cout << dp[n] << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    init();
    int test;
    cin >> test;
    while (test--) {
        process();
    }


    return 0;
}




