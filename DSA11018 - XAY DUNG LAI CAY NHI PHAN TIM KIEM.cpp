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

struct Node
{
    Node* pLeft;
    Node* pRight;
    int data;
    Node(int x) {
        this->data = x;
        pLeft = pRight = NULL;
    }
};

typedef Node* tree;

void add(tree& T, int x) {
    if(!T) {
        T = new Node(x);
    }
    else {
        if(x < T->data) add(T->pLeft, x);
        else add(T->pRight, x);
    }
}

void query(tree T) {
	cout << T->data << " ";
	if(T->pLeft) query(T->pLeft);
	if (T->pRight) query(T->pRight);
}

void process() {
    int n;
    cin >> n;
    tree t = NULL;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(t, x);
    }
    query(t);
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