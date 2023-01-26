#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#include<cmath>
#include<iomanip>
#define mod 1000000007;
using namespace std;



int main() {
    string s1 = "abcabc";
    string s2 = "caa";
    if (s1.find(s2) != string::npos) {
        cout << "found" << endl;
    }
    else {
        cout << "not found" << endl;
    }
    return 0;
};
