#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "contact.h"

char Find , Changes;

Outcome Result(void)
{
    char option ;
    printf("->> Press Any Key + Enter To Continue\n\t");
    printf("->> Press Enter To Exit\n\n");
    printf(Y"Enter Option : " E);
    getchar(); 
    option = getchar();
    __fpurge(stdin);

    if(option == 10)
    {
        system("clear");
        return EXIT ;
    }
    else
        return TRYAGAIN ;
}

void Intitalization(Addressbook * addressbook)
{
    FILE * fp = fopen("file.csv","r");
    if(fp == NULL)
    {
        printf("File < %s > Not Open\n", "file.csv");
        return ;
    }

    fscanf(fp ,"#%d\n",&addressbook->Contactcount);
    for(int i = 0; !feof(fp) ; i++)
        fscanf(fp , "%[^,], %[^,], %[^\n]\n",addressbook->contact[i].Name,addressbook->contact[i].Phone,addressbook->contact[i].Mail);
}

void Create(Addressbook * addressbook)
{
    char i = addressbook->Contactcount , result ;

    do
    {
        printf("\nEnter Name : "); 
        scanf(" %[^\n]",addressbook->contact[i].Name);
        result = NameValidation(addressbook->contact[i].Name);

        if(result == EXIT)
            return ;

    }while(result == TRYAGAIN);

    do
    {
        printf("\nEnter Mobile Number : "); 
        scanf(" %[^\n]",addressbook->contact[i].Phone);
        result = UniqueString(addressbook, addressbook->contact[i].Phone);

        if(result == VALID)
            result = PhoneValidation(addressbook->contact[i].Phone);

        if(result == EXIT)
            return ;

    }while(result == TRYAGAIN);

    do
    {
        printf("\nEnter Mail ID : "); 
        scanf(" %[^\n]",addressbook->contact[i].Mail);
        result = UniqueString(addressbook, addressbook->contact[i].Mail);

        if(result == VALID)
            result = MailValidation(addressbook->contact[i].Mail);

        if(result == EXIT)
            return;

    }while(result == TRYAGAIN);

    addressbook->Contactcount++;
    printf(G"\nContact Created Successfully"E B" (:"E"\n\n"); 
}

void List(Addressbook * addressbook)
{
    char count = addressbook->Contactcount;
    Contacts Temp;

    if(count < 1)
    {
        printf(O"LIST IS EMPTY"E B" ):\n");
        return;
    }

    for(char i = 0; i < count - 1; i++)
    {
        for(char j= 0; j < count - i - 1; j++)
        {
            if(strcmp(addressbook->contact[j].Name,addressbook->contact[j + 1].Name) > 0)
            {
                Temp = addressbook->contact[j];
                addressbook->contact[j] = addressbook->contact[j + 1];
                addressbook->contact[j + 1] = Temp; 
            }
        }
    }

    printf(B"\n!-------------------------------- ! LIST OF CONTACTS ! --------------------------------!\n"E);
    printf(" ______________________________________________________________________________________\n");
    printf("|"C" %-5s"E"|"C" %-30s"E"|"C" %-14s"E"|"C" %-30s"E"|\n","S.NO","NAME","MOBILE NUMBER","EMAIL ID");
    printf("|______|_______________________________|_______________|_______________________________|\n");

    for(char i = 0; i < count; i++)
    {
        printf("| %-5d| %-30s| %-14s| %-30s|\n",i + 1,addressbook->contact[i].Name,addressbook->contact[i].Phone
                ,addressbook->contact[i].Mail);

        printf("|______|_______________________________|_______________|_______________________________|\n");
    } printf("\n");

}

