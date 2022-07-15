// 2022-07-16
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
	string str;
    cin >> str;
    int n;
    cin >> n;
    stack<char> A, B;
    for(int i{0}; i < (int)str.size(); ++i){
        A.push(str[i]);
    }
    for(int i{0}; i < n; ++i){
        char q;
        cin >> q;
        if(q == 'L'){
            if(!A.empty()){
                B.push(A.top());
                A.pop();
            }
        }
        else if(q == 'D'){
            if(!B.empty()){
                A.push(B.top());
                B.pop();
            }
        }
        else if(q == 'B'){
            if(!A.empty()) A.pop();
        }
        else{
            char c;
            cin >> c;
            A.push(c);
        }
    }
    while(!A.empty()){
        B.push(A.top());
        A.pop();
    }
    while(!B.empty()){
        cout << B.top();
        B.pop();
    }
}
