#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode *left;
    TrieNode *right;
    TrieNode *child;
    bool isEndOfWord;
    int maxDist;
    char c;
};

int C, N, Q;
TrieNode *color, *name;

TrieNode *newNode()
{
    TrieNode *node = new TrieNode;
    node->left = node->right = node->child = nullptr;
    node->isEndOfWord = false;
    node->maxDist = 0;
    return node;
}

TrieNode *insertT(TrieNode *root, char s[])
{
    if(root == nullptr){
        root = newNode();
        root->c = s[0];
    }
    int strlen = 0;
    while(s[strlen] != '\0') strlen++;
    TrieNode *walk = root;
    for(int i=0; s[i] != '\0'; i++){
        while(walk->c != s[i]){
            if(walk->c < s[i]){
                if(walk->left == nullptr){
                    TrieNode *left = newNode();
                    walk->left = left;
                    left->c = s[i];
                }
                walk = walk->left;
            }
            else{
                if(walk->right == nullptr){
                    TrieNode *right = newNode();
                    walk->right = right;
                    right->c = s[i];
                }
                walk = walk->right;
            }
        }
        walk->maxDist = max(walk->maxDist, strlen - i);
        if(s[i + 1] == '\0') walk->isEndOfWord = true;
        else if(walk->child == nullptr){
            TrieNode *child = newNode();
            walk->child = child;
            child->c = s[i + 1];
        }
        walk = walk->child;
    }
    return root;
}

bool findName(char s[])
{
    int strlen = 0;
    while(s[strlen] != '\0') strlen++;
    TrieNode *walk = name;
    for(int i=0; s[i] != '\0'; i++){
        while(walk != nullptr && walk->c != s[i]){
            if(walk->c < s[i]) walk = walk->left;
            else walk = walk->right;
        }
        if(walk == nullptr) return false;
        if(walk->isEndOfWord && s[i+1] == '\0') return true;
        if(walk->maxDist < strlen - i) return false;
        walk = walk->child;
    }
    return false;
}

bool findT(char s[])
{
    TrieNode *walk = color;
    for(int i=0; s[i] != '\0'; i++){
        while(walk != nullptr && walk->c != s[i]){
            if(walk->c < s[i]) walk = walk->left;
            else walk = walk->right;
        }
        if(walk == nullptr) return false;
        if(walk->isEndOfWord && findName(s + i + 1)) return true;
        walk = walk->child;
    }
    return false;
}

void freeT(TrieNode *root)
{
    if(root == nullptr) return;
    freeT(root->left);
    freeT(root->right);
    freeT(root->child);
    delete root;
}

int main()
{
    scanf("%d %d", &C, &N);
    for(int i=0; i<C; i++){
        char tmp[1005];
        scanf(" %s", tmp);
        color = insertT(color, tmp);
    }
    for(int i=0; i<N; i++){
        char tmp[1005];
        scanf(" %s", tmp);
        name = insertT(name, tmp);
    }
    scanf("%d", &Q);
    for(int i=0; i<Q; i++){
        char tmp[2005];
        scanf(" %s", tmp);
        if(findT(tmp)) printf("Yes\n");
        else printf("No\n");
    }
    freeT(color);
    freeT(name);
    return 0;
}
