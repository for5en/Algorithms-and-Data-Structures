#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long

using namespace std;

struct node
{
    int num = 0;
    int numEnd = 0;
    unordered_map <char, node*> cld;
};

struct TrieTree
{
    node* root = new node;
    int prefNum = 0;

    int w_count()
    {
        return (root->num);
    }

    int w_count(string w)
    {
        node* ptr = root;
        int i = 0;
        while(i<w.length() && (ptr->cld).find(w[i]) != (ptr->cld).end())
        {
            ptr = (*(ptr->cld).find(w[i])).ss;
            i++;
        }
        if(i == w.length()) return (ptr->numEnd);
        else return 0;
    }

    int pref_count()
    {
        return prefNum;
    }

    int pref_count(string w)
    {
        node* ptr = root;
        int i = 0;
        while(i<w.length() && (ptr->cld).find(w[i]) != (ptr->cld).end())
        {
            ptr = (*(ptr->cld).find(w[i])).ss;
            i++;
        }
        if(i == w.length()) return (ptr->num);
        else return 0;
    }

    node* w_insert(string w)
    {
        node* ptr = root;
        (ptr->num)++;
        int i = 0;
        while(i<w.length() && (ptr->cld).find(w[i]) != (ptr->cld).end())
        {
            ptr = (*(ptr->cld).find(w[i])).ss;
            (ptr->num)++;
            i++;
        }
        while(i<w.length())
        {
            node* newNode = new node;
            (newNode->num)++;
            (ptr->cld).insert({w[i], newNode});
            ptr = newNode;
            prefNum++;
            i++;
        }
        (ptr->numEnd)++;
        return ptr;
    }

    void w_delete_rek(int i,string w, node* ptr)
    {
        if(i<w.length() && (ptr->cld).find(w[i]) != (ptr->cld).end())
        {
            w_delete_rek(i+1, w, (*(ptr->cld).find(w[i])).ss);
            delete ptr;
        }
    }

    void w_delete(string w)
    {
        if(this->w_count(w) == 0) return;
        node* ptr = root;
        (ptr->num)--;
        int i = 0;
        while(i<w.length() && (*(ptr->cld).find(w[i])).ss->num > 1)
        {
            ptr = (*(ptr->cld).find(w[i])).ss;
            (ptr->num)--;
            i++;
        }

        if(i<w.length())
        {
            w_delete_rek(i, w, (*(ptr->cld).find(w[i])).ss);
            (ptr->cld).erase((ptr->cld).find(w[i]));
        }
        else (ptr->numEnd)--;
    }

    list <string> suggestions_rek(string w, node* ptr)
    {
        list <string> lst;
        if(ptr->numEnd > 0) lst.push_front(w);

        auto it = (ptr->cld).begin();
        while(it != (ptr->cld).end())
        {
            lst.splice(lst.end(), suggestions_rek(w+(*it).ff, (*it).ss));
            it++;
        }
        return lst;
    }

    list <string> suggestions(string w)
    {
        node* ptr = root;
        int i = 0;
        while(i<w.length() && (ptr->cld).find(w[i]) != (ptr->cld).end())
        {
            ptr = (*(ptr->cld).find(w[i])).ss;
            i++;
        }

        list <string> lst = suggestions_rek(w, ptr);
        return lst;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    TrieTree tree;
    tree.w_insert("cat");
    tree.w_insert("cat");
    tree.w_insert("cats");

    cout << "the number of words \"cat\": " << tree.w_count("cat") << ", the number of words with \"cat\" as prefix: " << tree.pref_count("cat") << "\n";
    tree.w_delete("cat");
    cout << "the number of words \"cat\": " << tree.w_count("cat") << ", the number of words with \"cat\" as prefix: " << tree.pref_count("cat") << "\n";
    tree.w_delete("cat");
    cout << "the number of words \"cat\": " << tree.w_count("cat") << ", the number of words with \"cat\" as prefix: " << tree.pref_count("cat") << "\n";
    tree.w_delete("cats");
    cout << "the number of words \"cat\": " << tree.w_count("cat") << ", the number of words with \"cat\" as prefix: " << tree.pref_count("cat") << "\n";

    tree.w_insert("app");
    tree.w_insert("apple");
    tree.w_insert("application");
    tree.w_insert("apply");
    tree.w_insert("apps");

    cout << "\nCompletion suggestions for \"ap\":\n";
    list <string> lst = tree.suggestions("ap");
    for(auto it = lst.begin(); it != lst.end(); it++) cout << (*it) << "\n";

    cout << "\nCompletion suggestions for \"appl\":\n";
    list <string> lst2 = tree.suggestions("appl");
    for(auto it = lst2.begin(); it != lst2.end(); it++) cout << (*it) << "\n";


    return 0;
}
