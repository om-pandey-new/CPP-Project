#include <iostream>
using namespace std;

class Account{



};

int main(){
    int input=0;
    cout<<"*********** Welcome to The National Bank *********** "<<endl;
    cout<<"1.Create New Bank Account"<<endl;
    cout<<"2.Login Into Existing Account"<<endl;
    cout<<"3.Other Services"<<endl;
    cout<<"4.Contact Us"<<endl;
    while(input!=5){

        cout<<"Please Enter Your Choice: "<<endl;
        cin>>input;
        switch (input)
        {
        case 1:
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