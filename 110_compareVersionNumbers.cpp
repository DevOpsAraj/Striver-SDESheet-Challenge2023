// Code Studio - Compare Version Numbers

#include <bits/stdc++.h>
using namespace std;

int compareVersions(string a, string b)
{
    int i = 0, j = 0;

    while (i < a.size() || j < b.size())
    {

        long xCor = 0, yCor = 0;

        while (i < a.size() && a[i] != '.')
            xCor = xCor * 10 + (a[i++] - '0');

        while (j < b.size() && b[j] != '.')
            yCor = yCor * 10 + (b[j++] - '0');

        if (xCor > yCor)
            return 1;

        else if (xCor < yCor)
            return -1;

        i++;
        j++;
    }

    return 0;
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << compareVersions(a, b) << endl;

    return 0;
}