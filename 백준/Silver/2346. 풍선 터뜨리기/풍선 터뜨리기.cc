// 2022-07-28
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

int main() {
	fastio;
    int n;
    cin >> n;
    deque<pi> dQ;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        dQ.push_back({i + 1, a});
    }
    while(!dQ.empty()){
        cout << dQ.front().first << " ";
        int k = dQ.front().second;
        dQ.pop_front();
        if(dQ.empty()) break;
        if(k > 0){
            for(int i{0}; i < k - 1; ++i){
                dQ.push_back(dQ.front());
                dQ.pop_front();
            }
        }
        else{
            for(int i{0}; i < -k; ++i){
                dQ.push_front(dQ.back());
                dQ.pop_back();
            }
        }
    }
}

