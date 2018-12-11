/*!
    *This program opens a file based on user input and calls the functions to count the characters and lines.
*/


#include <cstdlib>
#include <cctype>
#include <stdio.h>
#include <stdarg.h>
#include <fstream>
#include <iostream>

using namespace std;

int countLine(std::istream& ins);
int countChar(std::istream& ins);


int main()
{
    ifstream fin;
    ofstream fout;
    //!name of the file to open (with .txt extension)
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
    //!if no filename entered, it runs the default
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
//!counts the number of lines in a file
int countLine(std::istream& ins)
{
    //!number of lines counted
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
//!Counts the number of characters
int countChar(std::istream& ins)
{
    //!number of characters counted
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
