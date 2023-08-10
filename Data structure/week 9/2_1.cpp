#include <bits/stdc++.h>
using namespace std;
void printfrequency(vector<int> v)
{
    map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        // we check if the  is the element in map or not
        //  if don't found insert that and set frequency to 1
        if (m.find(v[i]) == m.end())
            m[v[i]] = 1;

        // otherwise when condition is unmatched then we are sure the element is there
        // so we can increment the frequency
        else
            m[v[i]]++;
    }

    for (auto it : m)
    {
        cout << it.first << ": ";
        cout << it.second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    printfrequency(vec);

    return 0;
}