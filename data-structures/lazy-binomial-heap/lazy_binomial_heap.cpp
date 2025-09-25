#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

int my_log(int x)
{
    int i = 0;
    while(x > 0)
    {
        x /= 2;
        i++;
    }
    return i;
}

struct node
{
    int val;
    int rnk = 0;
    struct node* par = NULL;
    list <node*> cld;
};

struct LazyBinomialHeap
{
    list <node*> heap;
    list <node*> :: iterator minit = heap.end();

    node* join(node* x, node* y)
    {
        if((x->val) > (y->val)) swap(x, y);
        (x->cld).push_back(y);
        (x->rnk)++;
        return x;
    }

    void lazy_insert(int val)
    {
        struct node* x = new struct node;
        (x->val) = val;
        heap.push_front(x);
        if(minit == heap.end()) minit = heap.begin();
        else if(val < (**minit).val) minit = heap.begin();
    }

    void lazy_meld(list <node*> heap2)
    {
        if(heap2.empty()) return;
        list <node*> :: iterator jt = heap2.begin();
        while(jt != heap2.end())
        {
            heap.push_front(*jt);
            if(((*jt)->val) < (**minit).val) minit = heap.begin();
            jt++;
        }
    }

    void lazy_merge()
    {
        if(heap.empty()) return;

        int n = max(heap.back()->rnk, my_log(heap.size()));
        vector <node*> bkt[n+5];
        list <node*> :: iterator it;
        it = heap.begin();
        minit = heap.end();
        while(it != heap.end())
        {
            bkt[(*it)->rnk].pb(*it);
            it++;
        }
        node* tmp;
        heap.clear();
        for(int i=0; i<=n+3; i++)
        {
            while(bkt[i].size() >= 2)
            {
                tmp = join(bkt[i][bkt[i].size()-1], bkt[i][bkt[i].size()-2]);
                bkt[i+1].pb(tmp);
                bkt[i].pop_back();
                bkt[i].pop_back();
            }
            if(bkt[i].size() > 0)
            {
                heap.push_front(bkt[i][0]);
                if(minit == heap.end()) minit = heap.begin();
                else if((bkt[i][0]->val) < (**minit).val) minit = heap.begin();
            }
        }
    }

    int extract_min()
    {
        if(heap.empty()) return INT_MAX;

        if(minit != heap.end()) return (**minit).val;
        else return INT_MAX;
    }

    void deletemin()
    {
        if(heap.empty()) return;

        node* temp = (*minit);
        heap.erase(minit);
        this->lazy_meld(temp->cld);
        this->lazy_merge();
    }

    void print()
    {
        if(heap.empty())
        {
            cout << "Heap empty!\n";
            return;
        }

        list <node*> :: iterator it = heap.begin();
        while(it != heap.end())
        {
            cout << ((*it)->rnk) << "," << ((*it)->val) << " ";
            it++;
        }
        cout << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LazyBinomialHeap heapA;

    for(int i=1; i<=14; i++)
    {
        heapA.lazy_insert(i);
    }

    for(int i=1; i<=14; i++)
    {
        heapA.print();
        cout << heapA.extract_min() << "\n";
        heapA.deletemin();
    }



    return 0;
}
