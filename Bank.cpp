#include <iostream>
#include <vector>
using namespace std;

class Account{
    static int acc_no;
    string acc_name;
    int balance;
    int mobile;
    string address;
    int pin;

 public:
    //constructor
    Account(){
        acc_no++;
    }

    //setters
    void setAccName(string acc_name){
        this->acc_name=acc_name;
    }



};

int Account::acc_no = 1000;

class CurrAccount:public Account{



}; 

class SavAccount:public Account{


};

int main(){
    int input=0,i=0;
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
            while( i!=1 && i!=2 )
            {
                cout<<"Enter The type of Account You Want:"<<endl;
                cout<<"1.Current Account"<<endl<<"2.Savings Account"<<endl;
                cin>>i;
                switch(i)
                {  
                    case 1:
                        v1.emplace_back();
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