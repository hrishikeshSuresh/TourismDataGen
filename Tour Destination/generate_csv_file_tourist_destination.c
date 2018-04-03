#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	FILE *fp1 = fopen("country_city.csv","r+");
  	FILE *fp2 = fopen("tourist_destination.csv","w");
	FILE *fp3 = fopen("primary_key_tourist_destination_id.csv","w");
  	char token[100];
  	char *country;
  	char *city;
  	char *country_code;
  	char *best_time_to_visit;
  	int rating,code;
  	char month[12][12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  	while(fgets(token,sizeof(token),fp1)!=NULL){
    	country = strtok(token,",");
    	city = strtok(NULL,",");
    	best_time_to_visit = month[rand()%12];
    	rating = rand()%10;
    	country_code = strtok(NULL,"-");
			code = rand()%1000;
  	 	fprintf(fp2,"%s,%s,%s,%d,%s%d\n",country,city,best_time_to_visit,rating,country_code,code);
			fprintf(fp3,"%s%d0\n",country_code,code);
  	}
  	fclose(fp1);
  	fclose(fp2);
	fclose(fp3);
  	return 0;
}
