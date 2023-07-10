#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct Node_tag{
	int data;
	struct Node_tag* next1;
}Node;


Node* createlist(int n)
{
	Node *nptr,*lptr;
	lptr=NULL;
	int i=1;
	int d;
	char name[100];
	while(i<=n)
	{
		nptr=(Node*)malloc(sizeof(Node));
		printf("ENter the name of subject:");
		scanf("%s",name);
		printf("Enter the data");
		scanf("%d",&d);
		nptr->data=d;
		nptr->next1=lptr;
		lptr=nptr;
		i++;
	}
	return lptr;
}


typedef struct student_list{
	char stu_name[100];
	char dept_name[100];
	int sem;
	char roll_no[100];
	Node* noc;
	Node* noca;
	struct student_list* next2;
}stu_list;

stu_list* create_stu_list(int n,Node* sub1,Node* sub2,Node* sub3,Node* sub4,Node* sub5)
{
	stu_list *nptr,*lptr;
	lptr=NULL;
	int i=1;
	int sm;
	char stu[100],d[100],r[100];
	FILE* fp;
	fp=fopen("stu_list.txt","r");
	if(fp==NULL)
	{
		printf("Error");
	}
	else
	{
		while(i<=n)
		{
			//printf("Enter");
			nptr=(stu_list*)malloc(sizeof(stu_list));
			fscanf(fp,"%s",stu);
			strcpy(nptr->stu_name,stu);
			fscanf(fp,"%s",d);
			strcpy(nptr->dept_name,d);
			fscanf(fp,"%d",&sm);
			nptr->sem=sm;
			fscanf(fp,"%s",r);
			strcpy(nptr->roll_no,r);
			if(strcmp(nptr->dept_name,"CS")==0)
			{
				nptr->noc=sub1;
			}
			else if(strcmp(nptr->dept_name,"EC")==0)
			{
				nptr->noc=sub2;
			}
			else if(strcmp(nptr->dept_name,"EE")==0)
			{
				nptr->noc=sub3;
			}
			else if(strcmp(nptr->dept_name,"ME")==0)
			{
				nptr->noc=sub4;
			}
			else if(strcmp(nptr->dept_name,"CV")==0)
			{
				nptr->noc=sub5;
			}
			//nptr->noca=createlist(5);
			Node *nptr1,*lptr1;
			lptr1=NULL;
			//int i1=1;
			int d;
			char name[100];
			int j=1;
			while(j<=5)
			{
				nptr1=(Node*)malloc(sizeof(Node));
				fscanf(fp,"%d",&d);
				nptr1->data=d;
				nptr1->next1=lptr1;
				lptr1=nptr1;
				j++;
			}
			nptr->noca=lptr1;
			nptr->next2=lptr;
			lptr=nptr;
			i++;
		}
			
	}
	
	return lptr;
}


typedef struct Attendence_list{
	char roll[100];
	char dept[100];
	float att_MCC;
	float perc_att;
	struct Attendence_list* next3;
}Attendence;

Attendence* create_Attendence_list(int n)
{
	Attendence *nptr,*lptr;
	lptr=NULL;
	int i,m;
	char r[100],d[100];
	FILE* fp;
	fp=fopen("Attendence.txt","r");
	if(fp==NULL)
	{
		printf("Error");
	}
	else
	{
		i=1;
		while(i<=n)
		{
			nptr=(Attendence*)malloc(sizeof(Attendence));
			//printf("Enter the roll number:");
			fscanf(fp,"%s",r);
			strcpy(nptr->roll,r);
			//printf("Enter the department:");
			fscanf(fp,"%s",d);
			strcpy(nptr->dept,d);
			//printf("Enter the attendence in mcc");
			fscanf(fp,"%d",&m);
			nptr->att_MCC=m;
			nptr->perc_att=0;
			nptr->next3=lptr;
			lptr=nptr;
			i++;
		}
	}
	
	return lptr;
}


typedef struct fee_status_list{
	char Roll_num[100];
	char status[100];
	struct fee_status_list* next4;
}fee_status;

fee_status* create_fee_status_list(int n)
{
	fee_status *nptr,*lptr;
	lptr=NULL;
	int i=1;
	char r[100],s[100];
	FILE* fp=fopen("fee_status.txt","r");
	if(fp==NULL)
	{
		printf("ERROR");
		exit(0);
	}
	while(i<=n)
	{
		nptr=(fee_status*)malloc(sizeof(fee_status));
		fscanf(fp,"%s",r);
		strcpy(nptr->Roll_num,r);
		fscanf(fp,"%s",s);
		strcpy(nptr->status,s);
		nptr->next4=lptr;
		lptr=nptr;
		i++;
	}
	return lptr;
}

