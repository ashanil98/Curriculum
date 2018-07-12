#include<stdio.h>
#include<string.h>
struct student{
	char name[90];
	int age,marks;
}arr[100];
int main()
{
	int n,i,age,marks;
	char name;
	FILE *fp;
	fp = fopen("student.txt","w");
	printf("\nEnter number of students: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter student %d name: ",i+1);
		scanf("%s",arr[i].name);
		printf("\nEnter age of student [%d] :",i+1);
		scanf("%d",&arr[i].age);
		printf("\nEnter marks of student[%d] :",i+1);
		scanf("%d",&arr[i].marks);
		fprintf(fp,"%s - %d - %d\n",arr[i].name,arr[i].age,arr[i].marks);
		if(i==n-1){
		fprintf(fp,"%s - %d - %d",arr[i].name,arr[i].age,arr[i].marks);
		}
		
	}
	fclose(fp);
	printf("\n Successfully written into the file");
	fp = fopen("student.txt","r");
	if(fp==NULL){
		printf("\nError in opening the file");
		//exit(1);
	}
	printf("\nName\tAge\tMarks\n");
	i=0;
	while(!feof(fp)){
		fscanf(fp,"%s %d %d",&name,&age,&marks);
		printf("%s ,%d, %d",name,age,marks);
		i++;
	}
	return 0;
}
