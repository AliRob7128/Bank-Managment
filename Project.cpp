#include<fstream>
#include<time.h>
#include"Employee.h"


AccountHolder ::	AccountHolder(){
		srand(time(NULL));
		account_type = (char*)"";
		cc_numb = rand();
		name = (char*)"";
		cnic = (char*)"";
	}
	
AccountHolder ::	AccountHolder(char* at, int cn, char* n, char* c){
		account_type = at;
		cc_numb = rand();
		name = n;
		cnic = c;

	}
	
char* AccountHolder :: get_account_type(){
		return account_type;
	}
	
char* AccountHolder :: get_name(){
		return name;
	}

int AccountHolder :: get_cc_numb(){
		return cc_numb;
	}
	
char* AccountHolder :: get_cnic(){
		return cnic;
	}
	
void AccountHolder :: set_account_type(char* s){
		account_type = s;
	}
	
	
void AccountHolder :: set_name(char* n){
		name = n;
	}
	
void AccountHolder :: set_cnic(char* n){
		cnic = n;
	}
	
	
	

		

	
bool AccountHolder :: check_cc_numb(){
		int n;
		cout<<"Enter Card Number: ";
		cin>>n;
		if(n==cc_numb){
			return true;
		}
		else
		{
			return false;
		}
	}
	

	
bool AccountHolder :: check_cnic(){
		char* n;
		cout<<"Enter CNIC: ";
		cin>>n;
		if(n==cnic){
			return true;
		}
		else
		{
			return false;
		}
	}
	

Customer :: 	Customer(){
		srand(time(NULL));
		bal = 0;
		points = 0;
		account_numb =rand();
	}
	
Customer :: 	Customer(int b , int p){
		bal = b;
		points = p;
		account_numb = rand();
	}
int Customer ::  interest_rate(Customer &obj){
		int interest;
		if (obj.get_account_type() == "Current"){
			interest = 0;
		}
		else
		{
			interest = obj.get_bal()*0.01;
		}
		return interest;
	}
	
int Customer :: get_account_numb(){
		return account_numb;
	}
	
int Customer :: get_bal(){
		return bal;
	}
	
int Customer :: get_points(){
		return points;
	}
	
void Customer :: set_account_numb(int n){
		account_numb = n;
	}
void Customer :: set_bal(int b){
		bal = b;
	}
	
void Customer :: set_points(int p){
		points = p;
	}

bool Customer :: check_account_numb(){
		int n;
		cout<<"Enter Account Number: ";
		cin>>n;
		if(n==account_numb){
			return true;
		}
		else
		{
			return false;
		}
	}

void Customer :: withdraw(int x){
		int i;
		cout<<"Choose Option: "<<endl;
		cout<<"1. Master Card."<<endl;
		cout<<"2. Visa Card."<<endl;
		cout<<"3. Local Card."<<endl;
		cout<<"4. Cheque Book."<<endl;
		cin>>i;
		
		if(i==1){
			int amount, service_charge;
			amount = get_bal();
			if(x < 50000){
				if(check_cc_numb() == true){
					if(x > 5000){
						x+=(0.002*amount);
					}
					else if(x > 50000){
						x+=(0.025*amount);
					}
					x += (x*0.18);
					if(x < amount){
						cout<<"Amount to be withdrawn: "<<x<<endl;
						amount = amount - x;
						set_bal(amount);
						ofstream ofile;
						ofile.open(get_name(), ios :: app);
						if(ofile.is_open()){
							ofile<<amount<<endl;
						}
						ofile.close();
					}
					else{
						cout<<"Insufficent balance."<<endl;
					}			
				}
				else
				{
					cout<<"PIN Incorrect."<<endl;
				}	
			}
			else
			{
				cout<<"Limit Exceeded."<<endl;
			}			
		}
		
		else if(i==2){
			int amount;
			amount = get_bal();
			if(x < 100000){
				if(check_cc_numb() == true){
					if(x > 5000){
						x+=(0.002*amount);
					}
					else if(x > 50000){
						x+=(0.025*amount);
					}
					x += (x*0.1);
					if(x < amount){
						cout<<"Amount to be withdrawn: "<<x<<endl;
						amount = amount - x;
						set_bal(amount);
						set_points(x);
						cout<<"Usage Points Earned: "<<x<<endl;
						ofstream ofile;
						ofile.open(get_name(), ios :: app);
						if(ofile.is_open()){
							ofile<<amount<<endl;
						}
						ofile.close();
					}
					else{
						cout<<"Insufficent balance."<<endl;
					}			
				}
				else
				{
					cout<<"PIN Incorrect."<<endl;
				}	
			}
			else
			{
				cout<<"Limit Exceeded."<<endl;
			}				
		}
		
		else if(i==3){
			int amount;
			amount = get_bal();
			if(x < 10000){
				if(check_cc_numb() == true){
					if(x > 5000){
						x+=(0.002*amount);
					}
					else if(x > 50000){
						x+=(0.025*amount);
					}
					x += (x*0.25);
					if(x < amount){
						cout<<"Amount to be withdrawn: "<<x<<endl;
						amount = amount - x;
						set_bal(amount);
						ofstream ofile;
						ofile.open(get_name(), ios :: app);
						if(ofile.is_open()){
							ofile<<amount<<endl;
						}
						ofile.close();
					}
					else{
						cout<<"Insufficent balance."<<endl;
					}			
				}
				else
				{
					cout<<"PIN Incorrect."<<endl;
				}	
			}
			else
			{
				cout<<"Limit Exceeded."<<endl;
			}		
		}
		
		else if(i==4){
			int amount;
			amount = get_bal();
			if(check_account_numb() && check_cnic() == true){
				if(x < amount){
					cout<<"Amount to be withdrawn: "<<x<<endl;
					if(x > 5000){
						x+=(0.002*amount);
					}
					else if(x > 50000){
						x+=(0.025*amount);
					}
					amount = amount - x;
					set_bal(amount);
					ofstream ofile;
					ofile.open(get_name(), ios :: app);
					if(ofile.is_open()){
						ofile<<amount<<endl;
					}
					ofile.close();
				}
				else
				{
					cout<<"Insufficient Balance."<<endl;
				}
			}		
		}
	}
	
