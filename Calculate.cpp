#include <iostream>
#include <string>

#define users 2
#define internet 3072
#define sms 1000
#define call 500

using namespace std;

/* I need to declare all functions before main function or functions will not be work. */
void User_Inputs(string name);
bool Checking_Inputs(int inputs, string name, string services);
void Calculating_Bill(int input1, int input2, int input3, int input4, int input5, int input6, string name);
void Printing_Bill(string name, int total);

int main(){
  for (int i = 0; i < users; ++i)
  {
    string name;
    cout << "Please enter your name: ";
    /* I used getline for merging first and last name. */
    getline(cin, name);
    /* Calling first function for user's inputs. */
    User_Inputs(name);
    cin.ignore();
  }
  return 0;
}

/* This function takes inputs from user. */
void User_Inputs(string name){
  /* Array for every inputs. First three inputs for user's usage of internet, SMS and calls other three is for user's additional packages. */
  int inputs[6];
  string services[3] = {", number of minutes cannot be smaller than 0",", number of SMSs cannot be smaller than 0.",", internet usage cannot be smaller than 0."};

  cout << name << ", please enter how many minutes you used this month: ";
  cin >> inputs[0];
  /* After every inputs program calls the checking input for values smaller than zero. */
  if(Checking_Inputs(inputs[0], name, services[0]) == false)
  {
    return User_Inputs(name);
  }
  cout << name << ", please enter how many SMSs you sent this month: ";
  cin >> inputs[1];
  if(Checking_Inputs(inputs[1], name, services[1]) == false)
  {
    return User_Inputs(name);
  }
  cout << name << ", please enter how many MBs you used this month: ";
  cin >> inputs[2];
  if(Checking_Inputs(inputs[2], name, services[2]) == false)
  {
    return User_Inputs(name);
  }
  cout << name << ", please specify how many additional packages you bought for calls, SMS and internet in this order: ";
  cin >> inputs[3] >> inputs[4] >> inputs[5];
  /* If every condition is okay program calls calculating function */
  Calculating_Bill(inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], name);
}
/* This function is checking user's input. If input is equal or bigger than zero result is true. On the other hand result is false and terminate program. Also this function printing
error messages. */
bool Checking_Inputs(int inputs, string name, string services){
  if(inputs >= 0)
    return true;
  else
  {
    cout << name << services << endl;
    return false;
  }
}
/* This function is takes all inputs from user and calculating bill */
void Calculating_Bill(int input1, int input2, int input3, int input4, int input5, int input6, string name){
  /* 'int base' is for price of base package */
  int base = 49;
  /* 'double total' is for totall price of bill. */
  double total = 0;
  double temp[2];
  /* This is for prices of additional packages */
  int additional = 0;
  /* Calculating price of additional packages */
  additional = ((input4 * 12) + (input5 * 12) + (input6 *12));
  total = base + additional;
  /* All if statements calculate calls, SMS and internet prices.*/
  if(input1 >= call + (input4 * 250))
  {
    temp[0] = call + (input4 * 250);
    temp[1] = input1 - temp[0];
    total = total + (temp[1] * 0.66);
  }

  if (input2 >= sms + (input5 * 250))
  {
    temp[0] = sms + (input5 * 250);
    temp[1] = input2 - temp[0];
    total = total + (temp[1] * 0.55);
  }

  if (input3 >= internet + (input6 * 1024))
  {
    temp[0] = (internet + (input6 * 1024)) * 1024;
    temp[1] = (input3 * 1024) - temp[0];
    /* Price of using 100KB internet is 1 TL. So i multiply with 0.01 because my variables value is MB*/
    total = total + (temp[1] * 0.01);
  }
  /* Calling printing function */
  Printing_Bill(name, total);
}
/* This function is printing total bill to screen. */
void Printing_Bill(string name, int total)
{
  if(total == 49)
    cout << name << ", total cost of your phone usage is " << total << "TL. You did not exceed your base package." << endl;
  if(total < 100 && total > 49)
    cout << name << ", total cost of your phone usage is " << total << "TL. You exceeded your base package." << endl;
  if(total >= 100)
    cout << name << ", total cost of your phone usage is " << total << "TL. You exceeded your base package too much. We suggest you to change your base package." << endl;
}