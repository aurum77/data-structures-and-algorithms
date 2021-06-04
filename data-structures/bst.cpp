#include <iostream>
#include <cstdlib>

struct n{
    int data;
    n* left;
    n* right;
};
typedef n node;

node* add(node *tree, int x){
    if(tree == NULL){
        node* root = (node*)malloc(sizeof(node));
        root->left = NULL;
        root->right = NULL;
        root->data = x;
        return root;
    }

    node* iter = tree;

    if(iter->data < x){
        tree->right = add(tree->right, x);
        return tree;
    }

    // if(iter->data >= x)
    tree-> left = add(tree->left, x);
    return tree;
}

/*
 * Infix    = LNR, RNL
 * Prefix   = NLR, NRL
 * Postfix  = LRN, RLN
 */

void traverse(node *tree){
    if(tree == NULL){
        return;
    }

    // LNR traversal
    traverse(tree->left);
    std::cout << tree->data << " ";
    traverse(tree->right);
}

int search(node *tree, int deger){
    if(tree == NULL){
        return -1;
    }

    if(tree->data == deger){
        return 1;
    }

    if(search(tree->left, deger) == 1){
        return 1;
    }

    if(search(tree->right, deger) == 1){
        return 1;
    }
    return -1;
}

int max(node *tree){
    while(tree->right != NULL){
        tree = tree->right;
    }

    return tree->data;
}

int min(node *tree){
    while(tree->left != NULL){
        tree = tree->left;
    }
    return tree->data;
}

node* del(node *tree, int x){
    if(tree == NULL){
        return NULL;
    }

    if(tree->data == x){
        if(tree->left == NULL && tree->right == NULL){
            return NULL;
        }

        if(tree->right != NULL){
            tree->data = min(tree->right);
            tree->right = del(tree->right, min(tree->right));
            return tree;
        }

        if(tree->left != NULL){
            tree->data = max(tree->left);
            tree->left = del(tree->left, max(tree->left));
            return tree;
        }
    }
    if(tree->data < x){
        tree->right = del(tree->right, x);
        return tree;
    }
    tree = del(tree->left, x);
    return tree;
}

int main(){
    node * tree = NULL;
    tree = add(tree, 56);
    tree = add(tree, 200);
    tree = add(tree, 26);
    tree = add(tree, 190);
    tree = add(tree, 213);
    tree = add(tree, 18);
    tree = add(tree, 28);
    tree = add(tree, 12);
    tree = add(tree, 24);
    tree = add(tree, 27);

    std::cout << "result: " << search(tree, 28) << "\n";
    std::cout << "node with the max value: " << max(tree) << "\n";
    std::cout << "node with the min value: " << min(tree) << "\n";
    tree = del(tree, 190);
    tree = del(tree, 56);

    traverse(tree);
}
