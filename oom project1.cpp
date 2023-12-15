#include<iostream> 
using namespace std;
//Declare ATM  class
class ATM;//contained class
// base class 
class BankCard {
  private:
  string pinnumber;//pinnumber
  float money;//total amount
public:
  friend ATM;//Friend class ATM. Enable ATM class to access private members of bank card class 
  BankCard( int Pinnumber, float Money)
  {
 
    pinnumber = Pinnumber;
    money = Money;
  };          //Constructor
  
};

class ATM//ATM type, which simulates the main system of the machine
{
  int pinnumber;//pin number
  float money;//total amount

public:
  void accountType();//selecting account type
  int check_pin(int Pinnumber);//Verify pin function
  void transfer_money();//Money Transfer function
  void check_remain_money();//Query balance function
  void deposit();//deposite money function
  void widrawing();//Withdraw money function
  void change_pin();//Modify pin number function
  //parameterized constructor of ATM class
  ATM(int Pinnumber, float Money)
  {
  
    pinnumber = Pinnumber;
    money = Money;
  }
};
int ATM::check_pin(int Pinnumber)  //Verify account pin function
{
  int i = 0;
  cout << "Please enter your pin number" << endl;
  for (i = 0; i < 3; i++)
  {           //Cannot exceed three attempts
    cout << "Pinnumber:";
    cin>>Pinnumber;
    if (Pinnumber==pinnumber )
    {
      cout << "Login to India Bank successfully!" << endl
        << "welcome!"<< endl;
      return 1;
    }
    else 
    {
      cout << "Incorrect  pin number, please re-enter" << endl;
      if (i >= 2)
      {
        cout << "You have tried more than three times and have been frozen" << endl;
        exit(1);
      }
    }
  }
  return 0; 
}

void ATM::accountType(){
  string accType;
  cout << " Select Account Type:\n";
  cout << " Current 'C' or Savings 'S': ";
  cin >> accType;

  // If C or c is entered display Checking Account
  if(accType == "C" || accType == "c"){
     cout << "\t\t\t\tCurrent Account" << endl << endl;
  // Else if S or s is entered display Savings Account
  } else if (accType == "S" || accType == "s") {
     cout << "\t\t\t\tSavings Account" <<endl << endl;
  } else {
    cout << "\t\t\tInvalid Account Type.\n";
    cout << "\t\t\tSelect Account Type: 'C' or 'S': ";
    cin >> accType;
  }
}
void ATM::deposit()        //deposite money function
 {
  float e_money;//Define the variable to store the amount to be deposited
  cout << "Please enter the amount you want to deposit" << endl;
  cin >> e_money;
  money += e_money;//Change the total amount
  cout << "Your balance is" << money << endl;
  
}

void ATM::widrawing()        //Withdraw money function
{
  float e_money;//Define the variable to store the amount to be taken
  cout << "Please enter the amount you want to withdraw" << endl;
  cin >> e_money;
  if (e_money > money)//If the withdrawal is more than the total amount
    cout << "Insufficient account balance" << endl;
  else        //If the withdrawal is less than the total amount
  {  
    money -= e_money;
    cout << "Your balance is" << money << endl;
  }
  
}

void ATM::change_pin()  // //Modify pin number function
{        
  int  new_pin1, new_pin2, pin;
  cout << "Please enter the original pin: ";
  cin >> pin;
  cout << endl;
  if (pin == pinnumber)
  {
    cout << "Please enter a new pin number: ";
    cin >> new_pin1;
    cout << endl;
    while (new_pin1 == pinnumber)
    {
      cout << "The same as the old pinnumber, please enter a new pin number: ";
      cin >> new_pin1;
      cout << endl;
    }
    cout << "Please enter the new pinnumber again: ";
    cin >> new_pin2;
    cout << endl;
    while (new_pin1 != new_pin2)
    {
      cout << "Different from the first input, please input again: ";
      cin >> new_pin2;
      cout << endl;
    }
    pinnumber= new_pin2;
    cout << "pin number has been updated! " << endl;
    cout << endl;
  }
  else if (pin!= pinnumber) 
  {
    do {
      cout << "Wrong pin number, please re-enter: ";
      cin >> pin;
    } while (pin != pinnumber);
    change_pin();
  }
  
}

void ATM::transfer_money() //Transfer function
{
  float Transfer_money = 0.0;//Define the variable to store the amount to be transferred
  int tacc;
    cout<<"account number in which you want to transfer money"<<endl;
  cin>>tacc;
  cout << "Please enter the amount to be transferred" << endl;
  cin >> Transfer_money;
  if (Transfer_money > money)//If the transfer amount is greater than the total amount
    cout << "Insufficient account balance" << endl;
  else            //The transfer amount is less than the total amount
  {
    money -= Transfer_money;
    cout << "The operation is successful, your balance is" << money << endl;
  }
  
}

void ATM::check_remain_money() {      //Check balances
  cout << "Your balance is" << money << endl;
  
}



int main()
{
    cout<<"project topic-ATM management system"<<endl;
    cout<< "Name-Dipali kamble(22) and Manjiri Ahirrao(47)"<<endl;
    
  //Define the ATM class object atm, calling the constructor to assign values ??to the private member
  ATM atm( 88888,0);
  

  
  int pinnumber;
  int j = 0;
  int choice = 0;
  //calling check_pinnumber function and stores the output in the choice variable
  choice = atm.check_pin(pinnumber);
  //while loop will run only if choice =1 and then it will performs the requested action.
  while (choice)
  {
    cout << "Please choose your needs: \n1. Deposit money \n2. Withdraw money \n3. Change pin \n4. Transfer \n5. Check balance \n6. Exit" << endl;
    cin >> j;
    switch (j)
    {
    case 1:{atm.accountType();
     atm.deposit();
        break;}
    case 2:{
          atm.accountType();
          atm.widrawing(); 
        break;}
    case 3:{atm.change_pin();
        break;}
    case 4:{
           atm.accountType();
           atm.transfer_money(); 
       break;}
    case 5:{atm.check_remain_money();
       break;}
    case 6:{break;}
    default:break;
    }
    if (j==6)break;
    if(j != 1 && j != 2 && j != 3 && j != 4 &&j != 5&&j!=6){
      cout<<"Please enter the correct command!"<<endl;
      exit(1);
    }
  }
  return 0;
}


