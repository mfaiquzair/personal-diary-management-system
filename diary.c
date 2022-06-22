#include <stdio.h>
#include <stdlib.h>

/*
This file is in C. Do DM me on any inquiries at my twitter @mfaiquzair 
*/

struct User
{
    char name[50];
    int age;
    char gender[10];
};

struct Record
{
    char date;
    char day[20];
    char time;
    char place[30];
};

struct Content
{
    char title[30];
    char note[1000];
};

struct Diarydetails
{
    char id[5];
    int no;
    struct User user1;
    struct Record record1;
    struct Content content1;

    struct Diarydetails *ptrnext;

};

struct Diarydetails *headptr, *newptr, *currentptr;

void addRecord();
void deleteRecord();
void searchRecord();
//void updateRecord();
//void sortRecordByID();
void listRecord();

/*int main()
{
    char choice;
	//char choice=TRUE;
	int TRUE;
	int FALSE;

	headptr=NULL; //insert beginning empty = insert end empty
	while(choice==TRUE)

	{
        printf("\n\nDiary Management System\n");
        printf("\n\n------Main Menu------\n");
		printf("\n\n1 - Add Diary Record");
		printf("\n2 - Update Diary Record");
		printf("\n3 - Delete Diary Record");
		printf("\n4 - Search Diary Record");
		printf("\n5 - Sort Diary Record");
		printf("\n6 - List Diary Record");

		printf("\n7 - Exit\n");

		printf("\nEnter choice: ");
		scanf(" %c",&choice);

		switch(choice)
		{
		case '1':addRecord();break;
		//case '2':updateRecord();break;
		case '3':deleteRecord();break;
		case '4':searchRecord();break;
		//case '5':sortRecordByID();break;
		case '6':listRecord();break;

		case '7': choice=FALSE; break;

		default: printf("\nEnter only one from the above");
		}
	}
 return 0;

}*/
int main()
{
    int choice;
    int exit;

    do
    {
        printf("\n\nDiary Management System\n");
        printf("\n\n------Main Menu------\n");
		printf("\n\n1 - Add Diary Record");
		printf("\n2 - Update Diary Record");
		printf("\n3 - Delete Diary Record");
		printf("\n4 - Search Diary Record");
		printf("\n5 - Sort Diary Record");
		printf("\n6 - List Diary Record");

		printf("\n7 - Exit\n");
        printf("\nEnter your choice: ");
        scanf(" %d", &choice);

        choice = toupper(choice);

		switch(choice)
		{
		    case 1:
		        addRecord();
		    break;
		    case 2:
                deleteRecord();
            break;
            case 3:
                searchRecord();
            break;
            case 4:
                listRecord();
            break;
            case 5:
                printf("\nSee you next time!!");
                choice =  1;
            break;
            default: printf("\nInvalid choice. Please choose one of the option.\n");
        }//switch
    }//do
    while (exit != 1);

    return 0;

}//main



void addRecord() //insert at end
{
  newptr=(struct Diarydetails *)malloc(sizeof(struct Diarydetails)); // pointer to a new / new address for new node


  printf("\nEnter Diary ID: ");
  scanf("%s",&newptr->id);
  printf("\nEnter Diary No. : ");
  scanf("%d",&newptr->no);
  printf("\nWhat is Your Name? : ");
  scanf("%s",&newptr->user1.name); // user connection
  printf("\nHow Old Are You?: ");
  scanf("%d",&newptr->user1.age);
  printf("\nMale or Female?: ");
  scanf("%s",&newptr->user1.gender);
  printf("\nWhat Date is Today? : ");           //record connection
  scanf("%s",&newptr->record1.date);
  printf("\nWhat Day is Today? : ");
  scanf("%s",&newptr->record1.day);
  printf("\nWhat Time Now? : ");
  scanf("%s",&newptr->record1.time);
  printf("\nWhere Are You Right Now? : ");
  scanf("%s",&newptr->record1.place);
  printf("\nWhat is the Title for Today's Diary? : ");
  scanf("%s",&newptr->content1.title); //content connection
  printf("\nWhat's Up?: ");
  scanf("%[^\n]s",&newptr->content1.note);

  if (headptr==NULL)//node is empty?
  {headptr=newptr; //first pointer point to first node
   newptr->ptrnext=NULL; //first node pointer point to null
  }

  else
   {
    newptr->ptrnext=headptr;
    headptr=newptr;

   }


}

void deleteRecord() //delete at beginning
{

	if (headptr==NULL)
    {
    printf("\n\nThe list is empty. Cannot delete!!!\n");//no input yet
    }

	else
	{
      currentptr=headptr;
      headptr=headptr->ptrnext;
      free(currentptr);
	}

}

// QUEUE = insert at end, delete at beginning

void searchRecord()
{
    int searchValue;

    if(headptr=NULL)
    {
        printf("\nThere are No Diary Entry Yet!");
    }

    else
    {
        printf("\nEnter Diary ID: ");
        scanf("%d",&searchValue);

        currentptr=headptr;

        while(currentptr->ptrnext!=NULL)
        {
            if(currentptr->no == searchValue)
            {
                printf("\nDiary ID %d is found",searchValue);
                printf("\nThe Title  is %s",currentptr->content1.title);
                return;
            }
            else
            {
                currentptr=currentptr->ptrnext;
            }

        }

        if(currentptr->no == searchValue)
        {
            printf("\nDiary ID %d is found",searchValue);
            printf("\nThe Title is %s",currentptr->content1.title);
        }
        else
        {
            printf("\nCannot Find Record");
        }

    }

}

/*void sortRecordByID()
{
    char id;
	int  temp, i;

	while (id>1)
	{

		id--;

		for(i=0;i<id;i++)
		{

			if (id[i]>id[i+1])
			{
				temp=id[i];
				id[i]=id[i+1];
				id[i+1]=temp;

			}
		}

	}
}*/

void listRecord()
{
	if (headptr==NULL) //empty list
	{
		printf("\nEmpty list");
		return;
	}

	currentptr=headptr;
	do
	{
		printf("\n\n%d",currentptr->content1.title);
		printf("\n");
		currentptr=currentptr->ptrnext; //point to next node
	}while(currentptr !=NULL);
}

/*void updateRecord()
{
    //int option;
    char id;


    if(headptr == NULL)
    {
        printf("\n\nThe diary record list is empty\n");
    }
    else
    {
        printf("======================================================================================\n");
        printf("                                    Update Diary                                   \n");
        printf("======================================================================================\n");
        printf("\nYou can only update your note !");


            printf("\n\nEnter Diary ID: ");
            scanf("%s", &id);

            currentptr=headptr;

            while (currentptr->ptrnext != NULL)
            {
                if (id == currentptr->id)
                {
                    printf("\nUpdate Your 'What's Up': ");
                    scanf("%[^\n]s", &currentptr->content1.note);

                    printf("\n\nUpdate successful!");

                    return;
                }//if

                else
                {
                   currentptr = currentptr->ptrnext;
                }//else
           }//while
	if (id == currentptr->id)
                {
                    printf("\nUpdate Your 'What's Up': ");
                    scanf("%[^\n]s", &currentptr->content1.note);

                    printf("\n\nUpdate successful!");

                    return;
                }//if

                else
                {
                   printf("\nSorry, We couldn't find your search.");
                }//else
    }
}//update*/
