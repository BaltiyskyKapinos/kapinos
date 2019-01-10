#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <clocale>

using namespace std;

struct UNI
{
	string numberst;
	string sername;
	string name;
	string male;

};
UNI *stud, *copstud;
int kolvo=7;

void vivod()
{
	cout<< endl<< "_____________________"<< endl <<endl;
	for (int i=0; i<kolvo; i++)
	{
		cout<<stud[i].numberst<<" "<<stud[i].sername<<" "<<stud[i].name<<" "<<stud[i].male<<endl;
		 
	}
}

void dobavit()
{
	for (int i=0; i<kolvo; i++)
	{
		copstud[i].numberst=stud[i].numberst;
		copstud[i].sername=stud[i].sername;
		copstud[i].name=stud[i].name;
		copstud[i].male=stud[i].male;
	}
	
	kolvo++;
	stud = new UNI [kolvo];
	
		for(int i=0; i<kolvo-1;i++)
		{
			stud[i].numberst=copstud[i].numberst;
			stud[i].sername=copstud[i].sername;
			stud[i].name=copstud[i].name;
			stud[i].male=copstud[i].male;	
		}
			cout<< "Enter Name: ";
	 	cin >> stud[kolvo-1].name;
	 	cout<< "Enter Sername: ";
	 	cin >> stud[kolvo-1].sername;
	 	cout<< "Enter Male: ";
	 	cin >> stud[kolvo-1].male;
	 	cout<< "Enter Std number: ";
	 	cin>> stud[kolvo-1].numberst;
		

	
	copstud= new UNI[kolvo];
	
		 	cout << "\n";
		cout << "Студент успешно добавлен: \n";
		cout << "\n";
		system("pause");
			system("cls");
}

 void deleytstd()
 {
 	string namest;
 	cin>> namest;
 	for(int i=0;i<kolvo;i++)
 	{
 		copstud[i].numberst=stud[i].numberst;
		copstud[i].sername=stud[i].sername;
		copstud[i].name=stud[i].name;
		copstud[i].male=stud[i].male;
 	}
 	
 	kolvo--;
 	stud = new UNI [kolvo];
 	
 	int m=0;
 	
 	for (int i=0; i<kolvo+1; i++)
	 {
	 	if (copstud[i].numberst!=namest)
	 	{
	 		stud[m].numberst=copstud[i].numberst;
			stud[m].sername=copstud[i].sername;
			stud[m].name=copstud[i].name;
			stud[m].male=copstud[i].male;
			m++;
	 	}
	 
	 } 
	 
	 copstud=new UNI [kolvo];
	
 }

void sortingminys()
{
	string temp;
	string temp2;
	for (int m=0; m<kolvo; m++)
	{
		for (int i=0; i<kolvo-1; i++)
		{
			if (stud[i].sername<stud[i+1].sername)
			{
				temp=stud[i].sername;
				stud[i].sername=stud[i+1].sername;
				stud[i+1].sername=temp;
				
				temp=stud[i].name;
				stud[i].name=stud[i+1].name;
				stud[i+1].name=temp;
				
				temp=stud[i].numberst;
				stud[i].numberst=stud[i+1].numberst;
				stud[i+1].numberst=temp;
				
				temp=stud[i].male;
				stud[i].male=stud[i+1].male;
				stud[i+1].male=temp;
			}
		}
	}
}
void sortingpluse()
{
	string temp;
	string temp2;
	for (int m=0; m<kolvo; m++)
	{
		for (int i=0; i<kolvo-1; i++)
		{
			if (stud[i].sername>stud[i+1].sername)
			{
				temp=stud[i].sername;
				stud[i].sername=stud[i+1].sername;
				stud[i+1].sername=temp;
				
				temp=stud[i].name;
				stud[i].name=stud[i+1].name;
				stud[i+1].name=temp;
				
				temp=stud[i].numberst;
				stud[i].numberst=stud[i+1].numberst;
				stud[i+1].numberst=temp;
				
				temp=stud[i].male;
				stud[i].male=stud[i+1].male;
				stud[i+1].male=temp;
			}
		}
	}
}

void thinkfile()
{
	ifstream fin("std.txt");
	for ( int i=0; i<kolvo; i++)
	{
		fin>> stud[i].numberst>> stud[i].sername>> stud[i].name>> stud[i].male;
	}
}
void save()
{
	ofstream fout("std.txt");
	for ( int i=0; i<kolvo; i++)
	{
		fout<< stud[i].numberst<<" "<< stud[i].sername<<" "<< stud[i].name<<" "<< stud[i].male<<endl;
	}
}




int main() 
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	stud = new UNI[kolvo];
	copstud = new UNI[kolvo];
	
	int g;
	
	while (true)
	{
		cout<<"_____________________________________"<<endl;
		cout<<"Enter number to continue or 0 to end "<< endl;
		cout<<"Enter 1 Check Student list"<<
		endl<<"Enter 2 to add to Student list"<< 
		endl<<"Enter 3 to remove a student from the list"<<endl;
		cout<<"Enter 4 to sort the list descending"<<
		endl<<"Enter 5 to sort the list in ascending order"<<endl;
		cout<<"Enter 6 to read the list from the file"<<
		endl<<"Enter 7 to save the list in a file"<<endl;
		cout<<"______________________________________"<<endl;
	cin>>g;
	
	if (g==0)
	{
		break;
	}
		switch (g)
		{
			case(1):
				vivod();
				break;
			case(2):
				dobavit();
				break;
			case(3):
				deleytstd();
				break;
			case(4):
				sortingminys();
				break;
			case(5):
				sortingpluse();
				break;
			case(6):
				thinkfile();
				break;
			case(7):
				save();
				break;
				
			default:
				cout<<"Error"<<endl;
				break;
				
				
		}
	}
	
	
		
	return 0;
}

