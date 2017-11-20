/**/
/*
 *  Course: Algorithms (IAL) - FIT BUT
 *  Advanced tests for c206.c (Double linked list)
 *  Created: Martin Tuček, September 2005
 *  Modification: Bohuslav Křena, October 2016
 */

#include "c206.h"
                                                         /* working variables */
tDLList TEMPLIST;		                                         /* list for test */ 
int content=0;                               /* content for inserted elements */
int MaxListLength = 100;                 /* for hangling wrongly linked lists */

/*******************************************************************************
 * Wrapping functions to make tests scripts shorter: 
 ******************************************************************************/

void print_elements_of_list(tDLList TL)	{
/* Prints elements and activity of list TL. */
	
	tDLList TempList=TL;
	                               /* We count elements in order to avoid infinite
                                    loops when the list is wrongly linked. */
	int CurrListLength = 0;
	printf("-----------------");
	while ((TempList.First!=NULL) && (CurrListLength<MaxListLength))	{
		printf("\n \t%d",TempList.First->data);
		if ((TempList.First==TL.Act) && (TL.Act!=NULL))
			printf("\t <= activity ");
		TempList.First=TempList.First->rptr;
		CurrListLength++;
	}
    if (CurrListLength>=MaxListLength)
        printf("\nList exceeded the maximum length!");
	printf("\n-----------------\n");     
}

