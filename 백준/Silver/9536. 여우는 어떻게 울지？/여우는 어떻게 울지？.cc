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
	int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string str;
        getline(cin, str);
        string s;
        set<string> st;
        while(getline(cin, s)){
            if(s == "what does the fox say?"){
                break;
            }
            for(int i{(int)s.size() - 1}; i >= 0; --i){
                if(s[i] == ' '){
                    st.insert(s.substr(i + 1));
                    break;
                }
            }
        }
        stringstream ss;
        ss.str(str);
        string t;
        while(ss >> t){
            if(st.count(t)) continue;
            cout <<t << " ";
        }
        cout << "\n";
    }
}