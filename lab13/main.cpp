#include <iostream>

using namespace std;

struct node
{
    int key;
    node *parent;
    node *left;
    node *right;
};
node* makeNode(int value)
{
    node *n=new node;
    n->key=value;
    n->left=nullptr;
    n->right=nullptr;
    n->parent=nullptr;
    return n;
}
void addNode(int value, node *&root)
{
    if (root==nullptr)
    {
        root=makeNode(value);
        return;
    }
    node *temp=root;
    while (true)
    {
        if(value>=temp->key)
        {
            if (temp->right=nullptr)
            {
                temp->right=makeNode(value);
                temp->right->parent=temp;
                return;
            }
            else
            {
                temp=temp->right;
            }
        }
        else
        {
            if (temp->left==nullptr)
            {
                temp->left=makeNode(value);
                temp->left->parent=temp;
                return;

            }
            else
                temp = temp->left;
        }
    }
}

void preorder(node *root)
{
    if (root!=nullptr)
    {
        cout << root->key <<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if (root!=nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout <<root->key<<endl;
    }

}

void inorder(node *root)
{
    if (root!=nullptr)
    {
        inorder(root->left);

        cout <<root->key<<endl;
        inorder(root->right);
    }

}

node *findNode(node *root,int value)
{
    while (root!=nullptr)
    {
        if (root->key==value)
        {
            return root;
        }
        if (value>root->key)
        {
            root=root->right;

        }
        else root=root->left;

    }
    return nullptr;
}

void menu()
{
    cout << "1.sprawdz czy pusty"<<endl;
    cout << "2.dodanie wezla"<<endl;
    cout << "3,sprawdz czy jest w drzewie"<<endl;
    cout<< "4.preorder"<<endl;
    cout << "5.inorder"<<endl;
    cout << "6.postorder"<<endl;
    cout << "8.usuwanie drzewa"<<endl;
    cout << "9,wyjdz z programu"<< endl;

}

void postorderd(node *&root)
{
    if (root!=nullptr)
    {
        postorderd(root->left);
        postorderd(root->right);
        delete root;
    }

}

int main()
{
    node *tree=nullptr;
    menu();
    cout <<"podaj co chcesz zrobic"<<endl;
    int ind;
    cin >> ind;
    while (true){
    switch (ind)
    {
    case 1:
        {
            if (tree==nullptr) cout <<"jest puste"<<endl;
            else cout << "nie jest puste"<<endl;
            break;
        }
    case 2:
        {
            cout << "drzewo:"<<endl;
            inorder(tree);
            cout << "podaj wartosc klucza: ";
            int k;
            cin >>k;
            addNode(k,tree);
            cout << "drzewo po dodaniu: "<<endl;
            inorder(tree);
            break;

        }
    case 3:
        {
            cout << "podaj wartosc klucza: ";
            int k;
            cin >>k;
            node *n=findNode(tree, k);
            if (n==nullptr)
                cout << "nie ma takiego wezla"<<endl;
            else
                cout << "jest taki wezel"<<endl;
            break;
        }
    case 4:
        {
            preorder(tree);
            break;
        }
    case 5:
        {
            inorder(tree);
            break;
        }
    case 6:
        {
            postorder(tree);
            break;
        }
    case 8:
        {
           postorderd(tree);
           break;
        }
    case 9:
        return 0;
    default :
        {cout << "zly wybor"<<endl;
        break;}
    }
    menu();
    cout <<"podaj co chcesz zrobic"<<endl;

    cin >> ind;}

}
