#include <iostream>
#include <bits/stdc++.h>  // int to string
#include <fstream>  // file handling
#include <sstream>   // to get characters as strings
#include <string>    // for string
#include <windows.h>  // to put colours
#include <cstring>  // null terminated characters arrays
void issuebooks();
using namespace std;
void reset() {
	string nname , np;
	string name;
	string nic;
	cout<<endl<<endl<<"Enter youre First Name\t";
	cin>>name;
	cout<<endl<<endl<<"Enter youre last six digits of NIC\t";
	cin>>nic;
	
	
	fstream signfile;
	signfile.open("librarian.dat",ios::in);
	if(!signfile) {
			cout<<"\t\t\t\tFile cannot be open !!!";
		}
	else {
		string line , fpassword , fusername , fname ,  fnic;
		int count;
		while(getline(signfile, line)) { // use getline for read whole line of text as once
			istringstream iss(line);  
			if(iss>>fname>>fnic>>fpassword>>fusername) {
				
			}
		}
	}
	signfile.close();
	int count;
	if(count==1) {
	cout<<endl<<endl<<"Enter New  User Name\t";
	cin>>nname;
	cout<<endl<<endl<<"Enter New Password\t";
	cin>>np;
	}
	
	string variable;
	signfile.open("librarian.dat",ios::app);
	if(!signfile) {
		cout<<"\t\t\t\tFile not open";
	}
	else {
		if(count==0) {
			signfile<<name<<","<<nic<<","<<nname<<","<<np<<endl;
			
			cout<<endl<<endl<<"\t\t\t\t\tPleace Remember youre usernameandpassword:\t"<<endl<<endl;
			cout<<"\t\t\t\t\tuser  name:\t"<<nname<<endl<<endl;
			cout<<"\t\t\t\t\tpassword:\t"<<np<<endl<<endl;
			
		}
		else {
			cout<<"\t\t\t\t\tThis record has already input! Try again";
			
		}
	}
	signfile.close();
	
	
	
}
void signUpLibrarians(string a, string b) {  //  first name and last six digits of nic are come as parameters in to  the function
	string name;
	string nic;
	string fpassword;
	string fusername;
	string password;
	string username;
	int count;
	
	password="bsm#"+b;
	username="lbr@"+a;
	
	// open signup file to check is this librarian already added
	fstream signfile;
	signfile.open("librarian.dat",ios::in);
	if(!signfile) {
			cout<<"\t\t\t\tFile cannot be open !!!";
		}
	else {
		string line;
		while(getline(signfile, line)) { // use getline for read whole line of text as once
			istringstream iss(line);  
			if(iss>>name>>nic>>fpassword>>fusername) {
				if(name==a && nic==b) {
					count=1;  // if did this it's mean this record has already added
					
				}
			}
		}
	}
	signfile.close();
	
	string variable;
	signfile.open("librarian.dat",ios::app);
	if(!signfile) {
		cout<<"\t\t\t\tFile not open";
	}
	else {
		if(count==0) {
			signfile<<a<<","<<b<<","<<username<<","<<password<<endl;
			
			cout<<endl<<endl<<"\t\t\t\t\tLibrarian's first name:\t"<<a<<endl<<endl;
			cout<<"\t\t\t\t\tLast six digits of NIC:\t"<<b<<endl<<endl;
			cout<<"\t\t\t\t\tLibrarian's username:\t"<<username<<endl<<endl;
			cout<<"\t\t\t\t\tLibrarian's Password:\t"<<password<<endl<<endl;
			cout<<endl<<endl<<"\t\t\t\t\tSignup succesfully"<<endl;
		}
		else {
			cout<<"\t\t\t\t\tThis record has already input! Try again";
			
		}
	}
	signfile.close();	
}

void showlibrianlist() {
	string name;
	string nic;
	string fpassword;
	string fusername;
	
	cout<<endl<<endl<<"\t\t\t\t\t\t---Librarian Deatails---";
	cout<<endl<<endl<<"\t\t\t\t\tLibrarian First Name  "<<"Librarian's User Name  "<<"Librarian's Password";

	fstream librarianFile; 
	librarianFile.open("librarian.dat",ios::in); 
	if(!librarianFile){ 
		cout<<"No such file";
	} 
	string line;
	while (getline(librarianFile, line)) {
		istringstream iss(line);
		getline(iss, name, ','); 
		getline(iss, nic, ',');
		getline(iss, fpassword, ',');
		getline(iss, fusername, ',');
			
		cout<<endl<<endl<<"\t\t\t\t\t"<<name<<"\t\t\t"<<fpassword<<"\t\t\t"<<fusername;		
			
	}
	librarianFile.close();

} 
void searchbooksbyauthor() {

	int flag=0;	
	string id;
	string ftitle;
	string fauthor;
	string fprice;
	string fpublisher;
	string fgenre;
	string fstatus;
	
	string bookidORtitle;
	
	cout<<endl<<endl<<"\t\t\t\t\tSearch Books By Author"<<endl<<endl;
	cout<<endl<<"\t\t\t\t\tEnter Author Of The Book:\t";
	cin.ignore();
	getline(cin,bookidORtitle);
	
	
	fstream bookfile;
	bookfile.open("booklist.dat",ios::in);
	if(!bookfile) {
		cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
	}
	else {
		string line;
		while(getline(bookfile, line)) {
			istringstream iss(line);
			
			getline(iss, id, ','); 
			getline(iss, ftitle, ',');
			getline(iss, fauthor, ',');
			getline(iss, fprice, ',');
			getline(iss, fpublisher, ',');
			getline(iss, fgenre, ',');
			getline(iss, fstatus, ',');
			
				if(bookidORtitle==fauthor) {
					cout<<endl<<endl<<"\t\t\t\t\tID Of The Book:\t"<<id<<endl<<endl;
					cout<<"\t\t\t\t\tName Of The Book:\t"<<ftitle<<endl<<endl;
					cout<<"\t\t\t\t\tPrice Of The Book:\t"<<fprice<<endl<<endl;
					cout<<"\t\t\t\t\tPublisher Of The Book:\t"<<fpublisher<<endl<<endl;
					cout<<"\t\t\t\t\tGenre Of The Book:\t"<<fgenre<<endl<<endl;
					cout<<"\t\t\t\t\tThis Book is "<<fstatus<<" now"<<endl<<endl<<endl;
					flag=1;
				}		
			}
	}
	bookfile.close();
	if(flag!=1) {
		cout<<endl<<endl<<"\t\t\t\t\tThis Record Was Not Found!!"<<endl;
	}
	
	
}
void ShowFinerateAndMaximumBorrowingLimits() {
	string finerate;
	string maxximumborrow;
	
	fstream finerateFile; 
	finerateFile.open("finerate.dat",ios::in); 
	if(!finerateFile){ 
		cout<<"No such file";
	} 
	string line;
	while (getline(finerateFile, line)) {
		istringstream iss(line);
		getline(iss, finerate, ','); 
			
		cout<<endl<<endl<<"\t\t\t\t\tFine Rate:\t"<<finerate;		
			
	}
	finerateFile.close();
	
	
	fstream maxximumorrowFile; 
	maxximumorrowFile.open("maximumborrow.dat",ios::in); 
	if(!maxximumorrowFile){ 
		cout<<endl<<endl<<"\t\t\t\t\tNo such file";
	} 
	string line2;
	while (getline(maxximumorrowFile, line2)) {
		istringstream iss(line2);
		getline(iss, maxximumborrow, ','); 
			
		cout<<endl<<endl<<"\t\t\t\t\tMaxximum Borrow Limit:\t"<<maxximumborrow;		
			
	}
	maxximumorrowFile.close();
	
}

