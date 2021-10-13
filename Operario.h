#ifndef OPERARIO_H
#define OPERARIO_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Operative
{
	friend istream& operator>>(istream&in, Operative&); //Flujo de datos de entrada
	friend ostream& operator<<(ostream& out, Operative);  //Flujo de datos de salida
	friend void MenuType();
public:
	Operative();
	~Operative();
	float Average();
	float Bonification();
	float PayNet();
	float ProyectBon();
private:
	int WorkDays, OperatorType;
	string Name;
	int ExtraHours[31];

};


#endif
