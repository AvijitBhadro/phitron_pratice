#include <bits/stdc++.h>
using namespace std;

void removeduplicates(vector<int> v)
{
    set<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        st.insert(v[i]);
    }
    for (auto a : st)
    {
        cout << a << " ";
    }
    cout << "\n";
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
    removeduplicates(vec);

    return 0;
}