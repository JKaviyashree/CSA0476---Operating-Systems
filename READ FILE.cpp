#include<stdio.h>
int main(){
	FILE *n;
	n=fopen("PS.txt","r");
	char ch[1000];
	int count=fread(&ch,sizeof(char),10,n);
	fclose(n);
	printf("%s",ch);
	return 0;
}
