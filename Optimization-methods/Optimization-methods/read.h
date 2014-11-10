//
//  read.h
//  Optimization-methods
//
//  Created by ZN-MAC on 10/11/14.
//  Copyright (c) 2014 ZHANG Nan. All rights reserved.
//

#ifndef Optimization_methods_read_h
#define Optimization_methods_read_h

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>

using namespace std;

class view
{
public:
    vector <double> c;
    double a[256][256];
    vector <double> d;
    int tempar=0;
    int ta=0;

    
    char temp[10];
    int trk = 0;
    int tracker_num = 0;
    view(){
        
        char buffer[256];
        fstream readfile;
        readfile.open("test.txt", ios::in);
        while(!readfile.eof())
        {
            readfile.getline(buffer,256,'\n');
            tempar++;
        }
        tempar=tempar-2;
        //vector<vector<double> >teemp(temp-2,vector<double>(256));
        //a=teemp;

    }
    
    int CharToInt(int length,char temp[])   //length is track
    {
        int tempi = 0;
        if(temp[0]!='-')
        {
            for(int i=0;i<length;i++)
                tempi= tempi*10+temp[i]-48;
            
            return tempi;
        }
        else
        {
            for(int i=1;i<length;i++)
                tempi = tempi*10+temp[i]-48;
            
            return -tempi;
        }
        
    }
    
    void read()
    {
        char buffer[256];
        fstream readfile;
        readfile.open("test.txt", ios::in);
        
        while(!readfile.eof())
        {
            int i = 0;
            readfile.getline(buffer,256,'\n');
            
            if(buffer[0] == 'c')
            {
                i=i+2;
                while(buffer[i]!='E')
                {
                    if(buffer[i]!=' ')
                    {
                        temp[trk] = buffer[i];
                        trk++;
                        //i++;
                    }
                    else
                    {
                        //trk = 0;
                        c.push_back(CharToInt(trk,temp));
                        //delete temp;
                        trk=0;
                        char temp[10];
                    }
                    i++;
                }
            }
            if(buffer[0] == 'a')
            {
                ta=0;
                i=i+2;
                while(buffer[i]!='E')
                {
                    if(buffer[i]!=' ')
                    {
                        temp[trk] = buffer[i];
                        trk++;
                        //i++;
                    }
                    else
                    {
                        //trk = 0;
                        a[tracker_num][ta]=CharToInt(trk,temp);
                        ta++;
                        //a[tracker_num].push_back(CharToInt(trk, temp));
                        //delete temp;
                        trk=0;
                        char temp[10];
                    }
                    i++;
                }
                tracker_num++;
            }
            
            
            if(buffer[0] == 'd')
            {
                i=i+2;
                while(buffer[i]!='E')
                {
                    if(buffer[i]!=' ')
                    {
                        temp[trk] = buffer[i];
                        trk++;
                        //i++;
                    }
                    else
                    {
                        //trk = 0;
                        d.push_back(CharToInt(trk,temp));
                        //delete temp;
                        trk=0;
                        char temp[10];
                    }
                    i++;
                }
            }
        }
        
        readfile.close();
        //vector<double> tempp(256);
        //tempp=a[0];
        //tempp[0];
        //int f;
        //f=4;
    }
};


#endif
