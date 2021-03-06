#include "Operario.h"
void PrincipalMenu();
//En vez de usar 60000, 100000 y 80000. uso 60, 100, 80
//Para usar los valores de dinero estipulados de la actividad, puede multiplicar por 1000 a los resultados

int main()     
{
    Operative Op[10];
    char Option = '0'; int Amount = 0, Aux = 0, AuxOp = 0; float Bonus = 0;
    while (Option != '3')
    {
        PrincipalMenu();
        cin >> Option;
        system("cls");
        switch (Option)
        {
        case '1':
        {
            Aux = 1;
            while (!(1 <= Amount && Amount <= 10))
            {
                cout << "Write the amount of operator you want to register: ";
                cin >> Amount;
                if (1 <= Amount && Amount <= 10)
                {
                    break;
                }
                else
                {
                    cout << "\nNumber must be between 1 and 10\n";
                }
            }
            system("cls");
            for (int i = 0; i < Amount; i++)
            {
                cout << "|||   Operator " << i + 1 << "   |||\n\n";
                cin >> Op[i];
                Bonus += Op[i].Bonification();
            }
            break;
        }
        case '2':
        {
            if (Aux == 1)
            {
                for (int i = 0; i < Amount; i++)
                {
                    cout << "|||   Operator " << i + 1 << "   |||\n\n";
                    cout << Op[i];
                }
                cout << "Total bonus: ";
                cout << Bonus << endl;
                cin.ignore();
                cin.get();
                system("cls");
            }
            else
            {
                cout << "You need to enter the data before priting it\n";
                cin.ignore();
                cin.get();
                system("cls");
            }
            break;
        }
        case '3':
            exit(0);
        default:
            cout << "Invalid option\n";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }

    }
    return 0;
}

void PrincipalMenu()
{
    cout << "|||   Principal menu   |||\n";
    cout << "\n1. Register operators";
    cout << "\n2. Print Data";
    cout << "\n3. End program.";
    cout << "\n\n\nChoose one option: ";
}
