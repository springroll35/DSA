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

void add(tree& T, int u, int v, char c) {
    if(!T) {
        T = new Node(u);
        tree p = new Node(v);
        if(c == 'L') T->pLeft = p;
        else T->pRight = p;
    }
    else {
        if(T->data == u) {
            tree p = new Node(v);
            if(c == 'L') T->pLeft = p;
            else T->pRight = p;
        }
        else {
            if(T->pLeft) add(T->pLeft, u, v, c);
            if(T->pRight) add(T->pRight, u, v, c);
        }
    }
}

void query(tree T) {
    if (!T) return;
	stack<tree> st1, st2;
	st1.push(T);
	while (st1.size() || st2.size()) {
		while (st1.size()) {
			tree tmp = st1.top();
			st1.pop();
			cout << tmp->data << ' ';
			if (tmp->pRight) st2.push(tmp->pRight);
			if (tmp->pLeft) st2.push(tmp->pLeft);
		}
		while (st2.size()) {
			tree tmp = st2.top();
			st2.pop();
			cout << tmp->data << ' ';
			if (tmp->pLeft) st1.push(tmp->pLeft);
			if (tmp->pRight) st1.push(tmp->pRight);
		}
	}
}

void process() {
    int n;
    cin >> n;
    tree t = NULL;
    while(n--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        add(t, u, v, c);
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