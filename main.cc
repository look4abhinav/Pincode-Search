#include<iostream>
#include<fstream>
using namespace std;
bool checkpin(string pin)
{
    bool flag=true;
    if(pin.size()!=6)
        flag=false;
    else
        for(int i=0;i<pin.size();i++)
            if(pin[i]<'0' || pin[i]>'9')
                flag=false;
    return flag;
}
int main()
{
    ifstream f;
    bool flag=false;
    f.open("dataset.csv",ios::in);
    if(f==NULL)
        cout<<"FILE NOT FOUND"<<endl;
    else if(f.eof())
        cout<<"FILE EMPTY"<<endl;
    else
    {
        string pin;
        cout<<"ENTER PINCODE"<<endl;
        cin>>pin;
        if(checkpin(pin)==false)
            cout<<"INVALID PIN"<<endl;
        else
            while(!f.eof())
            {
                string locality,post_office,pincode,sub_district,district,state;
                getline(f,locality,',');
                getline(f,post_office,',');
                getline(f,pincode,',');
                getline(f,sub_district,',');
                getline(f,district,',');
                getline(f,state,'\n');
                if(pin==pincode)
                {
                    cout<<"LOCALITY:\t"<<locality<<endl;
                    cout<<"POST OFFICE:\t"<<post_office<<endl;
                    cout<<"PINCODE:\t"<<pincode<<endl;
                    cout<<"SUB DISTRICT:\t"<<sub_district<<endl;
                    cout<<"DISTRICT:\t"<<district<<endl;
                    cout<<"STATE:\t\t"<<state<<endl;
                    cout<<endl;
                    flag=true;
                }
            }
    }
        if(flag==false)
            cout<<"PINCODE NOT FOUND"<<endl;
    return 0;
}