void Customer :: display(){
		cout<<"========================================"<<endl;
		cout<<"Account Type: "<<get_account_type()<<endl;
		cout<<"Credit Card Number: "<<get_cc_numb()<<endl;
		cout<<"Name: "<<get_name()<<endl;
		cout<<"CNIC: "<<get_cnic()<<endl;
		cout<<"Balance: "<<get_bal()<<endl;
		cout<<"Account Number: "<<get_account_numb()<<endl;
		cout<<"========================================"<<endl;
	}		



Employee :: 	Employee(){
		password = 12345;
	}
	
int Employee :: get_pass(){
		return password;
	}
	
void Employee :: acc_write(){
		string a,b,c,d;
		int x,y,z;
		ofstream ofile;
		ofile.open("accounts.txt", ios :: app);
		if(ofile.is_open()){
			ofile<<endl;
			cout<<"Enter Account Type: ";
			cin>>a;
			cout<<"Enter Credit Card Number: ";
			cin>>y;
			cout<<"Enter Name: ";
			cin>>c;
			cout<<"Enter Cnic: ";
			cin>>d;
			z = get_account_numb();
			ofile<<z<<"    "<<a<<"      "<<y<<"       "<<c<<"        "<<d;
			
		}
		ofile.close();
	}




int main(){
	Employee e;
	Customer c;
	c.set_account_type((char*)"Current");
	c.set_bal(30000);
	c.set_cnic((char*)"123432");
	c.set_name((char*)"Ali");
	c.display();
	int n,o,p,w_draw;
	cout<<"1. Login as Bank Employee."<<endl;
	cout<<"2. Login as Bank Customer."<<endl;
	cin>>n;
	if(n==1){
		int p;
		cout<<"Enter Password: ";
		cin>>p;
		if(p==e.get_pass()){
			cout<<"1. Create New Account."<<endl;
			cout<<"2. Delte Account."<<endl;
			cout<<"3. Update Account."<<endl;
			cout<<"4. Deposit to an Account."<<endl;
			cout<<"5. Withdrawl from an Account."<<endl;
			cout<<"6. Display all Accounts."<<endl;
			cin>>p;
			if(p == 1){
				e.acc_write();
			}
			else if(p == 4){
				int x;
				cout<<"Enter amount to Deposit: ";
				cin>>x;
				e.set_bal(e.get_bal()+x);
				cout<<"New amount: "<<e.get_bal()+x;
			}
			else if(p == 5){
				int y;
				cout<<"Enter amount to Withdraw: ";
				cin>>y;
				e.set_bal(e.get_bal()-y);
				cout<<"New amount: "<<e.get_bal()-y;
			}
			else if(p==6){
				string line;
				cout<<"ACC/No     ACC/Type   CC/No   Name       CNIC        Balance     Points "<<endl;
				cout<<"========================================================================"<<endl;
				ifstream ifile;
				ifile.open("accounts.txt", ios :: in);
				if(ifile.is_open()){
					while(!ifile.eof()){
						getline(ifile,line);
						cout<<line<<endl;
					}
				}
				ifile.close();
			}
		}
	}
			
	else if(n==2){
		cout<<"1. Mini Statement."<<endl;
		cout<<"2. Withdrawl."<<endl;
		cout<<"3. Balance Inquiry."<<endl;
		cin>>o;
		if(o==1){
			int x;
			char* y;
			cout<<"Enter Account Number: ";
			cin>>x;
			cout<<"Enter CNIC: ";
			cin>>y;
			if(c.get_account_numb() == x && c.get_cnic() == y){
				string s;
				s = c.get_name();
				ifstream ifile;
				ifile.open(s, ios :: in);
				if(ifile.is_open()){
					while(!ifile.eof()){
						getline(ifile,s);
						cout<<s<<endl;
					}
				}
			}
		}
		
		else if(o==2){
			cout<<"Enter amount to withdraw: ";
			cin>>w_draw;
			c.withdraw(w_draw);
			c.display();
		
		}
		else if(o==3){
			int x;
			char* y;
			cout<<"Enter Account Number: ";
			cin>>x;
			cout<<"Enter CNIC: ";
			cin>>y;
			if(c.get_account_numb() == x && c.get_cnic() == y){
				cout<<"Amount in Account: "<<c.get_bal()<<endl;
			}
		}
	}
}
