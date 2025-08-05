#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    vector <int> res(26,0);
    for (int i=0;i<s.size();i++)
    {
        if(s[i] == 'a'||s[i]== 'A') res[0]++; 
        else if(s[i] == 'b'||s[i]== 'B')res[1]++;
        else if(s[i] == 'c'||s[i]== 'C') res[2]++;
        else if(s[i] == 'd'||s[i]== 'D')res[3]++;
        else if(s[i] == 'e'||s[i]== 'E')res[4]++;
        else if(s[i] == 'f'||s[i]== 'F')res[5]++;
        else if(s[i] == 'g'||s[i]== 'G')res[6]++;
        else if(s[i] == 'h'||s[i]== 'H')res[7]++;
        else if(s[i] == 'i'||s[i]== 'I')res[8]++;
        else if(s[i] == 'j'||s[i]== 'J')res[9]++;
        else if(s[i] == 'k'||s[i]== 'K')res[10]++;
        else if(s[i] == 'l'||s[i]== 'L')res[11]++;
        else if(s[i] == 'm'||s[i]== 'M')res[12]++;
        else if(s[i] == 'n'||s[i]== 'N')res[13]++;
        else if(s[i] == 'o'||s[i]== 'O')res[14]++;
        else if(s[i] == 'p'||s[i]== 'P')res[15]++;
        else if(s[i] == 'q'||s[i]== 'Q')res[16]++;
        else if(s[i] == 'r'||s[i]== 'R')res[17]++;
        else if(s[i] == 's'||s[i]== 'S')res[18]++;
        else if(s[i] == 't'||s[i]== 'T')res[19]++;
        else if(s[i] == 'u'||s[i]== 'U')res[20]++;
        else if(s[i] == 'v'||s[i]== 'V')res[21]++;
        else if(s[i] == 'w'||s[i]== 'W')res[22]++;
        else if(s[i] == 'x'||s[i]== 'X')res[23]++;
        else if(s[i] == 'y'||s[i]== 'Y')res[24]++;
        else if(s[i] == 'z'||s[i]== 'Z')res[25]++;
        else continue;
    
    }
    for(int i=0;i<res.size();i++)
    {
        if(res[i] == 0)
        {
            string s = "not pangram";
            return s;
        }
    }
 string ss="pangram";
 return ss;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
