/*Written by Gökçe Nur Erer, HW07_Gokce_Nur_Erer_171044079_part2.c*/
#include <stdio.h>

/*Determines if a year is a leap year or not*/
int is_leap_year(int year){
	int leap_year_status=0;
	if(year%400 ==0 || ((year%4==0) && (year%100!=0))){
		leap_year_status=1;
	}
	return leap_year_status;
}
void create_dates(int start_day_i,int start_month_i,int start_year_i,int end_day_i,int end_month_i,int end_year_i,char *date,FILE *input_date){
	/*Month endings of 1,3,5,7,8,10th months*/
	if((start_month_i==1 || start_month_i==3 || start_month_i==5 || start_month_i==7 || start_month_i==8 || start_month_i==10) && start_day_i==31){
		start_day_i=1;
		start_month_i=start_month_i+1;
		sprintf(date,"%02d/%02d/%d",start_day_i,start_month_i,start_year_i);
		fprintf(input_date,"%s\n",date);
	}
	/*Month endings of 4,6,9,11th months*/
	else if((start_month_i==4 || start_month_i==6 || start_month_i==9 || start_month_i==11) && start_day_i==30){
		start_day_i=1;
		start_month_i=start_month_i+1;
		sprintf(date,"%02d/%02d/%d",start_day_i,start_month_i,start_year_i);
		fprintf(input_date,"%s\n",date);
	}
	/*Month ending of 2nd month when year is a leap year*/
	else if(start_month_i==2 && is_leap_year(start_year_i)==1 && start_day_i==29){
		start_day_i=1;
		start_month_i=start_month_i+1;
		sprintf(date,"%02d/%02d/%d",start_day_i,start_month_i,start_year_i);
		fprintf(input_date,"%s\n",date);
	}
	/*Month ending of 2nd month when year is a not leap year*/
	else if(start_month_i==2 && is_leap_year(start_year_i)==0 && start_day_i==28){
		start_day_i=1;
		start_month_i=start_month_i+1;
		sprintf(date,"%02d/%02d/%d",start_day_i,start_month_i,start_year_i);
		fprintf(input_date,"%s\n",date);
	}
	/*Month ending for 12th month, year changes*/
	else if(start_month_i==12 && start_day_i==31){
		start_day_i=1;
		start_month_i=1;
		start_year_i=start_year_i+1;
		sprintf(date,"%02d/%02d/%d",start_day_i,start_month_i,start_year_i);
		fprintf(input_date,"%s\n",date);
	}
	/*If there is none from above increases the day only*/
	else{
		start_day_i=start_day_i+1;
		sprintf(date,"%02d/%02d/%d",start_day_i,start_month_i,start_year_i);
		fprintf(input_date,"%s\n",date);
	}
	printf("%s\n",date);
	/*Continue until the dates are equal*/	
	if(!((start_day_i==end_day_i) && (start_month_i==end_month_i) && (start_year_i==end_year_i))){
			create_dates(start_day_i,start_month_i,start_year_i,end_day_i,end_month_i,end_year_i,date,input_date);
	}
}

/*Checks if the given date is valid*/
int check_date(int day,int month,int year){
	int res=0;
	if((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && (day>0 && day<=31)){
		res=1;
	}
	else if((month==4 || month==6 || month==9 || month==11)&&(day>0 && day<=30)){
		res=1;
	}
	else if(month==2 && is_leap_year(year)==0 && (day>0 && day<=28)){
		res=1;
	}
	else if(month==2 && is_leap_year(year)==1 && (day>0 && day<=29)){
		res=1;
	}
	
	else
		res=0;
	
	return res;
}

/*Makes a file called input_file.txt and writes all dates between given start_date and end_date*/
void input_date(char *start_date,char *end_date){
	/*Opening the file in write mode*/
	FILE *input_date=fopen("input_date.txt","w");
	char date[11];
	int start_day_i,start_month_i,start_year_i,end_day_i,end_month_i,end_year_i;
		sscanf(start_date,"%d/%d/%d",&start_day_i,&start_month_i,&start_year_i);
		sscanf(end_date,"%d/%d/%d",&end_day_i,&end_month_i,&end_year_i);
			if(check_date(start_day_i,start_month_i,start_year_i) && check_date(end_day_i,end_month_i,end_year_i)){
				sprintf(date,"%02d/%02d/%d",start_day_i,start_month_i,start_year_i);
				printf("%s\n",date);
				fprintf(input_date,"%s\n",date);
				create_dates(start_day_i,start_month_i,start_year_i,end_day_i,end_month_i,end_year_i,date,input_date);
			}
		else
			printf("Wrong date input!\n");

	fclose(input_date);
}
/*Finds the day name of a given date, getting base day as 1st of January 1900, Monday. Using "The Key Value" method to find the weekday.*/
char *day_of_week(int day,int month,int year){
	char *weekday[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	int month_keys[12]={1,4,4,0,2,5,0,3,6,1,4,6};
	int week_day;
		week_day=(year-1900)+(year-1900)/4+month_keys[month-1]+day-1;
		if((year>1900) && is_leap_year(year) && month<2){
			week_day--;
		}
		week_day=week_day%7;
	return weekday[week_day];
}
/*Reads the dates from input_date.txt and writes it to new_date.txt with the given rules*/
void new_date(){
	FILE *input_date=fopen("input_date.txt","r");
	FILE *new_date=fopen("new_date.txt","w");
	char num_date[11];
	char *monthname[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int day,month,year,day_code;
		while(fgets(num_date,12,input_date)){
			sscanf(num_date,"%d/%d/%d",&day,&month,&year);
			printf("%s,%s %d,%d\n",day_of_week(day,month,year),monthname[month-1],day,year);
			fprintf(new_date,"%s,%s %d,%d\n",day_of_week(day,month,year),monthname[month-1],day,year);
		}
	fclose(input_date);
	fclose(new_date);
}
int main(){
	char start_date[11],end_date[11];
		printf("--------------------------------\n");
		printf("Start date(dd/mm/yyyy):");
		scanf("%s",start_date);
		printf("End date(dd/mm/yyyy):");
		scanf("%s",end_date);
		printf("--------------------------------\n");
		printf("HW07-Part 2-A\n");
		printf("--------------------------------\n");
		input_date(start_date,end_date);
		printf("\nWritten on input_date.txt file..\n");
		printf("--------------------------------\n");
		printf("HW07-Part 2-B\n");
		printf("--------------------------------\n");
		printf("Read from input_date.txt file..\n\n");
		new_date();
		printf("\nWritten on new_date.txt file..\n");
		printf("--------------------------------\n");
	return 0;
}
