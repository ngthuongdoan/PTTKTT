#include <stdio.h>
/*Khai bao*/
typedef int keytype;
typedef float othertype;
typedef struct
{
    keytype key;
    othertype otherfields;
} recordtype;
/*Doi cho*/
void Swap(recordtype &x, recordtype &y)
{
    recordtype temp;
    temp = x;
    x = y;
    y = temp;
}
/*Selection Sort*/
void SelectionSort(recordtype a[], int n)
{
    int i, j, lowindex;
    keytype lowkey;
    for (i = 0; i <= n - 2; i++)
    {
        lowkey = a[i].key;
        lowindex = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (a[j].key < lowkey)
            {
                lowkey = a[j].key;
                lowindex = j;
            }
        }
        Swap(a[i], a[lowindex]);
    }
}

void InsertionSort(recordtype a[], int n)
{
    int i, j;
    for (i = 1; i <= n - 1; i++)
    {
        j = i;
        while ((j > 0) && (a[j].key < a[j - 1].key))
        {
            Swap(a[j], a[j - 1]);
            j--;
        }
    }
}

void BubbleSort(recordtype a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j >= i + 1; j--)
            if (a[j].key < a[j - 1].key)
                Swap(a[j], a[j - 1]);
}

/*----------QuickSort----------*/
/*FindPivot*/
int FindPivot(recordtype a[], int i, int j)
{
    keytype firstkey;
    int k;
    k = i + 1;
    firstkey = a[i].key;
    while ((k <= j) && (a[k].key == firstkey))
        k++;
    if (k > j)
        return -1;
    if (a[k].key < firstkey)
        return k;
    return i;
}
/*Partition*/
int Partition(recordtype a[], int i, int j, keytype pivot)
{
    int L, R;
    L = i;
    R = j;
    while (L <= R)
    {
        while (a[L].key <= pivot)
            L++;
        while (a[R].key > pivot)
            R--;
        if (L < R)
            Swap(a[L], a[R]);
    }
    return L;
}
void QuickSort(recordtype a[], int i, int j)
{
    keytype pivot;
    int pivotindex, k;
    pivotindex = FindPivot(a, i, j);
    if (pivotindex != -1)
    {
        pivot = a[pivotindex].key;
        k = Partition(a, i, j, pivot);
        QuickSort(a, i, k - 1);
        QuickSort(a, k, j);
    }
}
/*----------HeapSort----------*/
/*PushDown*/
void PushDown(recordtype a[], int first, int last)
{
    int r = first;
    while (r <= (last - 1) / 2)
        if (last == 2 * r + 1)
        {
            if (a[r].key > a[last].key)
                Swap(a[r], a[last]);
            r = last;
        }
        else if ((a[r].key > a[2 * r + 1].key) && (a[2 * r + 1].key < a[2 * r + 2].key))
        {
            Swap(a[r], a[2 * r + 1]);
            r = 2 * r + 1;
        }
        else if ((a[r].key > a[2 * r + 2].key) && (a[2 * r + 2].key < a[2 * r + 1].key))
        {
            Swap(a[r], a[2 * r + 2]);
            r = 2 * r + 2;
        }
        else
            r = last;
}
/*HeapSort*/
void HeapSort(recordtype a[], int n)
{
    int i;
    for (i = (n - 2) / 2; i >= 0; i--)
        PushDown(a, i, n - 1);
    for (i = n - 1; i >= 2; i--)
    {
        Swap(a[0], a[i]);
        PushDown(a, 0, i - 1);
    }
    Swap(a[0], a[1]);
}

main()
{
    int n, i;
    recordtype a[100];
    FILE *file = fopen("dayso.inp", "r");
    fscanf(file, "%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        fscanf(file, "%d", &a[i]);
    }
    // SelectionSort(a, n);
    // InsertionSort(a,n);
    // BubbleSort(a,n);
    // QuickSort(a, 0, n - 1);
    // HeapSort(a, n);
    printf("Day sau khi sap xep theo kieu Selection_Sort la:\n\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", a[i]);
    }
}