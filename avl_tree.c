#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*creating a structure for binary tree */
struct node
{
    int key;
    struct node *left, *right;
};

struct node *root; /*structure pointer variable*/

/*defining prototype */
void preorder(struct node *dis);
struct node *insert(struct node *n, int data);
struct node *createnode(int data);
struct node *delete_node(struct node *root, int data);
struct node *inorder_predecessor(struct node *n);
struct node *ispresent(struct node *n, int key);
void search();
void newitem();

/*this function will insert the new node */

/*{ struct node* insert } to return the structure pointer  */

struct node *insert(struct node *n, int data)
{
    if (n == NULL) /*if root node is null key element will we inserted here*/
    {
        return createnode(data);
    }
    else
    {
        if (n->key > data) /*if key element is smaller than it will traverse towards left*/
        {
            n->left = insert(n->left, data);
        }
        else /*if key element is greater than it will traverse towards right*/
        {
            n->right = insert(n->right, data);
        }
    }
}

struct node *createnode(int data)
{
    struct node *k;                                 /*creating a new heap node to insert in the tree */
    k = (struct node *)malloc(sizeof(struct node)); /*craeting a heap node through malloc*/
    k->key = data;
    k->left = NULL;
    k->right = NULL;

    return k; /*returning the address of the node*/
}

/* function to delete the item */
struct node *delete_node(struct node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->key == data) /*if the root is matched and no other element in the tree then root node will be deleted*/
    {
        free(root);
        return NULL;
    }

    if (data < root->key)
    {
        root->left = delete_node(root->left, data);
    }
    else
    {
        if (data > root->key)
        {
            root->right = delete_node(root->right, data);
        }
        else
        {
            struct node *ipre = inorder_predecessor(root); /* calling the iorder predecessor function */
            root->key = ipre->key;
            root->left = delete_node(root->left, ipre->key);
            root->right = delete_node(root->right, ipre->key);
        }
        return root;
    }
}

void delete()
{
    int val;
    printf("enter your which element you want to delete ->");
    scanf("%d", &val);

    root = delete_node(root, val);
}

struct node *inorder_predecessor(struct node *n)
{
    if (n->left != NULL)
    {
        n = n->left;
        while (n->right != NULL)
        {
            n = n->right; /* traversing towards right  until NULL to replace the deleted node */
        }
    }
    else
    {
        n = n->right;
        while (n->left != NULL)
        {
            n = n->left; /* traversing towards left  until NULL to replace the deleted node */
        }
    }

    return n;
}

/* to print the binary tree in preorder  [in preorder the element is printed in first visit] */
void preorder(struct node *dis)
{
    if (dis != NULL)
    {
        printf("%d  ", dis->key);
        preorder(dis->left);  /*traversing towards left*/
        preorder(dis->right); /*traversing towards right*/
    }
}

/* to print the binary tree in postorder   [in preorder the element is printed in third visit] */
void postorder(struct node *post)
{
    if (post != NULL)
    {
        postorder(post->left);
        postorder(post->right);
        printf("%d  ", post->key);
    }
}

/* to print the binary tree in inorder  [in preorder the element is printed in second visit] */
void inorder(struct node *in)
{
    if (in != NULL)
    {
        inorder(in->left);
        printf("%d  ", in->key);
        inorder(in->right);
    }
}

void search() /*to search if the element is present or not */
{
    int value;
    struct node *k;
    printf("enter which value you want to searc :");
    scanf("%d", &value);

    k = ispresent(root, value);

    if (k == NULL)
    {
        printf("element is not present :");
    }
    else
    {
        if (k->key == value)
        {
            printf("element is present :");
        }
    }
}

struct node *ispresent(struct node *n, int key) /*recursive function to search the element */
{
    if (n == NULL || n->key == key)
    {
        return n;
    }
    else
    {
        if (key > n->key)
        {
            return ispresent(n->right, key);
        }
        else
        {
            return ispresent(n->left, key);
        }

        return n;
    }
}

void newitem() /*taking the new element from the user and sending to the insert funciton */
{
    int val;
    printf("enter your data :");
    scanf("%d", &val);

    root = insert(root, val); /*calling the insert function */
}

int main()
{
    root = NULL; /*making the root node null intially*/
    int ch;
    while (1) /*infinity loop until the user exit the code*/
    {
        printf("\nenter your choice :\n1.insert\n2.preorder\n3.postorder\n4.inorder\n5.delete\n6.search\n7.exit\n->");
        scanf("%d", &ch);

        switch (ch) /*switch case to call diff. function*/
        {
        case 1:
            newitem();
            break;

        case 2:
            preorder(root);
            break;

        case 3:
            postorder(root);
            break;

        case 4:
            inorder(root);
            break;

        case 5:
            delete ();
            break;

        case 6:
            search();
            break;

        case 7:
            exit(0);

        default:
            printf("enter proper option :\n");
        }
    }

    return 0;
}