typedef struct applicant_list{
	char Stu_name[100];
	char Rolln[100];
	char applied[10];
	struct applicant_list* next5;
}applicant;

applicant* create_applicant_list(int n)
{
	applicant *nptr,*lptr;
	lptr=NULL;
	int i=1;
	char s[100],r[100],a[100];
	FILE* fp=fopen("Applicant.txt","r");
	if(fp==NULL)
	{
		printf("Error");
		exit(0);
	}
	while(i<=n)
	{
		nptr=(applicant*)malloc(sizeof(applicant));
		fscanf(fp,"%s",s);
		strcpy(nptr->Stu_name,s);
		fscanf(fp,"%s",r);
		strcpy(nptr->Rolln,r);
		fscanf(fp,"%s",a);
		strcpy(nptr->applied,a);
		nptr->next5=lptr;
		lptr=nptr;
		i++;
	}
	return lptr;
}

void Print(stu_list* s);

stu_list* merge(stu_list* l1,stu_list* l2)
{
    stu_list *result, *tail , *ptr1 , *ptr2;
    ptr1=l1;
    ptr2=l2;
    if(ptr1->sem<ptr2->sem)
    {
        result=ptr1;
        ptr1=ptr1->next2;
    }
    else if (ptr2->sem<ptr1->sem)
    {
        result=ptr2;
        ptr2=ptr2->next2;
    }
    else
    {
        if(strcmp(ptr1->dept_name,ptr2->dept_name)<0)
        {
            result=ptr1;
            ptr1=ptr1->next2;
        }
        else if (strcmp(ptr1->dept_name,ptr2->dept_name)>0)
        {
            result=ptr2;
            ptr2=ptr2->next2;
        }
        else
        {
            if(ptr1->roll_no<ptr2->roll_no)
            {
                result=ptr1;
                ptr1=ptr1->next2;
            }
            else
            {
                result=ptr2;
                ptr2=ptr2->next2;
            }
        }
    }
    tail=result;
    while(ptr1 && ptr2)
    {
        if(ptr1->sem<ptr2->sem)
        {
            tail->next2=ptr1;
            tail=tail->next2;
            ptr1=ptr1->next2;
        }
        else if (ptr2->sem<ptr1->sem)
        {
            tail->next2=ptr2;
            tail=tail->next2;
            ptr2=ptr2->next2;
        }
        else
        {
            if(strcmp(ptr1->dept_name,ptr2->dept_name)<0)
            {
                tail->next2=ptr1;
                tail=tail->next2;
                ptr1=ptr1->next2;
            }
            else if (strcmp(ptr1->dept_name,ptr2->dept_name)>0)
            {
                tail->next2=ptr2;
                tail=tail->next2;
                ptr2=ptr2->next2;

            }
            else
            {
                if(ptr1->roll_no<ptr2->roll_no)
                {
                    tail->next2=ptr1;
                    tail=tail->next2;
                    ptr1=ptr1->next2;
                }
                else
                {
                    tail->next2=ptr2;
                    tail=tail->next2;
                    ptr2=ptr2->next2;

                }
            }
        }
    }
    if(ptr1)
    {
        tail->next2=ptr1;
    }
    else
    {
        tail->next2=ptr2;
    }
    return result;
}
stu_list* Divide(stu_list *lptr)
{
	stu_list *nptr,*fast,*slow;
	slow=lptr;
	fast=lptr->next2->next2;
	while(fast!=NULL)
	{
		fast=fast->next2;
		slow=slow->next2;
		if(fast!=NULL)
		{
			fast=fast->next2;
		}
	}
	nptr=slow->next2;
	slow->next2=NULL;
	return nptr;
}
stu_list* Mergesort(stu_list *list_ptr)
{
	stu_list *lptr,*nptr;
	lptr=list_ptr;
	if((lptr!=NULL) && (lptr->next2!=NULL))
	{
		nptr=Divide(lptr);
		lptr=Mergesort(lptr);
		nptr=Mergesort(nptr);
		lptr=merge(lptr,nptr);
	}
	return lptr;
}


