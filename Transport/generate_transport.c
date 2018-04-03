#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[]){
	FILE *fp1 = fopen("bus.csv","r");
	FILE *fp2 = fopen("train.csv","r");
	FILE *fp3 = fopen("transport.csv","w");
	char token1[100];
	char token2[100];
	char *train_code, *bus_code;
	while(fgets(token1,sizeof(token1),fp1)!=NULL && fgets(token2,sizeof(token2),fp2)){
		train_code = strtok(token1,",");
		bus_code = strtok(token2,",");
		fprintf(fp3,"%s,%s\n",train_code,bus_code);
		fflush(fp3);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
