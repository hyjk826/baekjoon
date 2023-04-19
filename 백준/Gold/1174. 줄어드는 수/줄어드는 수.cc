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
    vl vec;
    int cnt{10};
    for(int i{0}; i < 10; ++i){
        vec.push_back(i);
    }
    while(cnt){
        vl A;
        for(int i{(int)vec.size() - 1}; i >= (int)vec.size() - cnt; --i){
            for(int j{0}; j < vec[i] % 10; ++j){
                A.push_back(vec[i] * 10 + j);
            }
        }
        cnt = A.size();
        for(auto& i : A) vec.push_back(i);
    }
    sort(vec.begin(), vec.end());
    int k;
    cin >> k;
    if(k > (int)vec.size()) cout << -1;
    else cout << vec[k - 1];
}
