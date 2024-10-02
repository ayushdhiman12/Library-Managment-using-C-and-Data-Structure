#include<stdio.h>
#include<string.h>
struct book
    {
    int bno,status;
    char bname[20];
    }
b[100];
int cnt = 0;

// ********  Functions *********
void add()
{
    printf("Enter the Book Name: ");
    scanf("%s",b[cnt].bname);
    printf("Enter the Book Number: ");
    scanf("%d",&b[cnt].bno);
    b[cnt].status = 1;

    cnt++;
}
void viewBooks()
    {
    int i;
    for(i=0;i<cnt;i++)
        {
        printf("Book Name :%s - Book Number: %d - Book Status %s\n", b[i].bname,b[i].bno,(b[i].status?"available":"not Available"));
        }
    }
void lendBook()
      {
        int i,f = 0;
        char a[10];
        printf("Enter book name : \n");
        scanf("%s",a);
        for(i=0;i<cnt;i++)
        {
			if(strcmp(b[i].bname,a)==0){
				f=1;
				b[i].status = 0;
				break;
			}
		}
        printf(f==1?"issued":"not issued");
      }
void viewBook()
{
      int i;
      for(i=0;i<cnt;i++)
      {
            // if(b[i].status == 0)
            printf("Book Name :%s - Book Number: %d - Book Status %s\n",b[i].bname,b[i].bno,(b[i].status?"available":"not Available"));
      }
}

void returnBook()
      {
        int i,f = 0;
        char a[10];
        printf("enter book name : \n");
        scanf("%s",a);
        for(i=0;i<cnt;i++)
        {
			if(strcmp(b[i].bname,a)==0){
				f=1;
				b[i].status = 1;
				break;
			}
		}
        printf(f==1?"returned":"book not found : ");
      }

// ********** Main Functions ************

int main()
{
   int a,a1,b,b1;
   char login[100] = {"admin"};
   char pass[100] = {"123"};
   char l[100],p[100];
   while(1)
   {
       printf("\n 1.Admin\n 2.Student \n 3.Exit \n");
       scanf("%d",&a);
       if(a==3)
            break;
       else if(a==1)
        {
           printf("Enter Admin ID : ");
                scanf("%s", l);
                printf("Enter Admin Password : ");
                scanf("%s", p);
                if(strcmp(login, l) == 0 && strcmp(pass, p) == 0)
                {
                    while(1)
                    {
                         printf("1.Add books \n2.Exit\n");
                         scanf("%d",&b1);
                         if(b1==2)
                             break;
                         else if(b1==1)
                         {
                             add();
                         }
                         
                         else
                         {
                             printf("invalid option\n");
                         }
                        }
                }
                else
                {
                    printf("Invalid ID or Password ! \n");
                    continue;
                }
           }
       
        else if(a==2)
        {
         printf("\n 1.Lend books \n 2.Return books \n 3.view books \n 4.Exit \n");
         scanf("%d",&b);
         if(b==1)
        {
             lendBook();
        }
        else if(b== 2)
        {
            returnBook();
        }
        else if(b==3)
        {
            viewBook();
        }
        else
        {
            printf("invalid option");
        }
        }
    else
    printf("Invalid Choice");
   }
}












