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
        balance=0;
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

    void setBalance(int balance){
        this->balance+=balance;
    }

    void withdrawal(int withdraw){

        this->balance-=withdraw;
    }


    //getters
    int getAccNo(){
        return acc_no;
    }

    string getPassword(){
        return password;
    }

    int getBalance(){
        return  balance;
    }

    //print details
    void printDetails(){
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Account Number: "<<acc_no<<endl;
        cout<<"Account Name: "<<acc_name<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"Mobile Number: "<<mobile<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"------------------------------------------------------"<<endl;


    }

};

int Account::acc_no = 1000;

class CurrAccount:public Account{



}; 

class SavAccount:public Account{


};

template <class T>
void registration(T& v,string& name,string& address,string& password,string& mobile){
        v.emplace_back();
        cout<<"Enter  The Bank Details:"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Account Holder Name:"<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,name);
        v.back().setAccName(name);
        cout<<"Mobile Phone:"<<endl;
        getline(cin,mobile);
        v.back().setMobile(mobile);
        cout<<"Enter Your Address:"<<endl;
        getline(cin,address);
        v.back().setAddress(address);
        cout<<"Create Your Password:"<<endl;
        getline(cin,password);
        v.back().setPassword(password);
        cout<<"---Registration Successful---"<<endl;
        cout<<"Your Account NUmber is "<<v.back().getAccNo()<<endl;

}

template <class T>
void accountServices(T& v,int& index){
        int i=0,amount,withdraw;
        string password;
        cout << "\033[2J\033[1;1H";
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Choose the services you want to avail:"<<endl;//chequebook can be added later
        cout<<"1.Know Your Details"<<endl<<"2.Deposit Amount"<<endl<<"3.Withdrawal "<<endl<<"4.Check Balance"<<endl;
        cout<<"5.Update Details"<<endl<<"6.Card Services"<<endl<<"7.Terminate Account"<<endl<<"8.Go To  Main Menu"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        while(i!=8){
            cout<<"PLease Enter Your Choice:"<<endl;
            cin>>i;
            switch(i)
            {
                case 1:
                    v.at(index).printDetails();
                    break;
                case 2:
                    cout<<"Enter the amount you want to deposit:"<<endl;
                    cin>>amount;
                    v.at(index).setBalance(amount);
                    cout<<"Deposit Successful"<<endl<<"Deposited  Amount is "<<amount<<endl;
                    break;
                case 3:
                    cout<<"Enter the amount you want to withdraw:"<<endl;
                    cin>>withdraw;
                    //cout<<"Enter The Password for authorization:"<<endl;
                    if(checkPass(v,index,password)){
                        if(v.at(index).getBalance()>=withdraw){
                         v.at(index).withdrawal(withdraw);
                         cout<<"Transaction Successful."<<endl;
                        }
                        else cout<<"Insufficient Balance!!"<<endl;
                    }
                    break;
                case 4:
                    cout<<"Your Balance:"<<v.at(index).getBalance();
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                default:
                    cout<<"Invalid Choice.Try Again"<<endl;
                    break;
            }
        }


}

void mainMenu(void){
    cout<<"*********** Welcome to The National Bank *********** "<<endl;
    cout<<"1.Create New Bank Account"<<endl;
    cout<<"2.Login Into Existing Account"<<endl;
    cout<<"3.Other Services"<<endl;
    cout<<"4.Contact Us"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"------------------------------------------------------"<<endl;
}

template <class T>
bool checkPass(T& v,int& index,string& password){
    int flag1=0,attempt=0;
    while(flag1==0){
        cout<<"Enter your Password for authorization:"<<endl;
        cin>>password;
        if(v.at(index).getPassword()==password )
        {
            flag1=1;
            break;
        }
        else cout<<"Wrong Password Entered.Please Try Again"<<endl;
        attempt++;
        if(attempt>5){
            cout<<"Maximum Attempts Exceeded!!"<<endl;
            break;
        }
    }
    if (flag1==1) return true;
    else return false;
}

template <class T>
bool checkAccount(T& v,int& index,int& exist_num){
    int flag=0,attempt=0;
    while(flag==0){
        cout<<"Enter Your Account No."<<endl;
        cin>>exist_num;
        for(index=0;index<v.size();index++){
            if(v.at(index).getAccNo()==exist_num){ 
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"No Such Account Exist.PLease Try Again"<<endl;
        attempt++;
        if(attempt>3){
            cout<<"Maximum Attempts  Exceeded!!"<<endl;
            break;
        }
    }
    if(flag==0) return false;
    if(flag==1) return true;

}

//int flag1=0;
int input=0,i,exist_num,index;//flag=0;
string name,address,password,mobile;

int main(){
    
    mainMenu();
    vector<CurrAccount> v1;
    vector<SavAccount> v2;
    while(input!=5){

        cout<<"Please Enter Your Choice: "<<endl;
        cin>>input;
        cout<<"------------------------------------------------------"<<endl;
        switch (input)
        {
        case 1:
            i=0;
            while( i!=1 && i!=2 )
            {
                cout<<"Enter The type of Account You Want:"<<endl;
                cout<<"1.Current Account"<<endl<<"2.Savings Account"<<endl;
                cout<<"------------------------------------------------------"<<endl;
                cin>>i;
                cout<<"------------------------------------------------------"<<endl;
                switch(i)
                {  
                    case 1:
                        registration(v1,name,address,password,mobile);
                        break;

                    case 2:
                        registration(v2,name,address,password,mobile);
                        break;

                    default:
                        cout<<"You Have entered invalid choice, please choose again"<<endl;
                        break;
                }
                cout<<"------------------------------------------------------"<<endl;
            }
            cout<<"Enter Again or Press 5 To Exit"<<endl;
            cout<<"------------------------------------------------------"<<endl;
            mainMenu();
            break;
        case 2:
            i=0;
            while(i!=1 && i!=2 && i!=3){
                cout<<"Enter Your Account Type:"<<endl;
                cout<<"1.Current Account"<<endl<<"2.Savings Account"<<endl<<"3.Exit to Main Menu"<<endl;
                cout<<"------------------------------------------------------"<<endl;
                cin>>i;
                cout<<"------------------------------------------------------"<<endl;
                switch(i){
                    case 1:

                        if(checkAccount(v1,index,exist_num)){
                            if(checkPass(v1,index,password)) accountServices(v1,index);
                        }

                        //if(checkPass(v1,index,password)) accountServices(v1,index);

                        cout<<"------------------------------------------------------"<<endl;
                        break;
                    case 2:

                        if(checkAccount(v2,index,exist_num)){
                            if(checkPass(v2,index,password)) accountServices(v2,index);
                        }

                        //if(checkPass(v2,index,password)) accountServices(v2,index);
                        cout<<"------------------------------------------------------"<<endl;
                        break;
                    case 3:
                        break;
                    default:
                        cout<<"You Have entered invalid choice, please choose again"<<endl;
                        break;
                }
            }
            //cout << "\033[2J\033[1;1H";
            cout<<"Enter Your Choice Again or Press 5 To Exit"<<endl;
            mainMenu();
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