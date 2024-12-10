#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Doctor
{
    string Id;
    string Specializare;
    vector<string> prob;
    int prob_rez = 0;
    int timeLeft = 8 ;
};
struct Problem
{
    string Prob;
    string Specializare;
    int time;
    int severity;

    bool operator<(const Problem& p2 ) const
    {
        return severity < p2.severity;
         
    }
};
int main()
{

    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;
    int time, severity;
    
    inFile >> no_problems;
    Problem vecProb;
    Problem probt;
    vector<Doctor> vecDoc;
    priority_queue<Problem>probQ;


    for (int i = 0; i < no_problems; i++)
    {
        inFile >> vecProb.Prob;
        inFile >> vecProb.Specializare;
        inFile >> vecProb.time;
        inFile >> vecProb.severity;

        probQ.emplace(vecProb);
        //probt = probQ.top();
        //cout << probt.time;

    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
       // cout << name << ' ' << speciality << '\n';
        vecDoc.push_back({ name,speciality });
    }
    int nr_probrez = 0;

    while(probQ.size()!=0){
        probt = probQ.top();
        probQ.pop();
        for (int j = 0; j < vecDoc.size(); j++) {
            if (probt.Specializare == vecDoc[j].Specializare && probt.time <= vecDoc[j].timeLeft) {
                vecDoc[j].timeLeft -= probt.time;
                vecDoc[j].prob_rez++;
                vecDoc[j].prob.push_back(probt.Prob);
                break;
            }
        }
        
    }
    for (int i = 0; i < sizeof(vecDoc);i++) {
        if (vecDoc[i].prob_rez != 0) {
            cout << vecDoc[i].Id <<" " << vecDoc[i].prob_rez<< " " ;
            for (int j = 0; j < vecDoc[i].prob_rez; j++) {
                cout << vecDoc[i].prob[j]<< " ";
            }
            cout << endl;
        }

    }
   /*
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
    */
    return 0;
}