void Search(Addressbook * addressbook)
{
    char i , result , count , pos = 0 , index[100] , input[50];
    count = addressbook->Contactcount ;

    printf(U C"\nSearch Contact By :-\n\n\t"E);
    printf("1) Name\n\t");
    printf("2) Mobile Number\n\t");
    printf("3) Mail ID\n\t");
    printf("4) Exit\n\n");
    printf(Y"Enter Option : "E);
    if(!scanf("%hhd",&result))
        __fpurge(stdin);

    printf("\n");
    switch (result)
    {
        case 1:
            do
            {
                printf("Enter Name: "); 
                scanf(" %[^\n]", input);
                result = NameValidation(input);

                if(result == EXIT)
                    return ;

            }while(result == TRYAGAIN);

            for(i = 0 ; i < count ; i++)
            {
                if(strcasecmp(addressbook->contact[i].Name,input) == 0)
                    index[pos++] = i;
            }

            break;

        case 2:
            do
            {
                printf("Enter Mobile Number : ");
                scanf(" %[^\n]",input);
                result = PhoneValidation(input);

                if(result == EXIT)
                    return ;

            }while(result == TRYAGAIN);

            for(i = 0 ; i < count ; i++)
            {
                if(strcmp(addressbook->contact[i].Phone,input) == 0)
                    break;
            }

            break;

        case 3 :
            do
            {
                printf("Enter Mail ID : ");
                scanf(" %[^\n]",input);
                result = MailValidation(input);

                if(result == EXIT)
                    return ;

            }while(result == TRYAGAIN);

            for(i = 0 ; i < count ; i++)
            {
                if(strcmp(addressbook->contact[i].Mail,input) == 0)
                    break;
            }

            break;

        case 4 : return ;
                 break;

        default: printf(R "Invalid option"E"\n");
                 return ;
    }

    if(i < count || pos > 0)
    {
        if(pos == 0)
        {
            index[0] = Find = i ;
            pos = 1;
        }
        else
            Find = index[0];

        printf(B"\n\n!--------------------------------- ! CONTACT SEARCHED ! -------------------------------!\n"E);
        printf(" ______________________________________________________________________________________\n");
        printf("|"C" %-5s"E"|"C" %-30s"E"|"C" %-14s"E"|"C" %-30s"E"|\n","S.NO","NAME","MOBILE NUMBER","EMAIL ID");
        printf("|______|_______________________________|_______________|_______________________________|\n"E);

        for(char i = 0 ; i < pos ; i++)
        {
            count = index[i];
            printf("| %-5d| %-30s| %-14s| %-30s|\n",i + 1 ,addressbook->contact[count].Name,addressbook->contact[count].Phone
                    ,addressbook->contact[count].Mail);
            printf("|______|_______________________________|_______________|_______________________________|\n");
        }printf("\n");

        if(pos > 1 && Changes)
        {
            printf(U C"List Of Same Name : \n"E);
            for(char i = 0 ; i < pos ; i++)
                printf("\n\t %d -> Contact" , i + 1);

            printf(Y"\n\nEnter Position of Contact Do You Want to Change : "E);
            scanf("%hhd",&count);
            Find = index[count - 1];

            printf(B"\n\n!--------------------------------- ! CHOSEN CONTACT ! ---------------------------------!\n"E);
            printf(" ______________________________________________________________________________________\n");
            printf("|"C" %-5s"E"|"C" %-30s"E"|"C" %-14s"E"|"C" %-30s"E"|\n","S.NO","NAME","MOBILE NUMBER","EMAIL ID");
            printf("|______|_______________________________|_______________|_______________________________|\n"E);
            printf("| %-5d| %-30s| %-14s| %-30s|\n",1,addressbook->contact[Find].Name,addressbook->contact[Find].Phone
                    ,addressbook->contact[Find].Mail);
            printf("|______|_______________________________|_______________|_______________________________|\n\n");

            Changes = 0 ;
        }
    }

    else
    {
        printf(O"INFO : Searched Contact Not Found"E B" ):\n"E);
        Find = -1 ;
    }
}

void Edit(Addressbook * addressbook , char Types)
{
    char option , input[50];
    if(Types == 0)
    {
        Find = -1 ; Changes = 1;
        Search(addressbook);
        if(Find < 0)
            return ;

        printf(U C"\n"C"Edit Contact Menu :"E"\n\n\t");
        printf("1) Name\n\t");
        printf("2) Mobile Number\n\t");
        printf("3) Mail ID\n\t");
        printf("4) Edit All\n\t");
        printf("5) Exit\n\n");
        printf(Y"Enter Option : "E);
        if(!scanf("%hhd",&option))
            __fpurge(stdin);
    }

    else
        option = Types ;

    printf("\n");
    switch(option)
    {
        case 1:
            do
            {
                printf("Enter New Name : ");
                scanf(" %[^\n]",input);
                option = NameValidation(input);

                if(option == EXIT)
                    return ;

            }while(option == TRYAGAIN);

            strcpy(addressbook->contact[Find].Name,input);
            break;

        case 2 :
            do
            {
                printf("Enter New Mobile Number : ");
                scanf(" %[^\n]",input);
                option = PhoneValidation(input);

                if(option == VALID)
                    option = UniqueString(addressbook,input);

                if(option == EXIT)
                    return ;

            }while(option == TRYAGAIN);

            strcpy(addressbook->contact[Find].Phone,input);
            break;

        case 3:
            do
            {
                printf("Enter New Mail ID : ");
                scanf(" %[^\n]",input);
                option = MailValidation(input);

                if(option == VALID)
                    option = UniqueString(addressbook,input);

                if(option == EXIT)
                    return ;

            }while(option == TRYAGAIN);

            strcpy(addressbook->contact[Find].Mail,input);
            break;

        case 4 :
            Edit(addressbook , 1);
            Edit(addressbook , 2);
            Edit(addressbook , 3);
            break;
    }
}

