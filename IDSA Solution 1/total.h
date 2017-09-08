#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MYNULL -1

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
