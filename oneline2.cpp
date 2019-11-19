//C++ program to take in msfvenom's shellcode and output a formated, oneline file
//Usage oneline.exe rawShellCodeInput formatedShellCodeOutput
//Created by Skotizo 06-27-19
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int getSize(string);
void getData(string filename, string dataIn[]);
void writeData(string filename,string data[],int length);
int main(int argc, const char *argv[])
{
    cout<<"Usage: "<< argv[0] <<" <inputFilename> <outputFilename>\n\n\n";
    string inputName = argv[1];
    string outputName = argv[2];




    int size = getSize(inputName);
    cout << ">  Input Filename: " << inputName << endl;
    cout << ">  Size: " << size << endl;

    int arrSize = size/20;
    string bytes[arrSize];

    getData(inputName,bytes);
    writeData(outputName,bytes,arrSize);





    return 0;
}
int getSize(string filename)
{


    ifstream infile(filename, ios::binary);
    infile.seekg(0, ios::end);
    return infile.tellg();
    infile.close();
}
void getData(string filename,string dataIn[])
{
    ifstream infile;
    infile.open(filename,ios::in);
    int total = 0;
	while(infile)
    {
        infile >> dataIn[total];
        total++;
    }
    infile.close();
    //for(int i=0; i < total; i++)
    //{
    //    cout << "  " << dataIn[i] << endl;
    //}
}
void writeData(string filename,string data[],int length)
{
    fstream outfile(filename,ios::out);
    for(int i = 0; i < length; i++)
    {
        outfile << data[i];
    }
}
