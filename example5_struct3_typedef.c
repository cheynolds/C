/******************************************************************************
Structs Practice
*******************************************************************************/
#include <stdio.h>

//Example struct
typedef struct book {
  char title[20];
  int pages;
}Book;

//Write a function that accepts an array of books, and the count of books, 
//then returns back the number of pages for the book that has the fewest pages.
int findShortBook(Book books[], int count)
    {
        int pages = books[0].pages;
        for (int i = 1 ; i < count ; i++)
        {
            if (books[i].pages < pages)
                pages = books[i].pages;
        }
        return pages;
    }
    
//Write a function that takes a book pointer, prompts the user and populates 
//the fields of the book.
void populate(Book* book)
{
    puts("Title");
    scanf("%s", &book->title);
    puts("Pages");
    scanf("%d", &book->pages);
}
    
//Using this structure, write a function that declares a book,
//prompts the user for the values, then returns the book.
Book Buildabook()
{
    Book book;
    puts("Title");
    scanf("%s", &book.title);
    puts("Pages");
    scanf("%d", &book.pages);
    
    return book;
}

//Write a function that accepts a book and prints the fields out.
void PrintBook(Book book)
{
    printf("%s %d\n", book.title, book.pages);
}

int main()
{
    Buildabook();
    return 0;
}

//Define a structure variable to have the following fields:
//
//int score;
//char grade;

struct ex7{
    int score;
    char grade;
};
