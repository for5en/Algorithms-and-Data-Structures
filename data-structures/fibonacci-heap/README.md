# Fibonacci Heap
Implementation of Fibonacci Heap data structure with the following operations:
- `node* join(node* x, node* y)` – joins two fibonacci trees of the same rank.
- `node* lazy_insert(int val)` – inserts a new node into the heap and returns its pointer.
- `void lazy_meld(list<node*> heap2)` – adds a list of nodes (another heap) into the current heap.
- `void lazy_merge()` – merges all fibonacci trees so that ranks remain unique, ensuring the heap size is O(log(#nodes)).
- `int extract_min()` – returns the minimum value in the heap, if the heap is empty it returns value INT_MAX.
- `void cut(node* x)` - cuts node x from its parent into root list.
- `void decrease_key(node* x, int val)` - decreases value of node x by val.
- `void deletemin()` – deletes the minimum value from the heap.
- `void print()` – prints the first-level nodes of the heap in the format: `#rank1,#value1 #rank2,#value2 ...`.