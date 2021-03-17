#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<ostream>
#include<string.h>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
        int count=0;
        int co=0;
        int flag=0;
        ofstream fe("error.txt");
        ifstream fo("sample.txt");
        ifstream fo2("sample2.txt");
        string data;
        string data2;
        while(getline(fo,data)&&getline(fo2,data2))
        {
                        vector<string> tokens;
                        vector<string> tokens2;
                        stringstream check(data);
                        stringstream check2(data2);
                        string item;
                        string item2;
                        while(getline(check,item,',')&&getline(check2,item2,','))
                        {
                                tokens.push_back(item);
                                tokens2.push_back(item2);
                        }
                        if(tokens.size()==tokens2.size())
                        {
                                for(int i=0;i<tokens.size();i++)
                                {
                                        if(i!=0 || i!=3)
                                        {
                                                if(tokens!=tokens2)
                                                {
                                                        cout<<tokens[i]<<endl;
                                                        cout<<tokens2[i]<<endl;
                                                        fe<<tokens[i];
                                                        fe<<"\n";
                                                        fe<<tokens2[i];
                                                        fe<<"\n";
                                                        flag=1;
                                                        co++;
                                                        continue;
                                                }

                                        }

                                }
                        }
        }
                        fo.close();
                        fo2.close();
                        fe.close();
                        if(flag==1)
                        {
                                cout<<co<<" Unmatched found"<<endl;
                        }
                        else
                        {
                                cout<<"Matched"<<endl;
                        }
        return 0;
}
