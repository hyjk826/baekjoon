// 2022-08-19
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
	int n;
    cin >> n;
    map<string, int> mp;
    for(int i{0}; i < 2 * n - 1; ++i){
        string str;
        cin >> str;
        mp[str]++;
    }
    for(auto& i : mp){
        if(i.second & 1){
            cout << i.first;
            return 0;
        }
    }
}