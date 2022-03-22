//Kenneth Stearns
//Project 9
//Due 11/16/21
//This program will allow a user to dynamically utilize a binary search tree.
#include<iostream>
#include<cstdlib>

using namespace std;

//typedef that can be changed to any type
typedef int item;

//define the node structure for the class
struct node
{
    item data;
    node *left;
    node *right;
};

//define the class
class BST
{
public:
    node *root;
    bool present(node*,item);
    node* insert(node*,item);
    node* del(node*, item);
    node* minValueNode(node*);
    int length(node*);
    void inOrder(node*);
    BST(){root = NULL;}
    ~BST(){root = NULL;}
};

//insert function
//pre: a pointer to a node in a tree and a input to be inserted.
//post: adds a node into the array with the data of the input.
node* BST::insert(node *r, item item)
{
    if(r == NULL)
    {
        node *temp = new node();
        temp -> data = item;
        temp -> left = NULL;
        temp -> right = NULL;
        return temp;
    }

    else if(r -> data > item)
    {
        r -> left = this -> insert(r -> left, item);
        return r;
    }

    else if(r -> data < item)
    {
        r -> right = this -> insert(r -> right, item);
        return r;
    }

    else
        return r;
}

//present function
//pre: a pointer to a node in a tree and an item to be searched for.
//post: a value true or false based on if the input is in the tree or not.
bool BST::present(node *r, item item)
{
    if(r == NULL)
    {
        return false;
    }

    else if(r -> data == item)
        return true;

    else
    {
        return this -> present(r -> left, item) || this -> present(r -> right, item);
    }
}

//minValueNode function
//pre: a pointer to a node in the tree.
//post: the minimum value in the tree.
node* BST::minValueNode(node* r)
{
    node* current = r;

    while(current -> left != NULL)
        current = current -> left;

    return current;
}

//del function
//pre: a pointer to a node in a tree and an item to be removed.
//post: deletes the node in the tree with that item.
node* BST::del(node *r, item item)
{
    if(r == NULL)
        return r;

    if(item < root -> data)
        r -> left = del(root -> left, item);

    else if(item > root -> data)
        r -> right = del(root -> right, item);

    else
    {
        if(r -> left == NULL)
        {
            node *temp = r -> right;
            free(r);
            return temp;
        }

        else if(r -> right == NULL)
        {
            node *temp = r -> left;
            free(r);
            return temp;
        }

        node* temp = this -> minValueNode(r -> right);

        r -> data = temp -> data;

        root -> right = del(root -> right, temp -> data);
    }
    return r;
}

//length function
//pre: a pointer to a node in a tree
//post: an integer that is the length of the tree.
int BST::length(node* r)
{
    if(r == NULL)
        return 0;

    else
    {
        return 1 + this -> length(r -> left) + this -> length(r -> right);
    }
}

//in order function.
//pre: a pointer to a node in a tree.
//post: outputs to the terminal the contents of the tree in sorted order.
void BST::inOrder(node* r)
{
    if(r == NULL)
        return;

    this -> inOrder(r -> left);
    cout << r -> data << " ";
    this -> inOrder(r -> right);
}

int main()
{
    char input = 'h';
    int num;
    BST bst;

    cout << "This program responds to commands the user enters to " << endl;
    cout << "manipulate and ordered list of integers, which is" << endl;
    cout << "initially empty. In the following commands, v is an" << endl;
    cout << "integer." << endl << endl;

    while(input != 'q')
    {
        switch(input)
        {
        case 'e':
            {
                bst.~BST();
                bst = BST();
                break;
            }
        case 'i':
            {
                cin >> num;
                bst.root = bst.insert(bst.root, num);
                break;
            }
        case 'r':
            {
                cin >> num;
                bst.root = bst.del(bst.root, num);
                break;
            }
        case 'l':
            {
                int length = bst.length(bst.root);

                cout << "The list contains " << length << " elements." << endl;
                break;
            }
        case 'p':
            {
                cin >> num;

                bool present = bst.present(bst.root, num);

                if(present)
                    cout << "The value " << num << " is present in the list." << endl;
                else
                    cout << "The value " << num << " is not present in the list." << endl;

                break;
            }
        case 'w':
            {
                cout << "The list: ";
                bst.inOrder(bst.root);
                cout << endl;
                break;
            }
        case 'h':
            {
                cout << "e -- Re-initialize the list to be empty." << endl;
                cout << "i v -- Insert the value v into the list." << endl;
                cout << "r v -- Remove the value v from the list. " << endl;
                cout << "l -- Report the length of the list." << endl;
                cout << "p v -- Is the value v present in the list? " << endl;
                cout << "w -- Write out the list." << endl;
                cout << "h -- See this menu." << endl;
                cout << "q -- Quit." << endl << endl;
            }
        }
        cin >> input;
    }
}
