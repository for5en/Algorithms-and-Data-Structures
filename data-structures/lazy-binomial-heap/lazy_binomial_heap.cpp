#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

struct node
{
    int val;
    int rnk = 0;
    struct node* par = NULL;
    list <node*> :: iterator itl;
    list <node*> cld;
};

struct LazyBinomialHeap
{
    list <node*> heap;
    node* minptr = NULL;

    node* join(node* x, node* y)
    {
        if((x->val) > (y->val)) swap(x, y);
        (x->cld).push_back(y);
        y->par = x;
        (x->rnk)++;
        return x;
    }

    node* lazy_insert(int val)
    {
        struct node* x = new struct node;
        (x->val) = val;
        heap.push_front(x);

        x->itl = heap.begin();
        if(minptr == NULL || x->val < minptr->val) minptr = x;

        return x;
    }

    void lazy_meld(list <node*> heap2)
    {
        if(heap2.empty()) return;
        list <node*> :: iterator jt = heap2.begin();
        while(jt != heap2.end())
        {
            heap.push_front(*jt);
            (*jt)->itl = heap.begin();

            if(((*jt)->val) < (minptr->val)) minptr = *jt;
            jt++;
        }
    }

    void lazy_merge()
    {
        if(heap.empty()) return;

        int n = max(heap.back()->rnk, (int)log(heap.size()));
        vector <node*> bkt[n+5];
        list <node*> :: iterator it;
        it = heap.begin();

        minptr = NULL;

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
                bkt[i][0]->itl = heap.begin();

                if(minptr == NULL) minptr = bkt[i][0];
                else if((bkt[i][0]->val) < (minptr->val)) minptr = bkt[i][0];
            }
        }
    }

    int extract_min()
    {
        if(heap.empty()) return INT_MAX;

        if(minptr != NULL) return (minptr->val);
        else return INT_MAX;
    }

    void decrease_key(node* x, int val)
    {
        x->val -= val;
        while(x->par != NULL && x->par->val > x->val)
        {
            swap(x->val, x->par->val);
            swap(x->itl, x->par->itl);
            x = x->par;
        }
        if(x->val < minptr->val) minptr = x;
    }

    void deletemin()
    {
        if(heap.empty()) return;

        node* temp = minptr;
        heap.erase(minptr->itl);
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

    node* x = heapA.lazy_insert(100);
    heapA.decrease_key(x, 110);

    for(int i=1; i<=16; i++)
    {
        heapA.print();
        cout << heapA.extract_min() << "\n";
        heapA.deletemin();
    }



    return 0;
}
