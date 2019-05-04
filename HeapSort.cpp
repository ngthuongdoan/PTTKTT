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
    HeapSort(a, n);
    printf("Day sau khi sap xep theo kieu Heap_Sort la:\n\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", a[i]);
    }
}