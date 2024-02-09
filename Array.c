void insertion(int [ ], int, int, int);
int deletion (int [ ], int,int);
void traverse(int [ ], int);
int sum(int [ ],int);
void search(int [ ],int);
#include <stdio.h>
int main()
{
int LA[50], n, i, Index, Item, choice=1;
printf("Enter total numbers in Array:");
scanf("%d",&n);
printf("Enter the value of %d Numbers:",n);
for(i=0;i<=n-1;i++)
scanf("%d",&LA[i]);
printf("The original array elements are :\n");//Misleading indentation: statement is indented too deeply clang-tidy (readability-misleading-indentation) [15, 1]
traverse(LA,n);
while(choice==1)
{

printf("\nPress 1. For Insertion :");
printf("\nPress 2. For Deletion: ");
printf("\nPress 3. For display the elements of array: ");
printf("\nPress 4. For Sum of the elements of array: ");
printf("\nPress 5.For Search any element of array: ");
printf("\nEnter Your choice: ");

scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the value which you want to insert in this array: ");
scanf("%d", &Item);
printf("Enter the Index where you want to insert");
scanf("%d", &Index);
insertion(LA, n, Item, Index);//Function Call
n=n+1;
printf("The array after insertion one element is:\n");
traverse(LA,n);
break;
case 2:
printf("Enter the index from where you want to delete: ");

scanf("%d", &Index);
Item=deletion(LA, n, Index);//Function Call
printf("The deleted element is %d\n",Item);
n=n-1;
printf("The array after deletion of one element is:\n");
traverse(LA,n);
break;
case 3:
traverse(LA,n);
case 4:
printf("\nThe Sum of all the elements is %d",sum(LA,n));
case 5:
search(LA,n);
}//End of Switch
printf("\nDo you want to continue Press 1 otherwise press 0 to exit:");
scanf("%d",&choice);
}//End of while
return 0;
}//End of Main
int deletion (int A[ ], int n, int Pos)//Function Definition
{
int i, Item;
Item= A[Pos];
for(i=Pos+1;i<=n-1;i++)
A[i-1]=A[i];
return(Item);//Misleading indentation: statement is indented too deeply clang-tidy (readability-misleading-indentation) [68, 1]
}

void traverse(int A[ ], int N)//Function Definition
{
int i=0;
while(i<=N-1)
{
printf("%d\t ", A[i]);
i=i+1;
}
}
void insertion (int A[ ], int n, int Element, int Pos)//Function Definition
{

int i;
for(i=n-1;i>=Pos;i--)
A[i+1]=A[i];
A [Pos] = Element;//Misleading indentation: statement is indented too deeply clang-tidy (readability-misleading-indentation) [86, 1]
}

int sum(int A[ ],int n)
{
    int Total=0,i;
    for(i=0;i<=n;i++)
        Total=Total+A[i];
    return Total;
}
void search(int A[ ],int n){
    int Element;
    int count=0;
    printf("enter the element you want to search:");
    scanf("%d",&Element);
    for(int i=0;i<n;i++)
    {
        if(A[i]==Element){
            printf("element found at position :%d",i);
            count+=1;
        }
        else{
            continue;
        }
    
    }
    if(count==0){
        printf("element not found");
    }

    
}

