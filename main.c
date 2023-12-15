#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}node;

node * newNode(int value){
    node * newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node * insert(node * root,int value){
    if(root == NULL){
        return newNode(value);
    }

    if(value < root->data){
        root->left = insert(root->left,value);
    }
    else if(value > root->data){
        root->right = insert(root->right,value);
    }
    return root;
}

void traverse(node * root){
    if(root != NULL){
        traverse(root->left);
        printf("%d\n",root->data);
        traverse(root->right);
    }
}



int main() {

    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

   traverse(root);

    return 0;
}
