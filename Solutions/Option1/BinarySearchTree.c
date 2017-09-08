#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MAXLENGTH 255
#define MAXWIDTH 40


typedef struct node *nodePtr;
typedef struct datum candidate;

struct datum{
    int name;
    long int votes;
};

struct node{
	candidate *data;
	nodePtr left;
	nodePtr right;
};

typedef struct node node;


candidate *create(int);
void vote(nodePtr, int);
void displaytree(nodePtr);
void inorderdisplay(nodePtr);
nodePtr findHighVotes(nodePtr root);

int main()
{
    FILE *fp;
    fp = fopen("../op1data2.txt", "r");

    if (fp == NULL) {
        printf ("Cannot open file. Exiting...\n");
        return ERROR;
    }
    

    int num;
    unsigned int totalVotes = 0;
    
    nodePtr root = NULL;
    
	rewind(fp);
    while (fscanf(fp, "%d%*c%*c", &num) != EOF) {
		totalVotes++;
         if (root == NULL) {
    	 	root = malloc(sizeof(node));
    	 	root->data = create(num);
    	 	root->left = NULL;
    	 	root->right = NULL;
    	 	continue;
    	 }
        vote (root, num);
    }
    
	//displaytree(root);
	inorderdisplay(root);
	printf ("\nTotal Votes: %ld\n", totalVotes);
	
	
	nodePtr highestCand = findHighVotes(root);
	
	int highestName = highestCand->data->name;
	float highestVotes = highestCand->data->votes;
	printf ("\nHighest voted candidate: %d\n\t Votes: %.f\n\n", highestName, highestVotes);
	
	printf ("\n=====================================\n");
	if ( highestVotes > (totalVotes * 0.5)) {
		printf ("\nCandidate %ld is the winner with %.f%% of the votes\n", highestName, (highestVotes / totalVotes) * 100);
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


void vote(nodePtr root, int name) {
	nodePtr q = root;
	nodePtr p;

	p = malloc(sizeof(node));
	p->data = create(name);
	p->left = NULL;
	p->right = NULL;

		while((q->left != p) && (q->right != p)){
			if (q->data->name == name) {
				q->data->votes++;
				return;
			}
			else if (q->data->name > name){
				if (q->left == NULL){
					q->left = p;
				}
				else{
					q = q->left;
				}
			}	
			else{
				if (q->right == NULL){
					q->right = p;
				}
				else{
					q = q->right;
				}
			}
		}	
}

void inorderdisplay(nodePtr root){
	if(root != NULL){
		inorderdisplay(root->left);
		printf("Name: %d\n\tVotes: %ld\n", root->data->name, root->data->votes);
		inorderdisplay(root->right);
	}
}

nodePtr findHighVotes(nodePtr root){
	int candHighest = 0;
	int candHighestVotes = 0;
	if(root != NULL){		//inorder
		findHighVotes(root->left);
		if (root->data->votes > candHighestVotes){
			candHighest = root->data->name;
			candHighestVotes = root->data->votes;
		}
		findHighVotes(root->right);
	}
	
	nodePtr highest;
	highest = malloc(sizeof(node));
	highest->data = malloc(sizeof(candidate));
	highest->data->name = candHighest;
	highest->data->votes = candHighestVotes;
	highest->left = NULL;
	highest->right = NULL;
	return highest;
}

void displaytree(nodePtr root){
	nodePtr stack[MAXLENGTH], p;
	int level[MAXLENGTH][1];
	int top, n, i; 
	int width = 4;
	if(root != NULL){
		printf("display\n");
		top = 1;
		stack[top] = root;
		level[top][0] = width;
		while(top > 0){
			p = stack[top];
			n = level[top][0];
			for(i=1; i<=n; i++)
				printf(" ");
			printf("%d   %d", p->data->name, p->data->votes);
			for(i=n+1; i<=MAXWIDTH; i++)
				printf("-");
			printf("\n");
			top--;
			if(p->right != NULL){
				top++;
				stack[top] = p->right;
				level[top][0] = n + width;
			}
			if(p->left != NULL){
				top++;
				stack[top] = p->left;
				level[top][0] = n + width;
			}
				
		}
	}
}
