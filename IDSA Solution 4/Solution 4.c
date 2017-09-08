#include <stdio.h>
#include<string.h>
void insert();
int main()
{
	int i;
    int num;
	int maxNum = 0;
	int ch;
	FILE *fp,*ft;
	fp = fopen("op1data2.txt", "r");
	if (fp == NULL) 
	{
		printf ("Error;");
	}
	ft = fopen("op1newdata.txt", "a+");
	if (ft == NULL) 
	{
		printf ("Error;");
	};
		while (fscanf(fp, "%d%*c%*c", &num) != EOF) 
	{
		if (num > maxNum) {
			maxNum = num;
		}
	};
	rewind(fp);
	for(i=1;i<=maxNum;i++)
	{
		rewind(fp);
		while (fscanf(fp,"%d%*c%*c",&ch) != EOF) 
	{
		if(ch==i)
		{
			fprintf(ft,"%d ",ch);
		}
	}
	printf("%d.insertion success! \n",i);
    }
    fclose(fp);
    fclose(ft);
}

