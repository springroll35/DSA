#include<bits/stdc++.h>

using namespace std;

#define fi "inp.inp"
#define ll long long
#define fr first
#define sc second

typedef pair<int,int> ii;

const int maxn=1e5+5;
const ll mod = 1e9+7;


void  process(){
    string s,s1;
    getline(cin,s);
    vector<string> v;
    v.clear();
    stringstream ss(s);
    while(ss >> s1) {
        v.push_back(s1);
    }
    reverse(v.begin(),v.end());
    for(auto x : v) cout << x << " ";
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen(fi,"r",stdin);
    int test;
    cin >> test;
    cin.ignore();
    while (test--) {
        process();
    }


    return 0;
}





