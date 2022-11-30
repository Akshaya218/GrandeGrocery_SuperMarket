#include "superuser.h"

void superuser()
{

//loading of data:

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

//The Actual Process:
    int choice,exit=0;
    do{
        char *s[]={"Superuser","Add item", "Modify item", "Delete item", "View item","Exit"};
        choice=menu(s,5);

    switch(choice)
    {

        case 1:system("cls");
                dynarray=additem(&numberofitems,dynarray);
               system("pause");
        break;
        case 2:system("cls");
                dynarray=modifyitem(&numberofitems,dynarray);
               system("pause");
        break;
        case 3:system("cls");
                dynarray=deleteitem(&numberofitems,dynarray);
               system("pause");
        break;
        case 4:system("cls");
                view_items(dynarray,numberofitems);
        break;
        case 5:exit=1;
        break;

    }}while(exit==0);


//Writing Back to the file:

    FILE *wfile,*wmet;

    wfile=fopen("Listofitems.dat","w");
    fwrite(&dynarray[0],sizeof(struct item),numberofitems,wfile);
    fclose(wfile);

    wmet=fopen("metadata.txt","w");
    fprintf(wmet,"%d",numberofitems);
    fclose(wmet);

//Freeing the dynamic array

    free(dynarray);
}
