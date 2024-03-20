void computeLPSArray(string pattern, int lps[]) {
    int len = 0;
    int i = 1;
    int m = pattern.length();
    lps[0] = 0;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
