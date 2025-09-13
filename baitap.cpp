#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
// bài tập 1: fibo
int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

void fibo()
{
    {
        int n;
        cout << "Nhap n: ";
        cin >> n;
        cout << "Fibo(" << n << ") = " << fibo(n) << endl;
    }
}

// bài tập 2: giai thừa
int giaithua(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return n * giaithua(n - 1);
}

void giaithua()
{
    {
        int n;
        cout << "Nhap n: ";
        cin >> n;
        cout << n << "! = " << giaithua(n) << endl;
    }
}

// bài tập 3: n giờ ,virut
int virus(int gio, int virut)
{
    if (gio == 0)
        return virut;
    return 2 * virus(gio - 1, virut);
}

void virus()
{
    int gio,
        virut;
    cout << "Nhap so gio: ";
    cin >> gio;
    cout << "Nhap so virut: ";
    cin >> virut;
    for (int i = 1; i <= gio; i++)
    {
        virut = virut * 2;
    }
    cout << virut;
}

// bài tập 4: cho  cây n mét
int ocSen(int n, int x, int y, int day = 0, int vt = 0)
{
    {
        if (n <= x + vt)
            return day + 1;
    }
    return ocSen(n, x, y, day + 1, vt + x - y);
}

void ocsen()
{
    int n, x, y;
    cout << "Nhap chieu cao cay: ";
    cin >> n;
    cout << "Nhap so met ban ngay: ";
    cin >> x;
    cout << "Nhap so met ban dem: ";
    cin >> y;

    cout << "So ngay: " << ocSen(n, x, y);
}

// bài tập 5: phí tuyến : tính số hạng thứ n ( đệ qui )
long tn(int n)
{
    if (n == 0)
        return 1;
    long S = 0;
    for (int i = 1; i <= n; i++)
    {
        S = S + i * i * tn(n - i);
    }
    return S;
}

void n4()
{
    {
        int n;
        cout << "Nhap n: ";
        cin >> n;
        cout << "Ket qua: " << tn(n);
    }
}

// Bài 6: vòng lặp đồng cấp

void vldongcap()
{
    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap mang 1: ";
        cin >> arr1[i];
    }
    for (int j = 0; j < m; j++)
    {
        cout << "Nhap mang 2: ";
        cin >> arr2[j];
    }

    cout << "Mang 1: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\nMang 2: ";
    for (int j = 0; j < m; j++)
    {
        cout << arr2[j] << " ";
    }
    cout << "\nTong so phan tu: " << (n + m);
}

// Bài 7: vòng lặp lòng nhau

void vllongnhau()
{
    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap mang 1: ";
        cin >> arr1[i];
    }
    for (int j = 0; j < m; j++)
    {
        cout << "Nhap mang 2: ";
        cin >> arr2[j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "(" << arr1[i] << "," << arr2[j] << ") ";
        }
        cout << "\n";
    }
}

// Bài 8:  DSLK  Tính tổng , chẳn , lẻ , add first
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
    tmp->next = nullptr;
    return tmp;
}
void addFirst(node &root)
{
    int x;
    do
    {
        cout << "nhap x:";
        cin >> x;
        if (x != 0)
        {
            node tmp = makeNode(x);
            tmp->next = root;
            root = tmp;
        }
    } while (x != 0);
}

void printList(node root)
{
    cout << " Danh sach: ";
    while (root != nullptr)
    {
        cout << root->data << "";
        root = root->next;
    }
    cout << "\n";
}
int sumList(node root)
{

    {
        if (root == nullptr)
            return 0;
        return root->data + sumList(root->next);
    }
}

int chan(node root)
{
    if (root == nullptr)
        return 0;
    return (root->data % 2 == 0) + chan(root->next);
}

int le(node root)
{
    if (root == nullptr)
        return 0;
    return (root->data % 2 != 0) + le(root->next);
}

void DanhSach()
{
    node head = nullptr;
    addFirst(head);
    printList(head);
    cout << " Tong = " << sumList(head) << "\n";
    cout << " So chan = " << chan(head) << "\n";
    cout << " So le = " << le(head) << "\n";
}

// Bài 9: Tìm số chẳn lẻ đầu cuối
void addFirts(node &root)
{
    int x;
    do
    {
        cout << " Nhap x : ";
        cin >> x;
        if (x != 0)
        {
            node tmp = makeNode(x);
            tmp->next = root;
            root = tmp;
        }

    } while (x != 0);
}

int findlastEven(Node *root)
{
    {
        if (root == NULL)
            return -1;
        int kq = findlastEven(root->next);
        if (kq != -1)
            return kq;
        if (root->data % 2 == 0)
            return root->data;
        return -1;
    }
}

