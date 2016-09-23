
#include<iostream>
#include<strings.h>
using namespace std;

class Book
{

protected:
	char Title[50],Author[50],Publisher[50];
	float Price;
	Book *Left,*Right;

	friend class CartManager;

};

//Global Variables
int iBookCounter=0;

Book *First=NULL,*Current,*NewOne;

class CartManager
{
	Book *pSearchBook,*pSearchedBook;

public:

	void AddNewBook()
	{
		//Checking if First Is Exist or Not
		if(First == NULL)
		{
			First = new Book();
			cout<<"\nEnter Following Details For New Book";

			cout<<"\nTitle: ";		cin>>First->Title;
			cout<<"Author: ";		cin>>First->Author;
			cout<<"Publisher: ";	cin>>First->Publisher;
			cout<<"Price: ";		cin>>First->Price;

			First->Right=NULL;
			Current = First;
		}
		else
		{
			NewOne = new Book();

			cout<<"\nEnter Following Details For New Book";
			cout<<"\nTitle: ";		cin>>NewOne->Title;
			cout<<"Author: ";		cin>>NewOne->Author;
			cout<<"Publisher: ";	cin>>NewOne->Publisher;
			cout<<"Price: ";		cin>>NewOne->Price;

			NewOne->Right=NULL;
			Current->Right=NewOne;
			NewOne->Left=Current;
			Current = NewOne;


		}

	}

	void DisplayBook(Book *BookPointer)
	{
		cout<<"\n\t"<<BookPointer->Title;
		cout<<"\t"<<BookPointer->Author;
		cout<<"\t"<<BookPointer->Publisher;
		cout<<"\t\t"<<BookPointer->Price;
	}

	void SearchBook(int Option, string KeyWord)
	{
		pSearchBook = First;
		cout<<"\tTitle\tAuthor\tPublisher\tPrice\n";
		switch(Option)
		{
			//Case 1 Search By Title
			case 1:
						iBookCounter=0;
						while(pSearchBook->Right!=NULL)
						{
							if(KeyWord.compare(pSearchBook->Title)==0)
							{
								DisplayBook(pSearchBook);
								pSearchedBook = pSearchBook;
								cout<<"\n";
								iBookCounter++;


							}
							pSearchBook = pSearchBook->Right;
						}
						if(KeyWord.compare(pSearchBook->Title)==0)
						{
							DisplayBook(pSearchBook);
							pSearchedBook = pSearchBook;
							cout<<"\n";
							iBookCounter++;
						}
			break;

			//Case 2 Search By Author
			case 2:
						iBookCounter=0;
						while(pSearchBook->Right!=NULL)
						{
							if(KeyWord.compare(pSearchBook->Author)==0)
							{
								DisplayBook(pSearchBook);
								cout<<"\n";
								iBookCounter++;
							}
							pSearchBook = pSearchBook->Right;
						}
						if(KeyWord.compare(pSearchBook->Author)==0)
						{
							DisplayBook(pSearchBook);
							cout<<"\n";
							iBookCounter++;
						}

			break;

			//Case 3 Search By Publisher
			case 3:
						iBookCounter=0;
						while(pSearchBook->Right!=NULL)
						{
							if(KeyWord.compare(pSearchBook->Publisher)==0)
							{
								DisplayBook(pSearchBook);
								cout<<"\n";
								iBookCounter++;
							}
							pSearchBook = pSearchBook->Right;
						}
						if(KeyWord.compare(pSearchBook->Publisher)==0)
						{
							DisplayBook(pSearchBook);
							cout<<"\n";
							iBookCounter++;
						}

			break;

		}

	}

	void DisplayAllBooks()
	{
		Book *AllBooks;
		AllBooks = First;
		cout<<"\tTitle\tAuthor\tPublisher\tPrice\n";
		while(AllBooks->Right!=NULL)
		{
			DisplayBook(AllBooks);
			AllBooks = AllBooks->Right;
		}
		DisplayBook(AllBooks);
		cout<<"\n\n";
	}

	void DeleteBook(Book *BookDelete)
	{
		if(BookDelete==First)
		{
			First = pSearchedBook->Right;
		}
		else if(BookDelete==NewOne)
		{
			NewOne = pSearchedBook->Left;
			Current = NewOne->Left;
		}
		else
		{
			pSearchedBook->Left->Right = pSearchedBook->Right;
			pSearchedBook->Right->Left = pSearchedBook->Left;
		}
		delete(BookDelete);
	}

	void PurchaseBook()
	{
		string sPurchaseBook;
		int iConfirmBuy;
		cout<<"Enter Name Of Book To Purchase : ";
		cin>>sPurchaseBook;
		SearchBook(1,sPurchaseBook);
		if(iBookCounter!=0)
		{
			cout<<"Press 1 To Confirm ....";
			cin>>iConfirmBuy;
			if(iConfirmBuy == 1)
			{
				cout<<"Book Purchased Successfully";
				DeleteBook(pSearchedBook);
			}
		}
		else{ cout<<"\n Out Of Stock";}

	}
};

int main()
{

int iChoise,iRepeat;
string SearchKeyWord;
CartManager cmManager;
	do
	{
		cout<<"\nBook Cart Manager";
		cout<<"\n1.Add New Book";
		cout<<"\n2.Search Book By Title";
		cout<<"\n3.Search Book By Author";
		cout<<"\n4.Search Book By Publisher";
		cout<<"\n5.Purchase Book";
		cout<<"\n6.Display All Books Available";
		cout<<"\nExit\n";
		cin>>iChoise;

		switch(iChoise)
		{
			case 1: cmManager.AddNewBook();
			break;

			case 2:
					cout<<"\nEnter The Title Of Book To Search\n";
					cin>>SearchKeyWord;
					cmManager.SearchBook(1,SearchKeyWord);
					cout<<"\nTotal Stock "<<iBookCounter;
			break;

			case 3:
					cout<<"\nEnter The Author Of Book To Search\n";
					cin>>SearchKeyWord;
					cmManager.SearchBook(2,SearchKeyWord);
					cout<<"\nTotal Stock "<<iBookCounter;
			break;

			case 4:
					cout<<"\nEnter The Publisher Of Book To Search\n";
					cin>>SearchKeyWord;
					cmManager.SearchBook(3,SearchKeyWord);
					cout<<"\nTotal Stock "<<iBookCounter;
			break;

			case 5:
					cmManager.PurchaseBook();
			break;

			case 6:
					cmManager.DisplayAllBooks();
			break;

		}

		cout<<"\nReturn To Menu? \n 1.Yes 2.No";
		cin>>iRepeat;

	}while(iRepeat == 1);

return 0;
}
