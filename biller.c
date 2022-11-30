#include "biller.h"

void biller()
{
    //declaration
 scart carts[100];
 int size=0;
 int exit=0;
  FILE *rfile,*rmet;
    struct item *dynarray=NULL;
    int numberofitems=0;

    if((rfile=fopen("Listofitems.dat","r")) && (rmet=fopen("metadata.txt","r")))
    {
        fscanf(rmet,"%d",&numberofitems);
        fclose(rmet);
        dynarray=(struct item*)malloc((numberofitems)*sizeof(struct item));
        fread(dynarray,sizeof(struct item),numberofitems,rfile);
        fclose(rfile);
    }
    else
    {
        printf("No such file exist");
    }
    //process
    while(exit==0)
    {
      system("cls");
      displaycart(carts,size);
      char *s[]={"Biller","Add item to cart","Print Bill","Exit"};
      int ch=menu2(s,3);


      switch(ch)
      {
          case 1:additemcart(&carts[size],numberofitems,dynarray,&size);
          break;
          case 2:printbill(carts,size);
                printf("Bill printed successfully\n");
                size=0;
                system("pause");
          break;
          case 3:exit=1;
      }
    }
    free(dynarray);
}



void additemcart(scart *c,int n,struct item pro[],int *size)
{
    int id,quantity;
    printf("Enter id:");
    scanf("%d",&id);

    if(id<1 || id>n)
    {
        printf("The id is not valid ");
        return;
    }
    printf("Enter the Quantity:");
    scanf("%d",&quantity);
    c->product=pro[id-1];
    c->prz=c->product.item_prz*quantity;
    c->quantity=quantity;
    *size=*size+1;
}

void displaycart(scart p[],int size)

{
    float tot;
    tot=total(size,p);
    printf("------------\n");
    printf("    CART   |\n");
    printf("------------\n");
      printf("------------------------------------------\n");
      printf("|  S.No  |    Name    |   Qty  |   Price |\n");
      printf("------------------------------------------\n");
    if(size==0)
    {
      printf("|       NO ITEMS IN CART                |\n");
      printf("------------------------------------------\n");
      return ;
    }
    for(int i=0;i<size;i++)
    {
      printf("|   %2d  |%12s|   %3d  | %5.2f   |\n",i+1,p[i].product.item_name,p[i].quantity,p[i].prz);
    }
    printf("------------------------------------------\n");
    printf("                        TOTAL:   %8.2f   \n",tot);
    printf("------------------------------------------\n");
}


float total(int size,scart pro[])
{
    float total=0;
    for(int i=0;i<size;i++)
    {
      total=pro[i].prz+total;
    }
    return total;

}

void printbill(scart p[],int size)
{
     float tot;
    tot=total(size,p);
    srand(time(NULL));
    long billno=rand()%5000+1000;
    time_t t;   // not a primitive datatype
    time(&t);
    FILE *ptr;
    ptr=fopen("bill.txt","w+");

    fprintf(ptr,"                GRANDE GROCERY                \n");
    fprintf(ptr,"----------------------------------------------\n");
    fprintf(ptr,"                   SF No.30                   \n");
    fprintf(ptr,"                 Vasanth nagar,               \n");
    fprintf(ptr,"                   M G Road,                  \n");
    fprintf(ptr,"                  Sulur taluk,                \n");
    fprintf(ptr,"                Coimbatore-641005             \n");
    fprintf(ptr,"--------------Phone: 90004 43829--------------\n");
    fprintf(ptr,"----------------------------------------------\n");
    fprintf(ptr,"BILL NO:%ld  BILL Dt:%s                       \n",billno,ctime(&t));
    fprintf(ptr,"----------------------------------------------\n");
    fprintf(ptr,"|  S.No  |     Name    |   Qty   |   Price   |\n");
    fprintf(ptr,"----------------------------------------------\n");
    for(int i=0;i<size;i++)
    {
    fprintf(ptr,"|   %2d   |%12s |   %3d   |  %5.2f  |\n",i+1,p[i].product.item_name,p[i].quantity,p[i].prz);
    }
    fprintf(ptr,"----------------------------------------------\n");
    fprintf(ptr,"\n                           TOTAL: %8.2f   \n",tot);
    fprintf(ptr,"----------------------------------------------\n");
    fprintf(ptr,"                   THANK YOU                  \n");
    fprintf(ptr,"----------------------------------------------\n");
    fclose(ptr);
}
