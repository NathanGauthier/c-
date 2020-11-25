#include <iostream>
using namespace std;

char box[10] = { 'o','1','2','3','4','5','6','7','8','9' };


void board()
{
    system("cls");
    cout << "\n\n\t\t\tTic Tac Toe\n\n" << endl;
    cout << "\t\t aligner 3 fois votre signe,\n" << endl;
    cout << "\thorizontalement, verticalement, ou diagonalement\n " << endl;
    cout << " \t\t pour gagner la partie. \n\n" << endl;



    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << box[1] << "  |  " << box[2] << "  |  " << box[3] << endl;

    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;

    cout << "\t\t  " << box[4] << "  |  " << box[5] << "  |  " << box[6] << endl;

    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;

    cout << "\t\t  " << box[7] << "  |  " << box[8] << "  |  " << box[9] << endl;

    cout << "\t\t     |     |     \n\n" << endl << endl;
}


int checkwin()
{
    if (box[1] == box[2] && box[2] == box[3])

        return 1;
    else if (box[4] == box[5] && box[5] == box[6])

        return 1;
    else if (box[7] == box[8] && box[8] == box[9])

        return 1;
    else if (box[1] == box[4] && box[4] == box[7])

        return 1;
    else if (box[2] == box[5] && box[5] == box[8])

        return 1;
    else if (box[3] == box[6] && box[6] == box[9])

        return 1;
    else if (box[1] == box[5] && box[5] == box[9])

        return 1;
    else if (box[3] == box[5] && box[5] == box[7])

        return 1;
    else if (box[1] != '1' && box[2] != '2' && box[3] != '3'
        && box[4] != '4' && box[5] != '5' && box[6] != '6'
        && box[7] != '7' && box[8] != '8' && box[9] != '9')

        return 0;
    else
        return -1;
}


int main()
{
    int player = 1;
    int i;
    int choice;

    char sign;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        cout << " \t Player " << player << ", faites votre choix  ";
        cin >> choice;

        sign = (player == 1) ? 'X' : 'O';

        if (choice == 1 && box[1] == '1')

            box[1] = sign;
        else if (choice == 2 && box[2] == '2')

            box[2] = sign;
        else if (choice == 3 && box[3] == '3')

            box[3] = sign;
        else if (choice == 4 && box[4] == '4')

            box[4] = sign;
        else if (choice == 5 && box[5] == '5')

            box[5] = sign;
        else if (choice == 6 && box[6] == '6')

            box[6] = sign;
        else if (choice == 7 && box[7] == '7')

            box[7] = sign;
        else if (choice == 8 && box[8] == '8')

            box[8] = sign;
        else if (choice == 9 && box[9] == '9')

            box[9] = sign;
        else
        {
            cout << "la case est deja utilise ";

            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();

        player++;
    } while (i == -1);
    board();
    if (i == 1)

        cout << "\tPlayer " << sign  << " win ";
    else
        cout << "\t egalite ";

    cin.ignore();
    cin.get();
    return 0;
}


