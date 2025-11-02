#ifndef CONTACT_H
#define CONTACT_H

typedef struct
{
    char Name[50];
    char Phone[15];
    char Mail[50];

}Contacts ;


typedef struct Address_book
{
    Contacts contact[100];
    int Contactcount;

}Addressbook;

typedef enum 
{
    FAILURE ,
    SUCCESS ,
    NOT_FOUND ,
    VALID ,
    TRYAGAIN ,
    EXIT

}Outcome ;

/* Function declarations */
void Intitalization(Addressbook * addressbook);
void Create(Addressbook * );
void List(Addressbook * );
void Search(Addressbook * addressbook);
void Edit(Addressbook * addressbook , char);
void Delete(Addressbook *addressbook);
void Save(Addressbook *addressbook);

/* Validation Function Prototype */
Outcome NameValidation(char []);
Outcome PhoneValidation(char []);
Outcome MailValidation(char []);
Outcome UniqueString(Addressbook * , char []);

void print(Addressbook *, int );

//colour Code 
#define U "\033[4m"
#define BK "\033[5m"
#define R "\033[1;91m" 
#define G "\033[1;92m"
#define Y "\033[38;2;255;215;0m"
#define O "\033[38;2;255;140;0m"
#define B "\033[1;94m"
#define C "\033[38;2;0;206;209m"
#define E "\033[0m"

#endif
