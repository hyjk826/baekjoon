// 2023-01-18
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
    string str;
    cin >> str;
    vp vec;
    vi A;
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == '(') A.push_back(i);
        else if(str[i] == ')'){
            vec.push_back({A.back(), i});
            A.pop_back();
        }
    }
    vs ans;
    for(int i{1}; i < (1 << (int)vec.size()); ++i){
        vi ch((int)str.size());
        for(int j{0}; j < (int)vec.size(); ++j){
            if((i >> j) & 1){
                ch[vec[j].first] = ch[vec[j].second] = 1;
            }
        }
        string s;
        for(int j{0}; j < (int)str.size(); ++j){
            if(ch[j]) continue;
            s += str[j];
        }
        ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(auto& i : ans) cout << i << "\n";
}
