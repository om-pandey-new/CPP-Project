#include <iostream>
#include <conio.h> 
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Account {
    static int acc_counter; // To generate unique account numbers for each account
    int acc_no;             
    static int cred_no;
    string acc_name;
    string mobile;
    string address;
    string email;
    string password;

protected:
    int balance;

public:
    // Constructor
    Account() : acc_no(++acc_counter), balance(0) {}

    // Setters
    void setAccName(string acc_name) {
        this->acc_name = acc_name;
    }

    void setMobile(string mobile) {
        this->mobile = mobile;
    }

    void setAddress(string address) {
        this->address = address;
    }

    void setPassword(string password) {
        this->password = password;
    }

    void setEmail(string email) {
        this->email = email;
    }

    void setBalance(int balance) {
        this->balance += balance;
    }

    // Getters
    int getAccNo() {
        return acc_no; // Now each account has a unique account number
    }

    string getPassword() {
        return password;
    }

    int getBalance() {
        return balance;
    }

    // Print account details
    void printDetails() {
        cout << "------------------------------------------------------" << endl;
        cout << "Account Number: " << acc_no << endl;
        cout << "Account Name: " << acc_name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Mobile Number: " << mobile << endl;
        cout << "Address: " << address << endl;
        cout << "Email: " << email << endl;
        cout << "------------------------------------------------------" << endl;
    }


};

// Initialize static members
int Account::acc_counter = 1000; // Starts account numbering from 1000


class CurrAccount : public Account {
public:
    bool withdrawal(int withdraw) {
        if (withdraw > balance) {
            cout << "Insufficient Balance" << endl << "Overdraft Facility Availed" << endl;
        }
        this->balance -= withdraw;
        cout << "Transaction Successful" << endl;
        return true;
    }

    void addInterest() {
        cout << "Interest Facility is not provided in Current Account!!"<< endl;
    }
};

class SavAccount : public Account {
public:
    bool withdrawal(int withdraw) {
        if (withdraw <= balance) {
            this->balance -= withdraw;
            cout << "Transaction Successful." << endl;
            return true;
        }
        else {
            cout << "Insufficient Balance!!" << endl << "Transaction Failed." << endl;
            return false;
        }
    }

    void addInterest() {
        int interestRate = 5; // 5% interest rate, can be changed
        int interestAmount = (getBalance() * interestRate) / 100;
        setBalance(interestAmount);
        cout << "Interest added: " << interestAmount << endl;
    }
};

class Loan {
private:
    static int loan_counter;
    int loanId;
    string loanType;
    double loanAmount;
    int tenure;
    string mobileNumber;

public:
    Loan() : loanId(++loan_counter) {}

    void setLoanType(string loanType) {
        this->loanType = loanType;
    }

    void setLoanAmount(double loanAmount) {
        this->loanAmount = loanAmount;
    }

    void setTenure(int tenure) {
        this->tenure = tenure;
    }

    void setMobileNumber(string mobileNumber) {
        this->mobileNumber = mobileNumber;
    }

    void printLoanDetails() {
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Your Loan Details Are:"<<endl;

        cout << "Loan ID: " << loanId << endl;
        cout << "Loan Type: " << loanType << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Tenure: " << tenure << " months" << endl;
        cout << "Mobile Number: " << mobileNumber << endl;
        cout << "Your loan ID is: " << loanId << endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Thank You for Applying Loan!!"<<endl<<"Your Loan Request Has Been Successfully Processed!!"<<endl;
        cout << "Further process will be done by bank advisor, who will contact you on your mobile number: " << mobileNumber << endl;
    }
};

int Loan::loan_counter = 2000; // Initialize the loan counter


// Other functions related to account registration, services, etc. remain unchanged

