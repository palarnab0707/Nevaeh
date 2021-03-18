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
        int c=0;
        int flag=0;
        const char delim=',';
        int num,num2;
        string source;
        string dest;
        string error;
        cout<<"Enter the 1st file :"<<endl;
        cin>>source;
        cout<<"Enter the 2nd file :"<<endl;
        cin>>dest;
        cout<<"Enter the error saving file :"<<endl;
        cin>>error;
        ofstream fe(error.c_str());
        ifstream fo(source.c_str());
        ifstream fo2(dest.c_str());
        string data;
        string data2;
        while(1)   // getline(fo,data)&&getline(fo2,data2))
        {
                        int i=0;
                        getline(fo,data);
                        getline(fo2,data2);
                        if(fo.eof()&&fo2.eof())
                        {
                                break;
                        }
                        if(fo.eof())
                        {
                                flag=1;
                                cout<<"Remaining Lines of file 2"<<endl;
                                do
                                {
                                        vector<string> to;
                                        token(data2,delim,to);
                                        fe<<"\nRemaining lines of file 2\n";
                                        if(to.size()<=7)
                                        {
                                                for(i=0;i<7;i++)
                                                {
                                                        cout<<to[i]<<endl;
                                                        fe<<to[i];
                                                        fe<<"\n";
                                                }
                                        }
                                        to.empty();
                                        co++;
                                }while(getline(fo2,data2));
                                break;
                        }
                        if(fo2.eof())
                        {
                                flag=1;
                                cout<<"Remaining Lines of file 1"<<endl;
                                do
                                {
                                        vector<string> to2;
                                        token(data,delim,to2);
                                        fe<<"\nRemaining lines of file 1\n";
                                        if(to2.size()<=7)
                                        {
                                                for(i=0;i<7;i++)
                                                {
                                                        cout<<to2[i]<<endl;
                                                        fe<<to2[i];
                                                        fe<<"\n";
                                                }
                                        }
                                        co++;
                                        to2.empty();
                                }while(getline(fo,data));
                                break;
                        }                       //count++;
                        vector<string> tokens;
                        vector<string> tokens2;
                        c++;
                        if(c<=2)
                        {
                                continue;
                        }
                        token(data,delim,tokens);
                        token(data2,delim,tokens2);
                        if(tokens.size()==0||tokens2.size()==0)
                        {
                                cout<<"Blank line found sequence failed"<<endl;
                                fe<<"\nBlank line found sequence failed\n";
                                break;
                        }
                        int x=0;
                        int x2=0;
                        stringstream geek(tokens[0]);
                        geek>>x;
                        stringstream geek2(tokens2[0]);
                        geek2>>x2;
                        if(x!=(c-2))
                        {
                                cout<<"Sequence failed file 1 at line : "<<(c-2)<<endl;
                                fe<<"\nSequence failed file 1 at line : \n";
                                fe<<(c-2);
                                exit(0);
                        }
                        if(x2!=(c-2))
                        {
                                cout<<"Sequence Failed file 2 at line : "<<(c-2)<<endl;
                                fe<<"\nSequence failed file 2 at line : \n";
                                fe<<(c-2);
                                exit(0);
                        }
                        if(tokens.size()>=6&&tokens2.size()>=6)
                        {
                                if((tokens[1]!="N"&&tokens[1]!="M"&&tokens[1]!="X")&&(tokens2[1]!="N"&&tokens2[1]!="M"&&tokens2[1]!="X"))
                                {
                                        cout<<"N M X not matched at line no : "<<(c-2)<<endl;
                                        co++;
                                        fe<<"\nN M X not matched at line no :  \n";
                                        fe<<(c-2);
                                        flag=1;
                                        break;
                                }
                                if((tokens[1]=="N"||tokens[1]=="M"||tokens[1]=="X")&&(tokens2[1]=="N"||tokens2[1]=="M"||tokens2[1]=="X"))
                                {
                                        for(int i=0;i<tokens.size();i++)
                                        {
                                                cout<<tokens[i]<<" "<<tokens2[i]<<" ";
                                                if(tokens!=tokens2)
                                                {
                                                        cout<<tokens[i]<<" "<<tokens2[i]<<endl;
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
                                else
                                {
                                        continue;
                                }

                        }
                        tokens.empty();
                        tokens2.empty();
                        cout<<endl;
                }
                fo.close();
                fo2.close();
                fe.close();
                if(flag==1)
                {
                        cout<<co<<" "<<"Unmatched found"<<endl;
                        fe<<co;
                        fe<<" Unmatched found\n";
                }
                else
                {
                        cout<<"Files Matched"<<endl;
                        fe<<"Files Matched";
                }
        return 0;
}
