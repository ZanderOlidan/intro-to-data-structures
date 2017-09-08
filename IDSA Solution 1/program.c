#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MYNULL -1

int NumOfCandidates (FILE *);
void initArr(int arr[], int );
void voteNow(FILE *, int arr[]);

int main()
{
	typedef int boolean;
	int i, inputNum, num;
	int maxNum = 0;
	
	FILE *fp;
	fp = fopen("op1data.txt", "r");
	
	if (fp == NULL) {
		printf ("Error;");
		return 1;
	}
	/*
	 *
	 * Processes
	 *
	 */
	
	/* find max number of candidates (already added 1 in the function) */
	maxNum = NumOfCandidates(fp);
	printf ("max: %d\n", maxNum);
	
	/* Initiating the array, make every index = 0 */
	int count[maxNum];
	initArr(count, maxNum);
	
	/* main counting */
	voteNow(fp, count);
	
	/*
	 *
	 * Showing results
	 *
	 */
	
	/* long int because total sum > 32000 (int 4bit) */
	long int sum = 0;
	
	for ( i = 1; i <= maxNum; i++) {
		sum += count[i];
		printf ("Candidate %d: %d\n", i, count[i]);
	}
	
	
	int winrate = sum * 0.5;
	boolean winner = FALSE;
	int candidateWinner = 0;
	
	
	for ( i = 1 ; i <= maxNum; i++) {
		if(count[i] > winrate)
		{
			candidateWinner = i;
			winner = TRUE;
	    }
	}
	
	float voteper;
	printf ("\n\nTotal votes: %ld", sum);
	
	float total = sum;  // because sum is int, dividing using int will truncate results 
	if (winner) {
		printf("\nCandidate %d is the winner", candidateWinner);
		voteper = (count[candidateWinner]/total)*100;
		printf("\nThe percentage of votes are %.1f%%.\n", voteper);
	}
	else {
		printf ("\nA candidate with more than 50%% votes is not found\n");
	}
	
	fclose(fp);
	return 0;
}

int NumOfCandidates (FILE *fp) {
	int num;
	int maxNum = 0;

	while (fscanf(fp, "%d%*c%*c", &num) != EOF) {
		if (num > maxNum) {
			maxNum = num;
		}
	}
	
	return maxNum;
}

void initArr(int arr[], int maxNum){
	int i;
	for (i = 0; i <= maxNum; i++) {
		arr[i] = 0;
	}	
}

void voteNow(FILE *fp, int arr[]) {
	int inputNum;
	rewind(fp);
	while (fscanf(fp, "%d%*c%*c", &inputNum) != EOF) {
		arr[inputNum]++;
	}
}

