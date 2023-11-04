#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class My_Library{

     string isbn,title,author,edition,publication;  // known as Library Data Members

  public:

      //Initializing the above Data Members using Member Functions
      void setisbn(string ch1){ isbn = ch1; }
      void settitle(string ch2){ title = ch2; }
      void setauthor(string ch3){ author = ch3; }
      void setedition(string ch4){ edition = ch4; }
      void setpublication(string ch5){ publication = ch5; }

      //Functions for get the values of the Data Members!
      string getisbn(){ return isbn; }
      string gettitle(){ return title; }
      string getauthor(){ return author; }
      string geteditor(){ return edition; }
      string getpublisher(){ return publication; }


};

//Global functions for manipulate and edit details
void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);
void QUIT();

int counter = 0;

void INC(int num){

   num++;
   counter = num;

}

void DEC(int num){

    num--;
    counter = num;

}

My_Library books[10];

int main(){

string CH;// CH for 'Choice'

system("CLS");
cout<<"LIBRARY MANAGEMENT SYSTEM\n\n";
cout<<"[1]ADD BOOK\n";
cout<<"[2]DELETE BOOK\n";
cout<<"[3]EDIT BOOK\n";
cout<<"[4]SEARCH BOOK\n";
cout<<"[5]VIEW ALL BOOKS\n";
cout<<"[6]QUIT\n\n";

//do{
/*cout<<"ENTER YOUR CHOICE: ";
getline(cin,CH);
switch(CH){

  case '1':
      addBook(counter);
      break;
  case '2':
      deleteBook(counter);
      break;
  case '3':
      editBook(counter);
      break;
  case '4':
      searchBook(counter);
      break;
  case '5':
      viewAllBooks(counter);
      break;
  case '6':
      QUIT();
      break;
}

}while(CH!='6');*/

cout<<"ENTER CHOICE: ";
getline(cin,CH);
system("CLS");

if(CH=="1"){
	addBook(counter);
	cout<<endl;
}
else if(CH=="2"){
	deleteBook(counter);
}
else if(CH=="3"){
	editBook(counter);
}
else if(CH=="4"){
	searchBook(counter);
}
else if(CH=="5"){
	viewAllBooks(counter);
}
else if(CH=="6"){
	QUIT();
}
else{
	main();
}

getch();
return 0;
}

void addBook(int counter){

   string isbn,title,author,edition,publication;
   cout<<"ADD BOOK\n\n";
   if(counter<10){

      cout<<"ENTER ISBN: ";
      getline(cin,isbn);
      cout<<"\nENTER THE TITLE: ";
      getline(cin,title);
      cout<<"\nENTER AUTHOR NAME: ";
      getline(cin,author);
      cout<<"\nENTER THE EDITION: ";
      getline(cin,edition);
      cout<<"\nENTER THE PUBLICATION: ";
      getline(cin,publication);
      books[counter].setisbn(isbn);
      books[counter].settitle(title);
      books[counter].setauthor(author);
      books[counter].setedition(edition);
      books[counter].setpublication(publication);
      INC(counter);
      cout<<"\nBOOK ADDED SUCCESSFULLY!!\n\nPRESS ANY KEY TO CONTINUE..";
      getch();
      return; //main();
   }
   else{

    cout<<"\nYOU'VE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!\n\nPRESS ANY KEY TO CONTINUE..";
    getch();
    return;

   }

}

void deleteBook(int counter){

   string isbn;
   int choice;
   cout<<"DELETE BOOK\n\n";
   if(counter==0){

    cout<<"THERE IS NO BOOK TO DELETE\n\nPRESS ANY KEY TO CONTINUE..";
    getch();
    main();
   }
   cout<<"ENTER ISBN: ";
   getline(cin,isbn);

   for(int i= 0;i<counter;i++){
    //finding a match
    if(books[i].getisbn()==isbn){
        cout<<"\nBOOK FOUND\n\n";
        cout<<"DO YOU WANT TO DELETE?\n[1] Yes\n[2] No\nEnter Choice: ";
        cin>>choice;
        if(choice == 1){
            books[i].setisbn("");
            books[i].settitle("");
            books[i].setauthor("");
            books[i].setedition("");
            books[i].setpublication("");
            for(int j = i;j<counter;j++){
                //adjusting the values after deletion of data
                books[j] = books[j+1];
            }
            books[9].setisbn("");//adjustment if library is full
            books[9].settitle("");
            books[9].setauthor("");
            books[9].setedition("");
            books[9].setpublication("");
            DEC(counter);
            cout<<"\nBOOK SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
            getch();
            main();
        }
        else{main();}
    }

   }
   cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
   getch();
   main();
}