template <class T>
bool checkPass(T& v, int& index, string& password) {
    int flag1 = 0, attempt = 0;
    while (flag1 == 0) {
        cout << "Enter your Password for authorization:" << endl;
        password = "";
        char ch;
        while ((ch = getch()) != '\r') { // read character without echoing
            if (ch == '\b') { // backspace
                if (password.size() > 0) {
                    password.pop_back();
                    cout << "\b \b"; // erase last character
                }
            } else {
                password += ch;
                cout << "*"; // display asterisk instead of character
            }
        }
        cout << endl;
        if (v.at(index).getPassword() == password) {
            flag1 = 1;
            break;
        } else {
            cout << "Wrong Password Entered.Please Try Again" << endl;
            attempt++;
            if (attempt > 5) {
                cout << "Maximum Attempts Exceeded!!" << endl;
                break;
            }
        }
    }
    if (flag1 == 1) return true;
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

bool isValidMobile(string& mobile){
    int count=0;
    for(char c:mobile){
        if(!isdigit(c)) return false;
    }
    if(mobile.size()!=10) return false;
    return true;
}

template <class T>
void update(T& v,int& index,string& mobile,string& email,string&  address){

    int up=0;
    while(up!=4){
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Select the  field you want to update"<<endl;
        cout<<"1.Mobile  Number"<<endl<<"2.Email Id"<<endl<<"3.Address"<<endl<<"4.Go Back to Previous Menu"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cin>>up;
        switch(up){
            case 1:
                cout<<"------------------------------------------------------"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                do{
                    cout<<"Enter The New Mobile Number:"<<endl;
                    getline(cin,mobile);
                    if(!isValidMobile(mobile)) cout<<"Invalid Entry!!Please Enter Only digits"<<endl;
                }while(!isValidMobile(mobile)); 
                v.at(index).setMobile(mobile);
                cout<<"Mobile Number successfully updated"<<endl;
                cout<<"------------------------------------------------------"<<endl;
                break;
            case 2:
                cout<<"------------------------------------------------------"<<endl;
                cout<<"Enter the new email id"<<endl;
                cin>>email;
                v.at(index).setEmail(email);
                cout<<"Email-Id  successfully updated"<<endl;
                cout<<"------------------------------------------------------"<<endl;
                break;
            case 3:
                cout<<"------------------------------------------------------"<<endl;
                cout<<"Enter the new address"<<endl;
                cin>>address;
                v.at(index).setAddress(address);
                cout<<"Address successfully  updated"<<endl;
                cout<<"------------------------------------------------------"<<endl;
                break;
            case 4:
                break;
            default:
                cout<<"Invalid Choice!! Try Again"<<endl;
        }
    }
}



template <class T>
void registration(T& v,string& name,string& address,string& email,string& password,string& mobile){
        v.emplace_back();
        cout<<"Enter  The Bank Details:"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Account Holder Name:"<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,name);
        v.back().setAccName(name);
        do{
            cout<<"Mobile Phone:"<<endl;
            getline(cin,mobile);
            if(!isValidMobile(mobile)) cout<<"Invalid Entry!!Please Enter Only digits"<<endl;
        }while(!isValidMobile(mobile));   
        v.back().setMobile(mobile);
        cout<<"Enter Your Address:"<<endl;
        getline(cin,address);
        v.back().setAddress(address);
        cout<<"Enter Your Email Id:"<<endl;
        getline(cin,email);
        v.back().setEmail(email);
        cout<<"Create Your Password:"<<endl;
        getline(cin,password);
        v.back().setPassword(password);
        cout << "\033[2J\033[1;1H";
        cout<<"---Registration Successful---"<<endl;
        cout<<"Your Account NUmber is "<<v.back().getAccNo()<<endl;

}

template <class T1,class T2>
void transfer(T1& v,int& index2,T2& V,int& index){
    int amount;
    string password;
    cout<<"Enter The Amount You want to transfer:"<<endl;
    cin>>amount;
    if(checkPass(V,index,password)){
        if(V.at(index).withdrawal(amount)) v.at(index2).setBalance(amount);
    }
    else cout<<"Wrong Password Entered.Transaction Failed!!"<<endl;
}

template <class T>
void accountServices(T& v,int& index,vector<CurrAccount>& v1,vector<SavAccount>& v2){
        int i=0,amount,withdraw,j=0,k=0,l=0,index2=0,exist_num2;
        string password,mobile,address,email;
        cout << "\033[2J\033[1;1H";
        cout<<"------------------------------------------------------"<<endl;
        cout<<"Choose the services you want to avail:"<<endl;//chequebook can be added later
        cout<<"1.Know Your Details"<<endl<<"2.Deposit Amount"<<endl<<"3.Withdrawal "<<endl<<"4.Transfer Money To Another Bank Account"<<endl<<"5.Check Balance"<<endl;
        cout<<"6.Update Details"<<endl<<"7.Calculate Interest"<<endl<<"8.Terminate Account"<<endl<<"9.Go To  Main Menu"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        while(i!=9){
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
                    if(checkPass(v,index,password)) v.at(index).withdrawal(withdraw);
                    break;
                case 4:
                    cout<<"Select Account Type:"<<endl<<"1.Current Account"<<endl<<"2.Savings Account"<<endl;
                    cin>>l;
                    switch(l)
                    {
                        case 1:
                            if(checkAccount(v1,index2,exist_num2)){
                                transfer(v1,index2,v,index);
                            }
                            break;
                        case 2:
                            if(checkAccount(v2,index2,exist_num2)){
                                transfer(v2,index2,v,index);
                            }
                            break;
                        default:
                            cout<<"Invalid Choice!!"<<endl;
                            break;
                    }
                case 5:
                    cout<<"Your Balance is:"<<v.at(index).getBalance()<<endl;
                    break;
                case 6:
                    update(v,index,mobile,email,address);
                    break;
                case 7:
                    v.at(index).addInterest();
                    break;
                case 8:
                    if (checkPass(v, index, password)) {
                        v.erase(v.begin() + index);
                        cout << "Account terminated successfully." << endl;
                        i=10;
                    } 
                    else cout << "Invalid password. Account termination failed." << endl;
                    break;
                case 9:
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




//int flag1=0;
int input=0,i,exist_num,index;//flag=0;
string name,address,password,mobile,email;

int main(){
    
    mainMenu();
    vector<CurrAccount> v1;
    vector<SavAccount> v2;
    vector<Loan> loans;
    
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
                        registration(v1,name,address,email,password,mobile);
                        break;
                    case 2:
                        registration(v2,name,address,email,password,mobile);
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
                            if(checkPass(v1,index,password)) accountServices(v1,index,v1,v2);
                        }

                        //if(checkPass(v1,index,password)) accountServices(v1,index);

                        cout<<"------------------------------------------------------"<<endl;
                        break;
                    case 2:

                        if(checkAccount(v2,index,exist_num)){
                            if(checkPass(v2,index,password)) accountServices(v2,index,v1,v2);
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
            i=0;
            cout<<"1.Apply for Loan"<<endl;
            cout<<"Please Enter Your Choice"<<endl;
            cin>>i;
            switch(i){
                case 1:{
                    loans.emplace_back();
                    cout << "Enter loan type (e.g. personal, home, car): ";
                    string loanType;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, loanType);
                    loans.back().setLoanType(loanType);

                    cout << "Enter loan amount: ";
                    double loanAmount;
                    cin >> loanAmount;
                    loans.back().setLoanAmount(loanAmount);

                    cout << "Enter tenure (in months): ";
                    int tenure;
                    cin >> tenure;
                    loans.back().setTenure(tenure);

                    cout << "Enter your mobile number: ";
                    string mobileNumber;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, mobileNumber);
                    loans.back().setMobileNumber(mobileNumber);

                    loans.back().printLoanDetails();
                    break;
                }
                case 2:
                    break;
            }
            cout<<"Enter Again or Press 5 To Exit"<<endl;
            break;
        case 4: {
                cout << "Contact Us:" << endl;
                cout<<"------------------------------------------------------"<<endl;
                cout << "National Bank" << endl;
                cout << "Head Office: 123 Connaught Place, New Delhi, India" << endl;
                cout << "Phone: 011-23456789" << endl;
                cout << "Email: [info@nationalbank.in]" << endl;
                cout << "Website: nationalbank.in" << endl;
                cout<<"------------------------------------------------------"<<endl;
                cout << "Branches:" << endl;
                cout<<"------------------------------------------------------"<<endl;
                cout << "Mumbai Branch: 456 Marine Drive, Mumbai, India" << endl;
                cout << "Phone: 022-12345678" << endl;
                cout << "Email: [mumbai@nationalbank.in])" << endl;
                cout<<"------------------------------------------------------"<<endl;
                cout << "Bangalore Branch: 789 MG Road, Bangalore, India" << endl;
                cout << "Phone: 080-4567890" << endl;
                cout << "Email: [bangalore@nationalbank.in])" << endl;
                cout<<"------------------------------------------------------"<<endl;
                cout << "Feedback:" << endl;
                cout<<"------------------------------------------------------"<<endl;
                string feedback;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter your feedback or query: " << endl;
                getline(cin, feedback);
                cout << "Thank you for your feedback! We will get back to you soon." << endl;
                cout<<"Enter Again or Press 5 To Exit"<<endl;
                break;
        }
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