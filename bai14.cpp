#include <iostream>
using namespace std;
#define M 6

struct Node
{
    int key;
    Node *next;
};

typedef Node *node;

node makeNode(int x)
{
    node tmp = new Node();
    tmp->key = x;
    tmp->next = NULL;
    return tmp;
}

void init(node B[])
{
    for (int i = 0; i < M; i++)
    {
        B[i] = NULL;
    }
}

void addNode(node B[], int x)
{
    int i = x % M;
    node tmp = makeNode(x);
    node tam = B[i];

    if (B[i] == NULL)
    {
        B[i] = tmp;
    }
    else
    {
        while (tam->next != NULL)
        {
            tam = tam->next;
        }
        tam->next = tmp;
    }
}
int Search(node B[], int x)
{
    int i = x % M;
    node tam = B[i];
    while (tam != NULL)
    {
        if (tam->key == x)
            return 1;
        tam = tam->next;
    }
    return 0;
}

void printHashTable(node B[])
{
    cout << "Hash Table:" << endl;
    for (int i = 0; i < M; i++)
    {
        cout << "a[" << i << "]: ";
        node tam = B[i];
        if (tam == NULL)
        {
            cout << "NULL";
        }
        else
        {
            while (tam != NULL)
            {
                cout << tam->key;
                if (tam->next != NULL)
                    cout << " -> ";
                tam = tam->next;
            }
        }
        cout << endl;
    }
}
int main()
{
    node B[M];

    init(B);
    addNode(B, 7);
    addNode(B, 6);
    addNode(B, 9);
    addNode(B, 15);
    addNode(B, 8);
    addNode(B, 23);
    addNode(B, 45);
    addNode(B, 17);
    printHashTable(B);
    int x;
    cout << "Nhap so can tim: ";
    cin >> x;
    if (Search(B, x))
        cout << "Tim thay " << x << " trong hash table" << endl;
    else
        cout << "Khong tim thay " << x << " trong hash table" << endl;
    return 0;
}