void addbook() {
	int count;
	string id;
	string bookid;
	string title;
	string author;
	string price;
	string publisher;
	string genre;
	string status;
	
	string ftitle;
	string fauthor;
	string fprice;
	string fpublisher;
	string fgenre;
	string fstatus;
	
	
	cout<<endl<<endl<<"\t\t\t\t\t~~~Add Books~~~"<<endl;
	
	cout<<endl<<endl<<"\t\t\t\t\tEnter Book ID:\t";
	cin.ignore();
	getline(cin,bookid);
	
	if(system("CLS")) system("clear");
	
	// open book file to check is this book record already added
	fstream bookfile;
	bookfile.open("booklist.dat",ios::in);
	if(!bookfile) {
		cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
	}
	else {
		string line;
		while(getline(bookfile, line)) {
			istringstream iss(line);

				getline(iss, id, ','); 
				getline(iss, ftitle, ',');
				getline(iss, fauthor, ',');
				getline(iss, fprice, ',');
				getline(iss, fpublisher, ',');
				getline(iss, fgenre, ',');
				getline(iss, fstatus, ',');
				if(bookid==id){
				count=1;  // if did this it's mean this book is already added
			}
		}
		// if it is not , then add book details
		if(count==0) {
			cout<<endl<<"\t\t\t\t\tEnter Book Title:\t";
			getline(cin,title);
			
			cout<<endl<<"\t\t\t\t\tEnter Author of Book:\t";
			getline(cin,author);
			
			cout<<endl<<"\t\t\t\t\tEnter price of the Book:\t";
			getline(cin,price);
			
			cout<<endl<<"\t\t\t\t\tEnter Publisher of the Book:\t";
			getline(cin,publisher);
			
			cout<<endl<<"\t\t\t\t\tEnter Genre of the Book:\t";
			getline(cin,genre);
			
			cout<<endl<<"\t\t\t\t\tEnter Availability status of book:\t";
			getline(cin,status);
			if(system("CLS")) system("clear");
			
			fstream bookfile;
			bookfile.open("booklist.dat",ios::app);
			if(!bookfile) {
				cout<<endl<<endl<<endl<<"\t\t\t\t\tFile can not open"<<endl<<endl;
			}
			else {
				if(id!=bookid) {
					bookfile<<bookid<<","<<title<<","<<author<<","<<price<<","<<publisher<<","<<genre<<","<<status<<","<<endl;
					cout<<endl<<endl<<"\t\t\t\t\tBook details added"<<endl;
				
				}
			}
			bookfile.close();
		}
		else {
			cout<<endl<<endl<<"\t\t\t\t\tThis book details already added"<<endl;
		}
	}
	bookfile.close();
}

void deletebook() {
	int count=0;
	string id;
	string bookid;
	string ftitle;
	string fauthor;
	string fprice;
	string fpublisher;
	string fgenre;
	string fstatus;
	
	cout<<endl<<endl<<"\t\t\t\t\t~~~Delete Books by ID~~~"<<endl<<endl;
	cout<<"\t\t\t\t\tEnter Book Id:\t";
	cin>>id;
	if(system("CLS")) system("clear");
	
	// open book file to check if this book is in book file
	
	fstream bookfile;
	bookfile.open("booklist.dat",ios::in);
	
	fstream tempfile;
	tempfile.open("temp.dat",ios::out);
	
	string line;
	while (getline(bookfile, line)) {
		istringstream iss(line);
		
				getline(iss, bookid, ','); 
				getline(iss, ftitle, ',');
				getline(iss, fauthor, ',');
				getline(iss, fprice, ',');
				getline(iss, fpublisher, ',');
				getline(iss, fgenre, ',');
				getline(iss, fstatus, ',');
				if(bookid!=id){
				tempfile<<bookid<<","<<ftitle<<","<<fauthor<<","<<fprice<<","<<fpublisher<<","<<fgenre<<","<<fstatus<<","<<endl;
		
			}
			else if(bookid==id){
				count=1;  // if did this the book records are in the file
			}
	}
	if(count!=1) { // if it is not record not found
		cout<<endl<<endl<<"\t\t\t\t\tThis Record Was Not Found!!";
	}
	else {   //  if it is now can delete records
		cout<<endl<<"\t\t\t\t\tThe Book Details Have Been Deleted";
	}
	bookfile.close();
	tempfile.close();
	
	remove("booklist.dat");
	rename("temp.dat","booklist.dat");
}

void searchbook() {
	int flag=0;	
	string id;
	string ftitle;
	string fauthor;
	string fprice;
	string fpublisher;
	string fgenre;
	string fstatus;
	
	string bookidORtitle;
	
	cout<<endl<<endl<<"\t\t\t\t\tSearch Books By Book Name Or Book ID"<<endl<<endl;
	cout<<endl<<"\t\t\t\t\tEnter Name Of The Book Or Book ID:\t";
	cin>>bookidORtitle;
	
	fstream bookfile;
	bookfile.open("booklist.dat",ios::in);
	if(!bookfile) {
		cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
	}
	else {
		string line;
		while(getline(bookfile, line)) {
			istringstream iss(line);
			
			getline(iss, id, ','); 
			getline(iss, ftitle, ',');
			getline(iss, fauthor, ',');
			getline(iss, fprice, ',');
			getline(iss, fpublisher, ',');
			getline(iss, fgenre, ',');
			getline(iss, fstatus, ',');
			
				if(bookidORtitle==id || bookidORtitle==ftitle) {
					cout<<endl<<endl<<"\t\t\t\t\tID Of The Book:\t"<<id<<endl<<endl;
					cout<<"\t\t\t\t\tName Of The Book:\t"<<ftitle<<endl<<endl;
					cout<<"\t\t\t\t\tAuthor Of The Book:\t"<<fauthor<<endl<<endl;
					cout<<"\t\t\t\t\tPrice Of The Book:\t"<<fprice<<endl<<endl;
					cout<<"\t\t\t\t\tPublisher Of The Book:\t"<<fpublisher<<endl<<endl;
					cout<<"\t\t\t\t\tGenre Of The Book:\t"<<fgenre<<endl<<endl;
					cout<<"\t\t\t\t\tThis Book is "<<fstatus<<" now"<<endl<<endl;
					flag=1;
				}		
			}
	}
	bookfile.close();
	if(flag!=1) {
		cout<<endl<<endl<<"\t\t\t\t\tThis Record Was Not Found!!"<<endl;
	}
}

