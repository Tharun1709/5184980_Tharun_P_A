#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> generatePrimes(int limit) {
    vector<int> primes;
    int num = 2;
    while (primes.size() < limit) {
        bool isPrime = true;
        for (int p : primes) {
            if (1LL * p * p > num) break;
            if (num % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(num);
        num++;
    }
    return primes;
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> result;
    vector<int> primes = generatePrimes(q);

    stack<int> A, B;
    for (int x : number) {
        A.push(x);
    }
    for (int i = 0; i < q; i++) {
        stack<int> nextA;
        int prime = primes[i];
        while (!A.empty()) {
            int val = A.top();
            A.pop();
            if (val % prime == 0) {
                B.push(val);
            } else {
                nextA.push(val);
            }
        }
        while (!B.empty()) {
            result.push_back(B.top());
            B.pop();
        }
        A = nextA;
    }
    while (!A.empty()) {
        result.push_back(A.top());
        A.pop();
    }

    return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
