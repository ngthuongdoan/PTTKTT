// Bai toan cai ba lo 1
// Moi do vat co so luong khong han che
// Giai bang phuong phap NHANH CAN
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 100
typedef struct
{
    char TenDV[20];
    float TL, GT;
    int PA;
} DoVat;
DoVat *dsdv;    // Danh sach cac do vat (danh sach dong)
int n;          // luu so luong do vat
int x[MAX];     // Luu phuong an tot nhat tam thoi
float W;        // Luu trong luong cua Ba lo
float CT;       // Luu can tren
float TGT;      // Luu Tong gia tri cua cac vat da duoc chon tai moi nut
float GiaLNTT;  // Luu Gia lon nhat tam thoi
float TLConLai; // Luu Trong luong con lai cua Ba lo tai moi nut
DoVat *ReadFromFile(float *W, int *n)
{
    FILE *f;
    f = fopen("E:\\Code\\C\\PTTKTT\\Thi\\caibalo.inp", "r");
    fscanf(f, "%f", W); // Xac dinh trong luong Ba lo
    DoVat *dsdv;
    dsdv = (DoVat *)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f))
    {
        fscanf(f, "%f%f", &dsdv[i].TL, &dsdv[i].GT);
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
    printf("|---|--------------------|---------|---------|---------|---------|\n");
    printf("|%-3s|%-20s|%-9s|%-9s|%-9s|%-9s|\n", "STT", " Ten Do Vat", "T.Luong", "Gia Tri", "Don Gia", "P. An");
    printf("|---|--------------------|---------|---------|---------|---------|\n");
    for (i = 0; i < n; i++)
    {
        printf("|%-3d", i + 1);
        printf("|%-20s", dsdv[i].TenDV);
        printf("|%-9.1f", dsdv[i].TL);
        printf("|%-9.1f", dsdv[i].GT);
        printf("|%-9.1f", dsdv[i].GT / dsdv[i].TL);
        printf("|%-9d|\n", dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }
    printf("|---|--------------------|---------|---------|---------|---------|\n");
    printf("Trong luong cua ba lo= %9.1f\n", W);
    printf("Tong trong luong= %9.1f, Tong gia tri= %9.1f\n", TongTL,
           TongGT);
}
// Tinh cac dai luong tai nut goc
void init()
{
    TLConLai = W;
    CT = TLConLai * (dsdv[0].GT / dsdv[0].TL); // Can tren cua nut goc
    GiaLNTT = 0.0;
    TGT = 0.0;
}
//Ghi nhan phuong an tot nhat tam thoi
void GhiNhanKyLuc()
{
    int i;
    if (GiaLNTT < TGT)
    {
        GiaLNTT = TGT;
        for (i = 0; i < n; i++)
            dsdv[i].PA = x[i];
    }
}
void Try(int i)
{
    int j; // j la so vat duoc chon
    for (j = TLConLai / dsdv[i].TL; j >= 0; j--)
    {
        TGT = TGT + j * dsdv[i].GT;
        TLConLai = TLConLai - j * dsdv[i].TL;
        CT = TGT + TLConLai * dsdv[i + 1].GT / dsdv[i + 1].TL;
        if (CT > GiaLNTT)
        { // Chua cat tia
            x[i] = j;
            if ((i == n - 1) || (TLConLai == 0)) // Xet het tat ca cac do vat hoac da day ba lo
                GhiNhanKyLuc();
            else
                Try(i + 1); //Xet nut con cua nut i
        }
        // Quay lui xet
        x[i] = 0;
        TGT = TGT - j * dsdv[i].GT;
        TLConLai = TLConLai + j * dsdv[i].TL;
    }
}
int main()
{
    dsdv = ReadFromFile(&W, &n);
    BubbleSort(dsdv, n);
    init();
    Try(0);
    InDSDV(dsdv, n, W);
    free(dsdv);
    return 0;
}