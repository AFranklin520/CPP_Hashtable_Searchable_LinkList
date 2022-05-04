//Anthony Franklin afranklin18@cnm.edu
//Program to demonstrate the implementation of hash tables and searchable link lists in C++
//04/05/2022
//Driver.cpp

#include <iostream>
#include <iomanip>
#include "Hashtable.h"
#include "FranklinPersonGen/PersonGen.h"

int main()
{
    Date today;
	cout << "Anthony Franklin\nafranklin18@cnm.edu\nFranklinP7\n\n**** Program to demonstrate the implementation of hash tables and searchable link lists in C++ ****\n\n";
    ofstream outputFile("Franklin_P7_log.txt");
    if (outputFile.is_open())
    {
        cout << "Output File OK; Printing to FranklinP7.txt" << endl;
        outputFile << today.GetFormattedDate() << endl;
        outputFile << "Anthony Franklin\nafranklin18@cnm.edu\nFranklinP7\n\n**** Program to demonstrate the implementation of hash tables and searchable link lists in C++ ****\n\n";
        outputFile << "			                    Log file name: Franklin_P7_log.txt\n\nFile for loading the hash table : BJ_Persons2000.txt(2000 Persons)\nFile for searching : BJ_42PersonsToFind.txt(42 Persons)\n\n";
    }
    PersonGen* pg = new PersonGen;
    PersonGen* pgFind = new PersonGen;
    HashTable* hash = new HashTable;

    if (pg->UseFile("BJ_Persons2000.txt"))
    {
        outputFile << "***Inserting Person Objects into our hash table...." << endl;
        for (int i{ 0 }; i < 2000; i++)
        {
            Person* p = pg->GetNewPerson();
            hash->HashFunction(p);
        }
    }
    else
    {
        cout << "[ERROR] Unable to open file!";
    }
    
    int distribution[100] {NULL}; //Array to contain distibution of nodes in our array
    hash->AnalyzeTable(distribution, 100);


    int distMin{ 100 }; //Initializing at 100 since the largest hash can be 99, so the first value in our dist should become the new distMin.
    int distMax{ 0 };
    float mean{ 0.00 }; //mean should definitely be 20, but let's calculate it anyway.
    float var{ 0.00 };
    for (int items : distribution)
    {
        mean += items;
    }
    mean /= 100;
    for (int items : distribution)
    {
        var += pow(items - mean, 2); //variance == (value - mean)^2
        items < distMin ? distMin = items : distMin = distMin;
        items > distMax ? distMax = items : distMax = distMax;
    }
    var /= 100; //Find the mean variance
    var = sqrt(var); //Our stdev == sqrt of var
    outputFile << format("\n****Results of hash...\n\nDistribution:\nMinimum List Length: {}\nMaximum List Length: {}\nAverage List Length: {}", distMin, distMax, mean);
    outputFile << setprecision(3) << "\nStandard Deviation : " << var << endl << endl;

    int count{ 0 };
    int index{ 0 };
    for (int items : distribution)
    {
        double capacity = static_cast<double>(items) / 20;
        if (index < 10) //Fixing whitespace formatting issues with indexes < 10
        {
            if (count == 4)
            {
                outputFile << "\n";
                count = 0;
            }
            outputFile << format("[{}]   {}, ", index, items) << setfill('0') << fixed << setw(4) << setprecision(2) << capacity << "%      ";
            index++;
            count++;
            continue;
        }
        if (count == 4)
        {
            outputFile << "\n";
            count = 0;
        }
        outputFile << format("[{}] {}, ",index, items) << setfill('0') << fixed << setw(4) << setprecision(2) << capacity << "%      ";
        index++;
        count++;
    }

    if (pgFind->UseFile("BJ_42PersonsToFind.txt"))
    {
        for (int i{ 0 }; i < 42; i++)
        {
            Person* temp = pgFind->GetNewPerson();
            string name = temp->GetName();
            outputFile << format("\n\nSearching for: {}", temp->GetFullDesc());
            if (!(hash->GetValue(temp->GetName(), temp->GetBirthDay().GetMonth(), temp->GetBirthDay().GetDay(), temp->GetBirthDay().GetYear(), &temp) == -1))
            {
                outputFile << "\nFound " << temp->GetFullDesc();
            }
            else outputFile << endl << name << "NOT found!";
            
        }
    }
    else
    {
        cout << "[ERROR] Unable to open file!";
    }

    //Cleaning up our resources per good RAII practice
    delete pg;
    delete pgFind;
    delete hash;
    outputFile.close();
    
    cout << "\n********** Thank you for using my program, goodbye! *************\n\n";
	return 0;
}