void updatebook() {
	string title;
	string fauthor;
	string author;
	string fprice;
	string price;
	string fpublisher;
	string publisher;
	string fgenre;
	string genre;
	string fstatus;
	string status;
	string bookname;
	string bookidORtitle;
	int option;
	int flag=1;
	int count=0;
	int mark=0;
	string id;
	string bookid;
	string ftitle;

	cout<<endl<<endl<<"\t\t\t\t\t~~~Update Books~~~"<<endl<<endl;
	cout<<"\t\t\t\t\tUpdate Books By Book ID"<<endl<<endl;
	cout<<"\t\t\t\t\tEnter Book ID:\t";
	cin>>bookidORtitle;
	if(system("CLS")) system("clear");
	
	fstream newFile; 
	newFile.open("booklist.dat",ios::in); 
	if(!newFile){ 
		cout<<"No such file";
	} 
	string line;
	while (getline(newFile, line)) {
		istringstream iss(line);
				getline(iss, bookid, ','); 
				getline(iss, title, ',');
				getline(iss, author, ',');
				getline(iss, price, ',');
				getline(iss, publisher, ',');
				getline(iss, genre, ',');
				getline(iss, status, ',');
				
				if(bookidORtitle==bookid) {
					mark=1;
				}
				
	}
	newFile.close();
	
				if(mark==1) {
				
					while(flag==1) {
					cout<<endl<<"\t\t\t\t\tWhat Do You Want To Update?"<<endl<<endl;
					cout<<"\t\t\t\t\t01. Name Of The Book"<<endl<<endl;
					cout<<"\t\t\t\t\t02. Author Of The Book"<<endl<<endl;
					cout<<"\t\t\t\t\t03. Price Of The Book"<<endl<<endl;
					cout<<"\t\t\t\t\t04. Publisher Of The Book"<<endl<<endl;
					cout<<"\t\t\t\t\t05. Genre Of The Book"<<endl<<endl;
					cout<<"\t\t\t\t\t06. Availability status"<<endl<<endl;
					cout<<"\t\t\t\t\t07. Back to Menu"<<endl<<endl;
					cout<<"\t\t\t\t\tPleace Choose Any Option: ";
					cin>>option;
					if(system("CLS")) system("clear");
					
					switch(option) {
						case 1:{
							cout<<endl<<endl<<endl<<"\t\t\t\t\tEnter Name Of The Book:\t";
							cin.ignore();  //  to clear other characters
							getline(cin,title);  //  to input more than 2 words
							if(system("CLS")) system("clear");
							flag=1;   // to display update menu
							break;
						}
						case 2:{
							cout<<endl<<endl<<endl<<"\t\t\t\t\tEnter The Author Of The Book:\t";
							cin.ignore();
							getline(cin,author);
							if(system("CLS")) system("clear");
							flag=1;   // to display update menu
							break;
						}
						case 3:{
							cout<<endl<<endl<<endl<<"\t\t\t\t\tEnter Price Of The Book:\t";
							cin.ignore();
							getline(cin,price);
							if(system("CLS")) system("clear");
							flag=1;   // to display update menu
							break;        
						}
						case 4:{
							cout<<endl<<endl<<endl<<"\t\t\t\t\tEnter Publisher Of The Book:\t";
							cin.ignore();
							getline(cin,publisher);
							if(system("CLS")) system("clear");
							flag=1;   // to display update menu
							break;
						}
						case 5:{
							cout<<endl<<endl<<endl<<"\t\t\t\t\tEnter The Genre Of The Book:\t";
							cin.ignore();
							getline(cin,genre);
							if(system("CLS")) system("clear");
							flag=1;   // to display update menu
							break;
						}
						case 6:{
							cout<<endl<<endl<<endl<<"\t\t\t\t\tEnter The Availability status Of The Book:\t";
							cin.ignore();
							getline(cin,status);
							if(system("CLS")) system("clear");
							flag=1;   // to display update menu
							break;
						}
						case 7:{
							flag=0;  // to end this while loop
							break;
						}
						default :{
							cout<<endl<<endl<<"\t\t\t\t\tInvalid Enter!!!"<<endl;
							flag=1;   // to display update menu
							break;
						}
					}
					
					}
	fstream bookfile2;
	bookfile2.open("booklist.dat",ios::in);
	
	fstream tempfile2;
	tempfile2.open("temp.dat",ios::out);
	
	string line2;
	while (getline(bookfile2, line2)) {
		istringstream iss(line2);
			
				getline(iss, bookid, ','); 
				getline(iss, ftitle, ',');
				getline(iss, fauthor, ',');
				getline(iss, fprice, ',');
				getline(iss, fpublisher, ',');
				getline(iss, fgenre, ',');
				getline(iss, fstatus, ',');
			
			if(bookidORtitle!=bookid){
				tempfile2<<bookid<<","<<ftitle<<","<<fauthor<<","<<fprice<<","<<fpublisher<<","<<fgenre<<","<<fstatus<<","<<endl;
			}
			else if(bookidORtitle==bookid){
				tempfile2<<bookid<<","<<title<<","<<author<<","<<price<<","<<publisher<<","<<genre<<","<<status<<","<<endl;
				count=1;
			}
	}
	if(count==1) {
		cout<<endl<<"\t\t\t\t\tThe Book Details Have Been Updated";
	}
	bookfile2.close();
	tempfile2.close();
	
	remove("booklist.dat");
	rename("temp.dat","booklist.dat");
	
	}
	else {
		cout<<endl<<endl<<"\t\t\t\t\tThis Record Was Not Found!!";
	}
	
}


void showbooks() {
	string bookid;
	string id;
	string ftitle;
	string fauthor;
	string fprice;
	string fpublisher;
	string fgenre;
	string fstatus;
	
	cout<<endl<<endl<<"\t\t\t\t\t,,,,,,,,,____BOOK LIST____,,,,,,,,,";
	cout<<endl<<endl<<"\tID Of The Book"<<"\tName Of The Book"<<"\tAuthor Of The Book"<<"\tGenre Of The Book"<<"\tAvailability status"<<endl<<endl;						           
	fstream bookfile;		//show book list
	bookfile.open("booklist.dat",ios::in);
	if(!bookfile) {
		cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
	}
	else {
		string line;
		while(getline(bookfile, line)) {
			istringstream iss(line);
			
			getline(iss, id, ','); 
			getline(iss, ftitle, ',');
			getline(iss, fauthor, ',');
			getline(iss, fprice, ',');
			getline(iss, fpublisher, ',');
			getline(iss, fgenre, ',');
			getline(iss, fstatus, ',');
			
				
			cout<<"\t"<<id<<"\t\t"<<ftitle<<"\t\t"<<fauthor<<"\t\t"<<fgenre<<"\t\t"<<fstatus<<endl<<endl;
			}
	}
	bookfile.close();
}

void showborrowerdeatails() {
	string id;
	string fname;
	string fdate;
	string fcontact;
	string freadbooks;
	
	cout<<endl<<endl<<"\t\t\t\t---Borrower's Deatails---";
	cout<<endl<<endl<<"\t\t\t\tBorrow Id\t"<<"Borrower's Name\t"<<"Joined Date\t\t"<<"Contacts\t"<<"Numbers Of Books Read";
	
	fstream borrowfile;
	borrowfile.open("borrowfile.dat",ios::in);
	if(!borrowfile) {
		cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
	}
	else {
		string line;
		while(getline(borrowfile, line)) {
			istringstream iss(line);

			getline(iss, id, ','); 
			getline(iss, fname, ',');
			getline(iss, fdate, ',');
			getline(iss, fcontact, ',');
			getline(iss, freadbooks, ',');
			
			cout<<endl<<endl<<"\t\t\t\t"<<id<<"\t\t"<<fname<<"\t\t"<<fdate<<"\t\t"<<fcontact<<"\t\t"<<freadbooks;
			
	
	}
}
borrowfile.close();
}

