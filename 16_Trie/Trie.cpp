#include "Trie.hpp"

Trie::Trie() : word_count(0) {
    root = new TrieNode;
}

void Trie::insert(const std::string& word){
    TrieNode* cur = root;

    for (char c : word) {
        int idx = letterToIndex(c);
        
        if (cur->children[i] != nullptr) {
            cur->children[i] = new TrieNode;
        }
        cur = cur->children[i];
    }
}

int Trie::letterToIndex(char c) const {
    if (c <= 'z' && c >= 'a') {
        return c - 'a';
    }
    else {
        std::throw("letterToIndex: Out of Format");
    }
}

void Trie::print() const {

}