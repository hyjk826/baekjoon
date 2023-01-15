#include <bits/stdc++.h>
#define vi vector<int>
#define vl vector<long>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        bool ok = true;
        string str = to_string(n);
        int ans{0};
        ll sum{0};
        for(int i{0}; i < (int)str.size(); ++i){
            ok &= (str[i] == '0' || str[i] == '1');
            sum += (str[i] - '0');
        }
        if(ok){
            cout << "Hello, BOJ 2023!\n";
        }
        else{            
            vi B;
            set<int> st;
            for(int i{0}; i < (1 << ((int)str.size() - 1)); ++i){
                vi A;
                for(int j{0}; j < (int)str.size() - 1; ++j){
                    if((i >> j) & 1) A.push_back(1);
                    else A.push_back(0);
                }
                A.push_back(1);
                string s;
                int sum{0};
                for(int j{0}; j < (int)str.size(); ++j){
                    s += str[j];
                    if(A[j] == 1){
                        sum += stoi(s);
                        s.clear();
                    }
                }
                st.insert(sum);
            }
            vl vec((int)str.size(), 1);
            for(int i{1};;++i){
                ll sum = 0;
                for(int j{0}; j < (int)str.size(); ++j){
                    vec[j] *= (str[j] - '0');
                }
                for(auto& j : vec) sum += j;
                if(sum > n) break;
                if(st.count(sum)) ans++;
            }
            cout << ans << "\n";
        }
    }
}