#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
    struct Node *prev; 	
};

typedef struct Node   NODE;
typedef struct Node*  PNODE;
typedef struct Node** PPNODE;

void InsertFirst(PPNODE, int);
void InsertLast(PPNODE, int);
void InsertAtPos(PPNODE, int, int);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void DeleteAtPos(PPNODE, int);
void Display(PNODE);
int Count(PNODE);

int main()
{
     int choice =1, value =0, pos=0, cnt =0;
	 PNODE first = NULL;

	  while(choice !=0)
	  {
		  printf("---------------------------------------------\n");
          printf("DOBBLY LINKED LIST USING C\n");		  
		  printf("---------------------------------------------\n");
		  printf("1:Insert First\n");
          printf("2:Insert Last\n");
          printf("3:Insert At Pos\n");
          printf("4:Delete First\n");
          printf("5:Delete Last\n");
          printf("6:Delete At Pos\n");
		  printf("7:Display\n");
		  printf("8:Count\n");
		  printf("0:Exit\n\n");
		  printf("---------------------------------------------\n");

          printf("Enter your choice:\n");
          scanf("%d",&choice);		  
	     switch(choice)
		 {
			 case 1: 
			        printf("Enter value:\n");
  				    scanf("%d", &value);
                    InsertFirst(&first, value);	
               break;

            case 2: 
			        printf("Enter value:\n");
  				    scanf("%d", &value);
                    InsertLast(&first, value);	
               break;	

            case 3: 
			        printf("Enter value:\n");
  				    scanf("%d", &value);
                   	printf("Enter position:\n");
  				    scanf("%d", &pos);
                    InsertAtPos(&first, value, pos);	
               break;

             case 4: 
			        DeleteFirst(&first);	
               break;

              case 5: 
			        DeleteLast(&first);	
               break;			   

              case 6: 
			        printf("Enter position:\n");
  				    scanf("%d", &pos);
                    DeleteAtPos(&first, pos);	
               break;

            case 7: 
                   Display(first);	
					break;	

            case 8: 
                   cnt = Count(first);	
				   printf("Number of Nodes Present in linked list is:%d\n\n", cnt);
					break;						
		 }
	  }
	printf("Thank You!");
	return 0;
}

void InsertFirst(PPNODE Head, int data)
{
	PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
	newn->data = data;
    newn->next = NULL;
	newn->prev = NULL;	
	
   if(*Head == NULL)
   {
	   *Head = newn;
   }	   
   else
	{
 		 newn ->next = *Head;
		 (*Head)->prev = newn;
          *Head = newn;               
	}
}

void InsertLast(PPNODE Head, int data)
{
	PNODE newn = NULL;
	PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));
	newn->data = data;
	newn->next = NULL;
	newn->prev = NULL;
	
   if(Head == NULL)
   {
	   *Head = newn;
   }	   
   else
	{
      while(temp->next != NULL)
	  {
        temp=temp->next;		  
	  }
      
	  temp -> next = newn;   
      newn->prev = temp;  		
	}
}

void InsertAtPos(PPNODE Head, int data, int pos)
{
	PNODE newn = NULL;
    int size = Count(*Head);
     
	if(pos< 1 || pos> size+1)
	{
		printf("Error: Invalid Input!\n");
		return;
	}	
	 
	  if(pos ==1)
	  {
		  InsertFirst(Head, data);
	  }
	  else if(pos == size+1)
	  {
		  InsertLast(Head, data);
	  }
	  else
      {
	    PNODE temp = *Head;

		newn = (PNODE)malloc(sizeof(NODE));
		newn->data = data;
		newn->next = NULL;
		newn->prev = NULL;
		
        for(int i =1; i < pos-1;i++)
		{
			temp =temp->next;
		}			
		  
		newn->next = temp->next;
        temp->next->prev =newn; 
		temp->next = newn;
		newn->prev = temp;
  	  }
}

void DeleteFirst(PPNODE Head)
{
	if(Head == NULL)
	{
	    printf("Linked list is Empty!\n");	
		return;
	}
	
	if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
       *Head = (*Head)->next;
	    free((*Head)->prev);
		(*Head)->prev = NULL;	  
	}
	
	printf("Node Deleted Succesfully!\n");
}

void DeleteLast(PPNODE Head)
{
	if(Head == NULL)
		return;
	
	if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
        PNODE temp = *Head;
        while(temp->next->next !=NULL)
		{
			temp = temp->next;
		}			
		free(temp->next);
		temp->next = NULL;
	}
	
	printf("Node Deleted Succesfully!\n");
}

void DeleteAtPos(PPNODE Head, int pos)
{
	int size = Count(*Head); 
	if(pos <=0 || pos > size)
	{
		printf("Error : Invalid position!\n");
	    return;
	}
	else if(pos == 1)
	{
	  DeleteFirst(Head);
	}
	else if(pos == size)
	{
		DeleteLast(Head);
	}
	else
	{
 		PNODE temp = *Head; 
		 int i =0; 
		 for( i = 1; i <  pos-1; i++)
		 {
			 temp = temp->next;
		 }
		 
		 temp->next = temp->next->next;
		 free(temp->next->prev);
		 temp->next->prev=temp;
		 
		 printf("Node Deleted Succesfully from pos:%d\n", pos);
	}
}

void Display(PNODE Head)
{
	while(Head !=NULL)
	{
		printf("|%d|<=>",Head->data);
		Head = Head -> next;
	}	  
	printf("NULL\n");
}

int Count(PNODE Head)
{
	int icnt = 0;
	while(Head !=NULL)
	{
		icnt++;
		Head = Head -> next;
	}	
	return icnt;	
}


