#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Buffer_Len 500
#define MAX 100000
#define Len 50

typedef struct Web
{
	char ip[Len];
	char time[Len];
	char URL[Len];
	char state[Len];
}Web;
Web *four;
int n = 0;

void read() {
	char buffer[Buffer_Len];
	scanf("%s", buffer);
	FILE *read_fp = fopen(buffer, "r");

	char str[MAX];
	fgets(str, MAX, read_fp);
	while (!feof(read_fp)) {
		fgets(str, MAX, read_fp);

		char *token = strtok(str, ",");
		strcpy(four[n].ip, token);
		token = strtok(NULL, ",[");
		strcpy(four[n].time, token);
		token = strtok(NULL, ",");
		strcpy(four[n].URL, token);
		token = strtok(NULL, ",");
		strcpy(four[n].state, token);
		n++;
	}
	fclose(read_fp);
}
int month_test(char temp[]) {
	if (strcmp(temp, "Jan") == 0) {
		return 1;
	}
	else if (strcmp(temp, "Feb") == 0) {
		return 2;
	}
	else if (strcmp(temp, "Mar") == 0) {
		return 3;
	}
	else if (strcmp(temp, "Apr") == 0) {
		return 4;
	}
	else if (strcmp(temp, "May") == 0) {
		return 5;
	}
	else if (strcmp(temp, "Jun") == 0) {
		return 6;
	}
	else if (strcmp(temp, "Jul") == 0) {
		return 7;
	}
	else if (strcmp(temp, "Aug") == 0) {
		return 8;
	}
	else if (strcmp(temp, "Sep") == 0) {
		return 9;
	}
	else if (strcmp(temp, "Oct") == 0) {
		return 10;
	}
	else if (strcmp(temp, "Nov") == 0) {
		return 11;
	}
	return 12;
}
int compare_time(const void *first, const void *second) {
	char a[MAX], b[MAX];
	strcpy(a, ((Web *)first)->time);
	strcpy(b, ((Web *)second)->time);

	char time1[4][MAX];
	char time2[4][MAX];

	char *token_a = strtok(a, "/ "); //a분석
	strcpy(time1[0], token_a);	
	token_a = strtok(NULL, "/ ");
	strcpy(time1[1], token_a);	
	token_a = strtok(NULL, ": ");
	strcpy(time1[2], token_a);	
	token_a = strtok(NULL, "/ ");
	strcpy(time1[3], token_a);		

	char *token_b = strtok(b, "/ "); //b분석
	strcpy(time2[0], token_b);
	token_b = strtok(NULL, "/ ");
	strcpy(time2[1], token_b);
	token_b = strtok(NULL, ": ");
	strcpy(time2[2], token_b);
	token_b = strtok(NULL, "/ ");
	strcpy(time2[3], token_b);

	int result = strcmp(time1[2], time2[2]); //결과
	if (result != 0)
		return result;

	int day1 = month_test(time1[1]);
	int day2 = month_test(time2[1]);

	result = day1 - day2;

	if (result != 0)
		return result;

	result = strcmp(time1[3], time2[3]);
	if (result != 0)
		return result;
}
int compare_ip(const void *first, const void *second) {
	int result = strcmp(((Web*)first)->ip, ((Web*)second)->ip);
	if (result != 0)
		return result;
	return compare_time(first, second);
}

void print() {
	for (int i = 0; i < n; i++) {
		printf("time:%s\n", four[i].time);
		printf("\tURL:%s\n", four[i].URL);
		printf("\tip:%s\n", four[i].ip);
		printf("\tstatus:%s\n", four[i].state);
	}
}
int main()
{
	four = (Web *)malloc(MAX * sizeof(Web));

	char buffer[Buffer_Len];
	char buffer2[Buffer_Len];
	while (1) {
		printf("$ ");
		scanf("%s", buffer);
		if (strcmp(buffer, "read") == 0)
			read();
		else if (strcmp(buffer, "sort") == 0) {
			scanf("%s", buffer2);

			if (strcmp(buffer2, "-t") == 0) {
				qsort(four, n, sizeof(Web), compare_time);
			}
			else if (strcmp(buffer2, "-ip") == 0) {
				qsort(four, n, sizeof(Web), compare_ip);
			}
			else
				continue;
		}
		else if (strcmp(buffer, "print") == 0)
			print();
	}
}