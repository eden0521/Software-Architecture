#ifndef FILE_IO_H
#define FILE_IO_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class FileIO{
public:
    vector<vector<string>> fileInput(string fileName)
    {
        fstream f_input;
        f_input.open(fileName.c_str());
        vector<vector<string>> vecData;
        if( !f_input )
            cerr<<"Fail to open file(ex:input.txt)."<<endl;
        else{
            char ch[10000];
            while( f_input.getline(ch,5000) ){
                string str = string(ch);
                search(str,vecData);
            }
        }
        f_input.close();
        return vecData;
    }

    void fileOutPut(string fileName, string saveData)
    {
        fstream f_output;
        f_output.open(fileName.c_str(),fstream::out | fstream::trunc);
        if(!f_output)
            cerr<<"Fail to open file(ex:output.txt)."<<endl;
        else{
            f_output<<saveData;
        }
        f_output.close();
    }

private:
    void search(string str,vector<vector<string>> &vecData){
        vector<int> position;
        position.push_back(0);
        size_t found = str.find("|@$#|");
        position.push_back(static_cast<int>(found-1));
        if (found!=string::npos){
            for(int i=0;i<5;i++){
                position.push_back( static_cast<int>(found+5) );
                found = str.find("|@$#|",found+5);
                if (found!=string::npos){
                    position.push_back( static_cast<int>(found-1) );
                }
                else{
                    break;
                }
            }
        }

//        vector<int>::iterator it;
//        for(it = position.begin();it != position.end(); ++it){
//            cout<<"pos = "<<(*it)<<endl;
//        }

        vector<string> vecContent;
        for(int i=0;i<12;i=i+2){
            vecContent.push_back( str.substr(position[i],position[i+1]-position[i]+1) );
//            cout<<"str = "<<str.substr(position[i],position[i+1]-position[i]+1)<<endl;
        }
        vecData.push_back(vecContent);
    }
};

#endif // FILE_IO_H
