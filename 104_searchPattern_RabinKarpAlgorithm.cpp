// Code Studio - Search Pattern (Rabin-Karp Algorithm)

#include <bits/stdc++.h>
using namespace std;

vector<int> stringMatch(string text, string pattern)
{
    vector<int> positions;
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++)
    {
        bool match = true;
        for (int j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                match = false;
                break;
            }
        }

        if (match)
            positions.push_back(i + 1);
    }
    return positions;
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;

    vector<int> positions = stringMatch(text, pattern);

    if (positions.size() == 0)
        cout << "Pattern not found";
    else
    {
        cout << "Pattern found at positions: ";
        for (int i = 0; i < positions.size(); i++)
            cout << positions[i] << " ";
    }
    return 0;
}