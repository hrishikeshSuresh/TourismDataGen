#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[]){
	FILE *fp1 = fopen("Hotels.csv","r");
	FILE *fp2 = fopen("Hotels_dataset.csv","w");
	FILE *fp3 = fopen("Hotels_id.csv","w");
	int id;
	char *accomodation_name;
	int rating;
	char *review;
	char *city;
	char token[5000];
	int i = 1004;
	while(fgets(token,sizeof(token),fp1)!=NULL){
		id = i;
		accomodation_name = strtok(token,",");
		rating = atoi(strtok(NULL,","));
		review = strtok(NULL,",");
		city = strtok(NULL,"\n");
		fprintf(fp2,"%d,%s,%d,%s,%s\n",id,accomodation_name,rating,review,city);
		fprintf(fp3,"%d\n",id);
		i = i + 4;
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
