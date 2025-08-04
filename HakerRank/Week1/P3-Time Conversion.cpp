#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
     if(s[8]== 'P'){
        string s1;
        s1=s.substr(0,2);
        int a;
        a = stoi(s1);
        if(a==12)
        {
            return s= s.substr(0,8);
        }
        else{
            a+=12;
            string s3;
            s3= to_string(a);
            s3+=s.substr(2,6);
            return s3;
        }
        
     } 
     else{
        string s4;
        s4=s.substr(0,2);
        int b;
        b = stoi(s4);
        if(b==12)
        {   
            string s5="00";
            s5+= s.substr(2,6);
            return s5;
        }
        else{
            return s.substr(0,8);
        }
     }
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
