#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[]){
	FILE *fp1 = fopen("country_city.csv","r");
	FILE *fp2 = fopen("primary_key_tourist_destination_id.csv","r");
	FILE *fp3,*fp6;
	FILE *fp4 = fopen("airline.csv","w");
	FILE *fp5 = fopen("airline_id.csv","w");
	FILE *fp7 = fopen("Packages_travels.csv","w");
	char *source_code,*source_country,*source_city;
	char *dest_code,*dest_country,*dest_city;
	int cost;
	char luxury_class_list[2][50] = {"Economy Class","Business Class"};
	char token1[100],token2[100],token3[100];
	char *luxury_class;
	int code;
	char *package_id;
	int i = 30;
	while(fgets(token1,sizeof(token1),fp1)!=NULL){
		fp3 = fopen("country_city.csv","r");
		fp6 = fopen("package.csv","r");
		source_city = strtok(token1,",");
		source_country = strtok(NULL,",");
		source_code = strtok(NULL,",");
		while(fgets(token2,sizeof(token2),fp3)!=NULL && fgets(token3,sizeof(token3),fp6)!=NULL ){
			dest_city = strtok(token2,",");
			dest_country = strtok(NULL,",");
			dest_code = strtok(NULL,",");
			package_id = strtok(token3,",");
			if(strcmp(dest_country,source_country)!=0){
				if(strcmp(dest_city,source_city)!=0){
					code = i;
					cost = 3000 + rand()%2000;
					luxury_class = luxury_class_list[rand()%2];
					fprintf(fp5,"%s%s%d\n",source_code,dest_code,code);
					fprintf(fp4,"%s%s%d,%s,%s,%s,%d\n",source_code,dest_code,code,source_city,dest_city,luxury_class,cost);
					fprintf(fp7,"%s\n",package_id);					
					i = i + 6;			
				}					
			}
		}
		fflush(fp3);
		fflush(fp6);
		fflush(fp1);
	}
}
