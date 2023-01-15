#include <stdio.h>
#include <stdlib.h>

// Creating structure
struct node
{
    int key;
    struct node *left;
    struct node *right;
};

// Creating Newnode
struct node *Newnode(int val)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    temp->key = val;
    return temp;
}

// Inserting into the tree
struct node *insert(struct node *node, int val)
{
    if (node == NULL)
        return Newnode(val);
    else if (val < node->key)
        node->left = insert(node->left, val);
    else if (val > node->key)
        node->right = insert(node->right, val);
    return node;
}

// Preorder Traversal
void Preorder(struct node *node)
{
    if (node != NULL)
    {
        printf("%d->", node->key);
        Preorder(node->left);
        Preorder(node->right);
    }
}

// Inorder Traversal
void Inorder(struct node *node)
{
    if (node != NULL)
    {
        Inorder(node->left);
        printf("%d ", node->key);
        Inorder(node->right);
    }
}

// PostOrder Traversal
void Postorder(struct node *node)
{
    if (node != NULL)
    {
        Postorder(node->left);
        Postorder(node->right);
        printf("%d->", node->key);
    }
}

// Finding Indorder Successor
struct node *MinValueNode(struct node *node)
{
    struct node *current = node;
    // Finding the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Deleting Node from Tree
struct node *deleteNode(struct node *root, int key)
{
    // if root is empty.
    if (root == NULL)
        return root;

    // Finding the node to be deleted.
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        struct node *temp;
        // Finding whether leaf node or single child node.
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            temp = root->left;
            free(root);
            return temp;
        }

        // Node has Two Children
        temp = MinValueNode(root->right);

        root->key = temp->key;

        // Deleting the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Main function
void main()
{
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 10);
    root = insert(root, 5);
    // Preorder(root);
    // printf("\n");
    // Postorder(root);
    // printf("\n");
    Inorder(root);
    printf("\n");

    root = deleteNode(root, 2);
    Inorder(root);
    printf("\n");
}