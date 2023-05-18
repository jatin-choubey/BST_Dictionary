// Design and develop a project for word dictionary using search tree concept;
#include <iostream>
#include <string>
using namespace std;
struct node // nodee declaration
{
    string info;
    struct node *l;
    struct node *r;
} *r;

class BST
{
public:
    void search(node *, string);
    void insert(node *, node *);
    BST()
    {
        r = NULL;
    }
};

void BST::search(node *root, string data)
{
    system("CLS");
    if (data == "EXIT")
    {
        return;
    }
    int depth = 0;
    node *temp = new node;
    temp = root;
    int i = 0;

    while (temp != NULL)
    {
        for (i = 0; i < temp->info.length(); i++)
        {
            if (temp->info[i] == ' ')
                break;
        }
        string temp1 = temp->info.substr(0, i);
        depth++;
        if (temp1 == data)
        {
            cout << "WORD : " << data << endl;
            cout << "Meaning -> " << temp->info.substr(i + 4, temp->info.length() - (i + 3)) << "   Found at depth " << depth << " of the tree " << endl
                 << endl;
            return;
        }
        else if (temp1 > data)
            temp = temp->l;
        else
            temp = temp->r;
    }
    cout << "\n Word not present in the Dictionary " << endl;
    return;
}
void BST::insert(node *tree, node *newnode)
{

    if (r == NULL)
    {
        r = new node;
        r->info = newnode->info;
        r->l = NULL;
        r->r = NULL;
        cout << "Root Node is Added" << endl;
        return;
    }
    if (newnode->info == "EXIT")
    {
        cout << "Dictionary Completed " << endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout << "Word already present in the Dictionary " << endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->l != NULL)
        {
            insert(tree->l, newnode);
        }
        else
        {
            tree->l = newnode;
            (tree->l)->l = NULL;
            (tree->l)->r = NULL;
            cout << "Word Added to the Dictionary (left child)" << endl;
            return;
        }
    }
    else
    {
        if (tree->r != NULL)
        {
            insert(tree->r, newnode);
        }
        else
        {
            tree->r = newnode;
            (tree->r)->l = NULL;
            (tree->r)->r = NULL;
            cout << "Word Added to the Dictionary (Right Child)" << endl;
            return;
        }
    }
}
int main()
{
    string item;
    BST bst;
    node *t;
    cout << endl;
    cout << "* * * * * * * * READ CAREFULLY !!!!! * * * * * * * * " << endl
         << endl;
    cout << "1) First we need to create the dictonary manually" << endl;
    cout << "2) Enter the word and its meaning in a format 'word -> Its meaning'" << endl;
    cout << "3) Make sure that all the words begin with the small letter" << endl;
    cout << "4) Enter EXIT to end giving inputs to dictionary " << endl
         << endl;

    do
    {
        t = new node;
        cout << "Enter the Word to be added in the Dictionary : ";
        getline(cin >> ws, t->info);
        bst.insert(r, t);
    } while (t->info != "EXIT");

    do
    {
        cout << "Search:" << endl;
        cin >> item;
        bst.search(r, item);
        cout << "Enter EXIT if you want to end the program " << endl;
    } while (item != "EXIT");

    return 0;
}