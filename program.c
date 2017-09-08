#include <stdio.h>

int main()
{
	/*int count1, count2, count3, count4, count5, count6, count7, count8, count9, count10, 
	count11, count12, count13, count14, count15, count16, count17, count18, count19, count20, 
	count21, count22, count23, count24, count25, count26, count27, count28, count29, count30, 
	count31, count32, count33, count34, count35, count36, count37, count38, count39, count40, 
	count41, count42, count43, count44, count45, count46, count47, count48, count49, count50, 
	count51, count52, count53, count54, count55, count56, count57 = 0;*/
	int i;
	int ch;
	
	int count[60];
	
	for (i = 0; i <= 60; i++) {
		count[i] = 0;
	}

	FILE *fp;
	fp = fopen("op1data.txt", "r");
	
	if (fp == NULL) {
		printf ("Error;");
		return 1;
	}
	
	rewind(fp);
	while (fscanf(fp, "%d%*c%*c", &ch) != EOF) {
		
	    switch(ch)
	    {
            case 1:
            {
                count[1]++;
                break;
            }
            case 2:
            {
                count[2]++;
                break;
            }
            case 3:
            {
                count[3]++;
                break;
            }
            case 4:
            {
                count[4]++;
                break;
            }
            case 5:
            {
                count[5]++;
                break;
            }
            case 6:
            {
                count[6]++;
                break;
            }
            case 7:
            {
                count[7]++;
                break;
            }
            case 8:
            {
                count[8]++;
                break;
            }
            case 9:
            {
                count[9]++;
                break;
            }
            case 10:
            {
                count[10]++;
                break;
            }
            case 11:
            {
                count[11]++;
                break;
            }
            case 12:
            {
                count[12]++;
                break;
            }
            case 13:
            {
                count[13]++;
                break;
            }
            case 14:
            {
                count[14]++;
                break;
            }
            case 15:
            {
                count[15]++;
                break;
            }
            case 16:
            {
                count[16]++;
                break;
            }
            case 17:
            {
                count[17]++;
                break;
            }
            case 18:
            {
                count[18]++;
                break;
            }
            case 19:
            {
                count[19]++;
                break;
            }
            case 20:
            {
                count[20]++;
                break;
            }
            case 21:
            {
                count[21]++;
                break;
            }
            case 22:
            {
                count[22]++;
                break;
            }
            case 23:
            {
                count[23]++;
                break;
            }
            case 24:
            {
                count[24]++;
                break;
            }
            case 25:
            {
                count[25]++;
                break;
            }
            case 26:
            {
                count[26]++;
                break;
            }
            case 27:
            {
                count[27]++;
                break;
            }
            case 28:
            {
                count[28]++;
                break;
            }
            case 29:
            {
                count[29]++;
                break;
            }
            case 30:
            {
                count[30]++;
                break;
            }
            case 31:
            {
                count[31]++;
                break;
            }
            case 32:
            {
                count[32]++;
                break;
            }
            case 33:
            {
                count[33]++;
                break;
            }
            case 34:
            {
                count[34]++;
                break;
            }
            case 35:
            {
                count[35]++;
                break;
            }
            case 36:
            {
                count[36]++;
                break;
            }
            case 37:
            {
                count[37]++;
                break;
            }
            case 38:
            {
                count[38]++;
                break;
            }
            case 39:
            {
                count[39]++;
                break;
            }
            case 40:
            {
                count[40]++;
                break;
            }
            case 41:
            {
                count[41]++;
                break;
            }
            case 42:
            {
                count[42]++;
                break;
            }
            case 43:
            {
                count[43]++;
                break;
            }
            case 44:
            {
                count[44]++;
                break;
            }
            case 45:
            {
                count[45]++;
                break;
            }
            case 46:
            {
                count[46]++;
                break;
            }
            case 47:
            {
                count[47]++;
                break;
            }
            case 48:
            {
                count[48]++;
                break;
            }
            case 49:
            {
                count[49]++;
                break;
            }
            case 50:
            {
                count[50]++;
                break;
            }
            case 51:
            {
                count[51]++;
                break;
            }
            case 52:
            {
                count[52]++;
                break;
            }
            case 53:
            {
                count[53]++;
                break;
            }
            case 54:
            {
                count[54]++;
                break;
            }
            case 55:
            {
                count[55]++;
                break;
            }
            case 56:
            {
                count[56]++;
                break;
            }
            case 57:
            {
                count[57]++;
                break;
            }
		}
	}
	
	long int sum = 0;
	for ( i = 1; i <= 57; i++) {
		sum += count[i];
		printf ("Candidate %d: %d\n", i, count[i]);
	}
	
	printf ("The total: %ld", sum);
	
	fclose(fp);
	return 0;
}
