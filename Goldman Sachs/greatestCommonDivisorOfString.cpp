#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int gcd(int a, int b)
    {

        if (a == 0)
            return b;

        return gcd(b % a, a);
    }
    string gcdOfStrings(string str1, string str2)
    {

        // Two strings have a gcd string
        // iff str1+str2 == str2 + str1
        if ((str1 + str2) != (str2 + str1))
            return "";

        int m = str1.length();
        int n = str2.length();

        return str1.substr(0, gcd(m, n));
    }
};
