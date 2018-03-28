#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[]){
	FILE *fp1 = fopen("tour_operator_names.csv","r");
	FILE *fp2 = fopen("tour_operator.csv","w");
	FILE *fp3 = fopen("primary_key_tourID","w");
	FILE *fp4 = fopen("primary_key_tourist_destination_id.csv","r");
	FILE *fp5 = fopen("tour_operator.sql","w");
	char tour_operators_names[9][20] = {"Krishna Tours","Aphrodite Tours","Pan Tours","Tandas Tours","Boozey Woozey Tours","PUBG Tours","Bambooo Tours","Mythos Tours","FortNite Tours"};
	char token[100];
	char tour_operator_ID[9][10] = {"KRI8347","APH9348","PAN4738","TAN7563","BOO8423","PUB7458","BAM7523","MYT2312","FOR4063"};
	int tour_no = 0;
	char *tour_operator;
	char *tour_ID;
	char *package_id;
	int rating = 0;
	char *experience;
	char experience_list[13][100] = {"Not Rated","Very Poor","Poor","Mediocre","Average","Better than many other operators","Good","Very Good","Awesome","Outstanding","The best tour operator"};
	while(fgets(token,sizeof(fp4),fp4)!=NULL){
		tour_no = rand()%8;
		tour_operator = tour_operators_names[tour_no];
		tour_ID = tour_operator_ID[tour_no];
		package_id = strtok(token,"\n");
		rating = rand()%11;
		if(package_id == NULL)
				continue;
		experience = experience_list[rating];
		fprintf(fp2,"%s,%s,%s,%d,%s\n",tour_ID,tour_operator,package_id,rating,experience);
		fprintf(fp5,"insert into tour_operator values(\"%s\",\"%s\",\"%s\",%d,\"%s\");\n",tour_ID,tour_operator,package_id,rating,experience);
		fprintf(fp3,"%s\n",tour_ID);
		fflush(fp5);
		fflush(fp2);
		fflush(fp3);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
}
