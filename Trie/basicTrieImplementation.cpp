#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode *children[26];
    bool isWordEnd;
};

TrieNode* getNode(){
    TrieNode *curNode = new TrieNode();
    curNode->isWordEnd = false;
    for(int i=0; i<26; i++){
        curNode->children[i] = nullptr;
    }
    return curNode;
}

void insertWord(TrieNode* root, string s){
    TrieNode *curNode = root;
    int n = s.size();
    for(int i=0; i<n; i++){
        int curIndex = s[i]-'a';
        if(curNode->children[curIndex] == nullptr){
            curNode->children[curIndex] = getNode();
        }
        curNode = curNode->children[curIndex];
    }
    curNode->isWordEnd = true;
}

bool searchWord(TrieNode* root, string s){
    TrieNode *curNode = root;
    int n = s.size();
    for(int i=0; i<n; i++){
        int curIndex = s[i]-'a';
        if(curNode->children[curIndex] == nullptr){
            return false;
        }
        curNode = curNode->children[curIndex];
    }
    return curNode->isWordEnd;
}

int main(){
    TrieNode *root = getNode();
    insertWord(root, "abc");
    insertWord(root, "abcde");
    insertWord(root, "abcdep");
    cout << "Search result: " << searchWord(root, "abc") << endl;
    return 0;
}