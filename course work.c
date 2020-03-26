#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct grade
{
	int num;
	char name[81];
	float course[5];
};
typedef struct grade stuin;
void avecal(float average[4],stuin *student,int num);
void information (stuin*student,int num);
void courseavg_(float average[4]);
void studentavg_ (stuin*student,int num);
void OutinF (float average[],stuin *student,int num);
void Ranking (stuin*student,int num);
void bubble(int n,stuin *student,int num);

int main()
{
	char filename;
	int num;
	float average[4];
	stuin *student;
	FILE *fp;
	printf("please input the file name\n");
	scanf("%s",&filename);
	fflush(stdin);
	fp=fopen(&filename,"w");
	if(NULL==fp)
	{
		printf("failed\n");
		exit(0);
	}	
	printf("now input the information\n");
	printf("first tell me how many students\n");
	scanf("%d",&num);
	student=malloc(sizeof(stuin)*num);
	fprintf(fp,"%d\n",num);
	printf("now input like this:\n");
	printf("ID NAME co0 co1 co2 co3\n");
	int i;
	for(i=0;i<num;i++)
	{
		scanf("%d %s %f %f %f %f",&student[i].num,&student[i].name,&student[i].course[1],&student[i].course[2],&student[i].course[3],&student[i].course[4]);
		fprintf(fp,"%d %s %f %f %f %f\n",student[i].num,student[i].name,student[i].course[1],student[i].course[2],student[i].course[3],student[i].course[4]);
	}
	fclose(fp);
	fflush(stdin);
	
	system("cls");
	
	printf("now you can do some sepcial things with the MENU's help\n");
    
    printf("********MENU********\n");
    printf("1.student information\n");
    printf("2.coure avr_score\n");
    printf("3.student avg_score\n");
    printf("4.output into file\n");
    printf("5.course ranking\n");
    printf("6.exit");
    printf("********MENU********\n");
    
    printf("input the number you want\n");
    char a;
    
    avecal(average,student,num);
    
    do
    {
        scanf("%c",&a);
        fflush(stdin);
        switch(a)
        {
    	   case'1': information(student,num); break;
    	   case'2': courseavg_(average); break;
    	   case'3': studentavg_ (student,num); break;
    	   case'4': OutinF(average,student,num); break;
    	   case'5': Ranking(student,num);
           case'6': printf("now you out\n"); system("pause"); system("cls"); break;
	    }
	  system("pause");
      system("cls");
	} while('6'!=a);
	
	free(student);
	return 0;
    
}

void avecal(float average[4], stuin *student,int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		student[i].course[0]=(student[i].course[1]+student[i].course[2]+student[i].course[3]+student[i].course[4])/4;
	}
	for(i=0;i<num;i++)
	{
		average[0]+=student[i].course[1];												
		average[1]+=student[i].course[2];
		average[2]+=student[i].course[3];
		average[3]+=student[i].course[4];	
	}

	for(i=0;i<4;i++)
	{
		average[i]=average[i]/num;												
	}
}

void information (stuin*student,int num)
{
	int i;
	printf("ID	NAME	C00	C01	C02	C03\n");

	for(i=0;i<num;i++)
	{
		printf("%-8d%s\t%-8.1f%-8.1f%-8.1f%-8.1f\n",student[i].num,student[i].name,student[i].course[1],student[i].course[2],student[i].course[3],student[i].course[4]);
	}
}

void courseavg_(float average[4])
{
	printf("ITEM	C00	C01	C02	C03\n");
	printf("AVG 	%-8.1f%-8.1f%-8.1f%-8.1f\n",average[0],average[1],average[2],average[3]);
}

void studentavg_ (stuin*student,int num)
{
	int i;
	printf("ID		NAME		SCORE\n");
	for(i=0;i<num;i++)
	{
		printf("%-16d%s\t\t%-8.2f\n",student[i].num,student[i].name,student[i].course[0]);
	}
}

void OutinF (float average[],stuin *student,int num)
{
	FILE *fp;
	fp=fopen("out.txt","a");
	int i;
	printf("ID\tNAME\tC00\tC01\tC02\tC03\tAVG\n");
	fprintf(fp,"ID\tNAME\tC00\tC01\tC02\tC03\tAVG\n");
	for(i=0;i<num;i++)
	{
		printf("%-8d%-8s%-8.1f%-8.1f%-8.1f%-8.1f%-8.1f\n",student[i].num,student[i].name,student[i].course[1],student[i].course[2],student[i].course[3],student[i].course[4],student[i].course[0]);
		fprintf(fp,"%-8d%-8s%-8.1f%-8.1f%-8.1f%-8.1f%-8.1f\n",student[i].num,student[i].name,student[i].course[1],student[i].course[2],student[i].course[3],student[i].course[4],student[i].course[0]);
	}
	printf("- \t-   \t");	
	fprintf(fp,"- \t-   \t");
	for(i=0;i<4;i++)
		{
			printf("%-8.1f",average[i]);
			fprintf(fp,"%-8.1f",average[i]);
		}
		
	printf("-\n");	
	fprintf(fp,"-\n");
	printf("already input :out.txt.\n");
	fclose(fp);
} 

void Ranking (stuin*student,int num)
{
	int i,j,n;
	
	do{
	printf("Input course num(0 for avg score ranking) : ");
	scanf("%d",&n);
	system("cls");
	
	if(n>=0&&n<=4)
	bubble(n,student,num);							
	else															
	{
		printf("You input the wrong number.\n");
		system("pause");
		system("cls");
	}
	}while(-1!=n);
}


void bubble(int n,stuin *student,int num)
{
	int i,j,k;
	stuin *inf_copy,temp;
	float temp1;
	inf_copy=malloc(sizeof(stuin)*num);
	
	for(i=0;i<num;i++)
		inf_copy[i]=student[i];
		
	for(i=0;i<num;i++)												
		{
			k=i;
			for(j=i+1;j<num;j++)
				if(inf_copy[j].course[n]>inf_copy[k].course[n])
					k=j;
			temp=inf_copy[k];
			inf_copy[k]=inf_copy[i];
			inf_copy[i]=temp;
		}
	
		printf("RANK\tID\tNAME\t\tSCORE\n");
		for(i=0;i<num;i++)
			printf("%-8d%-8d%s\t\t%-4.1f\n",(i+1),inf_copy[i].num,inf_copy[i].name,inf_copy[i].course[n]);
	free(inf_copy);
	
	system("pause");
	system("cls");
 } 

