#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1


typedef struct node *nodePtr;
typedef struct datum candidate;

struct datum{
    int name;
    long int votes;
};

struct node{
	candidate *data;
	nodePtr next;
};

typedef struct node node;


candidate *create(int);
void vote(nodePtr, int);
void display(nodePtr, int);
nodePtr findHighVotes(nodePtr);

int main()
{
    FILE *fp;
    fp = fopen("../op1data2.txt", "r");

    if (fp == NULL) {
        printf ("Cannot open file. Exiting...\n");
        return ERROR;
    }
    
    int num;
    int candCount = 0; //counts the num of candidates
    
    nodePtr root = NULL;
    
	rewind(fp);
    while (fscanf(fp, "%d%*c%*c", &num) != EOF) {
		candCount++;
        if (root == NULL) {
    		root = malloc(sizeof(node));
    		root->data = create(num);
    		root->next = NULL;
    		continue;
    	}
        vote (root, num);
    }
    
	display(root, candCount);
	
	nodePtr highestCand = findHighVotes(root);
	
	int highestName = highestCand->data->name;
	float highestVotes = highestCand->data->votes;
	printf ("\nTotal Votes: %ld\n", candCount);
	printf ("\nHighest voted candidate: %d\n\t Votes: %.f\n\n", highestName, highestVotes);
	
	printf ("\n=====================================\n");
	if ( highestVotes > (candCount * 0.5)) {
		printf ("\nCandidate %ld is the winner with %.f%% of the votes\n", highestName, (highestVotes / candCount) * 100);
	}
	else  {
		printf ("\nNo winner because no candidate gained more than 50%% to the total votes\n\n");
	}
	
	fclose(fp);
    return 0;
}

candidate *create (int name) {
	candidate *q;
    q = malloc(sizeof(candidate));

	q->name = name;
	q->votes = 1;
	return q;
}


void vote(nodePtr p, int name) {
	nodePtr previous;
	
	
	while (p != NULL) {
		if (p->data->name == name) {
			p->data->votes++;
			return;
		}
		previous = p;
		p = p->next;
	}
	
	previous->next = malloc(sizeof(node));
	previous->next->data = create(name);
	previous->next->next = NULL;
	
}

nodePtr findHighVotes(nodePtr root) {
	int candHighest = 0;
	int candHighestVotes = 0;
	
	nodePtr p = root;
	nodePtr previous;
	while (p != NULL) { 
		if (p->data->votes > candHighestVotes ) {
			candHighest = p->data->name;
			candHighestVotes = p->data->votes;
			break;
		}
		previous = p;
		p = p->next;
	}
	
	nodePtr highest;
	highest = malloc(sizeof(node));
	highest->data = malloc(sizeof(candidate));
	highest->data->name = candHighest;
	highest->data->votes = candHighestVotes;
	return highest;
}

void display(nodePtr p, int candCount) {

	
	int i = 1;
	printf ("\n\n=======================================\n\n");
	
	while (i <= candCount) {
		nodePtr q = p;
		while (q != NULL) {
			if (q->data->name == i) {
				printf ("Name: %d\n\tVotes: %ld\n", q->data->name, q->data->votes);
				break;
			}
			q = q->next;
		}
		i++;
	}
}