//Q2
stu_list* create_Non_applicants_list(applicant* ap,stu_list* s)
{
	applicant* temp=ap;
	stu_list* temp1,*lptr=NULL,*nptr;
	while(temp!=NULL)
	{
		if(strcmp(temp->applied,"NA")==0)
		{
			temp1=s;
			while(strcmp(temp->Rolln,temp1->roll_no)!=0)
			{
				temp1=temp1->next2;
			}
			nptr=(stu_list*)malloc(sizeof(stu_list));
			nptr->next2=lptr;
			strcpy(nptr->roll_no,temp1->roll_no);
			strcpy(nptr->dept_name,temp1->dept_name);
			strcpy(nptr->stu_name,temp1->stu_name);
			nptr->sem=temp1->sem;
			nptr->noc=temp1->noc;
			nptr->noca=temp1->noca;
			lptr=nptr;
		}
		temp=temp->next5;
	}
	return lptr;
}


//Q3
stu_list* create_eligible_student_list(Attendence* a, fee_status *f, stu_list* s, applicant* ap)
{
    Attendence* temp1 = a;
    fee_status* temp2;
    applicant* temp3 = ap;
    stu_list* temp4 = s;
    stu_list* lptr = NULL, *nptr;
    
    while (temp1 != NULL)
    {
        //printf("Entered\n");
        if (temp1->perc_att > 75)
        {
            temp2 = f;
            while (temp2 != NULL && strcmp(temp1->roll, temp2->Roll_num) != 0)
            {
                temp2 = temp2->next4;
            }
            if (temp2 != NULL && strcmp(temp2->status, "clear") == 0)
            {
                temp3 = ap;
                while (temp3 != NULL && strcmp(temp3->Rolln, temp2->Roll_num) != 0)
                {
                    temp3 = temp3->next5;
                }
                if (temp3 != NULL && strcmp(temp3->applied, "A") == 0)
                {
                    temp4 = s;
                    while (temp4 != NULL && strcmp(temp4->roll_no, temp3->Rolln) != 0)
                    {
                        temp4 = temp4->next2;
                    }
                    nptr = (stu_list*)malloc(sizeof(stu_list));
                    nptr->next2 = lptr;
                    strcpy(nptr->roll_no, temp4->roll_no);
                    strcpy(nptr->dept_name, temp4->dept_name);
                    strcpy(nptr->stu_name, temp4->stu_name);
                    nptr->sem = temp4->sem;
                    nptr->noc = temp4->noc;
                    nptr->noca = temp4->noca;
                    lptr = nptr;
                    //printf("%s\n", nptr->stu_name);
                    //printf("Appended");
                }
            }
        }
        temp1 = temp1->next3;
    }
    return lptr;
}



//Q4
stu_list* create_less_Attendence_list(Attendence* a,stu_list* s)
{
	Attendence* temp=a;
	stu_list* temp1,*lptr=NULL,*nptr;
	while(temp!=NULL)
	{
		if(temp->perc_att<75)
		{
			temp1=s;
			while(strcmp(temp->roll,temp1->roll_no)!=0)
			{
				temp1=temp1->next2;
			}
			nptr=(stu_list*)malloc(sizeof(stu_list));
			nptr->next2=lptr;
			strcpy(nptr->roll_no,temp1->roll_no);
			strcpy(nptr->dept_name,temp1->dept_name);
			strcpy(nptr->stu_name,temp1->stu_name);
			nptr->sem=temp1->sem;
			nptr->noc=temp1->noc;
			nptr->noca=temp1->noca;
			lptr=nptr;
		}
		temp=temp->next3;
	}
	return lptr;
}


// Q5 
/*stu_list* print_stu(Attendence* a,fee_status *f,stu_list* s)
{
	Attendence *temp1=a;
	fee_status *temp2;
	stu_list *temp3,*nptr,*lptr=NULL;
	int i=0;
	while(temp1!=NULL)
	{
		if(temp1->perc_att>75.00)
		{
			temp2=f;
			while(strcmp(temp1->roll,temp2->Roll_num)!=0)
			{
				temp2=temp2->next4;
			}
			if(strcmp(temp2->status,"Pending")==0)
			{
				temp3=s;
				while(strcmp(temp3->roll_no,temp2->Roll_num)!=0)
				{
					temp3=temp3->next2;
				}
				//printf("%s\n",temp3->stu_name);
				printf("%d",i);
					nptr=(stu_list*)malloc(sizeof(stu_list));
					nptr->next2=lptr;
					strcpy(nptr->roll_no,temp3->roll_no);
					strcpy(nptr->dept_name,temp3->dept_name);
					strcpy(nptr->stu_name,temp3->stu_name);
					nptr->sem=temp3->sem;
					nptr->noc=temp3->noc;
					nptr->noca=temp3->noca;
					lptr=nptr;
			}
			//printf("%d",i);
			//i++;
		}
		//printf("Entered");
		//printf("%d",i);
		temp1=temp1->next3;
	}
	return lptr;
}*/
void print_stu(Attendence* a,fee_status *f,stu_list* s)
{
	//printf("ENtered\n");
    Attendence *temp1=a;
    fee_status *temp2;
    stu_list *temp3;
    while(temp1!=NULL)
    {
    	//printf("Entered\n");
        if(temp1->perc_att>75)
        {
        	//printf("ENtered\n");
            temp2=f;
            while(temp2!=NULL && strcmp(temp1->roll,temp2->Roll_num)!=0)
            {
            	//printf("ENtered\n");
                temp2=temp2->next4;
            }
            if(temp2 != NULL && strcmp(temp2->status,"pending")==0)
            {
            	//printf("ENtered\n");
                temp3=s;
                while(temp3!=NULL && strcmp(temp3->roll_no,temp2->Roll_num)!=0)
                {
                    temp3=temp3->next2;
                }
                printf("%s\n",temp3->stu_name);
            }
        }
        temp1=temp1->next3;
    }
}