void editBook(int counter){

        system("CLS");
        string editIsbn,Choice;
        string isbn,title,author,edition,publication;
        cout<<"\nEDIT BOOK\n\n";
        if(counter == 0){

           cout<<"THERE IS NO BOOK TO EDIT!\n\nPress any key to continue . . .";
           getch();
           main();

        }
        cout<<"ENTER ISBN: ";
        getline(cin,editIsbn);
        for(int i = 0;i<counter;i++){

            if(books[i].getisbn()==editIsbn){

                cout<<"\nBOOK FOUND!\n\n";
                cout<<"ISBN: "<<books[i].getisbn()<<endl;
                cout<<"TITLE: "<<books[i].gettitle()<<endl;
                cout<<"AUTHOR: "<<books[i].getauthor()<<endl;
                cout<<"EDITION: "<<books[i].geteditor()<<endl;
                cout<<"PUBLICATION: "<<books[i].getpublisher()<<endl;
                cout<<"\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
                getline(cin,Choice);
                if(Choice == "1"){

                    cout<<"\nENTER ISBN: ";
                    getline(cin,isbn);
                    books[i].setisbn(isbn);

                    cout<<"\nENTER TITLE: ";
                    getline(cin,title);
                    books[i].settitle(title);

                    cout<<"\nENTER AUTHOR: ";
                    getline(cin,author);
                    books[i].setauthor(author);

                    cout<<"\nENTER EDITION: ";
                    getline(cin,edition);
                    books[i].setedition(edition);

                    cout<<"\nENTER PUBLICATION: ";
                    getline(cin,publication);
                    books[i].setpublication(publication);

                    cout<<"\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
                    getch();
                    editBook(counter);
                }
                else{
                    main();
                }

            }

        }

        cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	   _getch();
	    main();
}

void searchBook(int counter){

    string isbn;
    int choice;
    bool print = false;
    cout<<"SEARCH BOOK\n\n";
    if(counter == 0){

        cout<<"THERE IS NO BOOK TO SEARCH!\n\nPress any key to continue . . .";
        getch();
        main();
    }
    cout<<"Enter ISBN: ";
    getline(cin,isbn);
    for(int i = 0;i<counter;i++){

        if(books[i].getisbn() == isbn){

            cout<<"\nBOOK FOUND\n\n";
            cout<<"ISBN: "<<books[i].getisbn()<<endl;
            cout<<"TITLE: "<<books[i].gettitle()<<endl;
            cout<<"AUTHOR: "<<books[i].getauthor()<<endl;
            cout<<"EDITION: "<<books[i].geteditor()<<endl;
            cout<<"PUBLICATION: "<<books[i].getpublisher()<<endl;
            print = true;

        }

    }
    if(print == true){
        cout<<"\n\nPress any key to continue . . .";
		getch();
		main();
    }
    else{
       cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
		getch();
		main();
    }

}
void viewAllBooks(int counter){

     cout<<"\nVIEW ALL BOOKS\n\n";
     for(int i = 0;i<counter;i++){

        cout<<"BOOK DETAILS\n\n";
        cout<<"ISBN: "<<books[i].getisbn()<<endl;
        cout<<"TITLE: "<<books[i].gettitle()<<endl;
        cout<<"AUTHOR: "<<books[i].getauthor()<<endl;
        cout<<"EDITION: "<<books[i].geteditor()<<endl;
        cout<<"PUBLISHER: "<<books[i].getpublisher()<<endl;
     }
      cout<<"Press any key to continue . . .";
	 getch();
     main();
}

void QUIT(){

     exit(1);

}
