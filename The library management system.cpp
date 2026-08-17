#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

void clearScreen() {
    system("cls"); }

void header() {
    cout << "+======================================================+\n";
    cout << "|        NISHAT LIBRARY MANAGMENT SYSTEM               |\n";
    cout << "+======================================================+\n";
}

void menu() {
    cout << "| 1. Show All Books                                   |\n";
    cout << "| 2. Search Book                                      |\n";
    cout << "| 3. Add New Book                                     |\n";
    cout << "| 4. Delete Book                                      |\n";
    cout << "| 5. Exit                                             |\n";
    cout << "+======================================================+\n";
    cout << "Enter Choice: ";
}

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();}

int main()
{
    string books[100] = {
        "C++ Programming","Data Structures","Operating System","Computer Networks","Database System",
        "Artificial Intelligence","Machine Learning","Digital Logic","Compiler Design","Software Engineering",
        "Mathematics 1","Mathematics 2","Statistics","Linear Algebra","Discrete Mathematics",
        "Physics","Chemistry","Biology","Environmental Science","General Science",
        "English Grammar","Functional English","Academic Writing","Communication Skills","Paragraph Writing",
        "Pakistan Studies","Islamic Studies","World History","Political Science","Economics",
        "Chinese Level 1","Chinese Level 2","Chinese Grammar","Chinese Conversation","HSK Preparation",
        "Web Development","HTML Basics","CSS Guide","JavaScript Basics","Python Programming",
        "Java Programming","Mobile App Development","Cyber Security","Cloud Computing","Data Science",
        "Machine Vision","Robotics","Internet of Things","Big Data","Deep Learning"
    };

    int totalBooks = 50;
    int choice;

    do {
        clearScreen();
        header();
        menu();
        cin >> choice;
        cin.ignore();

        clearScreen();
        header();

        if(choice == 1)
        {
            cout << "|------------------ BOOK LIST -------------------------|\n";
            cout << left << setw(5) << "No"
                 << setw(30) << "Title"
                 << setw(10) << "Shelf" << endl;
            cout << "-------------------------------------------------------\n";

            for(int i=0;i<totalBooks;i++)
            {
                cout << left << setw(5) << i+1
                     << setw(30) << books[i]
                     << setw(10) << (i/10)+1 << endl;
            }
        }

        else if(choice == 2)
        {
            string search;
            bool found=false;

            cout << "|---------------- SEARCH BOOK -------------------------|\n";
            cout << "Enter Book Name: ";
            getline(cin,search);

            for(int i=0;i<totalBooks;i++)
            {
                if(search == books[i])
                {
                    cout << "\n Book Found!\n";
                    cout << "Shelf Number: " << (i/10)+1 << endl;
                    found=true;
                    break;
                }
            }

            if(!found)
                cout << "\n Book not available.\n";
        }

        else if(choice == 3)
        {
            if(totalBooks < 100)
            {
                cout << "|---------------- ADD BOOK ----------------------------|\n";
                cout << "Enter New Book Name: ";
                getline(cin, books[totalBooks]);
                totalBooks++;

                cout << "\n Book Added Successfully.\n";
            }
            else
            {
                cout << "\n Library is Full.\n";
            }
        }

        else if(choice == 4)
        {
            string del;
            bool found=false;

            cout << "|---------------- DELETE BOOK -------------------------|\n";
            cout << "Enter Book Name to Delete: ";
            getline(cin,del);

            for(int i=0;i<totalBooks;i++)
            {
                if(del == books[i])
                {
                    for(int j=i;j<totalBooks-1;j++)
                    {
                        books[j] = books[j+1];
                    }
                    totalBooks--;

                    cout << "\n[?] Book Deleted Successfully.\n";
                    found=true;
                    break;
                }
            }

            if(!found)
                cout << "\n Book not found.\n";
        }

        else if(choice == 5)
        {
            cout << "\nThank you for using Nishat Library Management System.\n";
        }

        else
        {
            cout << "\n Invalid Choice.\n";
        }

        if(choice != 5) pause();

    } while(choice != 5);

    return 0;
}



    