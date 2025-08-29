#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    string S = "";
    stack<pair<int, string>> history; 

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) { 
            string w;
            cin >> w;
            S += w;
            history.push({1, w});
        } 
        else if (type == 2) { 
            int k;
            cin >> k;
            string deleted = S.substr(S.size() - k);
            S.erase(S.size() - k);
            history.push({2, deleted}); 
        } 
        else if (type == 3) { 
            int k;
            cin >> k;
            cout << S[k - 1] << "\n";
        } 
        else if (type == 4) { 
            if (!history.empty()) {
                auto last = history.top();
                history.pop();
                if (last.first == 1) {
                   
                    int len = last.second.size();
                    S.erase(S.size() - len);
                } else if (last.first == 2) {
                    
                    S += last.second;
                }
            }
        }
    }

    return 0;
}
