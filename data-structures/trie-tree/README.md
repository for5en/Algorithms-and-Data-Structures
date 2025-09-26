# Trie Tree
Implementation of Trie Tree data structure with the following operations:
- `int w_count()` – returns the number of words in the tree.
- `int w_count(string w)` – returns the number of words w in the tree.
- `int pref_count()` – returns the number of prefixes in the tree.
- `int pref_count(string w)` – returns the number of prefixes w in the tree.
- `node* w_insert(string w)` – inserts new word w into the tree and returns its pointer.
- `void w_delete(string w)` - deletes word w from the tree.
- `list <string> suggestions(string w)` - returns list of strings with completion suggestions for word w.