#include<bits/stdc++.h>
using namespace std;

class StreamChecker {
public:

    class Trie{
    public:
        bool isWordEnd;
        Trie* children[26];
        Trie(){
            this->isWordEnd = false;
            for(int i=0; i<26; i++){
                this->children[i] = nullptr;
            }
        }

        void insertWord(string word){
            reverse(word.begin(), word.end());
            Trie* node = this;
            for(int i=0; i<word.size(); i++){
                int indexOfChar = word[i];
                if(node->children[indexOfChar] == nullptr)
                    node->children[indexOfChar] = new Trie();
                node = node->children[indexOfChar];
            }
            node->isWordEnd = true;
        }

    };
    Trie trie;
    vector<char> queries;
    int maxLength=0;

    StreamChecker(vector<string>& words) {
        for(auto word:words){
            trie.insertWord(word);
            maxLength = max(maxLength, (int)word.size());
        }        
    }
    
    bool query(char letter) {
        queries.insert(queries.begin(), letter);

        if(queries.size() > maxLength)
            queries.pop_back();
        Trie* curTrie = &trie;
        for(auto it = queries.begin(); it != queries.end(); ++it){
            if(curTrie->isWordEnd)
                return true;
            if(curTrie->children[*it-'a'] == nullptr)
                return false;
            curTrie = curTrie->children[*it-'a'];
        }
        return curTrie->isWordEnd;
    }
};
