#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "contact.h"


void main()
{
    /* Variable and structre defintion */
    char option;
    Addressbook addressbook;
    Intitalization(&addressbook);
    system("clear");

    while (1)
    {
        printf(O"----------------------------------------------------------------------------------------------------|"E"\n");
        printf("\n"U C"Address Book Menu"E"\n\n\t"); /* Give a prompt message for a user */
        printf("1) Add Contact\n\t");
        printf("2) Edit Contact\n\t");
        printf("3) Delete Contact\n\t");
        printf("4) Search Contact\n\t");
        printf("5) Display Contact\n\t");
        printf("6) Save Contact\n\t");
        printf("7) Exit\n\n");
        printf(Y"Enter the option : "E"");
        if(!scanf("%hhd",&option))
            __fpurge(stdin);

        printf(O"----------------------------------------------------------------------------------------------------|"E"\n"); 
        switch (option) /* Based on choosed option */
        {
            case 1:
                Create(&addressbook);
                break;

            case 2:
                Edit(&addressbook , 0);
                printf(G"\nContact Update Successfully"E B" (:"E"\n");
                break;

            case 3:
                Delete(&addressbook);
                break;

            case 4:
                Search(&addressbook);
                break;

            case 5:
                List(&addressbook);
                break;

            case 6:
                Save(&addressbook);
                break;

            case 7:
                system("clear");
                return;
                break;

            default:
                printf(R "Invalid option "E"\n");
                break;
        }
    }
}
