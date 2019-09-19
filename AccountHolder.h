#include<iostream>
using namespace std;

class AccountHolder{
	char* account_type;
	int cc_numb;
	char* name;
	char* cnic;

	
	public:
	AccountHolder();
	AccountHolder(char* at, int cn, char* n, char* c);
	char* get_account_type();
	char* get_name();
	int get_cc_numb();
	char* get_cnic();
	void set_account_type(char* s);
	void set_name(char* n);
	void set_cnic(char* n);
	bool check_cc_numb();
	bool check_cnic();
	
};
	

