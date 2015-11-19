#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

#include <locale>
#include "SeparateChaining.h"
using namespace std;

string toLowerCase(string str)
{
  int i=0;
  char c;
  while (str[i])
  {
    c=str[i];
    str[i] = tolower(c);
    i++;
  }
  return str;
}

int main(int argc, char *argv[])
{
    HashTable<string> myDictonary;
    
    string dictName=argv[1];
    string tableType = argv[2];
    string spellCheckFile = argv[3];
    
    // arguement 1 
    if(dictName == "-1")
       dictName = "simple.dict.txt";
    else if(dictName == "-2")
        dictName = "ispell.words.txt";
    else
        cout << "unknown dictonary" <<endl;
    
    ifstream readDict(dictName); 
    if(!readDict.is_open())
    {
        cout << "file not found" << endl;
        return -1 ;
    }
    cout << "dictionary: " << dictName <<endl;
    
    string word;   // insert to dictonary
    while (!readDict.eof()) {
        readDict >> word;
        myDictonary.insert( word);
           
    }    
    readDict.close();
    
    // arguement 2 
    if(tableType =="-chain")
        tableType = "chain";
    else if(tableType =="-probe")
        tableType = "probe";
    else
        cout << "unknown hashTable type" <<endl;
    
     // arguement 3 
    ifstream fin(spellCheckFile);
    if(!fin.is_open())
    {
        cout << "file not found" << endl;
        return -1;
    }
    cout << "file to be checked: " << spellCheckFile <<endl;
    
    int lastindex = spellCheckFile.find_last_of("."); 
    string rawname = spellCheckFile.substr(0, lastindex);
    
    ofstream fout( rawname+".out");
    string temp_word;    // read from the sample txt
    while (!fin.eof()) {
        fin >> temp_word;
        temp_word = toLowerCase(temp_word);
        if (!myDictonary.contains( temp_word))  // check if a word in the dictonary
            fout << temp_word <<endl;
    }    
    fin.close();
    fout.close();
    
    ofstream fout2( rawname+".stat");
    vector<int>count_array = myDictonary.printStats();
    for(int j=0; j<count_array.size();j++)
    {
            if( count_array[j]!=0 )
              fout2<< j << " " << count_array[j] << endl;;
    }
    fout2.close();
   
    return 0;
}