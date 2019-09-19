#include "Customer.h"

class Employee : public Customer{
	int password;
	AccountHolder *ptr;
	
	public:
	Employee();
	int get_pass();
	void acc_write();

};
