#include <bits/stdc++.h>
using namespace std;
void sortarr(int ar[], int n)
{
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back(make_pair(ar[i], i));
    }

    sort(vp.begin(),vp.end());
        
    for (int i = 0; i < n; i++)
    {
        cout<<"Value " << vp[i].first <<",Previous Index  "<< vp[i].second << endl;
    }
}
int main()
{
    int n, ar[50];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    sortarr(ar, n);

    return 0;
}