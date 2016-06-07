  1 #include <stdio.h>
  2 int main(void)
  3 {
  4     FILE* save;//변수받는 놈
  5     char variance[10];//변수받는 새끼
  6     int i;// 도우미년
  7
  8     save=fopen("save.txt", "rw");
  9
 10     fscanf(save, "%c", &variance[i]);
 11     if (1)
 12     {
 13         for (i=1;i<=10;i++)
 14             fputc(variance[i], save);
 15
 16         if ((save = fopen("save.txt", "r"))!=NULL)
 17         {
 18             while ((variance[i] = fgetc(save))!=EOF)
 19                 printf("save.txt의 내용 %c\n", variance[i]);
 20
 21         }
 22     }
 23
 24     fclose(save);
 25
 26
 27
 28 }
 29
~
