#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct
{
    char TenDV[20];
    float TL, GT;
    int PA, SL;
} DoVat;

DoVat *ReadFromFile(float *W, int *n)
{
    FILE *f;
    f = fopen("CaiBalo2.INP", "r");
    fscanf(f, "%f", W); // Xac dinh trong luong Ba lo
    DoVat *dsdv;
    dsdv = (DoVat *)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f))
    {
        fscanf(f, "%f%f%d", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL);
        fgets(dsdv[i].TenDV, 20, f);
        dsdv[i].TenDV[strlen(dsdv[i].TenDV) - 1] = '\0';
        dsdv[i].PA = 0;
        i++;
        dsdv = (DoVat *)realloc(dsdv, sizeof(DoVat) * (i + 1));
    }
    *n = i;
    fclose(f);
    return dsdv;
}

void swap(DoVat *x, DoVat *y)
{
    DoVat Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}
void BubbleSort(DoVat *dsdv, int n)
{
    int i, j;
    for (i = 0; i <= n - 2; i++)
        for (j = n - 1; j >= i + 1; j--)
        {
            float DGJ = dsdv[j].GT / dsdv[j].TL;
            float DGJ_1 = dsdv[j - 1].GT / dsdv[j - 1].TL;
            if (DGJ > DGJ_1)
                swap(&dsdv[j], &dsdv[j - 1]);
        }
}

void InDSDV(DoVat *dsdv, int n, float W)
{
    int i;
    float TongTL = 0.0, TongGT = 0.0;
    printf("X(");
    for (i = 0; i < n; i++)
    {
        if (i != (n - 1))
        {
            printf("%d, ", dsdv[i].PA);
        }
        else
        {
            printf("%d", dsdv[i].PA);
        }

        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }
    printf(")\n");
    printf("Trong luong cua ba lo= %9.1f\n", W);
    printf("Tong trong luong= %9.1f, Tong gia tri= %9.1f\n", TongTL,
           TongGT);
}
void Greedy(DoVat *dsdv, int n, float W)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if ((W / dsdv[i].TL) >= dsdv[i].SL)
        {
            dsdv[i].PA = dsdv[i].SL;
        }
        else
        {
            dsdv[i].PA = (W / dsdv[i].TL);
        }

        W = W - dsdv[i].PA * dsdv[i].TL;
    }
}

int main()
{
    int n;
    float W;
    DoVat *dsdv;
    dsdv = ReadFromFile(&W, &n);
    BubbleSort(dsdv, n);
    Greedy(dsdv, n, W);
    InDSDV(dsdv, n, W);
    free(dsdv);
    return 0;
}