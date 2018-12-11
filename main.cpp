#include <cstdlib>
#include <cctype>
#include <stdio.h>
#include <stdarg.h>
#include <fstream>
#include <iostream>

using namespace std;

int countLine(std::istream& ins);
int countChar(std::istream& ins);

int main()///opens a file based on user input and calls the functions to count the characters and lines
{
    ifstream fin;
    ofstream fout;
    string filename;///name of the file to open with txt

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
    else///if no filename entered, it runs the default
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

int countLine(std::istream& ins)///counts the number of lines in a file
{
    int lCount=1; ///number of lines counted
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
int countChar(std::istream& ins) ///Counts the number of characters
{
    int cCount=0;///number of characters counted
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
