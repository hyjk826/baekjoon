// 2022-09-13
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

struct Node {
    int x;
    Node* left;
    Node* right;
};

Node* insert(Node* node, int n) {
    if (node == NULL) {
        node = new Node();
        node->x = n;
        node->left = node->right = NULL;
    }
    else if (n <= node->x) {
        node->left = insert(node->left, n);
    }
    else {
        node->right = insert(node->right, n);
    }
    return node;
}

void post(Node* node) {
    if (node->left != NULL) {
        post(node->left);
    }
    if (node->right != NULL) {
        post(node->right);
    }
    cout << node->x << "\n";
}

int main(){
    fastio;
    int n;
    Node* root = NULL;
    while (cin >> n) {
        root = insert(root, n);
    }
    post(root);
}

