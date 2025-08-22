#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


vector<string> detonate(vector<string> grid, int R, int C) {
    vector<string> result(R, string(C, 'O'));
    vector<vector<int>> dirs = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'O') {
                for (auto &d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
                        result[ni][nj] = '.';
                    }
                }
            }
        }
    }
    return result;
}

vector<string> bomberMan(int n, vector<string> grid) {
    int R = grid.size();
    int C = grid[0].size();
    
    if (n == 1) return grid;
    if (n % 2 == 0) return vector<string>(R, string(C, 'O'));

    
    vector<string> first = detonate(grid, R, C);
    
    vector<string> second = detonate(first, R, C);

    if (n % 4 == 3) return first;
    return second;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

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
