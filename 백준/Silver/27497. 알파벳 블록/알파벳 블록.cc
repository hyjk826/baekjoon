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
    vp vec;
    for(int i{0}; i < n; ++i){
        int op;
        char c;
        cin >> op;
        if(op == 1 || op == 2){
            cin >> c;
            vec.push_back({op, c - 'a'});
        }
        else{
            if(!vec.empty()) vec.pop_back();
        }
    }
    deque<int> dQ;
    for(int i{0}; i < (int)vec.size(); ++i){
        if(vec[i].first == 1) dQ.push_back(vec[i].second);
        else dQ.push_front(vec[i].second);
    }
    for(auto& i : dQ){
        cout << char('a' + i);
    }
    if(dQ.empty()) cout << 0;
}
