#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
   cin>>arr[i];
    }
    map<int, int> indexMap;

    for (int i = 0; i < arr.size(); ++i)
    {
        if (indexMap.find(arr[i]) != indexMap.end())
        {

            cout << "First duplicate element: " << arr[i] << ", Index: " << indexMap[arr[i]] <<endl;
            break;
        }
        else
        {

            indexMap[arr[i]] = i;
        }
    }

    return 0;
}