int test_DLInitList()	{
	solved=TRUE;	
	DLInitList(&TEMPLIST);
	if (!solved)	{
		printf("Function InitList is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}	
}

int test_DLDisposeList()	{
	solved=TRUE;
	DLDisposeList(&TEMPLIST);
	if (!solved)	{
		printf("Function DLDisposeList is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}	
}

int test_DLInsertFirst()	{
	solved=TRUE;
	content++;
	DLInsertFirst(&TEMPLIST,content);
	if (!solved)	{
		printf("Function DLInsertFirst is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}	

int test_DLInsertLast()	{
	solved=TRUE;
	content++;
	DLInsertLast(&TEMPLIST,content);
	if (!solved)	{
		printf("Function DLInsertLast is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}	

int test_DLFirst()	{
	solved=TRUE;
	DLFirst(&TEMPLIST);
	if (!solved)	{
		printf("Function DLFirst is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLLast()	{
	solved=TRUE;
	DLLast(&TEMPLIST);
	if (!solved)	{
		printf("Function DLLast is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLCopyFirst()	{
	solved=TRUE;	
    int temp;
    DLCopyFirst(&TEMPLIST,&temp);	
	if (!solved)	{
		printf("Function DLCopyFirst is not implemented!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Function DLCopyFirst has called function DLError.\n");
			errflg=FALSE;
			return(FALSE);
		}	
		else	{	 			
			printf("Return value of function DLCopyFirst is %d.\n",temp);
			return(TRUE);
		}	
	}
}	

int test_DLCopyLast()	{
	solved=TRUE;
    int temp;
    DLCopyLast(&TEMPLIST,&temp);	
	if (!solved)	{
		printf("Function DLCopyLast is not implemented!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Function DLCopyLast has called function DLError.\n");
			errflg=FALSE;
			return(FALSE);
		}	
		else	{	 			
			printf("Return value of function DLCopyLast is %d.\n",temp);
			return(TRUE);
		}	
	}
}	

int test_DLDeleteFirst ()	{
	solved=TRUE;	
	DLDeleteFirst(&TEMPLIST);
	if (!solved)	{
		printf("Function DLDeleteFirst is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}	

int test_DLDeleteLast ()	{
	solved=TRUE;	
	DLDeleteLast(&TEMPLIST);
	if (!solved)	{
		printf("Function DLDeleteLast is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}	

int test_DLPostDelete()	{
	solved=TRUE;	
	DLPostDelete(&TEMPLIST);
	if (!solved)	{
		printf("Function DLPostDelete is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}	

int test_DLPreDelete()	{
	solved=TRUE;	
	DLPreDelete(&TEMPLIST);
	if (!solved)	{
		printf("Function DLPreDelete is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPostInsert()	{
	solved=TRUE;
	content++;
	DLPostInsert(&TEMPLIST,content);
	if (!solved)	{
		printf("Function DLPostInsert is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPreInsert()	{
	solved=TRUE;
	content++;
	DLPreInsert(&TEMPLIST,content);
	if (!solved)	{
		printf("Function DLPreInsert is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLCopy()	{
	solved=TRUE;
	int temp;
  DLCopy(&TEMPLIST,&temp);	
	
	if (!solved)	{
		printf("Function DLCopy is not implemented!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Function DLCopy has called function DLError.\n");
			errflg=FALSE;
			return(FALSE);
		}	
		else	{	 			
			printf("Return value of function DLCopy is %d.\n",temp);
			return(TRUE);
		}	
	}	
}

int test_DLActualize()	{
	solved=TRUE;
	content++;
	DLActualize(&TEMPLIST,content);
	if (!solved)	{
		printf("Function DLActualize is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLSucc()	{
	solved=TRUE;
	DLSucc(&TEMPLIST);
	if (!solved)	{
		printf("Function DLSucc is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPred()	{
	solved=TRUE;
	DLPred(&TEMPLIST);
	if (!solved)	{
		printf("Function DLPred is not implemented!\n");
		return(FALSE);
	}	
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLActive()	{
	solved=TRUE;
	int tmp=DLActive(&TEMPLIST);
	if (!solved)	{
		printf("Function DLActive is not implemented!\n");
		return(FALSE);
	}	
	else	{
		if (tmp)
			printf("Return value of function DLActive is TRUE.\n");
		else
			printf("Return value of function DLActive is FALSE.\n");	
		return(TRUE);			
	}
}

/*******************************************************************************
 * Advanced Tests
 ******************************************************************************/

int main(int argc, char *argv[])	{
    printf("Double Linked List - Advanced Tests\n");
    printf("===================================\n");

    printf("\n[TEST01]\n");
    printf("List initialization\n");
    printf("~~~~~~~~~~~~~~~~~~~\n");
    test_DLInitList();

                       /* We test behaviour of some functions for empty list. */	
    printf("\n[TEST02]\n");
    printf("Calling DLCopyFirst for empty list should cause en error.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopyFirst();
	
    printf("\n[TEST03]\n");
    printf("Calling DLCopyLast for empty list should cause en error.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopyLast();

    printf("\n[TEST04]\n");
    printf("Calling DLCopy for empty list should cause en error.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopy();

    printf("\n[TEST05]\n");
    printf("Calling DLFirst for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLFirst();

    printf("\n[TEST06]\n");
    printf("Calling DLLast for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLLast();

    printf("\n[TEST07]\n");
    printf("Calling DLDeleteFirst for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDeleteFirst();

    printf("\n[TEST08]\n");
    printf("Calling DLDeleteLast for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDeleteLast();

    printf("\n[TEST09]\n");
    printf("Calling DLPostDelete for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPostDelete();

    printf("\n[TEST10]\n");
    printf("Calling DLPreDelete for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPreDelete();

    printf("\n[TEST11]\n");
    printf("Calling DLPostInsert for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPostInsert();

    printf("\n[TEST12]\n");
    printf("Calling DLPreInsert for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPreInsert();

    printf("\n[TEST13]\n");
    printf("Calling DLActualize for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLActualize();

    printf("\n[TEST14]\n");
    printf("Calling DLSucc for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLSucc();

    printf("\n[TEST15]\n");
    printf("Calling DLPred for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPred();

    printf("\n[TEST16]\n");
    printf("Function DLActive for empty list should return FALSE.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLActive();

    printf("\n[TEST17]\n");
    printf("Calling DLDisposeList for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDisposeList();
   
                                 /* We concentrate on DLInsertFirst function. */	
    printf("\n[TEST18]\n");
    printf("3x DLInsertFirst\n");
    printf("~~~~~~~~~~~~~~~~\n");	
    test_DLInsertFirst();	
    test_DLInsertFirst();	
    test_DLInsertFirst();	

    printf("\n[TEST19]\n");
    printf("The list should not be active now.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLActive();

    printf("\n[TEST20]\n");
    printf("We start at the begin of the list and go to the end.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLFirst();
    test_DLActive();
    test_DLSucc();
    test_DLActive();
    test_DLSucc();
    test_DLActive();
    test_DLSucc();
    test_DLActive();

    printf("\n[TEST21]\n");
    printf("We start at the end of the list and go to its begin.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLLast();
    test_DLActive();
    test_DLPred();
    test_DLActive();
    test_DLPred();
    test_DLActive();
    test_DLPred();
    test_DLActive();

                                /* We read and destroy the list from the end. */	
    printf("\n[TEST22]\n");
    printf("We read and destroy the list by DLCopylast and DLDeleteLast functions.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLCopyLast();
    test_DLDeleteLast();
    test_DLActive();
    test_DLFirst();
    test_DLCopyLast();
    test_DLDeleteLast();
    test_DLActive();
    test_DLLast();
    test_DLCopyLast();
    test_DLDeleteLast();
    test_DLActive();

                                  /* We concentrate on DLInsertLast function. */	
    printf("\n[TEST23]\n");
    printf("3x DLInsertLast\n");
    printf("~~~~~~~~~~~~~~~\n");	
    test_DLInsertLast();	
    test_DLInsertLast();	
    test_DLInsertLast();	

    printf("\n[TEST24]\n");
    printf("The list should not be active now.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLActive();

    printf("\n[TEST25]\n");
    printf("We start at the begin of the list and go to the end.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLFirst();
    test_DLActive();
    test_DLSucc();
    test_DLActive();
    test_DLSucc();
    test_DLActive();
    test_DLSucc();
    test_DLActive();

    printf("\n[TEST26]\n");
    printf("We start at the end of the list and go to its begin.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLLast();
    test_DLActive();
    test_DLPred();
    test_DLActive();
    test_DLPred();
    test_DLActive();
    test_DLPred();
    test_DLActive();

                              /* We read and destroy the list from the begin. */	
    printf("\n[TEST27]\n");
    printf("We read and destroy the list by DLCopyFirst and DLDeleteFirst functions.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLCopyFirst();
    test_DLDeleteFirst();
    test_DLActive();
    test_DLFirst();
    test_DLCopyFirst();
    test_DLDeleteFirst();
    test_DLActive();
    test_DLLast();
    test_DLCopyFirst();
    test_DLDeleteFirst();
    test_DLActive();

                       /* We concentrate on some functions for inactive list. */	
    printf("\n[TEST28]\n");
    printf("We start with one element in inactive list. Nothing should happen.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLActive();
    test_DLInsertLast();
    test_DLPostDelete();
    test_DLPreDelete();
    test_DLPostInsert();
    test_DLPreInsert();
    test_DLSucc();
    test_DLPred();
    test_DLActualize();
    test_DLActive();

    printf("\n[TEST29]\n");
    printf("Function DLCopy for inactive list should cause an error.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLActive();
    test_DLCopy();
    test_DLActive();

    printf("\n[TEST30]\n");
    printf("We continue with additional element in inactive list. Again, nothing should happen.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLActive();
    test_DLInsertFirst();
    test_DLPostDelete();
    test_DLPreDelete();
    test_DLPostInsert();
    test_DLPreInsert();
    test_DLSucc();
    test_DLPred();
    test_DLActualize();
    test_DLActive();

    printf("\n[TEST31]\n");
    printf("Function DLCopy for inactive list should cause an error again.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLActive();
    test_DLCopy();
    test_DLActive();

                                             /* We change values of elements. */	
    printf("\n[TEST32]\n");
    printf("We change values of elements from the begin.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLFirst();
    test_DLActualize();
    test_DLSucc();
    test_DLActualize();
    test_DLActive();

    printf("\n[TEST33]\n");
    printf("We change values of elements from the end.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
    test_DLLast();
    test_DLActualize();
    test_DLPred();
    test_DLActualize();
    test_DLActive();

                       /* We try to lose activity by deleting active element. */	
    printf("\n[TEST34]\n");
    printf("Function DLDeleteFirst can cause loss of activity.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLInsertLast();
    test_DLActive();
    test_DLFirst();
    test_DLDeleteFirst();
    test_DLActive();
   
    printf("\n[TEST35]\n");
    printf("Function DLDeleteLast can cause loss of activity.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLInsertFirst();
    test_DLActive();
    test_DLLast();
    test_DLDeleteLast();
    test_DLActive();

  /* We try to delete first and last element by DLPreDelete and DLPostDelete. */	
    printf("\n[TEST36]\n");
    printf("Function DLPreDelete deletes first element.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLInsertFirst();
    test_DLFirst();
    test_DLSucc();
    test_DLPreDelete();
    test_DLCopyFirst();

    printf("\n[TEST37]\n");
    printf("Function DLPostDelete deletes last element.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLInsertLast();
    test_DLLast();
    test_DLPred();
    test_DLPostDelete();
    test_DLCopyLast();

               /* We try some functions at the begin and the end of the list. */	
    printf("\n[TEST38]\n");
    printf("Function DLPreDelete at the begin of the list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLFirst();
    test_DLPreDelete();
    test_DLActive();

    printf("\n[TEST39]\n");
    printf("We add a new element at the begin by DLPreInsert.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPreInsert();
    test_DLCopyFirst();
    test_DLCopy();
    test_DLActive();

    printf("\n[TEST40]\n");
    printf("Function DLPostDelete at the end of the list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLLast();
    test_DLPostDelete();
    test_DLActive();

    printf("\n[TEST41]\n");
    printf("We add a new element at the end by DLPostInsert.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPostInsert();
    test_DLCopyLast();
    test_DLCopy();
    test_DLActive();

                                                          /* We dispose list. */	
    printf("\n[TEST42]\n");
    printf("We dispose the list.\n");
    printf("~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDisposeList();

    printf("\n[TEST43]\n");
    printf("Twice.\n");
    printf("~~~~~~~~~~\n");
    test_DLDisposeList();
 
  
                            /* We dispose list and test some functions again. */	
    printf("\n[TEST44]\n");
    printf("Calling DLCopyFirst for empty list should cause en error.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopyFirst();
	
    printf("\n[TEST45]\n");
    printf("Calling DLCopyLast for empty list should cause en error.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopyLast();

    printf("\n[TEST46]\n");
    printf("Calling DLCopy for empty list should cause en error.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopy();

    printf("\n[TEST47]\n");
    printf("Calling DLFirst for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLFirst();

    printf("\n[TEST48]\n");
    printf("Calling DLLast for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLLast();

    printf("\n[TEST49]\n");
    printf("Calling DLDeleteFirst for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDeleteFirst();

    printf("\n[TEST50]\n");
    printf("Calling DLDeleteLast for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDeleteLast();

    printf("\n[TEST51]\n");
    printf("Calling DLPostDelete for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPostDelete();

    printf("\n[TEST52]\n");
    printf("Calling DLPreDelete for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPreDelete();

    printf("\n[TEST53]\n");
    printf("Calling DLPostInsert for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPostInsert();

    printf("\n[TEST54]\n");
    printf("Calling DLPreInsert for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPreInsert();

    printf("\n[TEST55]\n");
    printf("Calling DLActualize for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLActualize();

    printf("\n[TEST56]\n");
    printf("Calling DLSucc for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLSucc();

    printf("\n[TEST57]\n");
    printf("Calling DLPred for empty list should do nothing.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPred();

    printf("\n[TEST58]\n");
    printf("Function DLActive for empty list should return FALSE.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLActive();

    printf("\n----------------------- End of advanced test for c206 ----------------------\n");
		
	return(0);
} 
/**/

