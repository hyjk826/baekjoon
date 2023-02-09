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
    int cnt{1};
    while(cin >> str){
        if(str[0] == '-') break;
        cout << cnt << ". ";
        int ans{0};
        vi vec;
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == '{'){
                vec.push_back(1);
            }
            else if(str[i]== '}'){
                if(!vec.empty()) vec.pop_back();
                else {
                    ans++;
                    vec.push_back(1);
                }
            }
        }
        cout << ans + (int)vec.size() / 2 << "\n";
        cnt++;
    }
}
