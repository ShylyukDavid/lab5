#define _CRT_SECURE_NO_WARNINGS
#include "libr.h"
#include <vector>
#include <string> 
#include <iostream>
#include <iterator>
#include <conio.h>
#include<fstream>

void menu1()
{
	float productivity; int num_dp, prod_num;
	cout << "Enter power productivity - "; cin >> productivity;
	cout << "Enter number departments - "; cin >> num_dp;
	cout << "Enter number products - "; cin >> prod_num;
	enterprise factory(productivity, num_dp, prod_num);
	bool departs = false; bool productions = false;
	if (factory.have_departs())
	{
		factory.describe_department(num_dp); departs = true; system("pause"); system("cls");
	}
	else cout << "Your enterprise has no departments!" << endl;

	if (factory.has_products())
	{
		factory.describe_products(prod_num); productions = true;
	}
	else cout << "No such a product is found!" << endl;
	if (departs && productions)cout << "You finally described enterprise!" << endl;
	char c;
	do
	{
		cout << "1.Show info departments\n"
			<< "2.Show info products\n"
			<< "3.Qualify workers\n"
			<< "4.Take order\n"
			<< "5.Add product\n"
			<< "6.Add department\n"
			<< "0.Exit\n";
		switch (c = _getch())
		{
		case '1': if (factory.have_departs())
		{
		factory.show_depart(); break;
		}
				  else cout << "You have no departments!" << endl; break;
		case '2': if (factory.has_products())
		{
			 factory.show_products(); break;
		}
				  else cout << "No production in your enterprise.Its bad!\n"; break;
		case '3':  cout << "Notice:input countdown starts from index 0:\n"; factory.choose_depart(); break;
		case '4':  if (factory.get_s().have_materials())
		{
					   int c = factory.get_pow(); ++factory;
					   if (factory.create_order())
					   {
						   cout << "Previous productivity - " << c << ", productivity after performing order - " << factory.get_pow() << endl;
					   }
					   break;
		}
				   else cout << "U cant take order without resources!" << endl; break;
		case '5': int w; cout << "Enter number of products u want to add - "; cin >> w; factory.describe_products(w); break;
		case '6': int l; cout << "Enter number of departments to add - "; cin >> l; factory.describe_department(l); break;
		case'0':exit(0); break;

		}


		//	cout << "Yout finally defined enterprise!" << endl;
		system("pause");
		system("cls");
	} while (c != '0');
	system("pause");

}

void menu2()
{
	float produc; int dep, prod; 
	ifstream f("data.txt");
	f >> produc;
	f >> dep;
	f >> prod;
	enterprise factory(produc, dep, prod,true);
    factory.input_departments(f);
	factory.show_depart();
	factory.input_products(f);
	system("pause");
	system("cls");
	char c;
	do
	{
		cout << "1.Show info departments\n"
			<< "2.Show info products\n"
			<< "3.Qualify workers\n"
			<< "4.Take order\n"
			<< "5.Add product\n"
			<< "6.Add department\n"
			<< "0.Exit\n";
		switch (c = _getch())
		{
		case '1': if (factory.have_departs())
		{
			factory.show_depart(); break;
		}
				  else cout << "You have no departments!" << endl; break;
		case '2': if (factory.has_products())
		{
			factory.show_products(); break;
		}
				  else cout << "No production in your enterprise.Its bad!\n"; break;
		case'3':  cout << "Notice:input countdown starts from index 0:\n"; factory.choose_depart(); break;
		case '4': if (factory.get_s().have_materials())
		{
			int c = factory.get_pow(); ++factory;
			if (factory.create_order())
			{
				cout << "Previous productivity - " << c << ", productivity after performing order - " << factory.get_pow() << endl;
			}
			break;
		}
				  else cout << "U cant take order without resources!" << endl; break;
		case '5': int w; cout << "Enter number of products u want to add - "; cin >> w; factory.describe_products(w); break;
		case '6': int l; cout << "Enter number of departments to add - "; cin >> l; factory.describe_department(l); break;
		case'0':exit(0); break;
		default:break;
		}


		//	cout << "Yout finally defined enterprise!" << endl;
		system("pause");
		system("cls");
	} while (c!= '0');

}
int main()
{
	{  
		cout << "Lab5 done by Shylyuk David" << endl;
		cout << "Program is running..." << endl;
		cout << "------------------------" << endl;
		////////////////////////*********************Demonstration of using overloaded operators*****************************/////////////////////////
		cout << "Demonstration of using overloaded operators:" << endl;
		int test_qual; string test_line;
		cout << "Creating 3 workers: " << endl;
		cout << "\nEnter value of qualification for worker#" << 1 << " - ";  cin >> test_qual;
		hand_worker c1(0, test_qual);
		cout << "\nEnter value of qualification for worker#" << 2 << " - "; cin >> test_qual;
		hand_worker c2(0, test_qual);
		cout << "\nEnter value of qualification for worker#" << 3 << " - "; cin >> test_qual;
		hand_worker c3(0, test_qual);

		cout<<"\nUpdating(increasing by 1) qualification for worker 1 and 3 - "<<endl; c1++; c3++;
		cout << "Worker#1:"; cout << c1.get_qualification() << endl;
		cout << "Worker#2:"; cout << c2.get_qualification() << endl;
		cout << "Worker#3:"; cout << c3.get_qualification() << endl << endl;

		cout<<"\nNext example:\nCreating 3 tecnicians, first has work experience - 3years , second: 2years , third: 3years. "<<endl;
		tecnique d1(3, 1); tecnique d2(2, 1); tecnique d3(3, 1);
		if (d1 == d3)
			cout<<"\nTecnician#1 has the same experience as tecnician#3"<<endl;
		if (d1 != d2)             //перевантаженн€ оператора пор≥вн€нн€(запереченн€)
			cout<<"\nTecnician#1 has different work experience from tecnician#2"<<endl;
		if (d1 > d2)
		{
			cout<<"\nTecnician#1 has bigger work experience than tecnician#2"<<endl;

		}
		cout << "\nNext example:\nCreating conveyer_line: " << endl; conveyer_line cv;;
		cout << "Enter equipment condition of line(0<c<10) - " << endl;  cin >> test_qual; cv.set_eqiupment_stat(test_qual);
		cv--;
		cout<<"There was some break down on this line and its state became horrible: equipment_state now = "<<cv.get_eqiupment_stat()<<endl;
		cout<<"\nFinish....\nPress something to start main program..."<<endl;
		system("pause"); system("cls");
		/////////////////////////************************Main program******************************///////////////////////////////
		int n;
		do
		{
			cout << "Do you want to create enterprise by yourself or by file-data?(1,2)\nBetter use file not to waste time...\n";
			switch (_getch())
			{
			case'1':n = true;  menu1(); break;
			case '2': n= true; menu2();  break;
			default:cout << "Try again.."; n = false; system("pause"); system("cls"); break;

			}
		} while (n == false);

	
	}

}