//Q6
//defaulter students
stu_list* create_defaulter_list(Attendence* a,fee_status* f,stu_list* s)
{
	Attendence* temp=a;
	stu_list* temp1,*lptr=NULL,*nptr;
	while(temp!=NULL)
	{
		if(temp!=NULL && temp->perc_att<=75)
		{
			temp1=s;
			while(temp1!=NULL && strcmp(temp->roll,temp1->roll_no)!=0)
			{
				temp1=temp1->next2;
			}
			nptr=(stu_list*)malloc(sizeof(stu_list));
			nptr->next2=lptr;
			strcpy(nptr->roll_no,temp1->roll_no);
			strcpy(nptr->dept_name,temp1->dept_name);
			strcpy(nptr->stu_name,temp1->stu_name);
			nptr->sem=temp1->sem;
			nptr->noc=temp1->noc;
			nptr->noca=temp1->noca;
			lptr=nptr;
			//printf("Entered due to perc");
			//Print(lptr);
		}
		temp=temp->next3;
	}
	fee_status* temp2=f;
	Attendence* temp3;
	while(temp2!=NULL)
	{
		if(temp2!=NULL && strcmp(temp2->status,"Pending")==0)
		{
			//printf("Entered due to fee");
			temp3=a;
			while(temp3!=NULL && strcmp(temp2->Roll_num,temp3->roll)!=0)
			{
				temp3=temp3->next3;
			}
			if(temp3!=NULL && temp3->perc_att>75)
			{
				temp1=s;
				while(temp1!=NULL && strcmp(temp2->Roll_num,temp1->roll_no)!=0)
				{
					temp1=temp1->next2;
				}
				nptr=(stu_list*)malloc(sizeof(stu_list));
				nptr->next2=lptr;
				strcpy(nptr->roll_no,temp1->roll_no);
				strcpy(nptr->dept_name,temp1->dept_name);
				strcpy(nptr->stu_name,temp1->stu_name);
				nptr->sem=temp1->sem;
				nptr->noc=temp1->noc;
				nptr->noca=temp1->noca;
				lptr=nptr;
			}
		}
		temp2=temp2->next4;
	}
	return lptr;
}

void max_defaulter_dept(stu_list* s)
{
	int dept[5];
	int i;
	for(i=0;i<5;i++)
	{
		dept[i]=0;
	}
	stu_list* temp=s;
	while(temp!=NULL)
	{
		if(strcmp(temp->dept_name,"CS")==0)
		{
			dept[0]++;
		}
		else if(strcmp(temp->dept_name,"EC")==0)
		{
			dept[1]++;
		}
		else if(strcmp(temp->dept_name,"EE")==0)
		{
			dept[2]++;
		}
		else if(strcmp(temp->dept_name,"ME")==0)
		{
			dept[3]++;
		}
		else if(strcmp(temp->dept_name,"CV")==0)
		{
			dept[4]++;
		}
		temp=temp->next2;
	}
	int max=0,max_i=0;
	for(i=0;i<5;i++)
	{
		if(dept[i]>max)
		{
			max=dept[i];
			max_i=i;
		}
	}
	if(max_i==0)
	{
		printf("CS has max number of defaulters\n");
	}
	else if(max_i==1)
	{
		printf("EC has max number of defaulters\n");
	}
	else if(max_i==2)
	{
		printf("EE has max number of defaulters\n");
	}
	else if(max_i==3)
	{
		printf("ME has max number of defaulters\n");
	}
	else if(max_i==4)
	{
		printf("CV has max number of defaulters\n");
	}
	
}

