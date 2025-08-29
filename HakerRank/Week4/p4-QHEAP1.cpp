#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    set<int> heap;  

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            heap.insert(x);
        } 
        else if (type == 2) {
            int x;
            cin >> x;
            heap.erase(x);  
        } 
        else if (type == 3) {
            cout << *heap.begin() << "\n";  
        }
    }

    return 0;
}
