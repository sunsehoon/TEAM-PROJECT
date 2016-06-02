#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char fvar[] = "save.txt";
	char var[10];

	FILE*f;

	printf("변수 저장할꺼냥?\n");
	scanf("%s", &var);

	//open save.txt

	if ((f=fopen(fvar, "w"))==NULL){
		printf("file open error.");
		exit(1);
	}

	// write save.txt
	fprintf(f, "%s", var);

	fclose(f);
}
