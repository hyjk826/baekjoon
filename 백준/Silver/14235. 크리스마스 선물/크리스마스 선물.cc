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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
	fastio;
	int n;
    cin >> n;
    priority_queue<int> pQ;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a == 0){
            if(pQ.empty()) cout << -1 << "\n";
            else{
                cout << pQ.top() << "\n"; pQ.pop();
            }
        }
        else{
            for(int j{0}; j < a; ++j){
                int x;
                cin >> x;
                pQ.push(x);
            }
        }
    }
}
