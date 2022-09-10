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
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int n;
        cin >> n;
        string s;
        cin >> s;
        s.pop_back();
        s += ',';
        deque<int> dQ;
        string t;
        for(int i{1}; i < (int)s.size(); ++i){
            if(s[i] == ','){
                if(t.size() == 0) break;
                dQ.push_back(stoi(t));
                t.clear();
            }
            else t += s[i];
        }
        int cnt{0};
        bool flag = true;
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == 'R') cnt++;
            else{
                if(cnt % 2 == 0){
                    if(dQ.empty()){
                        flag = false;
                        break;
                    }
                    else{
                        dQ.pop_front();
                    }
                }
                else{
                    if(dQ.empty()){
                        flag = false;
                        break;
                    }
                    else{
                        dQ.pop_back();
                    }
                }
            }
        }
        vi ans;
        while(!dQ.empty()){
            ans.push_back(dQ.front());
            dQ.pop_front();
        }
        if(cnt & 1) reverse(ans.begin(), ans.end());
        if(!flag) cout << "error\n";
        else{
            cout << "[";
            for(int i{0}; i < (int)ans.size(); ++i){
                cout << ans[i];
                if(i < (int)ans.size() - 1){
                    cout << ",";
                }
            }
            cout << "]\n";
        }
    }
}