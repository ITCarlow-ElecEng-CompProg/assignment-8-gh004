/**

23/10/17
Gearoid Hanrahan
Operational Amplifier Circuits

Exercise 8

*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdio>
#include <windows.h>

using namespace std;

using namespace std;

    char displayMenu(void);
    void invVals (void);
    void noninvVals (void);
    //* pointer functions */
    void inverting(double *avPtr, double rf, double rin, double *voutPtr, double vin);
    void noninverting(double *avPtr, double r2, double r1, double *voutPtr, double vin);

int main(void)
{
    char choice;
    do
    {
        choice = displayMenu();

        switch (choice)
        {
            case 'a':       invVals ();
                            break;

            case 'b':       noninvVals ();
                            break;

            case 'q':       system("cls");
                            cout <<"Goodbye...\n";
                            break;

            default:	    cout <<"\nInvalid input, press any key to continue..." ;
                            fflush(stdin);
                            getchar();
                            break;
    }
}
    while (choice != 'q' );

    return 0;
}
char displayMenu(void)
{
    char choice;
    system("cls");
    cout <<"Operational Amplifier Circuits" ;
    cout <<"\n\nPress 'a' for an inverting amplifier ...";
    cout <<"\nPress 'b' for a non-inverting amplifier ...";
    cout <<"\nPress 'q' to quit ...\n\nChoice: ";
    fflush(stdin);
    choice = getchar();
    return choice;
}

void invVals ()
{
    /** turns previous screen off */
    system("cls");

    double vcc = -1, vee = 1, vin, rin = 0, rf = 0, av, vout;
    double *avPtr = &av, *voutPtr = &vout;

    cout << "Inverting Amplifier Circuit\n\n" ;
    while (rin <= 0)
    {
        cout << "\nRin :\t";
        cin >> rin;
    }
    /** Ensuring positive values for rf in a while loop */
    while (rf <= 0)
    {
        cout << "\nRf :\t";
        cin >> rf;
    }
    /** Ensuring positive values for vcc in a while loop */
    while (vcc <= 0)
    {
        cout << "\nVcc :\t";
        cin >> vcc;
    }
    /** Ensuring negative values for vee in a while loop */
    while (vee >= 0)
    {
        cout << "\nVee :\t";
        cin >> vee;
    }
    /** Reading in values for vin */
    cout << "\nVin :\t";
    cin >> vin;

    inverting (avPtr, rf, rin, voutPtr, vin);
    cout << "\nAv =\t" << av << "\n\nVout =\t" << vout;
    if(vout >= vee || vout <= vcc)
    {
        if(vin <= 0)
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vcc ;
        }
        else
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vee ;
        }
    }
    cout << "\n\nPress enter to return to the main menu..." ;
    fflush(stdin);
    getchar();
    /** returns something back to main functon */
    return ;
}
void inverting(double *avPtr, double rf, double rin, double *voutPtr, double vin)
{
    *avPtr = -(rf/rin);

    *voutPtr = *avPtr * vin;
    /** returning no value but have assigned a value in each pointers address */
    return ;
}
void noninvVals ()
{
    system("cls");
    /** declare variables */
    double vcc = -1, vee = 1, vin, r1 = 0, r2 = 0, av, vout;
    double *avPtr = &av, *voutPtr = &vout;
    cout << "Non - Inverting Amplifier Circuit\n\n" ;
    while (r1 <= 0)
    {
        cout << "\nR1 :\t";
        cin >> r1;
    }
    /** Ensuring positive values for r2 in a while loop */
    while (r2 <= 0)
    {
        cout << "\nR2 :\t";
        cin >> r2;
    }
    /** Ensuring positive values for vcc in a while loop */
    while (vcc <= 0)
    {
        cout << "\nVcc :\t";
        cin >> vcc;
    }
    /** Ensuring neg values for vee in a while loop */
    while (vee >= 0)
    {
        cout << "\nVee :\t";
        cin >> vee;
    }
    cout << "\nVin :\t";
    cin >> vin;

    /** calling subfunction */
    noninverting (avPtr, r2, r1, voutPtr, vin);
    cout << "\nAv =\t" << av << "\n\nVout =\t" << vout ;
    if(vout >= vee || vout <= vcc)
    {
        if(vin >= 0)
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vcc ;
        }
        else
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vee ;
        }
    }
    cout << "\n\nPress enter to return to the main menu..." ;
    fflush(stdin);
    getchar();
    return ;
}
void noninverting(double *avPtr, double r2, double r1, double *voutPtr, double vin)
{
    *avPtr = 1 + (r2 / r1);

    *voutPtr = *avPtr * vin;
    /** returning no value but have assigned a value in each pointers address */
    return ;
}
