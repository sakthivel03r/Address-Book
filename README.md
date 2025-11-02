# 📘 Address Book Management System (C Project)

------------------------------------------------------------------------------------|

/* Describition About Project */ 

A simple 'Address Book Application' written in C that allows users to create , edit , delete , search , save contacts.

This project demonstrates the use of structures , enums , file handling , validation , ANSI color codes in C.
    
------------------------------------------------------------------------------------|

## 🚀 Features

✅ Add new contacts  
✅ Edit existing contacts  
✅ Delete contacts  
✅ Search contacts (by Name, Phone, or Email)  
✅ List all contacts (sorted alphabetically)  
✅ Save and load contacts from a CSV file  
✅ Input validation for name, phone, and email fields  
✅ Uses 'ANSI color codes' for an interactive console experience  

------------------------------------------------------------------------------------|

## 🧱 Project Structure

📦 AddressBook

    📜 contact.h → Header file with structure, macros, and function declarations
    📜 main.c → Main program with menu and control flow
    📜 functions.c → Implementation of core functions (create, edit, delete, etc.)
    📜 file.csv → Data file for saving contacts
    📜 README.md → Documentation (this file)

------------------------------------------------------------------------------------|

🎨 Color Codes Used

     _____________________________________________
    | Macro | Description | Color / Style        |
    |------ |------------ |--------------------- |
    | `U`   | Underline   | Underlined text      |
    | `BK`  | Blink       | Blinking text        |
    | `R`   | Red         | Error messages       |
    | `G`   | Green       | Success messages     |
    | `Y`   | Yellow/Gold | Prompts & highlights |
    | `O`   | Orange      | Section headers      |
    | `B`   | Blue        | Titles               |
    | `C`   | Cyan        | Labels / Info text   |
    | `E`   | End         | Reset style          |
    |_______|_____________|______________________|

------------------------------------------------------------------------------------|

💾 File Handling (file.csv)

All contacts are saved in a file named file.csv located in the same directory.

The first line stores the number of contacts:

#3

Each subsequent line stores contact details in CSV format:

Name,Phone,Email
John Doe,9876543210,john@example.com
Alice,8765432109,alice@mail.com
Bob,9123456780,bob@domain.com


------------------------------------------------------------------------------------|

🧰 Compilation & Execution Support GCC

You can compile all files easily with:

gcc *.c -o addressbook


Then run:

./addressbook

------------------------------------------------------------------------------------|

🧮 Validation Rules

 _____________________________________________________________________________________
|    Field  |                    Rules                             | Example          |
|-----------|------------------------------------------------------|----------------- |
|   Name    | Must start with an alphabet                          | `John`, `Alice`  |
|   Phone   | Must be 10 digits, start with 6–9                    | `9876543210`     |
|   Email   | Must be lowercase, include `@` and `.`, valid domain | `name@gmail.com` |
|___________|______________________________________________________|__________________|


------------------------------------------------------------------------------------|

🧩 Sample Run (Console)

Address Book Menu

    1) Add Contact
    2) Edit Contact
    3) Delete Contact
    4) Search Contact
    5) Display Contact
    6) Save Contact
    7) Exit

Enter the option: 1
Enter Name: John
Enter Mobile Number: 9876543210
Enter Mail ID: john@gmail.com

Contact Created Successfully (:

------------------------------------------------------------------------------------|

🧠 Concepts Covered

Structures & nested structs

Enumerations for state management

File handling (fopen, fscanf, fprintf)

String manipulation (strcmp, strcpy, strcasecmp)

Input validation (isalpha, isdigit, isalnum)

ANSI color codes for styling

Modular program design using header files

------------------------------------------------------------------------------------|
