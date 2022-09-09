// 2022-09-09
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n, k;
    cin >> n >> k;
    deque<int> dQ;
    for(int i{1}; i <= n; ++i){
        dQ.push_back(i);
    }
    vi ans;
    while(!dQ.empty()){
        for(int i{0}; i < k - 1; ++i){
            int a = dQ.front();
            dQ.pop_front();
            dQ.push_back(a);
        }
        ans.push_back(dQ.front());
        dQ.pop_front();
    }
    cout << "<";
    for(int i{0}; i < n; ++i){
        cout << ans[i];
        if(i < n - 1) cout << ", ";
        else cout << ">";
    }
}