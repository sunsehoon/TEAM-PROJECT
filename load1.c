#include <stdio.h>
int main(void)
{
	FILE* save;//변수받는 놈
	char variance[10];//변수받는 새끼
	int i;// 도우미년

	save=fopen("save.txt", "rw");

	fscanf(save, "%c", &variance[i]);
	if (1)
	{
		for (i=1;i<=10;i++)
			fputc(variance[i], save);

		if ((save = fopen("save.txt", "r"))!=NULL)
		{
			while ((variance[i] = fgetc(save))!=EOF)
				printf("save.txt의 내용 %c\n", variance[i]);

		}
	}

	fclose(save);



}

