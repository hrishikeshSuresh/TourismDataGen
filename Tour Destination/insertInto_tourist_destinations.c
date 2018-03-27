#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	FILE *fp1 = fopen("tourist_destination.csv","r+");
  	FILE *fp2 = fopen("tourist_destination_table.sql","w");
  	printf("HELLO");
  	char token[50];
  	char *country;
  	char *city;
  	char *country_code;
  	char *best_time_to_visit;
  	int rating;
	int code;
  	while(fgets(token,sizeof(token),fp1)!=NULL){
    	country = strtok(token,",");
    	city = strtok(NULL,",");
    	best_time_to_visit = strtok(NULL,",");
    	rating = atoi(strtok(NULL,","));
    	country_code = strtok(NULL,"\n");
		code = atoi(strtok(token,"\n"));
		fprintf(fp2,"insert into tourist_destination values(\"%s\",\"%s\",\"%s\",%d,\"%s%d\");\n",country,city,best_time_to_visit,rating,country_code,code);
  	}
  	fclose(fp1);
  	fclose(fp2);
  	return 0;
}
