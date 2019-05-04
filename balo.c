#include<stdio.h>

void readFile(char *fileName, int g[], int v[], int *pW, int *pN)
{
	FILE *f=fopen(fileName, "rt");
	if (f!=NULL)
	{
		int i;
		fscanf(f,"%d%d",pW,pN); // W N
		for(i=0;i<= (*pN)-1;i++)
			fscanf(f,"%d%d",&g[i],&v[i]); // Trong luong  Gia tri
		fclose(f);
	}
}

int main()
{
	/*	W: trong luong ba lo
		N: so luong vat
		gi: trong luong vat thu i
		vi: gia tri vat thu i
	*/
	
	int W, N,i;
	int v[100],g[100];
	
	readFile("balo.inp",g,v,&W,&N);
	printf("%d %d\n",W,N);
	//Test for reading file
	for(i=0;i<=N-1;i++)
		printf("%d %d\n",g[i],v[i]);
	return 0;
}


