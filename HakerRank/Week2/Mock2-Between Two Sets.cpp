/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */
 #include <bits/stdc++.h>
 using namespace std;
 int gcd(int a, int b) {
    while(b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
 }
 int lcm(int a, int b) {
    return a / gcd(a, b) * b;
 }
 int getTotalX(vector<int> a, vector<int> b) {
    
    int l = a[0];
    for(int i = 1; i < a.size(); i++) {
        l = lcm(l, a[i]);
    }
    
    int g = b[0];
    for(int i = 1; i < b.size(); i++) {
        g = gcd(g, b[i]);
    }
    
    int count = 0;
    for(int x = l; x <= g; x += l) {
        if(g % x == 0) count++;
    }
    return count;
 }