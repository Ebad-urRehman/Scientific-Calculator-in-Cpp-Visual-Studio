#pragma once
class Calculator
{
public: 
	double Calculate(double x, char opr, double y);
	double Trig(char opr, double x);
	double convert(double value, char convert_from, char convert_into);
	void display_user(char tr);
	void displayuser_conv(char con);
	double arctrig(char artr,double x_deg);
	void displayuser_arctrig(char art);
};

