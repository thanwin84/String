bool are_rotated(string a, string b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        a += a[i];
        if (a.substr(i).compare(b)) {
            return true;
        }
    }
    return true;
}
//time: O(n^3) and space: O(n)
