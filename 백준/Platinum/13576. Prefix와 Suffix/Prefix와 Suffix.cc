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

vi Z_algorithm(string& str){
    int l{0}, r{0};
    vi z((int)str.size());
    for(int i{1}; i < (int)str.size(); ++i){
        if(i > r){
            l = r = i;
            while(r < (int)str.size() && str[r - l] == str[r]) r++;
            z[i] = r - l; r--;
        }
        else{
            int k = i - l;
            if(z[k] < r - i + 1) z[i] = z[k];
            else{
                l = i;
                while(r < (int)str.size() && str[r - l] == str[r]) r++;
                z[i] = r - l; r--;
            }
        }
    }
    return z;
}

int main(){
	fastio;
	string str;
	cin >> str;
	vi Z = Z_algorithm(str);
	vp ans;
	vi A;
	Z[0] = (int)str.size();
	for(int i{0}; i < (int)Z.size(); ++i){
		if(i + Z[i] == (int)str.size()){
			ans.push_back({Z[i], 0});
		}
	}
	sort(Z.begin(), Z.end());
	for(auto& i : ans){
		i.second = Z.end() - lower_bound(Z.begin(), Z.end(), i.first);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(auto& i : ans) cout << i.first << " " << i.second << "\n";
}
