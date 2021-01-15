#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev; 
}NODE, *PNODE, **PPNODE	;

void InsertFirst(PPNODE,PPNODE,int);
void InsertLast(PPNODE,PPNODE,int);
void InsertAtPos(PPNODE, PPNODE, int, int);

void DeleteFirst(PPNODE, PPNODE);
void DeleteLast(PPNODE, PPNODE);
void DeleteAtPos(PPNODE, PPNODE, int);

void Display(PNODE,PNODE);
int Count(PNODE, PNODE);

int main()
{
     int choice =1, value =0, pos=0, cnt =0;
	 PNODE first = NULL;
	 PNODE last = NULL;

	  while(choice !=0)
	  {
		  printf("---------------------------------------------\n");
          printf("DOBBLY CIRCULAR LINKED LIST USING C\n");		  
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
                    InsertFirst(&first, &last, value);	
               break;

            case 2: 
			        printf("Enter value:\n");
  				    scanf("%d", &value);
                    InsertLast(&first, &last, value);	
               break;	

            case 3: 
			        printf("Enter value:\n");
  				    scanf("%d", &value);
                   	printf("Enter position:\n");
  				    scanf("%d", &pos);
                    InsertAtPos(&first, &last, value, pos);	
               break;

             case 4: 
			        DeleteFirst(&first, &last);	
               break;

              case 5: 
			        DeleteLast(&first, &last);	
               break;			   

              case 6: 
			        printf("Enter position:\n");
  				    scanf("%d", &pos);
                    DeleteAtPos(&first, &last, pos);	
               break; 

            case 7: 
                   Display(first, last);	
					break;	

            case 8: 
                   cnt = Count(first, last);	
				   printf("Number of Nodes Present in linked list is:%d\n\n", cnt);
					break;						
		 }
	  }
	printf("Thank You!");
	return 0;
}

void InsertFirst(PPNODE Head, PPNODE Tail, int data)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = data;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((*Head == NULL) && (*Tail ==  NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		newn ->next = *Head;
	    (*Head)->prev = newn;
		*Head = newn;
	}
	
	 (*Tail)->next = *Head;
	 (*Head)->prev = *Tail;
}

void InsertLast(PPNODE Head, PPNODE Tail, int data)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = data;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((*Head == NULL) && (*Tail ==  NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		(*Tail)->next = newn;
		newn -> prev = (*Tail);
		(*Tail) = newn;
	}
	
	 (*Tail)->next = *Head;
	 (*Head)->prev = *Tail;
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int data, int pos)
{
	PNODE newn = NULL;
    int size = Count(*Head, *Tail);
     
	if(pos< 1 || pos> size+1)
	{
		printf("Error: Invalid Input!\n");
		return;
	}	
	 
	  if(pos ==1)
	  {
		  InsertFirst(Head, Tail, data);
	  }
	  else if(pos == size+1)
	  {
		  InsertLast(Head, Tail, data);
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

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
	if((*Head == NULL) && (*Tail == NULL))//Linked List Empty
	{
		printf("Linked List is Empty!\n");
		return;
	}
	
	if(*Head == *Tail) //At least Single Node
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
		
		printf("Node Deleted Sucessfully\n");
	}
	else //More than One Node
	{
		*Head = (*Head) -> next;
		free((*Tail)->next);
		
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
		
		printf("Node Deleted Sucessfully\n");
	}
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
	if((*Head == NULL) && (*Tail == NULL))//Linked List Empty
	{
		printf("Linked List is Empty!\n");
		return;
	}
	
	if(*Head == *Tail) //At least Single Node
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else //More than One Node
	{
		(*Tail) = (*Tail)->prev;
		free((*Tail)->next);
		
		(*Head)->prev = *Tail;
		(*Tail)->next = *Head;
		
	}
	printf("Node Deleted Sucessfully\n");
}

void DeleteAtPos(PPNODE Head, PPNODE Tail, int pos)
{
	int size = Count(*Head, *Tail); 
	if(pos <= 0 || pos > size)
	{
		printf("Error : Invalid position!\n");
	    return;
	}
	else if(pos == 1)
	{
	  DeleteFirst(Head, Tail);
	}
	else if(pos == size)
	{
		DeleteLast(Head, Tail);
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

void Display(PNODE Head, PNODE Tail)
{
	if((Head == NULL) && (Tail == NULL))
	{
		printf("Linked List is Empty!\n");
		return;
	}
     
	do
	{
		printf("|%d|<=>", Head->data);
		Head = Head -> next;
	} 
    while(Head != Tail->next);
	printf("\n");
}

int Count(PNODE Head, PNODE Tail)
{
	int count = 0;
	if((Head == NULL) && (Tail == NULL))
	return 0;

	do
	{
		count++;
		Head = Head -> next;
	} 
    while(Head != Tail->next);
    
	return count;	
}