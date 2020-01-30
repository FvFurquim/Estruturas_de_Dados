#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

typedef struct aux{
    int key;
    struct aux* left;
    struct aux* right;
}NODE;

void initializateTree(NODE* root){
    root = NULL;
}

NODE* createNode(int k){
    NODE* n = (NODE*) malloc(sizeof(NODE));
    n->left = NULL;
    n->right = NULL;
    n->key = k;
    return n;
}

NODE* insection(NODE* root, NODE* n){
    if(root == NULL)
        return n;
    
    if(n->key <= root->key)
        root->left = insection(root->left, n);
    
    else if(n->key > root->key)
        root->right = insection(root->right, n);
    
    return root;
}

NODE* search(NODE* root, int num){
    if(root == NULL)
        return NULL;
    
    if(root->key == num)
        return root;
    
    if(root->key > num)
        return search(root->left, num);
    
    return search(root->right, num);
}

NODE* searchWithFather(NODE* root, int num, NODE** father){
    NODE* current = root;
    *father = NULL;
    
    while(current){
        if(current->key == num)
            return current;
        
        *father = current;
        
        if(current->key < num)
            current = current->left;
        
        else
            current = current->right;
    }
    
    return NULL;
}

NODE* delete(NODE* root, int num){
    NODE* n, father, subs, prevSubs;
    n = searchWithFather(root, num, &father);
    
    if(!n->left || !n->right){
        if(!n->left)
            subs = n->right;
        else
            subs = n->left;
    }
    
    else{
        prevSubs = n;
        subs = n->left;
        
        while(subs->right){
            prevSubs = subs;
            subs = subs->right;
        }
        
        if(prevSubs != n){
            prevSubs->left = subs->right;
            subs->left = n->left;
        }
        
        subs->right = n->right;
    }
    
    if(!father){
        free(n);
        return subs;
    }
        
    else{
        if(num > father->key)
            father->right = subs;
        else
            father->left = subs;
        }
    
    free(n);
    return root;
}

void printTreePre(NODE* root){
    printf("%i", root->key);
    printTreePre(root->left);
    printTreePre(root->right);
}

void printTreeOrd(NODE* root){
    printTreeOrd(root->left);
    printf("%i", root->key);
    printTreeOrd(root->right);
}

void printTreePos(NODE* root){
    printTreePos(root->left);
    printTreePos(root->right);
    printf("%i", root->key);
}

int main() {

    return 0;
}

