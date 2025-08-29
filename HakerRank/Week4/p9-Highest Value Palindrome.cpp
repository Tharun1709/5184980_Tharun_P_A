#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


string highestValuePalindrome(string s, int n, int k) {
    vector<bool> changed(n, false);
    int used = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            if (s[i] > s[n - 1 - i]) {
                s[n - 1 - i] = s[i];
            } else {
                s[i] = s[n - 1 - i];
            }
            changed[i] = true;  
            used++;
        }
    }
    if (used > k) return "-1"; 
    int remaining = k - used;
    for (int i = 0; i < n / 2 && remaining > 0; i++) {
        if (s[i] != '9') {
            if (changed[i] && remaining >= 1) {
                s[i] = s[n - 1 - i] = '9';
                remaining--;
            } else if (!changed[i] && remaining >= 2) {
                s[i] = s[n - 1 - i] = '9';
                remaining -= 2;
            }
        }
    }
      if (n % 2 == 1 && remaining > 0) {
        s[n / 2] = '9';
    }

    return s;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
