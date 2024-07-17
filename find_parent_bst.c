#include <stdio.h>
#include <stdlib.h>

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
struct node *getparents(struct node *root, int key);
void newitem();

/*this function will insert the new node */

/*{ struct node* insert } to return the address */

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
        else /*if key element is smaller than it will traverse towards right*/
        {
            n->right = insert(n->right, data);
        }
        return n;
    }
}

/*creating a new heap node to insert in the tree */
struct node *createnode(int data)
{
    struct node *k;
    k = (struct node *)malloc(sizeof(struct node)); /*craeting a heap node through malloc*/
    k->key = data;
    k->left = k->right = NULL;

    return k; /*returning the address of the node*/
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

void newitem() /*taking the new element from the user and sending to the insert funciton */
{
    int val;
    printf("enter your data :");
    scanf("%d", &val);

    root = insert(root, val); /*calling the insert function */
}


/*FUNCTION TO FIND THE PARENT OF THE GIVEN NODE */
void findparent(struct node *root)
{
    int val;
    printf("enter your value :");
    scanf("%d", &val);

    struct node *p = getparents(root, val);
    if (p != NULL)
    {
        printf("%d is the parent node :\n", p->key);
    }
    else{
        printf("parent not found or the node itself is parent :");
    }
}

/*THIS FUNCTION WILL RETURN THE PARENT NODE OF THE GIVEN ELEMENT */
struct node *getparents(struct node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return NULL;
    }

    if ((root->left != NULL && root->left->key == key) || (root->right != NULL && root->right->key == key))
    {
        return root;
    }

    struct node *parent = getparents(root->left, key);  /*TRAVERSING TOWARDS LEFT*/

    if (parent != NULL)
    {
        return parent;
    }

    parent = getparents(root->right, key);  /*TRAVERSING TOWARDS LEFT*/

    return parent;  /*RETURNING THE PARENT NODE */
}

int main()
{
    root = NULL; /*making the root node null intially*/
    int ch;
    while (1) /*infinity loop until the user exit the code*/
    {
        printf("\nenter your choice :\n1.insert\n2.preorder\n3.postorder\n4.inorder\n5.find parent\n6. exit\n->");
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
            findparent(root);
            break;

        case 6:
            exit(0);

        default:
            printf("enter proper option :\n");
        }
    }

    return 0;
}
