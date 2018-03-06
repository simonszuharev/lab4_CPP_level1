#include <iostream>
#include <iomanip>
#include <cstdlib>


using namespace std;

/*Write a class named Coin. The Coin class should have the following private member variables:

A string called sideUp. The string will contain either "Heads" or "Tails" indicating the side of the coin that is facing up.
An integer called headsCount. The integer will contain the total number of coin tosses in which the side up was "Heads".
An integer called tailsCount. The integer will contain the total number of coin tosses in which the side up was "Tails".
The Coin class should have the following pubic member functions:

A default constructor that initializes the sideUp, headsCount, and tailsCount variables.
Integer member functions getHeadsCount, getTailscount,
and getTossCount which return the current values of headsCount, tailsCount, headsCount+tailsCount, and sideUp respectively.
A string member function getSideUp which returns the current value of sideUp.
A void member function tossCoin that simulates the tossing of the coin and updates the sideUp, headsCount, and tailsCount member variables.
Write a program that demonstrates the Coin class. The program should create an instance of the class,
"toss" the coin, and display the side that is currently facing up. Then, ask if the user wants to toss the coin again.
If not, terminate the program. If so, toss the coin again and display the side that is currently facing up,
 the total number of tosses in which the side up was "Heads" and the total number of tosses in which the side up was "Tails".

Develop the class definition, implementation, and test program in a single file.
Submit your solution (main.cpp) as the file lab4_annnnnnn.cpp where annnnnnn is your ACC student identification number.*/

class Coin{

    private:
        int heads = 0;
        int tails = 0;
        unsigned int headsCount = 0;
        unsigned int tailsCount = 0;
        string sideUp;

    public:
            unsigned int getHeadsCount() {
                return headsCount;
		}

            unsigned int getTailscount() {
                return tailsCount;
		}
            unsigned int getTossCount(){
                return headsCount+tailsCount;
        }

        string getSideUp(){
                return sideUp;
            }
         void tossCoin()
        {
            if(rand() % 2) 
            {   sideUp = "Heads";
                ++headsCount;
            }
            else
            {   sideUp = "Tails";
                ++tailsCount;
            }

    }
};

int main()
{
    char repeat = 'y';

    Coin toss;

    cout << "Coin Toss Program" << endl;
    cout << "-----------------" << endl;

    while(repeat != 'n'){
    toss.tossCoin();
    cout << "Side up is '" << toss.getSideUp() << "' after " << toss.getTossCount() << " tosses. ";
    cout << "Total heads: " << toss.getHeadsCount() << ". Total tails: " << toss.getTailscount() << endl;
    cout << "Toss the coin (y/n)?" << endl;
    cin >> repeat;
    }
    return 0;
}