void Delete(Addressbook *addressbook)
{
    Changes = 1 ; Find = -1 ;
    Search(addressbook);

    if(Find < 0)
        return ;

    printf(U C"\nDo You Want To Delet The Contact:-\n\n\t"E);
    if(Result() == EXIT)
        return ;

    for(char i = Find ; i < addressbook->Contactcount ; i++)
        addressbook->contact[i] = addressbook->contact[i + 1];

    addressbook->Contactcount--; 
    printf(G "\nContact Deleted Successfully"E B" (:\n"E);
}

void Save(Addressbook *addressbook)
{
    FILE * fp = fopen("file.csv","w");
    if(fp == NULL)
    {
        printf("File < %s > is Not Open\n", "file.csv");
        return ;
    }

    fprintf(fp ,"#%d\n",addressbook->Contactcount);
    for(int i =0 ; i < addressbook->Contactcount; i++)
        fprintf( fp , "%s,%s,%s\n",addressbook->contact[i].Name,addressbook->contact[i].Phone
                ,addressbook->contact[i].Mail);

    printf(G"Contacts Saved Successfully"E B" (:\n"E);
}

Outcome NameValidation(char Name[])
{
    char option ;
    if(isalpha(Name[0]) == 0)
    {
        printf(U BK R "\nERROR "E":-""\nName Start with "O"Alphabet"E" Not with Any Other Character\n");
        printf(C"Do You Want To Try Again\n\n\t"E);
        return Result();
    }

    else
        return VALID ;
}

Outcome PhoneValidation(char Phone[])
{
    char i = 0 , count = 0;
    while(Phone[i])
    {
        if(isdigit(Phone[i]))
            count++;

        i++;
    }

    if(count == 10 && (Phone[0] >= '6' && Phone[0] <= '9'))
        return VALID ;

    else
    {
        printf(U BK R "\nERROR "E":-""\n"O"Mobile Number : "E"Should be 10 digit and Number Start with Range"C" (6 - 9) : \n"E);
        printf(U C"\nDo You Want To Try Again:-"E"\n\n\t");
        return Result();
    }
}

Outcome MailValidation(char string[])
{
    char i = 0 , option , Dot = 0, At = 0 , len = strlen(string);

    while(string[i])
    {
        if(isupper(string[i]))
            break;

        if(!isalnum(string[i]) && strchr("-@_." , string[i]) == NULL)
            break;

        if(string[i] == '.')
            Dot++;

        if(string[i] == '@')
            At++;

        if((string[i] == '.' && string[i +1] == '@' ) || (string[i] == '@' && string[i +1] == '.'))
            break;

        if( string[len - 1] == '.' || string[len - 1] == '@')
            break;

        if( !isalpha(string[0]) || At > 1 || Dot > 1 )
            break;

        i++;
    }

    if(len == i)
        return VALID ;

    else
    {
        printf(U BK R "\nERROR"E":-""\n\n"O"Mail ID : "E" Should Contain Lowercase , Digit , Special Character like (@ , - , _ , .)\n");
        printf(C"INFO : "E B"First Character"E" Should be Alphabet \n");
        printf(C"INFO : "E"Formate sholud be "B"name@domain.subdomain\n"E);
        printf(U C"\nDo You Want To Try Again:-"E"\n\n\t");
        return Result();
    }
}

Outcome UniqueString(Addressbook * data, char String[])
{
    char Digit = 0 , Mail = 0 , i;

    if(isdigit(String[0]))
        Digit = 1;

    else
        Mail = 1;

    for (i = 0 ; i < data->Contactcount ; i++)
    {
        if ((strcmp(data->contact[i].Phone, String) == 0) ||
                (strcmp(data->contact[i].Mail, String) == 0))
            break;
    }

    if(i < data->Contactcount)
    {
        printf("\n");
        if(Digit) 
            printf(U B BK R "ERROR "E":-""Given Mobile Number is Alraedy Present\n\n");
        else 
            printf(U  B BK R "ERROR "E":-""\nGiven Mail ID  is Already Present\n\n");

        printf(U C"\nDO YOU WANT TO TRY AGAIN:-"E"\n\n\t");
        return Result();
    }

    else
        return VALID ;
}
