#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Account{
    static int acc_no;
    string acc_name;
    int balance;
    string mobile;
    string address;
    int pin;
    string password;

 public:
    //constructor
    Account(){
        acc_no=++acc_no;
    }

    //setters
    void setAccName(string acc_name){
        this->acc_name=acc_name;
    }

    void setMobile(string mobile){
        this->mobile=mobile;
    }

    void setAddress(string address){
        this->address=address;
    }

    void setPassword(string password){
        this->password=password;
    }

    //getters
    int getAccNo(){
        return acc_no;
    }

    string getPassword(){
        return password;
    }




};

int Account::acc_no = 1000;

class CurrAccount:public Account{



}; 

class SavAccount:public Account{


};

template <class T>
void accountServices(T& v){
        cout<<"Choose the services you want to avail:"<<endl;//chequebook can be added later
        cout<<"1.Know Your Details"<<endl<<"2.Deposit Amount"<<endl<<"3.Withdrawal "<<endl<<"4.Check Balance"<<endl;
        cout<<"5.Update Details"<<endl<<"6.Card Services"<<endl<<"7.Terminate Account"<<endl;
}

int main(){
    int input=0,i,exist_num,index;
    string name,address,password,mobile;
    cout<<"*********** Welcome to The National Bank *********** "<<endl;
    cout<<"1.Create New Bank Account"<<endl;
    cout<<"2.Login Into Existing Account"<<endl;
    cout<<"3.Other Services"<<endl;
    cout<<"4.Contact Us"<<endl;
    vector<CurrAccount> v1;
    vector<SavAccount> v2;
    while(input!=5){

        cout<<"Please Enter Your Choice: "<<endl;
        cin>>input;
        switch (input)
        {
        case 1:
            i=0;
            while( i!=1 && i!=2 )
            {
                cout<<"Enter The type of Account You Want:"<<endl;
                cout<<"1.Current Account"<<endl<<"2.Savings Account"<<endl;
                cin>>i;
                switch(i)
                {  
                    case 1:

                        v1.emplace_back();
                        cout<<"Enter  The Bank Details:"<<endl;
                        cout<<"Account Holder Name:"<<endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin,name);
                        v1.back().setAccName(name);
                        cout<<"Mobile Phone:"<<endl;
                        getline(cin,mobile);
                        v1.back().setMobile(mobile);
                        cout<<"Enter Your Address:"<<endl;
                        getline(cin,address);
                        v1.back().setAddress(address);
                        cout<<"Create Your Password:"<<endl;
                        getline(cin,password);
                        v1.back().setPassword(password);
                        cout<<"Registration Successful"<<endl;
                        cout<<"Your Account NUmber is "<<v1.back().getAccNo()<<endl;
                        

                        break;
                    case 2:
                        v2.emplace_back();
                        break;
                    default:
                        cout<<"You Have entered invalid choice, please choose again"<<endl;
                        break;
                }
            }
            cout<<"Enter Again or Press 5 To Exit"<<endl;
            break;
        case 2:
            i=0;
            while(i!=1 && i!=2){
                cout<<"Enter Your Account Type:"<<endl;
                cout<<"1.Current Account"<<endl<<"2.Savings Account"<<endl;
                cin>>i;
                switch(i){
                    case 1:
                        cout<<"Enter Your Account No."<<endl;
                        cin>>exist_num;
                        for(index=0;index<=v1.size();index++){
                            
                            if(v1.at(index).getAccNo()==exist_num) break;
                        }
                        
                        //need to use template at many places
                        //have to add loop for wrong password
                        cout<<"Enter your Password"<<endl;
                        cin>>password;
                        if(v1.at(index).getPassword()==password ) accountServices(v1.at(index));
                        else cout<<"Wrong Password Entered.Please Try Again";
                        break;
                    case 2:

                        break;
                }
            }
            
            cout<<"Enter Again or Press 5 To Exit"<<endl;
            break;
        case 3:
            cout<<"Enter Again or Press 5 To Exit"<<endl;
            break;
        case 4:
           
            cout<<"Enter Again or Press 5 To Exit"<<endl;
            break;
        case 5:
            cout<<"Thank you for visiting us"<<endl;
            break;
        
        default:
            cout<<"Wrong Choice Entered"<<endl<<"Enter Again or Press 5 To Exit"<<endl;
            break;
        }

    }
    
    return 0;
}