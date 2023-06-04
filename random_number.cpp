#include <iostream> 
#include <time.h>

#include <cstdlib>
#include <ctime>

//#include <time.h>
#include <stdlib.h>
using namespace std;

// Function to get the random number between 8 and 64
int getRandomNumber() {
	srand(time(NULL));
	return (rand() % 56 + 8);
}

int initializeRandomNumber() {
    // Initializing random number generator 
    srand(time(0));
    // Generating random number between 8 and 64
    int randomNumber = rand() % 57 + 8;

    return randomNumber;
}

int randomNumber(){
    // Initialize random number seed
    srand(static_cast<unsigned>(time(nullptr)));

    // Generate random number between 8 and 64
    int randomNumber = rand() % (64 - 8 + 1) + 8;

    // Return the random number
    return randomNumber;
}
// Driver code 
int main()
{
    //Prompt 1:
    for (int i = 1; i <= 64; i++) {
        cout << getRandomNumber() << " ";
    }
    cout << endl;
    //Prompt 2:
    for (int i = 1; i <= 64; i++)
    {
        cout << "Random number between 8 and 64: " << initializeRandomNumber() << endl;
    }
        
    //Prompt 3:
        const int MAX_SIZE = 10;
        int numbers[MAX_SIZE]; // Array of numbers

        /* Initializing random number generator */
        srand(time(NULL));
        int lower = 8, upper = 64;
        int num;

        /* Initializing the array with random numbers */
        for (int i = 0; i < MAX_SIZE; i++) {
            num = (rand() % (upper - lower + 1)) + lower;
            numbers[i] = num;
        }

        /* Displaying the array */
        cout << "Displaying the array: ";
        for (int i = 0; i < MAX_SIZE; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;

    system("pause");
	return 0;
}
