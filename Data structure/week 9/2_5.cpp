#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    set<int> s1;
    set<int> intersection;

    cin >> n;
    vector<int> ar1(n);
    for (int i = 0; i < n; i++)
        cin >> ar1[i];
    cin >> m;
    vector<int> ar2(m);
    for (int i = 0; i < n; i++)
        cin >> ar2[i];
    for (int i = 0; i < n; i++)
    {
        s1.insert(ar1[i]);
    }

    for (int x : ar2)
    {
        if (s1.count(x) > 0)
        {
            intersection.insert(x);
        }
    }

    for (int z : intersection)
        cout << z << " ";
    cout << "\n";

    return 0;
}