int findlastOdd(Node *root)
{
    {
        if (root == NULL)
            return -1;
        int kq = findlastOdd(root->next);
        if (kq != -1)
            return kq;
        if (root->data % 2 != 0)
            return root->data;
        return -1;
    }
}
int findFirstEven(node root)
{
    {
        if (root == NULL)
            return -1;
        if (root->data % 2 == 0)
            return root->data;
        return findFirstEven(root->next);
    }
}

int findFirtsOdd(node root)
{
    {
        if (root == NULL)
            return -1;
        if (root->data % 2 != 0)
            return root->data;
        return findFirtsOdd(root->next);
    }
}

void daucuoi()
{
    node head = NULL;
    addFirts(head);
    printList(head);
    cout << " so le cuoi cung : " << findlastOdd(head) << endl;
    cout << " so chan cuoi cung : " << findlastEven(head) << endl;
    cout << " so chan dau tien : " << findFirstEven(head) << endl;
    cout << " so le dau tien : " << findFirtsOdd(head) << endl;
}

// Bài 10 : selectionSort
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        swap(a[i], a[min]);
    }
}

void selectionsort()
{

    ifstream file("10.csv");
    int a[100000], n = 0;
    string num;

    while (getline(file, num, ','))
        a[n++] = stoi(num);

    auto start = chrono::high_resolution_clock::now();

    selectionSort(a, n);

    auto end = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nThoi gian sap xep: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
}
// Bài 11: InsertSort

void InsertSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {

        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void InsetSort()
{
    ifstream file("10.csv");
    int a[100000], n = 0;
    string num;

    while (getline(file, num, ','))
        a[n++] = stoi(num);

    auto start = chrono::high_resolution_clock::now();

    InsertSort(a, n);

    auto end = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nThoi gian sap xep: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
}

// Bài 12:BubbleSort

void BubbleSort(int a[], int n)
{
    int i, j;
    for (i = n - 1; i >= 1; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])

                swap(a[j], a[j + 1]);
        }
    }
}

void Bubblesort()
{
    ifstream file("10.csv");
    int a[100000], n = 0;
    string num;

    while (getline(file, num, ','))
        a[n++] = stoi(num);

    auto start = chrono::high_resolution_clock::now();

    BubbleSort(a, n);

    auto end = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nThoi gian sap xep: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
}

// Bài 13: MeageSort
void Merge(int a[], int L, int R)
{
    if (L >= R)
        return;

    int m = L + (R - L) / 2;

    Merge(a, L, m);
    Merge(a, m + 1, R);

    int n1 = m + 1 - L;
    int n2 = R - m;

    int l[n1];
    int r[n2];

    for (int i = 0; i < n1; i++)
        l[i] = a[L + i];
    for (int j = 0; j < n2; j++)
        r[j] = a[m + 1 + j];

    int i = 0, j = 0, k = L;

    while (i < n1 && j < n2)
    {
        if (l[i] > r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = l[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}

void Merge()
{

    ifstream file("10.csv");

    int a[100000], n = 0;
    string num;

    while (getline(file, num, ','))
    {
        if (!num.empty())
            a[n++] = stoi(num);
    }
    file.close();

    auto start = chrono::high_resolution_clock::now();
    Merge(a, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nThoi gian sap xep: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
}

// Bài 14: HeapSort
void heap(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heap(a, n, largest);
    }
}

void HeapSort(int a[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heap(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heap(a, i, 0);
    }
}

void heapsort()
{
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    HeapSort(a, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Bài 15: Qicksort

void QickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int i = l;
    int j = r;
    int m = l + (r - l) / 2;
    int pivot = a[m];
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        QickSort(a, l, j);
    if (r > i)
        QickSort(a, i, r);
}
void PrintArr(int a[], int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
}
void Qicksort()
{
    int n;
    cout << " Nhap vao phan tu : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    QickSort(a, 0, n - 1);
    cout << "Mang duoc sap xep: ";
    PrintArr(a, n);
}

int main()
{
    int choice;
    cout << "Chon bai muon chay : ";
    cin >> choice;

    if (choice == 0)
    {
        fibo();
    }
    else if (choice == 1)
    {
        giaithua();
    }
    else if (choice == 2)
    {
        virus();
    }

    else if (choice == 3)
    {
        ocsen();
    }
    else if (choice == 4)
    {
        n4();
    }
    else if (choice == 5)
    {
        vldongcap();
    }

    else if (choice == 6)
    {
        vllongnhau();
    }
    else if (choice == 7)
    {
        DanhSach();
    }

    else if (choice == 8)
    {
        daucuoi();
    }
    else if (choice == 9)
    {
        selectionsort();
    }
    else if (choice == 10)
    {
        InsetSort();
    }

    else if (choice == 11)
    {
        Bubblesort();
    }

    else if (choice == 12)
    {
        Merge();
    }
    else if (choice == 13)
    {
        heapsort();
    }
    else if (choice == 14)
    {
        Qicksort();
    }
    else
    {
        cout << "Lua chon khong hop le!\n";
    }

    return 0;
}
