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
	int t;
    cin >> t;
    vi vec;
    while(t--){
        string str;
        cin >> str;
        int k;
        if(str == "push"){
            cin >> k;
            vec.push_back(k);
        }
        else if(str == "pop"){
            if(vec.empty()) cout << -1 << "\n";
            else{
                cout << vec.back() << "\n";
                vec.pop_back();
            }
        }
        else if(str == "size"){
            cout << vec.size() << "\n";
        }
        else if(str == "top"){
            if(vec.empty()) cout << -1 << "\n";
            else cout << vec.back() << "\n";
        }
        else if(str == "empty"){
            if(vec.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}