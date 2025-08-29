#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <bits/stdc++.h>
int main() {
    int q;
    cin >> q;

    stack<int> stack_in, stack_out;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            stack_in.push(x);
        } 
        else if (type == 2) {
                       if (stack_out.empty()) {
                while (!stack_in.empty()) {
                    stack_out.push(stack_in.top());
                    stack_in.pop();
                }
            }
            if (!stack_out.empty()) {
                stack_out.pop();
            }
        } 
        else if (type == 3) {
                    if (stack_out.empty()) {
                while (!stack_in.empty()) {
                    stack_out.push(stack_in.top());
                    stack_in.pop();
                }
            }
            if (!stack_out.empty()) {
                cout << stack_out.top() << "\n";
            }
        }
    }
    return 0;
}

