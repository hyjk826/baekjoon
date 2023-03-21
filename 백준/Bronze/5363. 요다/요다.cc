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
    int t;
    cin >> t;
    string str; getline(cin, str);
    while(t--){
        getline(cin, str);
        stringstream ss;
        ss.str(str);
        string s;
        vs A;
        while(ss >> s){
            A.push_back(s);
        }
        for(int i{2}; i < (int)A.size(); ++i){
            cout << A[i] << " ";
        }
        cout << A[0] << " " << A[1] << "\n";
    }
}
