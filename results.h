#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

string getFinalResult(bool totalL1, bool totalL2, bool totalL3, bool totalL4)
{
    //TODO Compounding into a 4 bit int
    string finalResult = "";

    if (totalL1)
    {
        finalResult += "1";
    }
    else
    {
        finalResult += "0";
    }

    if (totalL2)
    {
        finalResult += "1";
    }
    else
    {
        finalResult += "0";
    }

    if (totalL3)
    {
        finalResult += "1";
    }
    else
    {
        finalResult += "0";
    }

    if (totalL4)
    {
        finalResult += "1";
    }
    else
    {
        finalResult += "0";
    }

    return finalResult;
}

void displayFinalResult(string result)
{
    string filename = "results/" + result + ".txt";

    fstream resultFile;
    resultFile.open(filename, ios::in);

    if (!resultFile) //* Making sure the file is found
    {
        cout << "File not found!";
        exit(1);
    }

    static string results[6];
    string temp;
    int count = 0;

    if (resultFile.is_open())
    {
        while (getline(resultFile, temp))
        {
            results[count] = temp;
            count++;
        }
    }

    //* Displaying
    cout << "Your personality type is: "
         << results[0]
         << "\n\n"
         << results[1];
}