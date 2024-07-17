#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int key;
    struct node* left,*right;
    int height;
};

struct node* root;

struct node* createnode(int val){
    struct node* k=(struct node*)malloc(sizeof(struct node));
    k->key=val;
    k->left=k->right=NULL;
    k->height=1;

    return k;
}

struct node* insertitem(struct node* n,int key){
    if(n==NULL){
        return createnode(key);
    }
    if(n->key>key){
        n->left=insertitem(n->left,key);
    }
    else{
        n->right=insertitem(n->right,key);
    }


    n->height=
}