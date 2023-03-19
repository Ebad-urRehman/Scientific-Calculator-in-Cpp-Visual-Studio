// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Calculator.h"
#include <conio.h>;
#include <cmath>
#include <Windows.h>
using namespace std;
int main()
{
	double x = 0.0;
	double y = 0.0;
	double q;
	double result = 0.0;
	char choice;//for inputting choice from user
	char opr;
	cout << "This is a Calculator" << endl << endl;
	int k = 1;
	Calculator objcalc;//creating an object of class Claculator
	//Calculator trigcacl;
	while (true)
	{
	start:
		int i = 1;
		if (k == 1)//agr k==1 ho ga phir ye necha wala display ho ga 
		{
			cout << "\n\n          **********MAIN MENU**********          \n";
			cout << "What type of calculation you want to perform      " << endl;
			cout << "Press 't' for Trignometric, 'T' for Inverse Trignometric, 'a' for arthematic and 'c' for conversion(length units)     " << endl;
		}
			choice = _getch();
		if (choice == 't')
		{
			k = 1;//to make sure it returns to main menu to display instructions
			cout << "\n\nTrignometric Calculator\n";
			do
			{
				
				if (i == 1)
				{
					cout << "write as \n sx for sin(x)\n cx for cos(x)\n tx for tan(x)\n Cx for cosec(x)\n Sx for sec(x)\n Tx for cot(x)\n Where x is angle in degree \n press Esc to return to the main menu" << endl<<endl;
				}
					i++;
					int j = 0;
					while (j == 0)
					{
						opr = _getch();
						if (int(opr) != 27)
						{
							if (opr == 's' || opr == 'c' || opr == 't' || opr == 'C' || opr == 'S' || opr == 'T')
							{
								objcalc.display_user(opr);
								cin >> x;
								result = objcalc.Trig(opr, x);
								cout << "**********         Result of " << opr << x << " is : " << result << "         **********" << endl;
								j++;
							}
							else
							{
								//wrong input try again
								j--;
							}
						}
						else
						{
							cout << "Exiting to Menu";
							j++;
						}
					}
				} while (int(opr) != 27);
		}
		else if (choice == 'a')
		{
			k = 1;//to make sure it returns to main menu to display instructions
			do {
				if (i == 1)
				{
					cout << "This Calculator can add, subtract, multiply, divide, and can find mod in format : a+b, a-b, a*b, a/b, a%b \n Enter 0n0 for main menu " << endl;
				}
				i++;
				cin >> x >> opr >> y;
				
				result = objcalc.Calculate(x, opr, y);
				if (opr == 'n')
				{
					break;
				}
				cout << "**********         Result of " << x << opr << y << " is : " << result << "          **********" << endl;
				} while (opr != 'n');
		}
		else if (choice == 'c')
		{
			k = 1;//to make sure it returns to main menu to display instructions
			char convertfrom, convertinto;
			double val_to_convert;
			do {
				if (i == 1)
				{
					cout << "This calculator can convert physical quantities from one unit to another\n";
					cout << "\nChoices are \n m for miles\n k for kilometers\n f for feet\n i for inches\n\n";
				}
				i++;
				cout << "Enter the unit you want to covert from : (press Esc to exit to main menu)\n ";
				convertfrom = _getch();
				objcalc.displayuser_conv(convertfrom);
				if (int(convertfrom) != 27)
				{
					cout << "\nTo unit : ";
					convertinto = _getch();
					objcalc.displayuser_conv(convertinto);
					cout << "\nEnter the value you want to convert from " << convertfrom << " to " << convertinto << endl;
					cin >> val_to_convert;
					result = objcalc.convert(val_to_convert, convertfrom, convertinto);
					cout << "\n**********         Conversion from " << convertfrom << " to " << convertinto << " is : " << result << "          **********\n" << endl;
				}
				} while (int(convertfrom) != 27);
			}
		else if (choice == 'T')
		{
			k = 1;//to make sure it returns to main menu to display instructions
			int i = 0;
			cout << "Inverse Trignometric Calculator\n";
			do
			{
				if (i == 0)
				{
					cout << "Write as \nsx for arcsinx\n cx for arccosx\n tx for arctanx\n Cx for arccosecx\n S for arcsecx\n T for arccotx\n Where x is angle in degree \n press Esc to return to the main menu\n\n";
				}
				i++;//display above line once
				int j = 0;//to check if input is sucessfull or not
				while (j == 0)
				{
					opr = _getch();
					if (int(opr) != 27)
					{
						if (opr == 's' || opr == 'c' || opr == 't' || opr == 'C' || opr == 'S' || opr == 'T')
						{
							objcalc.displayuser_arctrig(opr);
							cin >> x;
							result = objcalc.arctrig(opr, x);
							cout << "**********         Result of " << opr << x << " is : " << result << "         **********" << endl;
							j++;
						}
						else
						{
							//wrong input try again
							j--;
						}
					}
					else
					{
						cout << "Exiting to Menu";
						j++;
					}

				}

			} while (int(opr) != 27);

		}
		else
		{
			k--;//Do not show instructions again and again if user put wrong input
			// Frequency of the bell sound
			DWORD frequency = 800;

			// Duration of the bell sound in milliseconds
			DWORD duration = 200;

			// Call the Beep function to produce the sound
			Beep(frequency, duration);
		}
	}
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
