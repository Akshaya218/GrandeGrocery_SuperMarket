#include "firstscreen.h"


int view_first_screen()
{
    int choice;
    char *men[]={"Main menu","Biller","Superuser","Exit"};
    choice=menu(men,3);

    switch(choice)
     {
        case 1:biller();
        break;
        case 2:superuser();
        break;
        case 3:printf("Exit \n");
               return(1);
        break;

    }
    system("cls");
    return(0);
}
