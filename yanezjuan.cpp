#include <iostream>
 using namespace std;
 int IsPrime(int number);

int main ()
 {
 int userInput;
 int counter = 0;
 float total_values = 0;
 float average = 0;
 cout << "PRIME NUMBERS (numeros primos) \nMade by: Juan Aguilera\n";
 cout << "Enter the number of prime numbers to be known: ";
 cin >> userInput;
 cin.ignore();

 if (userInput < 1 || userInput > 1000)
 {
 cout << "Please put one number between 1 and 1000" << en
dl;
 }
 else
 {
 
ut
 for(int k = 2; userInput > 0 ; k++)
 {
 if((IsPrime(k) == 1))
 {
 cout << k << " ";
 counter++;
 total_values += k;
 }
 if(counter == userInput)
 {
 break;
 }
 }
 }
 average = total_values / counter;
 cout << "\n\nthe average of the " << userInput << " prime numbers iss: " <<average << endl;
 cout << "\nPress enter to exit" << "\n" << endl;
 cin.get();
 return 0;
 }
 //Function to check if one number is prime or not
 int IsPrime(int number)
 {
 int Prime = 1;
 if (number < 2)
 {
 Prime = 0;
 }
 else
 {
 if (number == 2 || number == 3)
 {
 Prime = 1; //That means that prime is true,the number is pri
me
 }
 else
 {
 if(number%2==0)
 {
 Prime = 0;
 }
 else
 {
 for(int k=3; k < number/2 ; k+=2 )
 {
 if( number%k == 0)
 {
 Prime = 0;
 break;
 }
 }

}

}

}
 return Prime;

}
