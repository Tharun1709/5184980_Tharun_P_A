/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 int palindromeIndex(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] == s[j]) {
            i++; j--;
        } else {
           
            int a = i, b = j-1;
            while (a < b && s[a] == s[b]) { a++; b--; }
            if (a >= b) return j;
            a = i+1; b = j;
            while (a < b && s[a] == s[b]) { a++; b--; }
            if (a >= b) return i;
            return -1;
        }
    }
    return -1; 
}