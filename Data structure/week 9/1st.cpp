#include <bits/stdc++.h>
using namespace std;
template <class T>
class MaxHeap
{
public:
    vector<T> nodes;
    MaxHeap()
    {
    }

    void up_heapify(int idx)
    {
        while (idx < nodes.size() && nodes[idx] > nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void insert(T x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size() - 1);
    }

    void printheap()
    {
        for (int i = 0; i < nodes.size(); i++)
            cout << nodes[i] << " ";
        cout << "\n";
    }

    void downheapify(int idx)
    {
        while (1)
        {
            int largest = idx;
            int l = 2 * idx + 1;
            int r = 2 * idx + 2;
            if (l < nodes.size() && nodes[largest] < nodes[l])
                largest = l;
            if (r < nodes.size() && nodes[largest] < nodes[r])
                largest = r;
            if (largest == idx)
                break;

            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }

    void Delete(int idx)
    {
        if (idx >= nodes.size())
            return;
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        downheapify(idx);
    }

    T getMax()
    {
        return nodes[0];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    MaxHeap<int> h;
    h.insert(4);
    h.insert(20);
    h.insert(15);
    h.insert(7);
    h.insert(2);
    h.printheap();
    h.Delete(2);
    h.printheap();
    cout << h.getMax() << "\n";

    return 0;
}