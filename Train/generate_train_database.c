#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[]){
	FILE *fp1 = fopen("country_city.csv","r");
	//FILE *fp2 = fopen("primary_key_tourist_destination_id.csv","r");
	FILE *fp3;
	FILE *fp4 = fopen("train.csv","w");
	FILE *fp5 = fopen("train_id.csv","w");
	char *source_code,*source_country,*source_city;
	char *dest_code,*dest_country,*dest_city;
	int cost;
	char luxury_class_list[3][50] = {"Economy Class","Sleeper Class","AC Class"};
	char token1[100],token2[100];
	char *luxury_class;
	int code;
	while(fgets(token1,sizeof(token1),fp1)!=NULL){
		fp3 = fopen("country_city.csv","r");
		source_city = strtok(token1,",");
		source_country = strtok(NULL,",");
		source_code = strtok(NULL,",");
		while(fgets(token2,sizeof(token2),fp3)!=NULL){
			dest_city = strtok(token2,",");
			dest_country = strtok(NULL,",");
			dest_code = strtok(NULL,",");
			if(strcmp(dest_country,source_country)==0){
				if(strcmp(dest_city,source_city)!=0){
					code = rand()%200 + 201;
					cost = 500 + rand()%1000;
					luxury_class = luxury_class_list[rand()%3];
					fprintf(fp5,"%s%d\n",dest_code,code);
					fprintf(fp4,"%s%d,%s,%s,%s,%d\n",dest_code,code,source_city,dest_city,luxury_class,cost);
				}					
			}
		}
		fflush(fp3);
		fflush(fp1);
	}
}