void issuebooks() {
	int smark;
	int mark;
	int mark2;
	int count=1;
	int flag=1;
	int Maxximumborrow;
	int value=0;
	string maxximumborrow;
	string borrowid;
	string issuedate;
	string returendate;
	string bookid;
	string id;
	string ftitle;
	string fauthor;
	string fprice;
	string fpublisher;
	string fgenre;
	string fstatus;
	string status;
	string FineRate;
	string returnedDay;
	
	//read maxximum borrow file to get maxximum borrow value.
	fstream maxximumborrowfile;
	maxximumborrowfile.open("maximumborrow.dat",ios::in);
	if(!maxximumborrowfile) {
		cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
	}
	else {
		string line;
		while(getline(maxximumborrowfile, line)) {
			istringstream iss(line);
			if(iss>>maxximumborrow) {
				cout<<endl<<endl<<"\t\t\t\t\tMaxximum Borrow Limit:\t"<<maxximumborrow<<endl;
			}
			else {
				cout<<endl<<endl<<"\t\t\t\t\tCan't read"	;
			}
		}
	}
	maxximumborrowfile.close();
	
	// now maximum borrow value is a string. in this step it convert to int value
	stringstream ss(maxximumborrow);
	ss>>Maxximumborrow;
	
	while(flag==1) {
		cout<<endl<<endl<<"\t\t\t\t\tEnter The Book ID To Be Issued:\t";
		cin>>bookid;
		if(system("CLS")) system("clear");
		
		fstream bookfile;
		bookfile.open("booklist.dat",ios::in);
		if(!bookfile) {
			cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
		}
		else {
			string line;
			while(getline(bookfile, line)) {
				istringstream iss(line);
				
				getline(iss, id, ','); 
				getline(iss, ftitle, ',');
				getline(iss, fauthor, ',');
				getline(iss, fprice, ',');
				getline(iss, fpublisher, ',');
				getline(iss, fgenre, ',');
				getline(iss, fstatus, ',');
				
				if(bookid==id) {
					mark=1;
					if(fstatus=="available") {
						smark=1;  // if did this it's mean this book is available now. so we can issue that book
					}
				}
				
			}
		}
		bookfile.close();
		
		if(mark!=1) {  // if book record was not fount
			cout<<endl<<endl<<"\t\t\t\t\tInvalid Book ID";
		}
		if(mark==1) {  // book records are in file
			
			if(count<=Maxximumborrow && smark==1) {  //  check the number of times the books are issued are equal or less than to 
			//   the maxximum borrow limit and  availability status equal cto available

				cout<<endl<<endl<<"\t\t\t\t\tEnter Borrower ID:\t";
				cin.ignore();
				getline(cin,borrowid);		
				cout<<endl<<endl<<"\t\t\t\t\tEnter Issue Date(yyyy.mm.dd):\t";
				getline(cin,issuedate);
				cout<<endl<<endl<<"\t\t\t\t\tEnter Due Data(yyyy.mm.dd):\t";
				getline(cin,returendate);
				if(system("CLS")) system("clear");
				
				fstream issuefile;
				issuefile.open("issue.dat",ios::app);
				if(!issuefile) {
					cout<<endl<<endl<<"\t\t\t\t\tFile Can Not Open";
				}
				else {
					issuefile<<borrowid<<","<<bookid<<","<<issuedate<<","<<returendate<<","<<FineRate<<","<<returnedDay<<endl;
					cout<<endl<<endl<<"\t\t\t\t\tIssue File Updated...";
					count++;
				}
				issuefile.close();
				string fname; 
				string fdate; 
				string fcontact; 
				string freadbooks;
				string nofbookstring;
				// to read borrow file to check entered borrow id is right and get nomber of read books
				fstream borrowfile;
				borrowfile.open("borrowfile.dat",ios::in);
				if(!borrowfile) {
					cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
				}
				else {
					string line;
					while(getline(borrowfile, line)) {
						istringstream iss(line);
			
						getline(iss, id, ','); 
						getline(iss, fname, ',');
						getline(iss, fdate, ',');
						getline(iss, fcontact, ',');
						getline(iss, freadbooks, ',');
						
						if(borrowid==id && count>=1){  // to check if entered borrow id is in borrow details file and is issue file updated
						
						// to nomber of read books convert to int value
							int nofbooks;
							stringstream ss(freadbooks);
							ss>>nofbooks;
							nofbooks=nofbooks+1;
							stringstream stream;
							stream << nofbooks;
							stream >> nofbookstring;
						}
				}
			}
				borrowfile.close();
		
				
				string bid , bfname , bfdate , bfcontact , bfreadbooks;
				// to update borrow file
					borrowfile.open("borrowfile.dat",ios::in);
					
					fstream tempfile;
					tempfile.open("temp.dat",ios::out);
					
					string line2;
					while (getline(borrowfile, line2)) {
						istringstream iss(line2);
							
						getline(iss, bid, ','); 
						getline(iss, bfname, ',');
						getline(iss, bfdate, ',');
						getline(iss, bfcontact, ',');
						getline(iss, bfreadbooks, ',');
								
							
							if(borrowid!=bid){
								tempfile<<bid<<","<<bfname<<","<<bfdate<<","<<bfcontact<<","<<bfreadbooks<<endl;
							}
							else if(borrowid==bid){
								
								tempfile<<bid<<","<<bfname<<","<<bfdate<<","<<bfcontact<<","<<nofbookstring<<endl;
								mark2=1;
								
							}
							
					}
				borrowfile.close();
				tempfile.close();
					
				// to update book file
				remove("borrowfile.dat");
				rename("temp.dat","borrowfile.dat");
			
				fstream bookfile;
					bookfile.open("booklist.dat",ios::in);
					
					tempfile.open("temp.dat",ios::out);
					
					while (getline(bookfile, line2)) {
						istringstream iss(line2);
							
								getline(iss, id, ','); 
								getline(iss, ftitle, ',');
								getline(iss, fauthor, ',');
								getline(iss, fprice, ',');
								getline(iss, fpublisher, ',');
								getline(iss, fgenre, ',');
								getline(iss, status, ',');
								
							
							if(bookid!=id){
								tempfile<<id<<","<<ftitle<<","<<fauthor<<","<<fprice<<","<<fpublisher<<","<<fgenre<<","<<status<<endl;
							}
							else if(bookid==id){
								fstatus="unavailable";
								tempfile<<id<<","<<ftitle<<","<<fauthor<<","<<fprice<<","<<fpublisher<<","<<fgenre<<","<<"unavailable"<<endl;
								mark2=1;
							}
							
					}
				bookfile.close();
				tempfile.close();
					
				remove("booklist.dat");
				rename("temp.dat","booklist.dat");
				
				if(mark2==1) {
					cout<<endl<<endl<<"\t\t\t\t\tBook List Updated";
				}
		}
			else {
				if(count>Maxximumborrow) {
					cout<<endl<<endl<<"\t\t\t\t\tYou Can Issue Only "<<Maxximumborrow<<" Books"<<endl;
				}
				else if(smark!=1) {
					cout<<endl<<endl<<"\t\t\t\t\tThis Book Is Unavailable Now"<<endl;
					
				}
				
				
			}
			cout<<endl<<endl<<"\t\t\t\t\tDo You Want To";
			cout<<endl<<endl<<"\t\t\t\t\t01.Continue";
			cout<<endl<<endl<<"\t\t\t\t\t02.Exit";
			cout<<endl<<endl<<"\t\t\t\t\tCoose A Option: ";
			cin>>flag;
			if(system("CLS")) system("clear");
			
			if(flag==2) {
				count=0;
				break;
			}	
		}
		
	}
	
}

