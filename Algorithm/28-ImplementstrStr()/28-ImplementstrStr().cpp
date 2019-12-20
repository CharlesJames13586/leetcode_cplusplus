#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr_KMP(string haystack, string needle) {
        int lenNeedle = needle.length();
        if (lenNeedle == 0)
            return 0;
        int*next = new int[lenNeedle];
        this->Next(needle, next);
        int lenHaystack = haystack.length();
        int i = 0, j = 0;
        while (i < lenHaystack && j < lenNeedle) {
            if (j == -1 || haystack[i] == needle[j]) {
                j++;
                i++;
            }
            else {
                j = next[j];
            }
        }
        delete next;
        if ( j==lenNeedle) {
            return i-j;
        }
        else {
            return -1;
        }
    }
private:
    void Next(string needle, int*next) {
        int len = needle.length();
        int k = -1, j = 0;
        next[0] = -1;
        while (j < len-1) {
            if (k == -1 || needle[j] == needle[k]) {
                j++;
                k++;
                cout << j << " " << k << endl;
                next[j] = k;
            }
            else {
                k = next[k];
            }
        }
    }
};
/*
int main() {
    Solution solution;
    string haystack, needle;
    while (true) {
        cin >> haystack;
        if (haystack._Equal("#"))
            break;
        cin >> needle;
        cout<<solution.strStr_KMP(haystack, needle)<<endl;
    }
    

    return 0;
}
*/
/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/