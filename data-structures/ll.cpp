#include <iostream>
#include <cstdlib>

struct n{
    int data;
    n *next;
};

typedef n node;

void add(node *root, int x){
    if(root == NULL){
        node *root = (node*)malloc(sizeof(node));
        root->next = NULL;
        root->data = x;
        return;
    }

    while(root->next != NULL){
        root = root->next;
    }

    root->next = (node*)malloc(sizeof(node));
    root->next->data = x;
    root->next->next = NULL;
}

void addInOrder(node *root, int x){
    if(root == NULL){
        node *root = (node*)malloc(sizeof(node));
        root->next = NULL;
        root->data = x;
        return;
    }
    while(root->next->data > x && x > root->data){
        root = root->next;
    }
    if(root->next == NULL){
        if(root->data > x){
            node* tmp = (node*)malloc(sizeof(node));
            tmp->data = x;
            tmp->next = root;
            root = tmp;
        }
        else{
            node* tmp = (node*)malloc(sizeof(node));
            tmp->data = x;
            tmp->next = NULL;
            root->next = tmp;
        }
        return;
    }

    while(root->next != NULL){
        if(root->data > x && x >= root->next->data){
        }
        root = root->next;
    }

}

void traverse(node *root){
    while(root != NULL){
        std::cout << root->data << " ";
        root = root->next;
    }
}

int main(){
    node *root;
    root = (node*)malloc(sizeof(node));
    root->data = 500;
    add(root, 77);
    add(root, 69);
    add(root, 31);
    traverse(root);
}
