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
	vi vec(8);
    for(int i{0}; i < 8; ++i){
        cin >> vec[i];
    }
    if(is_sorted(vec.begin(), vec.end())) cout << "ascending";
    else if(is_sorted(vec.rbegin(), vec.rend())) cout << "descending";
    else cout << "mixed";
}