void acceptReturnedBooks(){
	string returnedDay;
	string issueBookId;
	string borrowID;
	string borrowid;
	string bookid;
	string issuedate;
	string returendate;
	string finerate;
	int flag=1;
	int latedays;
	string FineRate;
	string ReturnedDay;					      
	int fineRate;
	int mark2;
	string id;
	string ftitle;
	string fauthor;
	string fprice;
	string fpublisher;
	string fgenre;
	string status;
	string fineRateString;
	
	while(flag==1) {
		cout<<endl<<endl<<"\t\t\t\t\tEnter Book ID:\t";
		cin.ignore();
		getline(cin,issueBookId);
		
		cout<<endl<<endl<<"\t\t\t\t\tEnter Returned Day (yyyy/mm/dd):\t";
		getline(cin,ReturnedDay);
		
		cout<<endl<<endl<<"\t\t\t\t\tEnter Borrow ID:\t";
		getline(cin,borrowID);
		if(system("CLS")) system("clear");
		
		//open issue details file to get returen date and other values.
		fstream issuefile;
		issuefile.open("issue.dat",ios::in);
		if(!issuefile) {
			cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
		}
		else {
			string line;
			while(getline(issuefile, line)) {
				istringstream iss(line);
				getline(iss, borrowid, ','); 
				getline(iss, bookid, ',');
				getline(iss, issuedate, ',');
				getline(iss, returendate, ',');
				getline(iss, FineRate, ',');
				getline(iss, returnedDay, ',');
				
				if(issueBookId==bookid)	{
					cout<<endl<<endl<<"\t\t\t\t\tDue Date(yyyy.mm.dd):\t"<<returendate<<endl<<endl;
				}
				
			}
		}
		issuefile.close();
		
		//read fine rate file to get fine rate value.
		
		fstream fineratefile;
		fineratefile.open("finerate.dat",ios::in);
		if(!fineratefile) {
			cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
		}
		else {
			string line;
			while(getline(fineratefile, line)) {
				istringstream iss(line);
				if(iss>>finerate) {	
				}
				else {
					cout<<endl<<endl<<"\t\t\t\t\tCan't read";
				}
			}
		}
		fineratefile.close();
		
		//calculate fine rate
		
		int FINErate;
		
		stringstream ss(finerate);
		ss>>FINErate;
		
		cout<<endl<<endl<<"\t\t\t\t\tEnter Number Of Days Late:\t";
		cin>>latedays;
		if(system("CLS")) system("clear");
		cout<<endl<<endl<<"\t\t\t\t\tFine Rate For One Late Day:\t"<<finerate;
		
		fineRate=FINErate*latedays;
		
		cout<<endl<<endl<<"\t\t\t\t\tBorrower's Fine Rate Is:\t"<<fineRate<<endl<<endl;
		
		stringstream stream;
		stream << fineRate;
		stream >> fineRateString;
					
			issuefile.open("issue.dat",ios::in);
						
			fstream tempfile;
			tempfile.open("temp2.dat",ios::out);
						
			string line2;
			while (getline(issuefile, line2)) {
				istringstream iss(line2);
				getline(iss, borrowid, ','); 
				getline(iss, bookid, ',');
				getline(iss, issuedate, ',');
				getline(iss, returendate, ',');
				getline(iss, FineRate, ',');
				getline(iss, returnedDay, ',');
								
				if(issueBookId!=bookid){
					tempfile<<borrowid<<","<<bookid<<","<<issuedate<<","<<returendate<<","<<FineRate<<","<<returnedDay<<endl;
				}
				else if(issueBookId==bookid){
				
					tempfile<<borrowid<<","<<bookid<<","<<issuedate<<","<<returendate<<","<<fineRateString<<","<<ReturnedDay<<endl;
				}
			}
			
			
				issuefile.close();
				tempfile.close();
						
				remove("issue.dat");
				rename("temp2.dat","issue.dat");
				
				
				fstream bookfile;
						bookfile.open("booklist.dat",ios::in);
						
						fstream tempfile2;
						tempfile2.open("temp.dat",ios::out);
						
						string line3;
						while (getline(bookfile, line3)) {
							istringstream iss(line3);
								
									getline(iss, id, ','); 
									getline(iss, ftitle, ',');
									getline(iss, fauthor, ',');
									getline(iss, fprice, ',');
									getline(iss, fpublisher, ',');
									getline(iss, fgenre, ',');
									getline(iss, status, ',');
									
								
								if(issueBookId!=id){
									tempfile2<<id<<","<<ftitle<<","<<fauthor<<","<<fprice<<","<<fpublisher<<","<<fgenre<<","<<status<<endl;
								}
								else if(issueBookId==id){
									
									tempfile2<<id<<","<<ftitle<<","<<fauthor<<","<<fprice<<","<<fpublisher<<","<<fgenre<<","<<"available"<<endl;
									mark2=1;
								}
								
						}
					bookfile.close();
					tempfile2.close();
						
					remove("booklist.dat");
					rename("temp.dat","booklist.dat");
					
					cout<<endl<<endl<<"\t\t\t\t\tDo You Want To";
					cout<<endl<<endl<<"\t\t\t\t\t01. Contineue";
					cout<<endl<<endl<<"\t\t\t\t\t02. Exit";
					cout<<endl<<endl<<"\t\t\t\t\tCoose Any Option: ";
					cin>>flag;
					if(system("CLS")) system("clear");
					if(flag==2) {
						break;
					}
					
		}
}
void addborrowers(){
	string borrowid;
	string name;
	string date;
	string contact;
	string id;
	string fname;
	string fdate;
	string fcontact;
	string freadbooks;
	int count=0;
	
	cout<<endl<<endl<<"\t\t\t\t\t~~~Add Borrowers~~~"<<endl;
	
	cout<<endl<<endl<<"\t\t\t\t\tEnter Borrower ID:\t";
	cin.ignore();
	getline(cin,borrowid);
	
	if(system("CLS")) system("clear");
	fstream borrowfile;
	borrowfile.open("borrowfile.dat",ios::in);
	if(!borrowfile) {
		cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
	}
	else {
		string line;
		while(getline(borrowfile, line)) {
			istringstream iss(line);

				getline(iss, id, ','); 
				getline(iss, fname, ',');
				getline(iss, fdate, ',');
				getline(iss, fcontact, ',');
				getline(iss, freadbooks, ',');
			
				if(id==borrowid) {
					count=count+1;	
				}	
			
		}
		if(count==0) {
			
			cout<<endl<<"\t\t\t\t\tEnter Borrower Name\t:";
			getline(cin,name);
	
			cout<<endl<<"\t\t\t\t\tEnter Joined Date(yyyy.mm.dd):\t";
			getline(cin,date);
	
			cout<<endl<<"\t\t\t\t\tEnter Contact Number:\t";
			getline(cin,contact);
			if(system("CLS")) system("clear");
			
			fstream borrowfile;
			borrowfile.open("borrowfile.dat",ios::app);
			if(!borrowfile) {
				cout<<endl<<endl<<endl<<"\t\t\t\t\tFile can not open"<<endl<<endl;
			}
			else {
				if(borrowid!=id) {
				borrowfile<<borrowid<<","<<name<<","<<date<<","<<contact<<","<<freadbooks<<endl;
				cout<<endl<<endl<<"\t\t\t\t\tBorrower's details added"<<endl;
				
				}
			}
			borrowfile.close();
		}
	else {
			cout<<endl<<endl<<"\t\t\t\t\tThe Borrower Details Already Added"<<endl;
			
		}
		
	}
	
	borrowfile.close();

}


void deleteBorrowers() {
	string borrowid;
	string id;
	string fname;
	string fdate;
	string fcontact;
	string freadbooks;
	int count=0;
	
	cout<<endl<<endl<<"\t\t\t\t\t~~~Delete Books by ID~~~"<<endl<<endl;
	cout<<"\t\t\t\t\tEnter Borrow Id:\t";
	cin>>borrowid;
	if(system("CLS")) system("clear");
	
	fstream borrowfile;
	borrowfile.open("borrowfile.dat",ios::in);
	
	fstream tempfile;
	tempfile.open("temp.dat",ios::out);
	
	string line;
	while (getline(borrowfile, line)) {
		istringstream iss(line);
		
				getline(iss, id, ','); 
				getline(iss, fname, ',');
				getline(iss, fdate, ',');
				getline(iss, fcontact, ',');
				getline(iss, freadbooks, ',');
				if(borrowid!=id){
				tempfile<<id<<","<<fname<<","<<fdate<<","<<fcontact<<","<<freadbooks<<endl;
		
			}
			else if(borrowid==id){
				count=1;
			}
	}
	if(count!=1) {
		cout<<endl<<endl<<"\t\t\t\t\tThis Record Was Not Found!!";
	}
	else {
		cout<<endl<<"\t\t\t\t\tThe Book Details Have Been Deleted";
	}
	borrowfile.close();
	tempfile.close();
	
	remove("borrowfile.dat");
	rename("temp.dat","borrowfile.dat");
}

void searchBorrowers() {
	string borrowidORname;
	string id;
	string fname;
	string fdate;
	string fcontact;
	string freadbooks;
	int flag=0;
	
	cout<<endl<<endl<<"\t\t\t\t\tSearch Borrowers By Borrower's Name Or Borrower's ID"<<endl<<endl;
	cout<<endl<<"\t\t\t\t\tEnter Name Of The Borrower Or Borrow ID:\t";
	cin>>borrowidORname;
	if(system("CLS")) system("clear");
	
	fstream borrowfile;
	borrowfile.open("borrowfile.dat",ios::in);
	if(!borrowfile) {
		cout<<endl<<endl<<"\t\t\t\t\tFile cannot be open !!!";
	}
	else {
		string line;
		while(getline(borrowfile, line)) {
			istringstream iss(line);
			
				getline(iss, id, ','); 
				getline(iss, fname, ',');
				getline(iss, fdate, ',');
				getline(iss, fcontact, ',');
				getline(iss, freadbooks, ',');
			
				if(borrowidORname==id || borrowidORname==fname) {
					cout<<endl<<endl<<"\t\t\t\t\tBorrow ID:\t"<<id<<endl<<endl;
					cout<<"\t\t\t\t\tBorrower's Name:\t"<<fname<<endl<<endl;
					cout<<"\t\t\t\t\tJoined Date:\t"<<fdate<<endl<<endl;
					cout<<"\t\t\t\t\tContact Number:\t"<<fcontact<<endl<<endl;
					cout<<"\t\t\t\t\tThe Number Of Books Borrower Has Read:\t"<<freadbooks<<endl<<endl;
					
					flag=1;
				}		
			}
	}
	borrowfile.close();
	if(flag!=1) {
		cout<<endl<<endl<<"\t\t\t\t\tThis Record Was Not Found!!"<<endl;
	}
}

