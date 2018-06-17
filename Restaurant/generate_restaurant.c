#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char const *argv[]){
	FILE *fp1 = fopen("Restaurant.csv","r");
	FILE *fp2 = fopen("Restaurant_dataset.csv","w");
	FILE *fp3 = fopen("Restaurant_id.csv","w");
	int id;
	char *restaurant_name;
	char *phone_number;
	char *website;
	char *cuisine;
	char *city;
	char token[300];
	while(fgets(token,sizeof(token),fp1)!=NULL){
		id = atoi(strtok(token,",")) + rand()%6789;
		restaurant_name = strtok(NULL,",");
		phone_number = strtok(NULL,",");
		website = strtok(NULL,",");
		cuisine = strtok(NULL,",");
		city = strtok(NULL,"\n");
		fprintf(fp2,"%d,%s,%s,%s,%s,%s\n",id,restaurant_name,phone_number,website,cuisine,city);
		fprintf(fp3,"%d\n",id);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
