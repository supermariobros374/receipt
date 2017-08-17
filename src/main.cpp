#include <vector>
#include <iostream>
#include <string>

/*
	if you wanna use this function, you have to declare it.
	this function was parcticed in online_get.cpp
	open that file to check how it work
	
	following code can be put in main.cpp or another custom header you will included 
*/
void online_get_invoice(std::vector<std::string>&);

int main(){

	std::vector<std::string> invoice_sto;
    online_get_invoice(invoice_sto);

/*
	following code is for testing result of online_get_invoice return
	it's can be commented or deleted
	
	***** if you write some codes for testing 
	***** you can just deleted its indentation to mark as "codes for testing"
	***** like following
*/
for(std::vector<std::string>::iterator iter = invoice_sto.begin();
	iter != invoice_sto.end(); iter++)
{
	std::cout << (*iter) << std::endl;
}
	
	return 0;
}
