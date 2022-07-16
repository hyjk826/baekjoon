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
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        stack<char> A, B;
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == '<'){
                if(!A.empty()){
                    B.push(A.top());
                    A.pop();
                }
            }
            else if(str[i] == '>'){
                if(!B.empty()) {
                    A.push(B.top());
                    B.pop();
                }
            }
            else if(str[i] == '-'){
                if(!A.empty()) A.pop();
            }
            else{
                A.push(str[i]);
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
        cout << "\n";
    }
}
