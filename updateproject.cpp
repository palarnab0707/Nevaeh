#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ostream>
#include<string.h>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
void token(string const &str, const char delim,vector<string> &tokens)
{
   int i=0;
    stringstream ss(str);

    string s;

    while (getline(ss, s, delim)) {
        if(i==0 || i==3);
        else{
        tokens.push_back(s);
        }
        i++;

    }
}
int main()
{
        double count=0;
        int co=0;
        int flag=0;
        int c=0;
        int ct=0;
        const char delim=',';
        int num,num2;
        ofstream fe("error.txt");
        ifstream fo("sample.txt");
        ifstream fo2("sample2.txt");
        string data;
        string data2;
        while(getline(fo,data)&&getline(fo2,data2))
        {
                        int i=0;
                        count++;
                        int to=0;
                        int to2=0;
                        vector<string> tokens;
                        vector<string> tokens2;
                        c++;
                        if(c<=2)
                        {
                                continue;
                        }
                        token(data,delim,tokens);
                        token(data,delim,tokens2);
                        int x=0;
                        stringstream geek(tokens[0]);
                        geek>>x;
                        if(x!=(count-2))
                        {
                                cout<<"Not Done"<<endl;
                                cout<<tokens[0]<<endl;
                                cout<<tokens.size()<<endl;
                                cout<<count<<endl;
                                exit(0);
                        }
                        if(tokens.size()>=6&&tokens2.size()>=6)
                        {
                                if(tokens[1]=="N"||tokens[1]=="M"||tokens[1]=="X"||tokens2[1]=="N"||tokens2[1]=="M"||tokens2[1]=="X")
                                {
                                        for(int i=0;i<tokens.size();i++)
                                        {
                                                cout<<tokens[i]<<endl;
                                                if(tokens!=tokens2)
                                                {
                                                        cout<<tokens[i]<<endl;
                                                        cout<<tokens2[i]<<endl;
                                                        fe<<tokens[i];
                                                        fe<<"\n";
                                                        fe<<tokens2[i];
                                                        fe<<"\n";
                                                        flag=1;
                                                        continue;
                                                }
                                        }
                                }
                                else
                                {
                                        continue;
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
