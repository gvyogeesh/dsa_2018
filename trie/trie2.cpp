/* Demonstration of trie memory optimization */

struct trie{
    bool is_end;
    map<char, trie*>my_map;
    string word;
};
