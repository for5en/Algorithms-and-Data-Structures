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
    bool del = 0;
    struct node* par = NULL;
    list <node*> :: iterator itl;
    list <node*> cld;
};

struct FibonacciHeap
{
    list <node*> heap;
    node* minptr = NULL;

    node* join(node* x, node* y)
    {
        if((x->val) > (y->val)) swap(x, y);
        (x->cld).push_front(y);
        y->itl = (x->cld).begin();
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

    void cut(node* x)
    {
        x->del = 0;

        if(x->par == NULL)
        {
            x->rnk = (x->cld).size();
            return;
        }

        (x->par->cld).erase(x->itl);
        node* temp = x->par;
        x->par = NULL;
        heap.push_front(x);
        x->itl = heap.begin();
        x->rnk = (x->cld).size();

        if(temp->del == 0) temp->del = 1;
        else
        {
            cut(temp);
        }
    }

    void decrease_key(node* x, int val)
    {
        x->val -= val;
        if(x->val < minptr->val) minptr = x;
        cut(x);
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

    FibonacciHeap heapA;
    node* nodes[15];

    for(int i=1; i<=12; i++)
    {
        nodes[i] = heapA.lazy_insert(i);
    }

    cout << "heap: ";
    heapA.print();
    cout << "min: " << heapA.extract_min() << "\n";
    heapA.deletemin();
    cout << "heap: ";
    heapA.print();
    cout << "min: " << heapA.extract_min() << "\n";

    heapA.decrease_key(nodes[8], 10);
    cout << "heap: ";
    heapA.print();
    cout << "min: " << heapA.extract_min() << "\n";
    heapA.decrease_key(nodes[6], 10);
    cout << "heap: ";
    heapA.print();
    cout << "min: " << heapA.extract_min() << "\n\n";

    for(int i=1; i<=12; i++)
    {
        cout << "heap: ";
        heapA.print();
        cout << "min: " << heapA.extract_min() << "\n";
        heapA.deletemin();
    }


    return 0;
}
