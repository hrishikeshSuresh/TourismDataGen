#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <random.h>

int main(int argc, char const *argv[]){
  FILE *fp1 = fopen('country_city.csv','r');
  FILE *fp2 = fopen('tourist_destination.csv','w');
  char country[50];
  char city[30];
  char country_code[10];
  char best_time_to_visit[10];
  int rating;
  char month[][] = ["January","February","March","April","June","July","August","September","October","November","December"];
  while(fgets(token,100,fp)!=NULL){
    country = strtok(token,',');
    city = strtok(NULL,',');
    best_time_to_visit = month[random(0,12)];
    rating = random(4,11);
    country_code = strtok(NULL,'\n');
    fprintf(fp2,"%s,%s,%s,%d,%s%s%s%d\n",country,city,best_time_to_visit,rating,country_city,city[0],city[1],random(0,100));
  }
  fclose(fp1);
  fclose(fp2);
}
