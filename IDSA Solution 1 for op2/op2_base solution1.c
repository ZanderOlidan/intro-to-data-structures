#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void search(char [255]);
void bksearch(char [255]);

int main(){
	
	
	FILE *qfile;
	
	qfile=fopen("op2query.txt","r+");
	if(qfile==NULL){
		printf("Failed to load the file.");
		fflush(stdin);getchar();
		return 0;
	}
	
	char query[255];
	int j;
	
	
	while(fscanf(qfile,"%[a-z,A-Z,' ']%",query) != EOF){
		for(j=strlen(query);j>=0;j--){
			if(query[j]==' ')
				j=-1;
		}
		if(j==-1){
			search(query);
		}else{
			bksearch(query);
		}
	}
	fclose(qfile);
	
	system("pause");
	return 0;
}

void search(char q[255]){
	
	char match[255];
	int i=0;
	int found=0;
	
	FILE *infile;
	infile=fopen("op2data.txt","r+");
	if(infile==NULL){
		printf("Failed to load the file.");
		fflush(stdin);getchar();
	}
	
	while(fscanf(infile,"%s",match) !=EOF && found == 0){
		i++;
		if(strcmp(match,q)==0){
			found=1;
			printf("%s %d\n",q,i);
		}
	}
	if(found==0){
		printf("%s --\n",q);
	}
	fclose(infile);
}

void bksearch(char q[255]){
	char match[255];char tmp[255];
	int i=0,j=0;int found=0;
	strcpy(tmp,q);
	
	char *token;
	token = strtok(tmp, " ");
	
	FILE *infile;
	infile=fopen("op2data.txt","r+");
	if(infile==NULL){
		printf("Failed to load the file.");
		fflush(stdin);getchar();
	}
	
	
	
	while(fscanf(infile,"%s",match) !=EOF && found == 0){
		i++;j=0;
		if(strcmp(match,token)==0){
			while((token=strtok(NULL," "))!=NULL){
				fscanf(infile,"%s",match);
				i++;j++;
				if(strcmp(match,token)!=0){
					strcpy(tmp,q);
					token = strtok(tmp, " ");
					break;
				}
			}
			if(token==NULL){
				printf("%s %d\n",q,i-j);
				found=1;
				break;
			}
		}
	}
	if(found== 0){
		printf("%s --\n",q);
	}
	fclose(infile);		
	
}
