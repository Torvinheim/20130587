#include <iostream>
#include <algorithm>
#include<string>
#include <stdlib.h>
#include <ctime>

using namespace std;

// PhoneNumbers.h
class PhoneNumbers
{
private:
    int N_services;
    int *Frequency;
    int *PhoneNumbersArray;
public:
    PhoneNumbers();
    PhoneNumbers(int N);
    ~PhoneNumbers();
    void inputData();
    void printFrequency();
    void generatePhoneNumbers();
};

// PhoneNumbers.cpp

//constructor
PhoneNumbers::PhoneNumbers()
{
    Frequency= new int[N_services];
}
//constructor
PhoneNumbers::PhoneNumbers(int N)
{
    N_services=N;
    Frequency= new int[N];
}
//destructor
PhoneNumbers::~PhoneNumbers()
{
    cout<<"The destructor is invoked automatically, Deleting frequency array .........";
    delete [] Frequency;
}
// to input data
void PhoneNumbers::inputData()
{
    cout<<"Enter No. of services: "<<endl;
    cin>>N_services;
    cout<<"Enter frequency of services: "<<endl;
    for(int i=0; i<N_services; i++)
    {
        cin>>Frequency[i];
    }
}
//print frequency
void PhoneNumbers::printFrequency()
{
    for(int i=0; i<N_services; i++)
    {
        cout<<Frequency[i]<<" "<<endl;
    }
}

//generate random phone numbers to N services with respect to that more frequent service dialing takes shorter phone numbers
void PhoneNumbers::generatePhoneNumbers()
{
    int min=1, max=1000;
    srand((unsigned) time(0));// to generate different phone numbers each time we run the program
    PhoneNumbersArray= new int[N_services];
    for(int i=0; i<N_services; i++)
    {
        /*Generate a random number between "min" and "max" using rand() function*/
        int new_phone_number=(rand() % max) + min;
        if(i==0)// no need to check the first number as it isn't substring of another string
        {
            PhoneNumbersArray[i]=new_phone_number;
        }
        else
        {
            string s = to_string(new_phone_number);
            //cout<<"\nstring to search: "<<s<<endl;
            //cout<<"array of strings to search: ";
            //for(int k=0; k<=i-1; k++)
            //  cout<<PhoneNumbersArray[k]<<" ";
            //cout<<endl;
            //make sure that each phone number isn't substring of another number otherwise, generate another random number
            for(int k=0; k<=i-1; k++)
            {
                size_t found = s.find(to_string(PhoneNumbersArray[k]));//return index, std:string::find to find the first occurrence of given string. If returned position is 0, then it will make sure that our main string starts with the given string.
                //  cout<<"string: "<<s<<", arr["<<k<<"]= "<<PhoneNumbersArray[k]<<",  found= "<<found<<endl;
                if(found == 0) // there is a string that start with another string
                {
                    new_phone_number=(rand() % 6) + 1;
                    s = to_string(new_phone_number);
                    k=-1;
                    //    cout<<"new rand and start at"<<k<<": "<<s<<endl;
                }
            }
            PhoneNumbersArray[i]=new_phone_number;
            //cout<<"\nphone numbers until now"<<endl;
            //for(int h=0; h<=i; h++)
            //{
            //   cout<<PhoneNumbersArray[h]<<" ";
            //}
            //cout<<endl;
        }
    }//end i
    //Assigning Max frequencies to shorter phone numbers
    sort(PhoneNumbersArray, PhoneNumbersArray + N_services);//sort in ascending order
    sort(Frequency, Frequency + N_services, greater<int>());//descending sort() takes a third parameter that is used to specify the order in which elements are to be sorted. We can pass “greater()” function to sort in descending order.
    cout<<"PhoneNumbersArray <---> Frequency per year"<<endl;
    for(int i=0; i<N_services; i++)
    {
        cout<<PhoneNumbersArray[i]<<"    <--->    "<<Frequency[i]<<endl;
    }
}

//main.cpp

int main()
{
    cout<<"********************************   Phone numbers   *******************************\n\n";
    PhoneNumbers p;
    p.inputData();
    cout<<"Output\n";
    p.generatePhoneNumbers();
    return 0;
}
