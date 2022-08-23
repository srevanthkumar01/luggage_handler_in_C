//Partial code:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bag
{
	int age,wght;
	char name[30], dest[20], fl_no[10];
};
struct bag queue[50];
struct bag *frontq=NULL, *rearq=NULL, *current=NULL , *ptr;
void checkin();
int length=0;
void checkout(int);
void display();
void search();


void checkin()
{
   if(length==0)
    {
        frontq=&queue[0]; rearq=&queue[0];
    }
   else
   	{ rearq++;}
   length++;
   printf("\n%d\n",length);
   printf("\nEnter name of passenger: ");
   scanf("%s",queue[length-1].name);
   printf("\nEnter Destination: ");
   scanf("%s",queue[length-1].dest);
   printf("\nEnter flight number: ");
   scanf("%s",queue[length-1].fl_no);
   printf("\nEnter Age: ");
   scanf("%d",&queue[length-1].age);
   printf("\nEnter the weight of the bag: ");
   scanf("%d",&queue[length-1].wght);
 }
 void display()
 {
 	if(length==0)
 	   printf("\nQueue is empty...\n");
 	else
 	{
 		int i;
 		printf("\n   Age\tName\tDestination\tFlight No.\tBag Weight");
 		for(int i=0;i<length;i++)
 			printf("\n%d.%d\t%s\t%s\t\t%s\t\t%d",(i+1),queue[i].age,queue[i].name,queue[i].dest,queue[i].fl_no,queue[i].wght);
 	}
 }

 void checkout(int key)
 {
 	 if((key==1)||(length==1))
   {
      int i;
      if(length==1)
     {
         frontq=rearq=NULL;
         length--;
         printf("\nElement deleted...\n");
      }
      else
      {
        for(i=1;i<=length;i++)
        queue[i-1]=queue[i];
        rearq--;
        printf("\nElement deleted...\n");length--;
      }
     }
   else if ((key>1)&&(key<=length))
   {
      if(key<length)
      for(int i=key;i<length;i++)
      {
          queue[i-1]=queue[i];

      }

     rearq--;
     printf("\nElement deleted...\n");length--;
   }
  else
  printf("\nNo bag to checkout...");

 }

void search()
{

 char comp[20];int val,i;

        if(length>0)
        {printf("\nEnter name to search:");
         scanf("%s",comp);
         for(i=0;i<length;i++)
           {  val = strcmp(comp,queue[i].name);
             if(val == 0)
              {
                printf("\nAge:%d\tName:%s\tDestination:%s\tFlight No.:%s\tBag Weight:%d\n\n",queue[i].age,queue[i].name,queue[i].dest,queue[i].fl_no,queue[i].wght);
                break;
              }
               
           }
            if(val!=0)
            printf("\n %s not found",comp);
        }
        else
        printf("\nNo bags in the queue to search...");
}

int main()
{


	int choice=-1;
	do{
	printf("\nNumber of bags in the queue= %d",length);
	printf("\n1.Check in a new bag.\n2.Checkout a bag.");
	printf("\n3.View all bags.\n4.Search a bag.");
	printf("\n5.Exit and clear.");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);

	    switch(choice)
	 {
	    case 1: //check-in
	            checkin();
	            break;
	    case 2: //check-out
	             if(length==0)
             printf("\nNumber of bags in the queue to checkout...");
             else if(length==1)
             {
                 checkout(1);
             }
             else if(length>1)
             {
                 display();int pos=0;
                 printf("\nEnter bag number to checkout:");
                 scanf("%d",&pos);
                 checkout(pos);
             }
	            break;
	    case 3: //View all
	            display();
	            break;
	    case 4: //Search
	             search();
	            break;
	    case 5: //Exit
	            printf("\nThank you for using.\nEnter any key to exit.");
	            
	            return 0;
	    default: printf("\nInvalid Choice");

	 }
	}while(choice>=0);

}