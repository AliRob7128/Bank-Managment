#include "AccountHolder.h"

class Customer : public AccountHolder{
	
	int account_numb;
	int bal;
	int points;
	AccountHolder *ptr;
	
	public:	
	Customer();
	Customer(int b , int p);
	int interest_rate(Customer &obj);
	int get_account_numb();
	int get_bal();
	int get_points();
	void set_account_numb(int n);
	void set_bal(int b);
	void set_points(int p);
	bool check_account_numb();
	void withdraw(int x);
	void display();
	
};
