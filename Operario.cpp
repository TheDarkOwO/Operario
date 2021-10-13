#include "Operario.h"

Operative::Operative()
{
	Name = "";
	WorkDays = 31;
	for (int i = 0; i < 31; i++)
	{
		ExtraHours[i] = 0;
	}
	OperatorType = 1;
}
Operative::~Operative()
{

}

ostream& operator<<(ostream& Data, Operative Aux)
{
	string OperatorTypeP[] = { "Supervisor employee","Plant employee","Specialized employee" };
	Data << "Name of the operator: ";
	Data << Aux.Name << endl;
	Data << "Worked days: ";
	Data << Aux.WorkDays << endl;
	Data << "Average extra hours: ";
	Data << Aux.Average() << endl;
	cout << "Operator type: ";
	cout << OperatorTypeP[Aux.OperatorType-1] << endl;
	Data << "Pay net: ";
	Data << Aux.PayNet() << endl;
	Data << "Bonus: ";
	Data << Aux.Bonification() << endl << endl;

	return Data;
}
void MenuType()
{
	cout << "|||   Operator type menu   |||\n\n";
	cout << "\n1. Supervisor employee.";
	cout << "\n2. Plant employee.";
	cout << "\n3. Specialized employee.";
	cout << "\n\nWrite the type of operator: ";
}

istream& operator>>(istream& in, Operative& Aux)
{
	cout << "Name of the operator: ";
	in >> Aux.Name;
	system("cls");
	cout << "Worked days: ";
	
	do
	{
		in >> Aux.WorkDays;
		if (8 <= Aux.WorkDays && Aux.WorkDays <= 31)
		{
			for (int i = 0; i < Aux.WorkDays; i++)
			{
				cout << "\nHow many extra hours in the " << i + 1 << " day: ";
				in >> Aux.ExtraHours[i];
			}
			break;
		}
		else
		{
			cout << "Days must be between 8 and 31\n\n";
			cout << "Write again the Worked days: ";
		}
	} while (!(8 <= Aux.WorkDays && Aux.WorkDays <= 31));
	system("cls");
	do
	{
		MenuType();
		in >> Aux.OperatorType;
		if ((1 <= Aux.OperatorType && Aux.OperatorType <= 3))
		{
			break;
		}
		else
		{
			cout << "Invalid input\n\n";
			cout << "Write something to return\n";
			cin.ignore();
			cin.get();
			system("cls");
		}
	} while (!(1 <= Aux.OperatorType && Aux.OperatorType <= 3));
	system("cls");
	return in;
}
float Operative::Average()
{
	float Average = 0;
	for (int i = 0; i < WorkDays; i++)
	{
		Average+=ExtraHours[i];
	}
	Average = Average / WorkDays;
	return Average;
}

float Operative::Bonification()
{
	if (Average() > 4)
	{
		int BaseB = 0, NumAux;
		for (int i = 0; i < 31; i++)
		{
			NumAux = ExtraHours[i] - 4;
			if (NumAux >= 0)
				BaseB += NumAux;
		}
		switch (OperatorType)
		{
		case 1:
			return BaseB * (80 * 0.7);
		case 2:
			return BaseB * (60 * 0.5);
		case 3:
			return BaseB * (100 * 0.3);
		default:
			break;
		}
	}
	return 0;
}
float Operative::PayNet()
{
	int AuxHours = 0;
	for (int i = 0; i < WorkDays; i++)
	{
		AuxHours += ExtraHours[i];
	}
	switch (OperatorType)
	{
	case 1:
		return (WorkDays * 8 * 80) + ((80 * 1.3) * AuxHours) + Bonification();
	case 2:
		return (WorkDays * 8 * 60) + ((60 * 1.5) * AuxHours) + Bonification();
	case 3:
		return (WorkDays * 8 * 100) + ((100 * 1.7) * AuxHours) + Bonification();
	default:
		break;
	}
	return 0;
}
/*cin.ignore();
  cin.get();
  system("cls");*/