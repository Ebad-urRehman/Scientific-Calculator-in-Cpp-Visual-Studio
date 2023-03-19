#define _USE_MATH_DEFINES	
#include "Calculator.h"
	#include <iostream>
    #include <cmath>
//#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <boost/math/constants/constants.hpp>
	using namespace std;
	class conv
	{
	public:
		double x_deg, x_rad;
	
		double deg_to_rad(double deg)
		{
			x_rad = (deg * M_PI / 180);
			return 0;
		}
		double rad_to_deg(double rad)
		{
			x_deg = (rad * 180 / M_PI);
			return 0;
		}
		double showdata()
		{
			cout << "in degree : " << x_deg << "In radians : " << x_rad;
		}
		double sintemp(int deg)
		{
			x_rad = sin(x_rad);
			if (deg == 0 || int(deg) % 90 == 0)
				return int(x_rad);
			else {
				return double(x_rad);
			}
		}
		double costemp(int deg)
		{
			x_rad = cos(x_rad);
			if (deg == 0 || int(deg) % 90 == 0)
				return int(x_rad);
			else {
				return double(x_rad);
			}
			
		}
	};
	

	double Calculator::Calculate(double x, char opr, double y)
	{
		switch (opr)
		{
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			if (x == 0 && y == 0)
				cout << "Indeterminant form";
			return x / y;
			
		case '%':
			return int(x) % int(y);
		default:
			if (opr != 'n')
			{
				cout << "wrong input";
			}
			return 0;
		}
	}
	double Calculator::Trig(char opr, double x_deg)
	{
		conv obj1;
		obj1.deg_to_rad(x_deg);
		switch (opr)
		{
		case's':
			obj1.x_rad = sin(obj1.x_rad);
			if (x_deg == 0 || int(x_deg) % 90 == 0)
				return int(obj1.x_rad);
			else {
				return double(obj1.x_rad);
			}
			break;
		case'c':
			obj1.x_rad = cos(obj1.x_rad);
			if (x_deg == 0 || int(x_deg) % 90 == 0)
				return int(obj1.x_rad);
			else {
				return double(obj1.x_rad);
			}
			break;
		case't':
			
			if (x_deg == 0 || int(x_deg) % 90 == 0)
			{
				double temp;
				temp = obj1.costemp(x_deg);
				obj1.x_rad = tan(obj1.x_rad);
				if (temp == 0)
				{
					cout << "Undefined"<<endl;
					return NAN;
				}
				else
				{
					obj1.x_rad = tan(obj1.x_rad);
					return int(obj1.x_rad);
				}
			}
			else if(int(x_deg) % 90 == 0) {
				obj1.x_rad = tan(obj1.x_rad);
				return int(obj1.x_rad);
			}
			else
			{
				obj1.x_rad = tan(obj1.x_rad);
				return double(obj1.x_rad);
			}
			break;
		case 'C':
			//cosec(x)
			double temp;
			temp = obj1.sintemp(x_deg);
			//obj1.x_rad = 1/sin(obj1.x_rad);
			if (temp == 0)
			{
				cout << "undefined"<<endl;
				return NAN;
			}
			else if (int(x_deg) % 90 == 0)
			{
				obj1.x_rad = 1 / sin(obj1.x_rad);
				return int(obj1.x_rad);
			}
			else {
				obj1.x_rad = 1 / (sin(obj1.x_rad));
				return double(obj1.x_rad);
			}
			break;
		case'S':
			
			temp = obj1.costemp(x_deg);
			if (temp == 0)
			{
				cout << "undefined" << endl;
				return NAN;
			}
			if (int(x_deg) % 90 == 0)
			{
				obj1.x_rad = 1 / cos(obj1.x_rad);
				return int(obj1.x_rad);
			}
			else {
				obj1.x_rad = 1 / cos(obj1.x_rad);
				return double(obj1.x_rad);
			}
			break;
		case'T':

			temp = (tan(obj1.x_rad));
			if (temp == 0)
			{
				cout << "undefined" << endl;
				return NAN;
			}
			if (int(x_deg) % 90 == 0)
			{
				obj1.x_rad = 1 / tan(obj1.x_rad);
				return int(obj1.x_rad);
			}
			else if (obj1.x_rad<-M_PI / 2 || obj1.x_rad>M_PI / 2)
			{
				cout << "Invalid Input";
			}
			else {
				obj1.x_rad = 1 / tan(obj1.x_rad);
				return double(obj1.x_rad);
			}
			break;
		default:
			if (opr != 'n')
			{
				cout << "wrong input" << endl;
				return 0;
			}
			break;
			return 0;
		}
	}

	void Calculator::display_user(char tri)//for user ease user can type only s and see Sin written on console
	{
		switch (tri)
		{
		case 's':
			cout << "sin";
			break;
		case'c':
			cout << "cos";
			break;
		case't':
			cout << "tan";
			break;
		case'S':
			cout << "sec";
			break;
		case'C':
			cout << "cosec";
			break;
		case'T':
			cout << "cot";
			break;
		default:
			if (tri == 'n')
			{
				cout << "n";
				break;
			}
			cout << "Enter a correct value" << endl;
			break;
		}
	}


	double Calculator::convert(double value, char convertfrom, char convertinto)
	{
		if (convertfrom == 'k' && convertinto == 'm')//convert from kilometer to miles
		{
			return value * 0.621371;//1km = 0.621371 miles
		}
		else if (convertfrom == 'm' && convertinto == 'k')//convert from miles to kilometers
		{
			return value / 0.621371;//1 miles = 1/0.621371 kilometers
		}
		else if (convertfrom == 'i' && convertinto == 'f')//convert from inches to foots
		{
			return value / 12;//1 inch = 1/12 foot
		}
		else if (convertfrom == 'f' && convertinto == 'i')//convert from foots to inches
		{
			return value * 12;//1 foot = 12 inches
		}
		else if (convertfrom == 'k' && convertinto == 'f')//convert from kilometer to foots
		{
			return value * 3280.84;//1 km = 3280.84 foots
		}
		else if (convertfrom == 'f' && convertinto == 'k')//convert from foots to kilometer
		{
			return value / 3280.84;//1 foot = 1/3280.84 kilometer
		}
		else if (convertfrom == 'm' && convertinto == 'i')//convert from miles to inches
		{
			return value * 63360;//1 mile = 63360 inches
		}
		else if (convertfrom == 'i' && convertinto == 'm')//convert from inches to miles
		{
			return value / 63360;//1 inches = 1/63360 miles
		}
		else if (convertfrom == 'm' && convertinto == 'f')//convert from miles to foots
		{
			return value * 5280;//1 mile = 5280 foots
		}
		else if (convertfrom == 'f' && convertinto == 'm')//convert from foots to miles
		{
			return value / 5280;//1 foot = 1/5280 mile
		}
		else if (convertfrom == 'k' && convertinto == 'i')//convert from kilometer to inches
		{
			return value * 39370.1;//1 kilometer = 39370.1 inches
		}
		else if (convertfrom == 'i' && convertinto == 'k')//convert from inches to kilometers
		{
			return value / 39370.1;//1 inch = 1/39370.1 kilometers
		}
		else//if user input a unit another than the given units
		{
			printf("Invalid Unit\n");
			return value;
		}
	}

	void Calculator::displayuser_conv(char c)
	{
		switch (c)
		{
		case 'm':
				cout << "Miles";
				break;
		case 'k':
				cout << "kilometers";
				break;
		case 'i':
				cout << "Inches";
				break;
		case'f':
			cout << "Feet";
			break;
		default:
			if (c == 'n')
			{
				cout << "n";
				break;
			}
			if (int(c) != 27)
			{
				cout << "wrong input";
			}
			break;
		}
	}

	double Calculator::arctrig(char arcr, double value)
	{
		conv obj1;
		obj1.deg_to_rad(value);
		switch (arcr)
		{
		case's':
			obj1.x_rad = asin(value);
			obj1.rad_to_deg(obj1.x_rad);
			if (value < -1 || value > 1)
			{
				cout << "Undefined\n";
				return NAN;
			}
			else if(value == 0)
			{
				int temp = 0;
				return temp;
			}
			else
			{
				return double(obj1.x_deg);
			}
			break;
		case'c':
			obj1.x_rad = acos(value);
			obj1.rad_to_deg(obj1.x_rad);
			if (value < -1 || value > 1)
			{
				cout << "Undefined\n";
				return NAN;
			}
			else if (value == 0)
			{
				int temp = 0;
				return temp;
			}
			else
			{
				return double(obj1.x_deg);
			}
			break;
		case't':
			obj1.x_rad = atan(value);
			obj1.rad_to_deg(obj1.x_rad);
			return double(obj1.x_deg);
			break;
		/*case 'C':
			//cosec(x)
			double temp;
			temp = obj1.sintemp(x_deg);
			//obj1.x_rad = 1/sin(obj1.x_rad);
			if (temp == 0)
			{
				cout << "undefined" << endl;
				return NAN;
			}
			else if (int(x_deg) % 90 == 0)
			{
				obj1.x_rad = 1 / sin(obj1.x_rad);
				return int(obj1.x_rad);
			}
			else {
				obj1.x_rad = 1 / (sin(obj1.x_rad));
				return double(obj1.x_rad);
			}
			break;
		case'S':

			temp = obj1.costemp(x_deg);
			if (temp == 0)
			{
				cout << "undefined" << endl;
				return NAN;
			}
			if (int(x_deg) % 90 == 0)
			{
				obj1.x_rad = 1 / cos(obj1.x_rad);
				return int(obj1.x_rad);
			}
			else {
				obj1.x_rad = 1 / cos(obj1.x_rad);
				return double(obj1.x_rad);
			}
			break;
		case'T':

			temp = (tan(obj1.x_rad));
			if (temp == 0)
			{
				cout << "undefined" << endl;
				return NAN;
			}
			if (int(x_deg) % 90 == 0)
			{
				obj1.x_rad = 1 / tan(obj1.x_rad);
				return int(obj1.x_rad);
			}
			else if (obj1.x_rad<-M_PI / 2 || obj1.x_rad>M_PI / 2)
			{
				cout << "Invalid Input";
			}
			else {
				obj1.x_rad = 1 / tan(obj1.x_rad);
				return double(obj1.x_rad);
			}
			break;
		default:
			if (arcr != 'n')
			{
				cout << "wrong input" << endl;
				return 0;
			}
			break;
			return 0;*/
		}
	}

	void Calculator::displayuser_arctrig(char artr)
	{
		switch (artr)
		{
		case 's':
			cout << "arcsin";
			break;
		case'c':
			cout << "arccos";
			break;
		case't':
			cout << "arctan";
			break;
		case'S':
			cout << "arcsec";
			break;
		case'C':
			cout << "arccosec";
			break;
		case'T':
			cout << "arccot";
			break;
		default:
			if (artr == 'n')
			{
				cout << "n";
				break;
			}
			cout << "Enter a correct value" << endl;
			break;
		}
	}