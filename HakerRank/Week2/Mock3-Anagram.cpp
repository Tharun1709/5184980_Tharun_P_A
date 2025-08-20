 /*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 int anagram(string s) {
    int n = s.size();
    if (n % 2 != 0) return -1;
    int mid = n / 2;
    string first = s.substr(0, mid);
    string second = s.substr(mid);
    
    vector<int> f1(26, 0), f2(26, 0);
    for (char c : first) f1[c - 'a']++;
    for (char c : second) f2[c - 'a']++;
    int changes = 0;
    for (int i = 0; i < 26; i++) {
        if (f1[i] > f2[i]) {
            changes += f1[i] - f2[i];  
        }
    }
    return changes;
 }