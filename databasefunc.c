 #include "databasefunc.h"

struct item* additem(int *no_of_items,struct item *arr)
{

    int n=0;
    int x=*no_of_items;
    printf("Enter the number of items to be added:");
    scanf("%d",&n);
    fflush(stdin);
    arr=realloc(arr,(x+n)*sizeof(struct item));
    for(int i=x;i<x+n;i++)
    {
        printf("Enter item name:");
        gets(arr[i].item_name);
        printf("\n Enter prize:");
        scanf("%f",&arr[i].item_prz);
        arr[i].item_id=i+1;
        fflush(stdin);

    }
    *no_of_items+=n;
    printf("\n %d item have been added successfully",n);
    return arr;

}




void view_items(struct item pro[],int numberofitems)
{
    int id=0,exit=0;
    int curpage=1;
    int last_page=(numberofitems%10==0)?numberofitems/10:numberofitems/10+1;
    if(numberofitems==0)
    {
        printf("Sorry there are no items in the database");
        return ;
    }
    while(exit==0){
    system("cls");
    printf("\n\n\n");
    printf("\t\t       |-------------------------------------------------|\n");
    printf("\t\t       |    Item id   |      Item name         |   Price |\n");
    printf("\t\t       |-------------------------------------------------|\n");
    for(int i=0;i<10&&id<numberofitems;i++)
    {
        printf("\t\t       |%11d   |",pro[id].item_id);
        printf("     %-17s  |",pro[id].item_name);
        printf("%8.2f |\n",pro[id].item_prz);
        id++;

    }
    if(curpage==1)
    printf("\t\t       |-------------------------------------------------|   next>\n");
    else if(curpage==last_page)
    printf("\t\t<prev  |-------------------------------------------------|\n");
    else
    printf("\t\t<prev  |-------------------------------------------------|   next>\n");
    printf("\n\t\t         Press Enter key to exit.");
    int keypressed;
    keypressed=getch();
    if (keypressed == 224) { // if the first value is esc
        keypressed=getch();
    switch(keypressed) { // the real value
        case 75:
            // code for arrow up
            if(curpage!=1)
            {
                curpage--;

            }
            else
                printf("\a");
            break;
        case 77:
            // code for arrow down
            if(curpage!=last_page)
            {
                curpage++;
            }
            else
                printf("\a");
            break;
        default:
            printf("\a");
    }id=(curpage-1)*10;}
    else if(keypressed==13)
        exit=1;
    }



}

struct item* modifyitem(int *no_of_items,struct item *pro)
{
    int id;
    id=search(*no_of_items,pro);
    if(id==-1)
    {
        printf("No items to be modified.");
        return pro;
    }
    printf("Enter the new name:");
    gets(pro[id-1].item_name);
    printf("Enter the new prize:");
    scanf("%f",&pro[id-1].item_prz);
    return pro;


}

struct item* deleteitem(int *no_of_items,struct item *pro)
{
    int x=*no_of_items;
    int id;
    id=search(x,pro);
    if(id==-1)
    {
        printf("No items to be deleted.");
        return pro;
    }
    for(int i=0;i<*no_of_items;i++)
    {
        if(pro[i].item_id == id)
        {
            for(int j=i;j<*no_of_items-1;j++)
            {
                pro[j]=pro[j+1];
                pro[j].item_id-=1;
            }
        }
    }
    pro=realloc(pro,(x-1)*sizeof(struct item));
    *no_of_items-=1;
    return(pro);
}

int search(int no_of_items,struct item pro[])
{
    system("cls");
    fflush(stdin);
    char search[20];
    printf("Enter the name of the item: ");
    gets(search);
    printf("\n");

    printf("|-------------------------------------------------|\n");
    printf("|    Item id   |        Item name       |   Price |\n");
    printf("|-------------------------------------------------|\n");

    int displayed_items=0;
    for(int i=0;i<no_of_items;i++)
    {
        if(strstr(pro[i].item_name, search) != NULL)
        {
          /* ... */

        printf("|%11d   |",pro[i].item_id);
        printf("%17s       |",pro[i].item_name);
        printf("%8.2f |\n",pro[i].item_prz);
        displayed_items++;
        }
    }
    if(displayed_items==0){
    printf("|          NO ITEMS IN DATABASE                   |\n");
    printf("|-------------------------------------------------|\n");
    return -1;
    }
    printf("|-------------------------------------------------|\n");

    int id=-1;
    printf("Enter the id of the item to be modified or deleted:");
    scanf("%d",&id);
    fflush(stdin);
    return id;
}
