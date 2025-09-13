#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef Node *node;
node makeNode(int x)
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}


void addLast(node &root, int x)
{
    node tmp = makeNode(x);
    if (root == NULL)
    {
        root = tmp;
        return;
    }
    node p = root;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = tmp;
}

void printList(node root)
{
    for (node p = root; p != NULL; p = p->next)
    {
        cout << p->data << " ";         
    }
    cout << endl;
}

void insertAt(node &root, int k, int x)
{
    node tmp = makeNode(x);

    if (k == 0)
    {
        tmp->next = root;
        root = tmp;
        return;
    }

    node p = root;
    for (int i = 0; i < k  && p != NULL; i++)
    {
        p = p->next;
    }
    tmp->next = p->next;
    p->next = tmp;
}

int main()
{
    Node *root = NULL;
    int n;
    cout << "Nhap so phan tu ban dau: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Nhap a[" << i << "] = ";
        cin >> val;
        addLast(root, val);
    }

    int x;
    printList(root);
    int k;
    cout << "Nhap vi tri can chen: ";
    cin >> k;
    cout << "Nhap gia tri can chen: ";
    cin >> x;
    insertAt(root, k, x);

    cout << "Danh sach sau khi chen: ";
    printList(root);

    return 0;
}