void UpdateBorrowers() {
	
	string borrowid;
	string id;
	string fname;
	string fdate;
	string fcontact;
	string freadbooks;
	string name;
	string date;
	string contact;
	string readbooks;
	int flag=1;
	int count=0;
	int option;
	int mark=0;
	
	cout<<endl<<endl<<"\t\t\t\t\t~~~Update Borrowers' Deatails~~~"<<endl<<endl;
	cout<<"\t\t\t\t\tUpdate Borrower Deatails By Borrower ID"<<endl<<endl;
	cout<<"\t\t\t\t\tEnter Borrow ID: ";
	cin>>borrowid;
	if(system("CLS")) system("clear");
	
	fstream newFile; 
	newFile.open("borrowfile.dat",ios::in); 
	if(!newFile){ 
		cout<<endl<<endl<<endl<<"\t\t\t\t\tNo such file";
	} 
	string line;
	while (getline(newFile, line)) {
		istringstream iss(line);
				getline(iss, id, ','); 
				getline(iss, fname, ',');
				getline(iss, fdate, ',');
				getline(iss, fcontact, ',');
				getline(iss, freadbooks, ',');
				
				if(borrowid==id) {
					mark=1;
				}
				
	}
	newFile.close();
				
				if(mark==1) {
				
					while(flag==1) {
					cout<<endl<<"\t\t\t\t\tWhat Do You Want To Update?"<<endl<<endl;
					cout<<"\t\t\t\t\t01. Borrow's Name"<<endl<<endl;
					cout<<"\t\t\t\t\t02. Joined Date"<<endl<<endl;
					cout<<"\t\t\t\t\t03. Borrower's Contacts"<<endl<<endl;
					cout<<"\t\t\t\t\t04. Back to Menu"<<endl<<endl;
					cout<<"\t\t\t\t\tPleace Choose Any Option: ";
					cin>>option;
					if(system("CLS")) system("clear");
					
					switch(option) {
						case 1:{
							cout<<endl<<endl<<endl<<"\t\t\t\t\tEnter Borrow's Name:\t";
							cin.ignore();
							getline(cin,fname);
							if(system("CLS")) system("clear");
							flag=1;
							break;
						}
						case 2:{
							cout<<endl<<endl<<endl<<"\t\t\t\t\tEnter Joined Date:\t";
							cin.ignore();
							getline(cin,fdate);
							if(system("CLS")) system("clear");
							flag=1;
							break;
						}
						case 3:{
							cout<<endl<<endl<<endl<<"\t\t\t\t\tBorrower's Contacts:\t";
							cin.ignore();
							getline(cin,fcontact);
							if(system("CLS")) system("clear");
							flag=1;
							break;        
						}
						case 4:{
							flag=0;
							break;
						}
						default :{
							cout<<endl<<endl<<"\t\t\t\t\tInvalid Enter!!!"<<endl;
							flag=1;
							break;
						}
					}
					
				}
	fstream borrowfile;
	borrowfile.open("borrowfile.dat",ios::in);
	
	fstream tempfile2;
	tempfile2.open("temp.dat",ios::out);
	
	string line2;
	while (getline(borrowfile, line2)) {
		istringstream iss(line2);
			
				getline(iss, id, ','); 
				getline(iss, name, ',');
				getline(iss, date, ',');
				getline(iss, contact, ',');
				getline(iss, readbooks, ',');
			
			if(borrowid!=id){
				tempfile2<<id<<","<<name<<","<<date<<","<<contact<<","<<readbooks<<endl;
			
			}
			else if(borrowid==id){
				tempfile2<<id<<","<<fname<<","<<fdate<<","<<fcontact<<","<<freadbooks<<endl;
				count=1;
			
			}
	}
	if(count==1) {
		cout<<endl<<"\t\t\t\t\tThe Borrower Details Have Been Updated";
	}
	
	borrowfile.close();
	tempfile2.close();
	
	remove("borrowfile.dat");
	rename("temp.dat","borrowfile.dat");

}
else {
	cout<<endl<<endl<<"\t\t\t\t\tThis Record Was Not Found ";
}
	
}

void prizewinner() {
	
	int largestValue , nofbooks;
	string id , fname , fdate , fcontact , freadbooks , nofbookstring;

	cout<<endl<<endl<<"\t\t\t\t\t***Borrower, The Prize Winner Who Has Read The Most Books***";

	fstream newFile; 
	newFile.open("borrowfile.dat",ios::in); 
	if(!newFile){ 
		cout<<endl<<endl<<endl<<"\t\t\t\t\tNo such file";
	} 
	string line;
	while (getline(newFile, line)) {
		istringstream iss(line);
		getline(iss, id, ','); 
		getline(iss, fname, ',');
		getline(iss, fdate, ',');
		getline(iss, fcontact, ',');
		getline(iss, freadbooks, ',');
		
		
		stringstream ss(freadbooks);
		ss>>nofbooks;   //convert nomber of read books to int 					
		
		if(largestValue<nofbooks) {
			largestValue=nofbooks;
		}		
		
	}
	newFile.close();
	
	// again convert to string
		stringstream stream;
		stream << nofbooks;
		stream >> nofbookstring;
		
	newFile.open("borrowfile.dat",ios::in); 
	if(!newFile){ 
		cout<<endl<<endl<<endl<<"\t\t\t\t\tNo such file";
	} 

	while (getline(newFile, line)) {
		istringstream iss(line);
		getline(iss, id, ','); 
		getline(iss, fname, ',');
		getline(iss, fdate, ',');
		getline(iss, fcontact, ',');
		getline(iss, freadbooks, ',');
		
		if(freadbooks==nofbookstring) {
			cout<<endl<<endl<<"\t\t\t\t\tBorrower ID:\t"<<id;
			cout<<endl<<endl<<"\t\t\t\t\tBorrower Name:\t"<<fname;
			cout<<endl<<endl<<"\t\t\t\t\tBorrower Contact:\t"<<fcontact;
			cout<<endl<<endl<<"\t\t\t\t\tNumbe Of Books Read:\t"<<freadbooks;
		}
	}
	newFile.close();
	
	int backtomenu;
	cout<<endl<<endl<<"\t\t\t\t\tEnter Any key To Back To Menu:\t";
	cin>>backtomenu;
	if(system("CLS")) system("clear");
}

