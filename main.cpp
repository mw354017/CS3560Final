#include <cstdlib>
#include <cctype>
#include <stdio.h>
#include <stdarg.h>
#include <fstream>
#include <iostream>

using namespace std;

typedef unsigned long count_t;  /* Counter type */

/* Current file counters: chars, words, lines */
count_t ccount;
count_t wcount;
count_t lcount;

/* Totals counters: chars, words, lines */
count_t total_ccount = 0;
count_t total_wcount = 0;
count_t total_lcount = 0;


int countLine(std::istream& ins);
int countChar(std::istream& ins);

int main()
{
    ifstream fin;
    ofstream fout;
    string filename;

    cout<<"Begin by entering your filename: \n (enter nothing for default case)\n";
    getline(cin,filename);
    if(filename!="")
    {
        fin.open(filename.c_str());
        if(!fin.fail())
        {
            countLine(fin);
            fin.close();
        }
        else
        {
            cout<<"No file named " << filename << "\n";
        }
        fin.open(filename.c_str());
        if(!fin.fail())
        {
            countChar(fin);
            fin.close();
        }
        else
        {
            cout<<"No file named " << filename << "\n";
        }
    }
    else
    {
        filename = "Ohio_University.txt";
        fin.open(filename.c_str());
        if(!fin.fail())
        {
            countLine(fin);
            fin.close();
        }
        else
        {
            cout<<"No file named " << filename << "\n";
        }
        filename = "Athens.txt";
        fin.open(filename.c_str());
        if(!fin.fail())
        {
            countChar(fin);
            fin.close();
        }
        else
        {
            cout<<"No file named " << filename << "\n";
        }
    }
}

int countLine(std::istream& ins)
{
    int lCount=1;
    while(!ins.eof())
    {
        if(ins.peek()!= '\n' )
        {
            ins.ignore();
        }
        else
        {
            lCount++;
            ins.ignore();
        }
    }
    cout<< lCount<< " Lines\n";
    return lCount;
}
int countChar(std::istream& ins)
{
    int cCount=0;
    while(!ins.eof())
    {
        if(ins.peek()== '\n' )
        {
            ins.ignore();
        }
        else
        {
            cCount++;
            ins.ignore();
        }
    }
    cout<< cCount<< " Characters\n";
    return cCount;
}
