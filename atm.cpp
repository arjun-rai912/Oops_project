#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;


/* Mini Project - ATM
Check Balance
Cash withdraw
User Details
update Mobile No.
*/

class atm{                      //class atm

    private:                   // private member variables
long int account_No;
string name;
int PIN;
double balance;
string mobile_No;

public:

//setData function is setting the Data into the private member variables
void setData(long int account_No_a, string name_a,int PIN_a,double balance_a,string mobile_No_a){
    account_No = account_No_a; //assigning the formal arguments to the private member 
     name=name_a;
     PIN=PIN_a;
     balance=balance_a;
     mobile_No=mobile_No_a;
}

//getAccountNO function is returning the user's account no.
long int getAccount_No(){
    return account_No;
}
string getName(){
    return name;
}
int getPIN(){
    return PIN;
}

double getBalance(){
    return balance;
}
string getMobileNo(){
    return mobile_No;
}

//setMobi1e function is Updating the user mobile no

void setMobile(string mob_prev,string mob_new){
    if(mob_prev == mobile_No){     // it will check the old mobile no
                                   

        mobile_No = mob_new;         // and update with new , if old matches
    
        cout<<endl<<"Successfully Updated Mobile No.";
        _getch(); // used to hold the screen untill user presses any key 
    }
    else{
        cout<<endl<<"Incorrect !! Old mobile no.";
        _getch();
    }
}

// cashwithdrawl function is used ot withdraw money from ATM

void casWithDraw(int amount_a){

if (amount_a > 0 && amount_a <balance){
    balance -= amount_a;
    cout<< endl<<"Please Collect your cash";
    cout<<endl<<"Available Balance:"<<balance;
    _getch();
}
else{
    cout<<endl<<"Invalid Input or Insufficient balance";
    _getch();
}
}

};

int main(){

    int choice =0 , enterPIN; // user authentication
    long int enterAccountNo;

    system("cls");

    //created User (object)

    atm user1;
    //Set user Details (into object) ( setting default Data)
    user1.setData(1234567,"Arjun",1111,43000.00,"9878041734");

    do{
       system("cls");
       cout<<endl<<"****Welcome to ATM****"<<endl;
       cout<<endl<<"Enter your account No";
       cin>>enterAccountNo;

       cout<<endl<<"Enter PIN";
       cin>>enterPIN;



       //check whether enter values matches with user details
       if((enterAccountNo == user1.getAccount_No() ) && (enterPIN == user1.getPIN()))
       {
        do{
            int amount=0;
            string oldMobileNo,newMobileNo;

            system("cls");
            // userinterface

            cout<<endl<<"**** Welcome to ATM ****"<<endl;
            cout<<endl<<"Select options";
            cout<<endl<<"1. Check Balance";
            cout<<endl<<"2. Cash Withdraw";
            cout<<endl<<"3. Show User Details";
            cout<<endl<<"4. Update Mobile No.";
            cout<<endl<<"5. Exit "<<endl;
            cin>>choice;
    
        switch (choice)
        {
        case 1:
            cout<<endl<<"Your bank balance is :"<<user1.getBalance();
            _getch();
            break;
        case 2:
            cout<<endl<<"Enter the amount:";
            cin>>amount;
            user1.casWithDraw(amount);
            
            break;
        case 3:
           cout<<endl<<"**** User Details are :-";
           cout<<endl<<"-> Account no "<<user1.getAccount_No();
           cout<<endl<<"-> Name "<<user1.getName();
           cout<<endl<<"-> Balance "<<user1.getBalance();
           cout<<endl<<"-> Mobile no "<<user1.getMobileNo();
            _getch();
            break;
        case 4:
              cout<<endl<<"enter the old Mobile N0.";
              cin>>oldMobileNo;

              cout<<endl<<"enter the new mobile no.";
              cin>>newMobileNo;

              user1.setMobile(oldMobileNo,newMobileNo);
              break;
        case 5:
           exit(0);
        default:
              cout<<endl<<"Enter valid data!!";

    
        }


        }while(1);
       }
       else{
        cout<<endl<<"user details are invalid !!";
        _getch();
       }
    }while(1);
   return 0;
}