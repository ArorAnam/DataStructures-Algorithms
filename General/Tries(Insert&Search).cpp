#include <bits/stdc++.h>

using namespace std;

#define ALPHABET_SIZE 26

struct TreeNode {
    struct TreeNode* children[ALPHABET_SIZE];
    bool isEndofWord;
};

struct TreeNode* getNode(void) {
    struct TreeNode *pnode = new TreeNode;

    pnode->isEndofWord = false;
    for(int i=0; i<ALPHABET_SIZE; i++) {
        pnode->children[i] = NULL;
    }

    return pnode;
}

void insert(struct TreeNode *root, string keys) {
    struct TreeNode *pCrawl = root;

    for(char c : keys) {
        int index = c - 'a';
        if(!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndofWord = true;
}

bool search(struct TreeNode *root, string key) {
    struct TreeNode *pCrawl = root;

    for(char c : key) {
        int index = c - 'a';
        if(!pCrawl->children[index])
            return false;
        
        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndofWord);
}

int main() {
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" };

    int n = sizeof(keys)/sizeof(keys[0]);

    struct TreeNode *root = getNode();

    for(auto key : keys)
        insert(root, key);

    // search for different keys
    search(root, "the") ? cout << "Yes" << endl : cout << "No" << endl;

    search(root, "these")? cout << "Yes\n" : 
                           cout << "No\n";

    return 0;
}