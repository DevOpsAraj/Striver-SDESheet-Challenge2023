// Code Studio - Find Pattern in String - KMP Algorithm

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the Longest Proper Prefix which is also a Suffix (LPS)
// for pattern 'p'
void lps(string p, vector<int> &temp)
{
    temp[0] = 0; // LPS of the first character is always 0
    int i = 0;   // i tracks the length of the previous longest prefix suffix
    int j = 1;   // j tracks the index of the current character being processed

    // Loop through the pattern to fill the LPS array
    while (j < temp.size())
    {
        if (p[i] == p[j])
        {
            i++;
            temp[j] = i; // LPS for the current character is the length of the
                         // previous longest prefix suffix + 1
            j++;
        }
        else
        {
            if (i != 0)
                i = temp[i - 1]; // If there is a mismatch, move 'i' to the previous
                                 // longest prefix suffix and continue comparing
            else
            {
                temp[j] = 0; // If 'i' is already at 0, set LPS for the current
                             // character as 0 and move to the next character
                j++;
            }
        }
    }
}

// Function to find pattern 'p' in string 's'
bool findPattern(string p, string s)
{
    int n = p.size(); // Length of the pattern
    int m = s.size(); // Length of the string

    vector<int> temp(
        n);       // Create an array to store the LPS values for the pattern
    lps(p, temp); // Calculate the LPS array for the pattern

    int i = 0; // i tracks the index of the current character in the pattern
    int j = 0; // j tracks the index of the current character in the string

    // Loop through the string to find the pattern
    while (j < m)
    {
        if (s[j] == p[i]) // If the characters match
        {
            i++;
            j++;
        }

        if (i ==
            n) // If all characters of the pattern have been matched, pattern found
            return true;
        else if (j < m && s[j] != p[i]) // If characters don't match
        {
            if (i != 0)
                i = temp[i - 1]; // Move 'i' to the previous longest prefix suffix and
                                 // continue comparing
            else
                j++; // If 'i' is already at 0, move to the next character in the string
        }
    }

    return false; // Pattern not found in the string
}

int main()
{
    string s, p;
    cin >> s >> p;

    if (findPattern(p, s))
        cout << "Pattern found in the string";
    else
        cout << "Pattern not found in the string";

    return 0;
}