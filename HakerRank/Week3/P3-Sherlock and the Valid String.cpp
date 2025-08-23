#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

#include <bits/stdc++.h>
using namespace std;

string isValid(string s) {
    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }
    unordered_map<int, int> freqCount;
    for (auto &p : freq) {
        freqCount[p.second]++;
    }
    if (freqCount.size() == 1) {
        return "YES";
    }
   
    if (freqCount.size() > 2) {
        return "NO";
    }
    auto it = freqCount.begin();
    int f1 = it->first, c1 = it->second;
    it++;
    int f2 = it->first, c2 = it->second;

    if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) {
        return "YES";
    } 
    if ((abs(f1 - f2) == 1) && ((c1 == 1) || (c2 == 1))) {
        return "YES";
    }
    return "NO";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
