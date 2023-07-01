// Code Studio - Longest Substring Without Repeating Characters

#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithoutRepeatingCharacters(string &s)
{
    unordered_map<char, int> mp;
    int ans = 0;
    int i = 0;
    int j = 0;
    while (j < s.size())
    {
        mp[s[j]]++;
        if (mp.size() == j - i + 1)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << longestSubstringWithoutRepeatingCharacters(s) << endl;
    return 0;
}