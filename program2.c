#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct book
{
    int book_id;
    char title[MAX];
    char author[MAX];
    float price;
    char availability[20];
};

/* Function prototypes */
struct book* create(int n);
void display(struct book *books, int n);
void search(struct book *books, int n);
void issue_book(struct book *books, int n);
void return_book(struct book *books, int n);

int main()
{
    struct book *books = NULL;
    int n = 0;
    int choice;

    while (1)
    {
        printf("\n========== LIBRARY MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Book Records\n");
        printf("2. Display all Available Book Records\n");
        printf("3. Search Book by Book ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");
        printf("===============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                /* Free previously allocated memory */
                if (books != NULL)
                {
                    free(books);
                    books = NULL;
                }

                printf("\nEnter number of books: ");
                scanf("%d", &n);

                if (n <= 0)
                {
                    printf("\nInvalid number of books.\n");
                    n = 0;
                    break;
                }

                books = create(n);
                break;

            case 2:
                if (books == NULL)
                {
                    printf("\nNo book records available. Please add books first.\n");
                }
                else
                {
                    display(books, n);
                }
                break;

            case 3:
                if (books == NULL)
                {
                    printf("\nNo book records available. Please add books first.\n");
                }
                else
                {
                    search(books, n);
                }
                break;

            case 4:
                if (books == NULL)
                {
                    printf("\nNo book records available. Please add books first.\n");
                }
                else
                {
                    issue_book(books, n);
                }
                break;

            case 5:
                if (books == NULL)
                {
                    printf("\nNo book records available. Please add books first.\n");
                }
                else
                {
                    return_book(books, n);
                }
                break;

            case 6:
                if (books != NULL)
                {
                    free(books);
                }

                printf("\nThank you for using the Library Management System.\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

/* Function to dynamically allocate memory and read book details */
struct book* create(int n)
{
    struct book *books;

    books = (struct book *)malloc(n * sizeof(struct book));

    if (books == NULL)
    {
        printf("\nMemory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details of Book %d\n", i + 1);

        printf("Book ID: ");
        scanf("%d", &books[i].book_id);

        printf("Title: ");
        scanf(" %s", books[i].title);

        printf("Author: ");
        scanf(" %s", books[i].author);

        printf("Price: ");
        scanf("%f", &books[i].price);

        /* Initially every book is Available */
        strcpy(books[i].availability, "Available");
    }

    printf("\nBook records added successfully!\n");

    return books;
}

/* Function to display all available books */
void display(struct book *books, int n)
{
    int found = 0;

    printf("\n================ AVAILABLE BOOKS ================\n");

    printf("%-10s %-25s %-20s %-10s %-15s\n",
           "Book ID", "Title", "Author", "Price", "Status");

    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        if (strcmp(books[i].availability, "Available") == 0)
        {
            printf("%-10d %-25s %-20s %-10.2f %-15s\n",
                   books[i].book_id,
                   books[i].title,
                   books[i].author,
                   books[i].price,
                   books[i].availability);

            found = 1;
        }
    }

    if (!found)
    {
        printf("No books are currently available.\n");
    }
}

/* Function to search for a book using Book ID */
void search(struct book *books, int n)
{
    int id;
    int found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (books[i].book_id == id)
        {
            printf("\nBook Found!\n");
            printf("----------------------------\n");
            printf("Book ID       : %d\n", books[i].book_id);
            printf("Title         : %s\n", books[i].title);
            printf("Author        : %s\n", books[i].author);
            printf("Price         : %.2f\n", books[i].price);
            printf("Availability  : %s\n", books[i].availability);
            printf("----------------------------\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nBook with ID %d not found.\n", id);
    }
}

/* Function to issue a book */
void issue_book(struct book *books, int n)
{
    int id;
    int found = 0;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (books[i].book_id == id)
        {
            found = 1;

            if (strcmp(books[i].availability, "Available") == 0)
            {
                strcpy(books[i].availability, "Issued");

                printf("\nBook issued successfully!\n");
                printf("Book: %s\n", books[i].title);
            }
            else
            {
                printf("\nBook is already issued.\n");
            }

            break;
        }
    }

    if (!found)
    {
        printf("\nBook with ID %d not found.\n", id);
    }
}

/* Function to return a book */
void return_book(struct book *books, int n)
{
    int id;
    int found = 0;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (books[i].book_id == id)
        {
            found = 1;

            if (strcmp(books[i].availability, "Issued") == 0)
            {
                strcpy(books[i].availability, "Available");

                printf("\nBook returned successfully!\n");
                printf("Book: %s\n", books[i].title);
            }
            else
            {
                printf("\nBook is already available.\n");
            }

            break;
        }
    }

    if (!found)
    {
        printf("\nBook with ID %d not found.\n", id);
    }
}

