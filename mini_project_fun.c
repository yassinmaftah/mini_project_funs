#include <stdio.h>
#include <string.h>

int choice; // to store the user's choice
int      i;
int      number_books = 0;
int      quantity[100];

char     name_book[100][100];
char     book_auteur[100][100];
float    book_prix[100];


void    add_book()
{
    printf(">> Here we will add a book\n");
    printf("Titre du livre : ");
    scanf("%s",name_book[number_books]);
    printf("Auteur du livre : ");
    scanf("%s",book_auteur[number_books]);
    printf("Prix du livre : ");
    scanf("%f",&book_prix[number_books]);
    printf("Quantite en stock : ");
    scanf("%d",&quantity[number_books]);
    number_books++;
}

void    desplay()
{
    printf(">> Here we will display all books\n");
    i = 0;
    while (i < number_books)
    {
        if (quantity[i] != 0)
        {
            printf("stock  %d\n", i + 1);
            printf("Titre du livre ==> %s\n" ,name_book[i]);
            printf("Auteur du livre ==> %s\n",book_auteur[i]);
            printf("Prix du livre ==> %.2fDH\n",book_prix[i]);
            printf("Quantite en stock ==> %d\n",quantity[i]);
        }
        i++;
    }
}

void    to_find()
{
    char check_book[100];
	printf("enter your book to find : ");
    scanf("%s",check_book);
    int found = 0;
    i = 0;
    while (i < number_books)
    {
        if (stricmp(check_book,name_book[i]) == 0)
        {
            printf("Book found : %s\n",name_book[i]);
            found = 1;
            if (quantity[i] == 0)
                printf("but the quantity is 0.\n");
        }
        i++;
    }
    if (!found)
        printf("not found !");
}

void       Update_quantity()
{
    char cheeck_book[100];
    int     new_quantity;
    int     check_find  =  0;
	printf("enter your book to Update quantity : ");
    scanf("%s",cheeck_book);
    i = 0;
    while(i < number_books)
    {
        if (stricmp(cheeck_book,name_book[i]) == 0)
        {
            printf("Entre the value of new quantity: ");
            scanf("%d", &new_quantity);
            printf("this is quantity before change: %d\n", quantity[i]);
            quantity[i] = new_quantity;
            printf("this is quantity after change: %d\n", quantity[i]);
            check_find = 1;
            break;
        }
        i++;
    }
    if(check_find == 0)
        printf("\nnot find this book!\n");
}

void    delate()
{
    printf(">> Here we will delete a book\n");
    char    cheeeck_book[100];
    int     cheeeck_find = 0;
	printf("enter your book to delate : ");
    scanf("%s",cheeeck_book);
    i = 0;
    while(i < number_books)
    {
        if (stricmp(cheeeck_book,name_book[i]) == 0)
        {
            while(i < number_books - 1)
            {
                strcpy(name_book[i], name_book[i + 1]);
                strcpy(book_auteur[i], book_auteur[i + 1]);
                book_prix[i] = book_prix[i + 1];
                quantity[i] = quantity[i + 1];
                i++;
            }
            number_books -= 1;
            cheeeck_find = 1;
            break;
        }
        i++;
    }
    if(cheeeck_find == 0)
        printf("\nnot find this book!\n");
}

int     calcule_total()
{
    printf(">> Here we will calculate total number of books\n");
    int total = 0;
    i = 0;
    while (i < number_books)
    {
        total += quantity[i];
        i++;
    }
    return total;
}

void    goodbye()
{
    printf("Exiting the program...\n");
}

void    Invalid_choice()
{
    printf("Invalid choice, please try again.\n");
}

int main() {

        do {
            // Display menu
            printf("\n=== Library Stock Management System ===\n");
            printf("1. Add a book\n");
            printf("2. Display all books\n");
            printf("3. Search for a book by title\n"); // wash kayn return 1 ila la retun 0.
            printf("4. Update book quantity\n");
            printf("5. Delete a book\n");
            printf("6. Display total number of books\n");
            printf("0. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            // Switch to handle user choice
            switch(choice) {
                case 1:
                    add_book();
                    break;
                case 2:
                    desplay();
                    break;
                case 3:
                    to_find();
                    break;
                case 4:
                    Update_quantity();
                    break;
                case 5:
                    delate();
                    break;
                case 6:
                    int     tootal = calcule_total();
                    printf("your quantity === > %d\n", tootal);
                    break;
                case 0:
                    goodbye();
                    break;
                default:
                    Invalid_choice();
            }
        } while(choice != 0);

    return 0;
}
