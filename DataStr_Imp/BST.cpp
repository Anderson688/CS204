//Binary Search Tree (BST) implementation

#include <iostream>
#include<stack>

using namespace std;

struct node
{
	int key;
	struct node *left, *right;
};

node* root = NULL;

struct node *newNode(int item)
{
	struct node *temp = new node();
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void insert(int key)
{
    if(root == NULL)
    {
        root = newNode(key);
        cout << "Key successfully inserted" << endl;
    }
    else
    {
        node *temp1 = root, *temp2 = NULL;
        while(temp1 != NULL && temp1->key != key)
        {
            temp2 = temp1;
            if(temp1->key > key)
                temp1 = temp1->left;
            else
                temp1 = temp1->right;
        }
        if(temp1 == NULL)
        {
            if(temp2->key > key)
                temp2->left = newNode(key);
            else
                temp2->right = newNode(key);
            cout << "Key successfully inserted" << endl;
        }
        else
            cout << "Key already present" << endl;
    }
}

node* search(int key)
{
    node* temp = root;
    while(temp != NULL && temp->key != key)
    {
        if(temp->key > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp == NULL)
        cout << "Key not found" << endl;
    else
        cout << "Key found" << endl;
    return temp;
}

void dlt0(node* temp, node* parent)
{
    if(parent == NULL)
        root = NULL;
    else
    {
        if(parent->left == temp)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
}

void dlt1(node* temp, node* parent)
{
    if(parent == NULL)
    {
        if(temp->left != NULL)
            root = temp->left;
        else
            root = temp->right;
    }
    else
    {
        if(temp->left != NULL)
        {
            if(parent->left == temp)
                parent->left = temp->left;
            else
                parent->right = temp->left;
        }
        else
        {
            if(parent->left == temp)
                parent->left = temp->right;
            else
                parent->right = temp->right;
        }
    }
}

void dlt2(node* temp)
{
    node *successor = temp->right, *sparent = temp;
    while(successor->left != NULL)
    {
        sparent = successor;
        successor = successor->left;
    }
    int svalue = successor->key;
    if(successor->right == NULL)
    {
        dlt0(successor, sparent);
        temp->key = svalue;
    }
    else
    {
        dlt1(successor, sparent);
        temp->key = svalue;
    }
}

void deleteNode(int key)
{
    node *temp = root, *parent = NULL;
    while(temp != NULL && temp->key != key)
    {
        parent = temp;
        if(temp->key > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp == NULL)
        cout << "Key not found" << endl;
    else
    {
        if(temp->left == NULL && temp->right == NULL)
            dlt0(temp, parent);
        else if(temp->left == NULL || temp->right == NULL)
            dlt1(temp, parent);
        else
            dlt2(temp);
        cout << "Key successfully deleted" << endl;
    }
}

void inorder()
{
    stack<node*> s;
    node *curr = root;
    cout << "Inorder traversal -> ";
    if(root == NULL)
        cout << "No keys";
    else
    {
        while(curr != NULL || s.empty() == false)
        {
            while (curr !=  NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->key << " ";
            curr = curr->right;
        }
    }
    cout << endl;
}

node* successor(int key)
{
    node* temp = root;
    while(temp != NULL && temp->key != key)
    {
        if(temp->key > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(temp == NULL)
        cout << "Key not found" << endl;
    else
    {
        if(temp->right != NULL)
        {
            temp = temp->right;
            while(temp->left != NULL)
                temp = temp->left;
        }
        else
        {
            node *succ = NULL, *curr = root;
            while(curr != NULL)
            {
                if(temp->key < curr->key)
                {
                    succ = curr;
                    curr = curr->left;
                }
                else if(temp->key > curr->key)
                    curr = curr->right;
                else
                    break;
            }
            temp = succ;
        }
        if(temp == NULL)
            cout << "No successor of " << key << endl;
        else
            cout << "Successor of " << key << " is " << temp->key << endl;
    }
    return temp;
}

int main()
{
    insert(20);
    insert(30);
    search(25);
    deleteNode(30);
    insert(22);
    deleteNode(20);
    insert(10);
    insert(25);
    inorder();
    successor(4);
    deleteNode(22);
    deleteNode(25);
    deleteNode(10);
    inorder();
    return 0;
}
