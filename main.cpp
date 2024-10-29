#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Doctor
{
    string Id;
    string Specializare;
};
struct Problem
{
    string Prob;
    string Specializare;
};
int main()
{

    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;
    
    inFile >> no_problems;
    vector<Problem> vecProb;
    vector<Doctor> vecDoc;


    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        cout << name << ' ' << speciality << '\n';
        vecProb.push_back({ name,speciality });

    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        cout << name << ' ' << speciality << '\n';
        vecDoc.push_back({ name,speciality });
    }
    
    for (auto it1 = begin(vecProb); it1 != end(vecProb); it1++)
    {
        int i = 0;
        for (auto it = begin(vecDoc); it != end(vecDoc); it++)
        {
            if ((*it).Specializare == (*it1).Specializare) 
            {
                cout << (*it1).Prob << " Acceptat"<<endl;
                i = 1;
            }

        }
        if (i == 0)
        {
            cout << (*it1).Prob << " Respins" << endl;
        }
    }
    return 0;
}