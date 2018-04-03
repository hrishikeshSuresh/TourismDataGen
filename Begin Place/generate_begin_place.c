#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	FILE *fp1 = fopen("country_city.csv","r+");
	FILE *fp2 = fopen("begin_place.csv","w");
	FILE *fp3 = fopen("package_id.csv","r");
	char token1[100],token2[100];
  	char *country;
  	char *city;
  	char *country_code;
	char *p_id;
  	while(fgets(token1,sizeof(token1),fp1)!=NULL && fgets(token2,sizeof(token2),fp3)){
    	city = strtok(token1,",");
    	country = strtok(NULL,",");
    	country_code = strtok(NULL,"-");
		p_id = strtok(token2,"\n");
  	 	fprintf(fp2,"%s,%s\n",p_id,city);
  	}
  	fclose(fp1);
  	fclose(fp2);
	fclose(fp3);
  	return 0;
}
