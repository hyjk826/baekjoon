// 2022-09-10
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
    set<int> st;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        int k;
        if(str == "add"){
            cin >> k;
            st.insert(k);
        }
        else if(str == "remove"){
            cin >> k;
            if(st.count(k)) st.erase(k);
        }
        else if(str == "check"){
            cin >> k;
            if(st.count(k)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(str == "all"){
            for(int j{1}; j <= 20; ++j) st.insert(j);
        }
        else if(str == "empty"){
            st.clear();
        }
        else if(str == "toggle"){
            cin >> k;
            if(st.count(k)) st.erase(k);
            else st.insert(k);
        }
    }
}