int main(int argc, char** argv) {
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	static CONSOLE_FONT_INFOEX fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX); 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	GetCurrentConsoleFontEx(hOut, 0, &fontex); 
	fontex.FontWeight = 700; 
	fontex.dwFontSize.X = 20; 
	fontex.dwFontSize.Y = 20; 
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
	
	int menu3;
	int menu2=1;
	int menu1=1;
	int length;
	int addDeleteBorrowers;
	int searchUpdateBorrowers;
	string adminPassword;
	string adminPasswordOriginal="1234";
	string Lusername;
	string Lpassword;
	string username;
	string password;
	string lnic;
	string lname;
	string name;
	string nic;
	string fpassword;
	string fusername;
	int searchORupdate=1;
	int fineRate=10;
	int maximumLimit=2;
	int issuebooks=1;
	
		while(menu1<=2) {
		SetConsoleTextAttribute(h,3);
		cout<<endl<<endl<<endl<<"\t\t\t\t_________________________________________________"<<endl<<endl;
		cout<<"\t\t\t\t        WELCOME TO BLOSSOM LIBRARY SYSTEM        "<<endl;
		cout<<"\t\t\t\t________________________________________________"<<endl<<endl;	
		cout<<"\t\t\t\t\t01. Admin"<<endl<<endl;
		cout<<"\t\t\t\t\t02. Librarian"<<endl<<endl;
		cout<<"\t\t\t\t\t03. Close Application"<<endl;
		cout<<endl<<"\t\t\t\t\tPleace Choose Any Option to login: ";
		cin>>menu1;
		if(system("CLS")) system("clear");

		
			if(menu1==1) {
				cout<<endl<<"\t\t\t\t\tEnter Admin password:\t";
				cin>>adminPassword;
				cout<<endl;
				if(system("CLS")) system("clear");
				if(adminPassword==adminPasswordOriginal) {
					menu2=1;
					
					while(menu2<=3) {
						cout<<endl<<endl<<endl;
						cout<<"\t\t\t\t\t________M E N U________"<<endl<<endl;
						cout<<"\t\t\t\t\t01. Sign up librarians"<<endl<<endl;
						cout<<"\t\t\t\t\t02. Change the fine rate"<<endl<<endl;
						cout<<"\t\t\t\t\t03. Modify maximum borrowing limits"<<endl<<endl;
						cout<<"\t\t\t\t\t04. Show Librarian List"<<endl<<endl;
						cout<<"\t\t\t\t\t05. Show fine rate and maximum borrowing limits"<<endl<<endl;
						cout<<"\t\t\t\t\t06. Exit"<<endl<<endl;
						cout<<"\t\t\t\t\t07. Back to menu"<<endl<<endl;
						cout<<"\t\t\t\t\tPleace Choose Any Option ";
						cin>>menu2;
						cout<<endl;
						
						switch(menu2) {
							case 1:{
								cout<<endl<<endl<<"\t\t\t\t\tEnter librarian's first name:\t";
								cin>>lname;
								cout<<endl<<"\t\t\t\t\tEnter librarian's last six digits of NIC number:\t";
								cin>>lnic;
								if(system("CLS")) system("clear");
								length=lnic.length();
								if(length<6 || length>6) {
									cout<<endl<<"\t\t\t\t\tInvalid enter Try again";
									menu2=1; // to display librarian menu again
									break;
								}
								if(system("CLS")) system("clear");
								signUpLibrarians(lname, lnic);
								break;
							}
							case 2:{
								cout<<endl<<endl<<"\t\t\t\t\tEnter value for fine rate:\t";
								cin>>fineRate;
								if(system("CLS")) system("clear");
								fstream ratefile;
								ratefile.open("finerate.dat",ios::out);
								if(! ratefile) {
									cout<<endl<<"\t\t\t\t\tFile does not exit!";
								}
								else {
									ratefile<<fineRate<<"\n";
									ratefile.close();
									cout<<endl<<"\t\t\t\t\tFine rate updated"<<endl;
								}
								break;
							}
							case 3:{
								cout<<"\t\t\t\t\tModify maximum borrowing limits:\t";
								cin>>maximumLimit;
								if(system("CLS")) system("clear");
								fstream maximumborrowfile;
								maximumborrowfile.open("maximumborrow.dat",ios::out);
								if(! maximumborrowfile) {
									cout<<endl<<"\t\t\t\t\tFile does not exit!";
								}
								else {
									maximumborrowfile<<maximumLimit<<"\n";
									maximumborrowfile.close();
									cout<<endl<<endl<<"\t\t\t\t\tMaximum borrowing limit updated"<<endl;
								}
								break;
							}
							
							case 4:{
								if(system("CLS")) system("clear");
								showlibrianlist();
								menu2=1; // to display librarian menu again
								break;
							}
							
							case 5:{
								if(system("CLS")) system("clear");
								cout<<endl<<endl<<"\t\t\t\t\tFinerate And Maximum Borrowing Limits";
								ShowFinerateAndMaximumBorrowingLimits();
								menu2=1; // to display librarian menu again
								break;
							}
							
							case 6:{
								if(system("CLS")) system("clear");
								cout<<endl<<"\t\t\t\t\tThankyou....."<<endl;
								menu1=3; // to close programe
								break;
							}
							case 7:{
								if(system("CLS")) system("clear");
								break;
							}
							default:{
								if(system("CLS")) system("clear");
								cout<<endl<<endl<<"\t\t\t\t\tInvalid enter!";
								menu1=1; // to display main menu again
								break;
							}
						}
						
					}
				}
				else {
					cout<<endl<<endl<<"\t\t\t\t\tWrong password! Try again...";
					menu1=1; // to display main menu again
				}
				
			}
			
			else if(menu1==2) {
				int count=0;
				cout<<endl<<endl<<"\t\t\t\t\tEnter username and password..."<<endl; // for login as a librarian
				cout<<endl<<"\t\t\t\t\tUsername>>\t";
				cin>>username;
				cout<<endl<<"\t\t\t\t\tPassword>>\t";
				cin>>password;
				if(system("CLS")) system("clear");
				
				fstream signfile;
				signfile.open("librarian.dat",ios::in);
				if(!signfile) {
					cout<<"\t\t\t\t\tFile cannot be open !!!";
				}
				else {
					/* read librarian file to get librarians 
					user names and passwords for check if passwords and usernames are right */
					string line;
					while(getline(signfile, line)) {
						istringstream iss(line);

						getline(iss, name, ','); 
						getline(iss, nic, ',');
						getline(iss, fusername, ',');
						getline(iss, fpassword, ',');
			
						if(fpassword==password && fusername==username) { // if entered password or user name and read password usernames 
							count=1;												// are same, count is 1
						}
						/*else {
							int reset;
							cout<<endl<<endl<<"\t\t\t\t\tForgoten Password?";
							cout<<endl<<endl<<"\t\t\t\t\t01. Reset Username And Password";
							cout<<endl<<endl<<"\t\t\t\t\t02. Enter Username And Password";
							cout<<endl<<endl<<"\t\t\t\t\tSelect Any Option:\t";
							cin>>reset;
							if(reset==1) {
								void reset();
								reset();
							}
							else if(reset==2) {
								menu1=2;
								break;
							}
						}*/		
							
				}
					}
				signfile.close();
				
				if(count==1) {
					int flag=1;
					while(flag==1) {  // to display librarian menu
					int addOrDelete;
					cout<<endl<<endl<<endl;
					cout<<"\t\t\t\t\t________M E N U________"<<endl<<endl;
					cout<<"\t\t\t\t01. Show Book deatails"<<endl<<endl;
					cout<<"\t\t\t\t02. Add and delete books"<<endl<<endl;
					cout<<"\t\t\t\t03. Search and update books"<<endl<<endl;
					cout<<"\t\t\t\t04. Issue books"<<endl<<endl;
					cout<<"\t\t\t\t05. Accept returned books"<<endl<<endl;
					cout<<"\t\t\t\t06. Show boorrower Deatails"<<endl<<endl;
					cout<<"\t\t\t\t07. Add and delete borrowers"<<endl<<endl;
					cout<<"\t\t\t\t08. Search and update borrowers"<<endl<<endl;
					cout<<"\t\t\t\t09. Show The Prize Winner"<<endl<<endl;
					cout<<"\t\t\t\t10. Back to menu"<<endl<<endl;
					cout<<"\t\t\t\t11. Exit"<<endl<<endl;
					cout<<"\t\t\t\tChoose Any Option: ";
					cin>>menu3;
					if(system("CLS")) system("clear");
					addOrDelete=1;	
					searchORupdate=1;
					addDeleteBorrowers=1;
					searchUpdateBorrowers=1;
					switch(menu3) {
						
						case 1:{
							showbooks();
							break;
						}
						
						case 2: {
							while(addOrDelete<=2) {
								cout<<endl<<endl<<"\t\t\t\t\t***Add And Delete Books***"<<endl;
								cout<<endl<<endl<<"\t\t\t\t\tDo you want to"<<endl;
								cout<<endl<<"\t\t\t\t\t01. Add Books"<<endl;
								cout<<endl<<"\t\t\t\t\t02. Delete Books"<<endl;
								cout<<endl<<"\t\t\t\t\t03. Back To Menu"<<endl;
								cout<<endl<<"\t\t\t\t\t04. Exit"<<endl;
								cout<<endl<<"\t\t\t\t\tPleace choose any option: ";
								cin>>addOrDelete;
								if(system("CLS")) system("clear");
								if(addOrDelete==1) {
									addbook();
									addOrDelete=1;  // to display add delete menu
								}
								else if(addOrDelete==2) {
									deletebook();
									addOrDelete=1;  // to display add delete menu
								}
								else if(addOrDelete<1 || addOrDelete>4) {
									cout<<endl<<endl<<"\t\t\t\t\tInvalid Enter. Try Again....";
									addOrDelete=1;  // to display add delete menu
								}
								else if(addOrDelete==4) {
									menu1=3;  // to exit main menu
									cout<<endl<<endl<<"\t\t\t\t\tThankyou....."<<endl<<endl<<endl<<endl;
									flag=0;  // to exit librarian menu
								}	
							}
							if(addOrDelete==3){ 
									flag=1; // to display librarian menu
								}
							break;
						}
						
						
						case 3:{
							flag=0;
							while(searchORupdate<=2) {
								cout<<endl<<endl<<"\t\t\t\t\t***Search And Update Books***"<<endl;
								cout<<endl<<endl<<"\t\t\t\t\tDo you want to"<<endl;
								cout<<endl<<"\t\t\t\t\t01. Search Books By Book ID Or Book Name"<<endl;
								cout<<endl<<"\t\t\t\t\t02. Search Books By Author"<<endl;
								cout<<endl<<"\t\t\t\t\t03. Update Books"<<endl;
								cout<<endl<<"\t\t\t\t\t04. Back To Menu"<<endl;
								cout<<endl<<"\t\t\t\t\t05. Exit"<<endl;
								cout<<endl<<"\t\t\t\t\tPleace choose any option: ";
								cin>>searchORupdate;
								if(system("CLS")) system("clear");
								if(searchORupdate==1) {
									searchbook();
									searchORupdate=1; // to go to search update menu again
								}
								else if(searchORupdate==2) {
									searchbooksbyauthor();
									searchORupdate=1;  // to go to search update menu again
								}
								else if(searchORupdate==3) {
									updatebook();
									searchORupdate=1;
								}
								else if(searchORupdate<1 || searchORupdate>4) {
									cout<<endl<<endl<<"\t\t\t\t\tInvalid Enter. Try Again....";
									searchORupdate=1;  // to go to search update menu again
								}
								else if(searchORupdate==5) {
									menu1=3; // to exit main menu
									cout<<endl<<endl<<"\t\t\t\t\tThankyou....."<<endl<<endl<<endl<<endl;
									flag=0;  // to exit librarian menu
								}	
							}
							if(searchORupdate==4){ 
									flag=1;  // to display librarian menu
								}
							break;
						}
						
						
						case 4:{
							flag=0;
							while(issuebooks<=3) {
								cout<<endl<<endl<<"\t\t\t\t\t***Issue Books***"<<endl;
								cout<<endl<<endl<<"\t\t\t\t\tDo you want to"<<endl;
								cout<<endl<<"\t\t\t\t\t01. Show Books"<<endl;
								cout<<endl<<"\t\t\t\t\t02. Issue Books"<<endl;
								cout<<endl<<"\t\t\t\t\t03. Back To Menu"<<endl;
								cout<<endl<<"\t\t\t\t\t04. Exit"<<endl;
								cout<<endl<<"\t\t\t\t\tPleace choose any option: ";
								cin>>issuebooks;
								if(system("CLS")) system("clear");
								if(issuebooks==1) {
									showbooks();
									cout<<"\t\t\t\t\tEnter No:01 To Issue Books: ";
									cin>>issuebooks;
									
								}
								if(issuebooks==2) {
									void issuebooks();
									issuebooks();
									cout<<endl<<endl<<"\t\t\t\t\tThankyou......";
								}
								else if(issuebooks<1 || issuebooks>4) {
									cout<<endl<<endl<<"\t\t\t\t\tInvalid Enter. Try Again....";
									issuebooks=1; // to  display issue book menu again
								}
								else if(issuebooks==4) {
									menu1=3;  //  to exit main menu
									cout<<endl<<endl<<"\t\t\t\t\tThankyou....."<<endl<<endl<<endl<<endl;
									flag=0;  // to exit librarian menu
								}
								if(issuebooks==3){ 
									flag=1; // to display librarian menu
									break;
								}	
							}
							break;
						}
						
						
						case 5:{
							acceptReturnedBooks();
							cout<<endl<<endl<<"\t\t\t\t\tThankyou.....";
							break;
						}
						
						case 6:{
							showborrowerdeatails();
							break;
						}
						
						case 7:{
							while(addDeleteBorrowers<=2) {
								cout<<endl<<endl<<"\t\t\t\t\t***Add And Delete Borrowers***"<<endl;
								cout<<endl<<endl<<"\t\t\t\t\tDo you want to"<<endl;
								cout<<endl<<"\t\t\t\t\t01. Add Borrowers"<<endl;
								cout<<endl<<"\t\t\t\t\t02. Delete Borrowers"<<endl;
								cout<<endl<<"\t\t\t\t\t03. Back To Menu"<<endl;
								cout<<endl<<"\t\t\t\t\t04. Exit"<<endl;
								cout<<endl<<"\t\t\t\t\tPleace choose any option: ";
								cin>>addDeleteBorrowers;
								if(system("CLS")) system("clear");
								
								if(addDeleteBorrowers==1) {
									addborrowers();
									addDeleteBorrowers=1;  //  to display add delete borrow menu again
								}
								else if(addDeleteBorrowers==2) {
									deleteBorrowers();
									addDeleteBorrowers=1;  //  to display add delete borrow menu again
								}
								else if(addDeleteBorrowers<1 || addDeleteBorrowers>4) {
									cout<<endl<<endl<<"\t\t\t\t\tInvalid Enter. Try Again....";
									addDeleteBorrowers=1;   //  to display add delete borrow menu again
								}
								else if(addDeleteBorrowers==4) {
									menu1=3;  // to exit main menu
									cout<<endl<<endl<<"\t\t\t\t\tThankyou....."<<endl<<endl<<endl<<endl;
									flag=0;   //  to exit librarian menu
								}
								if(addDeleteBorrowers==3) {
									flag=1;    // to display librarian menu
								}
								break;
							}
						
							break;
						}
						
						
						case 8:{
								while(searchUpdateBorrowers<=2) {
								cout<<endl<<endl<<"\t\t\t\t\t***Search And Update Borrowers***"<<endl;
								cout<<endl<<endl<<"\t\t\t\t\tDo you want to"<<endl;
								cout<<endl<<"\t\t\t\t\t01. Search Borrowers"<<endl;
								cout<<endl<<"\t\t\t\t\t02. Update Borrowers"<<endl;
								cout<<endl<<"\t\t\t\t\t03. Back To Menu"<<endl;
								cout<<endl<<"\t\t\t\t\t04. Exit"<<endl;
								cout<<endl<<"\t\t\t\t\tPleace choose any option: ";
								cin>>searchUpdateBorrowers;
								if(system("CLS")) system("clear");
								
								if(searchUpdateBorrowers==1) {
									searchBorrowers();
									searchUpdateBorrowers=1;   // to displa search update borrow menu again
								}
								else if(searchUpdateBorrowers==2) {
									UpdateBorrowers();
									searchUpdateBorrowers-1;   // to displa search update borrow menu again
								}
								else if(searchUpdateBorrowers<1 || searchUpdateBorrowers>4) {
									cout<<endl<<endl<<"\t\t\t\t\tInvalid Enter. Try Again....";
									searchUpdateBorrowers=1;   // to displa search update borrow menu again
								}
								else if(searchUpdateBorrowers==4) {
									menu1=3;   // to exit main menu
									cout<<endl<<endl<<"\t\t\t\t\tThankyou....."<<endl<<endl<<endl<<endl;
									flag=0;   //  to exit librarian menu
								}
								if(searchUpdateBorrowers==3) {
									flag=1;  // to display librarian menu
									
								}
								break;
							}
							
							break;
						}
						case 9:{
							prizewinner();
							break;
						}
						
						case 10:{
							if(system("CLS")) system("clear");
							flag=0;  // to end this while loop (go to main menu)
							break;
						}
						case 11:{
							if(system("CLS")) system("clear");
							cout<<endl<<"\t\t\t\t\tThankyou....."<<endl;
							flag=0; // to end this while loop  (go to main menu)
							menu1=3; // to exit main menu
							break;
							
						}
					}
				}
				}
				
				else {
					cout<<endl<<endl<<endl<<"\t\t\t\t\tInvalid username or password"<<endl<<endl;
					menu1=1; // to display main menu againk
				}	
		}	
		else if(menu1==3) {
			cout<<endl<<"\t\t\t\t\tThankyou..........."<<endl;
		}
			else {
				cout<<endl<<endl<<"\t\t\t\t\tInvalid enter!";
				menu1=1; // to display main menu againk
			}
		}
		
	return 0;
}
