// space is O(1)
void printDuplicates(string &S) {
    int counts[26] = { 0 };

    for (int i = 0; i < S.size(); i++) {
        counts[S[i] - 'a'] += 1;
    }
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 1) {
            cout << (char)(i + 'a') << " " << counts[i] << endl;
        }
    }
}
