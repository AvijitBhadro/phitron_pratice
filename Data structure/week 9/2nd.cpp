#include<bits/stdc++.h>
using namespace std;
template<class T>
class minheap{
    public:
vector<T> nodes;
minheap()
{

}
void up_heapify(int idx)
{
    while(idx<nodes.size() && nodes[idx]<nodes[(idx-1)/2])
    {
        swap(nodes[idx],nodes[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}
void insert(T value)
{
    nodes.push_back(value);
    up_heapify(nodes.size()-1);
}

void printheap()
{
    if(nodes.empty()) return;
    for(int i=0;i<nodes.size();i++)
    cout<<nodes[i]<<" ";

    printf("\n");
}
void downheapify(int idx)
{
    while(1)
    {
    int smallest = idx;
    int l = 2*idx + 1;
    int r = 2*idx +2;
     if(l<nodes.size() && nodes[smallest]>nodes[l])
     smallest = l;
     if(r<nodes.size() && nodes[smallest] > nodes[r])
     smallest = r;
     if(smallest == idx) break;

     swap(nodes[smallest],nodes[idx]);
     idx = smallest;

    }
    
}
void Delete(int idx)
{
    if(idx>=nodes.size()) return;
    swap(nodes[idx],nodes[nodes.size()-1]);
    nodes.pop_back();
    downheapify(idx);
}

T mn()
{
    return nodes[0];
}
T minextract()
{
    if(nodes.empty())
    {
        cout<<"Heap is empty"<<"\n";
        return -1;
    }
    T min = nodes[0];
    Delete(0);
    return min;
}

};

int main()
{
minheap<int> min;
min.insert(20);
min.insert(10);
min.insert(30);
min.insert(50);
min.insert(70);
min.insert(80);
min.insert(40);



cout<<"Minimum: "<<min.mn()<<"\n";
cout<<"minextract: "<<min.minextract()<<"\n";
min.printheap();


}