void Print(stu_list* s)
{
	stu_list* temp=s;
	while(temp!=NULL)
	{
		printf("Name:%s\n",temp->stu_name);
		printf("Dept:%s\n",temp->dept_name);
		printf("Roll Number:%s\n",temp->roll_no);
		printf("Sem:%d\n",temp->sem);
		temp=temp->next2;
	}
}

float Max_MCC_att(Attendence* a)
{
	//printf("ENtered1");
	Attendence* temp=a;
	float max=0;
	while(temp!=NULL)
	{
		if(temp->att_MCC>max)
		{
			max=temp->att_MCC;
		}
		temp=temp->next3;
	}
	//printf("%d",max);
	return max;
}

Attendence* set_perc_att(Attendence *a)
{
	//printf("ENtered");
	float m=Max_MCC_att(a);
	printf("%f\n",m);
	Attendence* temp=a;
	while(temp!=NULL)
	{
		//printf("ok");
		temp->perc_att=(temp->att_MCC/m)*100.00;
		temp=temp->next3;
	}
	//printf("done");
	return a;
}
Attendence* PrintA(Attendence* a)
{
	Attendence* temp=a;
	while(temp!=NULL)
	{
		printf("Roll NO:%s\n",temp->roll);
		printf("dept:%s\n",temp->dept);
		printf("Attendence:%f\n",temp->perc_att);
		temp=temp->next3;
	}
}
main()
{
	Node *sub1,*sub2,*sub3,*sub4,*sub5;
	int j=1;
	while(j<=5)
	{
		Node *nptr,*lptr;
		lptr=NULL;
		int i=1;
		int d;
		FILE* fp=fopen("subject.txt","r");
		if(fp==NULL)
		{
			printf("Error");
		}
		else
		{
			while(i<=5)
			{
				nptr=(Node*)malloc(sizeof(Node));
				fscanf(fp,"%d",&d);
				nptr->data=d;
				nptr->next1=lptr;
				lptr=nptr;
				i++;
			}
		}
		if(j==1)
		{
			sub1=lptr;
		}
		else if(j==2)
		{
			sub2=lptr;
		}
		else if(j==3)
		{
			sub3=lptr;
		}
		else if(j==4)
		{
			sub4=lptr;
		}
		else if(j==5)
		{
			sub5=lptr;
		}	
		j++;
	}
	
	int n;
	printf("ENter the number of students:");
	scanf("%d",&n);
	
	//Q1
	printf("Q1\n");
	stu_list *first;
	first=create_stu_list(n,sub1,sub2,sub3,sub4,sub5);
	//Print(first);
	first=Mergesort(first);
	Print(first);
	/*first=PartialSort(first);
	Print(first);
	first=PartialSort1(first);
	Print(first);*/
	
	Attendence *att=create_Attendence_list(n);
	//PrintA(att);
	att=set_perc_att(att);
	fee_status* fs=create_fee_status_list(n);
	applicant* app=create_applicant_list(n);
	
	
	//Q2
	printf("\n\n\n\n\n\n");
	printf("Q2\n");
	stu_list* na;
	na=create_Non_applicants_list(app,first);//arguements remaining
	//Print(na);
	na=Mergesort(na);
	Print(na);
	//na=PartialSort(na);
	
	//Q3
	printf("\n\n\n\n\n\n");
	printf("Q3\n");
	stu_list* newfirst;
	newfirst=create_eligible_student_list(att,fs,first,app);//arguements remaining
	if(newfirst==NULL)
	{
		printf("YES\n");
	}
	newfirst=Mergesort(newfirst);
	//newfirst=PartialSort(newfirst);
	//newfirst=PartialSort1(newfirst);
	Print(newfirst);
	
	//Q4
	printf("\n\n\n\n\n\n");
	printf("Q4\n");
	stu_list* less_att;
	less_att=create_less_Attendence_list(att,first);//arguements remaining
	less_att=Mergesort(less_att);
	//less_att=PartialSort(less_att);
	//less_att=PartialSort1(less_att);
	Print(less_att);
	
	//Q5
	printf("\n\n\n\n\n\n");
	printf("Q5\n");
	print_stu(att,fs,first);//arguements remaining
	//Print(first2);
	//printf("OK DONE");
	//Q6
	printf("\n\n\n\n\n\n");
	printf("Q6\n");
	stu_list* defaulter;
	defaulter=create_defaulter_list(att,fs,first);
	//printf("6 ll created");
	Print(defaulter);
	max_defaulter_dept(defaulter);
}
