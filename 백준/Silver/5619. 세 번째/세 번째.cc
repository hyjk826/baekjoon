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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
	int n;
    cin >> n;
    priority_queue<int> pQ;
    for(int i{0}; i < n; ++i){
        int x;
        cin >> x;
        if(pQ.size() < 4) pQ.push(x);
        else{
            if(pQ.top() > x){
                pQ.pop();
                pQ.push(x);
            }
        }
    }
    vi A;
    while(!pQ.empty()){
        A.push_back(pQ.top());
        pQ.pop();
    }
    vl tmp;
    for(int i{0}; i < (int)A.size(); ++i){
        for(int j{0}; j < (int)A.size(); ++j){
            if(i == j) continue;
            tmp.push_back(stoll(to_string(A[i]) + to_string(A[j])));
        }
    }
    sort(tmp.begin(), tmp.end());
    cout << tmp[2] << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
