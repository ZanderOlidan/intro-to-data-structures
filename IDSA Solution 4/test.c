#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ch=0, vote=0, j=1, total=0, total2=0, max=0;
	FILE * fp;
	fp = fopen ("outputop1data.txt","r");
	 while (fscanf(fp, "%d ", &ch)!=EOF){
		if (ch>max)
			max=ch;}
	rewind(fp);
	for(j=1;j<=max;j++){
		while(fscanf(fp, "%d ", &ch)==1){
			if (ch==j)
				++vote;
			else
				break;
		}
		printf("There are %d of votes for Candidate %d.\n", vote, j);
		total+=vote;
		vote=1;
	}	


	
	rewind(fp);
	vote=0;
	for(j=1;j<=max;j++){
		while(fscanf(fp, "%d ", &ch)==1){
			if (ch==j)
				++vote;	
			else if ((((float)vote/total)*100)>50.00){
				printf("Candidate %d is the next chief executive.\n", j);
				exit(1);}
			else if ((((float)total2/total)*100)>50.00){
				printf("The election was not successful.");
				exit(1);
			}
			else
				break;
		}
		total2+=vote;
		vote=1;

}
fclose(fp);	
return 0;
}
