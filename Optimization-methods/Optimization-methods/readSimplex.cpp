//
//  readSimplex.cpp
//  Optimization-methods
//
//  Created by ZN-MAC on 14/11/28.
//  Copyright (c) 2014年 ZHANG Nan. All rights reserved.
//

#include "readSimplex.h"

void readSimplex::read()
{
    char buffer[256];
    fstream readfile;
    readfile.open(this->myAdress, ios::in);
    
    while(!readfile.eof())
    {
        int i = 0;
        readfile.getline(buffer,256,'\n');
        
        if(buffer[0] == 'c')
        {
            i=i+2;
            while(buffer[i]!='E' && buffer[i]!='B' && buffer[i]!='L')
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
            while(buffer[i]!='E' && buffer[i]!='B' && buffer[i]!='L')
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
            symbol.push_back(buffer[i]);
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
    this->rmax=this->tempar;
    this->colmax=this->ta;
    this->xnum=this->c.size()-1;
    readfile.close();
    //vector<double> tempp(256);
    //tempp=a[0];
    //tempp[0];
    //int f;
    //f=4;
}
