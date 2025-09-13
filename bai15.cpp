#include <iostream>
using namespace std;
#define M 9

struct Node
{
    int key;
    int lk;
};

typedef Node *node;

void init(node B[])
{
    for (int i = 0; i < M; i++)
    {
        B[i] = new Node();
        B[i]->key = 0;
        B[i]->lk = -1;
    }
}
void addNode(node B[], int x)
{
    int i = x % M;

    if (B[i]->key == 0)
    {
        B[i]->key = x;
        B[i]->lk = -1;
    }
    else
    {
        int j = M - 1;
        while ( B[j]->key != 0)
            j--;
        B[j]->key = x;
        B[j]->lk = -1;
        int k = i;
        while (B[k]->lk != -1)
            k = B[k]->lk;

        B[k]->lk = j;
    }
}

int Search(node B[], int x)
{
    int i = x % M;
    while (i != -1)
    {
        if (B[i]->key == x)
            return 1;
        i = B[i]->lk;
    }
    return 0;
}

void printHashTable(node B[])
{
    cout << "     HASH TABLE      " << endl;
    for (int i = 0; i < M; i++)
    {
        cout << "a[" << i << "]: ";
        if (B[i]->key != 0)
        {
            cout << B[i]->key;
            int k = B[i]->lk;
            while (k != -1)
            {
                cout << " -> " << B[k]->key;
                k = B[k]->lk;
            }
        }
        cout << endl;
    }
}

int main()
{
    node B[M];
    init(B);
    addNode(B, 12);
    addNode(B, 15);
    addNode(B, 24);
    addNode(B, 5);
    addNode(B, 9);
    addNode(B, 33);
    addNode(B, 16);
    addNode(B, 30);
    addNode(B, 38);

    printHashTable(B);

    int x;
    cout << "Nhap so can tim: ";
    cin >> x;
    if (Search(B, x))
        cout << "Tim thay " << x << " trong bang bam." << endl;
    else
        cout << "Khong tim thay " << x << " trong bang bam." << endl;

    return 0;
}