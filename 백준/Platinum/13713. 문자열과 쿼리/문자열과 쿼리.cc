// 2023-01-08
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

vi Z_algorithm(string str){
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
    reverse(str.begin(), str.end());
    vi Z = Z_algorithm(str);
    reverse(Z.begin(), Z.end());
    Z.back() = (int)str.size();
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        cout << Z[a - 1] << "\n";
    }
}
