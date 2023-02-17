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
        printf("%d ", node->key);
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
        printf("%d ", node->key);
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
  struct node *root=NULL;
	int ch, data;
	do
  {
   	printf("ENTER \n0:EXIT\n1:INSERT \n2:DELETE \n3:PREORDER TRAVERSAL \n4:INORDER TRAVERSAL \n5:POSTORDER \n6:PRINT ROOT \nCHOICE: ");
   	scanf("%d", &ch);
   	switch(ch)
   	{
			case 0:
				break;
   		case 1:
   			printf("ENTER THE NUMBER: ");
    		scanf("%d", &data);
    		root = insert(root, data);
    		break;
   		case 2:
   			printf("ENTER THE NUMBER TO DELETE: ");
   			scanf("%d", &data);
    		root = deleteNode(root, data);
    		break;
   		case 3:
   			Preorder(root);
   			printf("\n");
    		break;
   		case 4:
   			Inorder(root);
   			printf("\n");
    		break;
   		case 5:
   			Postorder(root);
   			printf("\n");
   			break;
   		case 6:
    		printf("ROOT: %d\n", root->key);
    		break;
    	default:
    		printf("WRONG OPTION!\n");
    }
	}while(ch != 0);
}
