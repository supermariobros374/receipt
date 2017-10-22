#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

void compare(){ 

for(int i = 0;;i++){
	

}

} 

int main(){
	//compare();
	int tebiejiang = 99768846, tejiang = 83660478, tou1 = 70628612, tou2 = 87596250, tou3 = 97294175;
	int zengkai = 904;

	string scode;
	cout << "Please enter your RECEIPT NUMBER:";
	while(getline(cin , scode))
	{
	int icode = atoi(scode.c_str());

	
	if(tebiejiang==icode)
		cout<< "Congrats! You won the $10M TEBIEJIANG!" << endl;
	else if(tejiang==icode)
		cout<< "Congrats! You won the $2M TEJIANG!" << endl;
	else if((icode==tou1) || (icode==tou2) || (icode==tou3))
		cout<< "Congrats! You won the $200K TOUJIANG!" << endl;
	else if(((icode-tou1)%10000000==0) || ((icode-tou2)%10000000==0) || ((icode-tou3)%10000000==0))
		cout<< "Congrats! You won the $40K ERJIANG!" << endl;
	else if(((icode-tou1)%1000000==0) || ((icode-tou2)%1000000==0) || ((icode-tou3)%1000000==0))
		cout<< "Congrats! You won the $10K SANJIANG!" << endl;	
	else if(((icode-tou1)%100000==0) || ((icode-tou2)%100000==0) || ((icode-tou3)%100000==0))
		cout<< "Congrats! You won the $4K SIJIANG!" << endl;
	else if(((icode-tou1)%10000==0) || ((icode-tou2)%10000==0) || ((icode-tou3)%10000==0))
		cout<< "Congrats! You won the $1K WUJIANG!" << endl;
	else if(((icode-tou1)%1000==0) || ((icode-tou2)%1000==0) || ((icode-tou3)%1000==0) || ((icode-zengkai)%1000==0))
		cout<< "Congrats! You won the $200 LIUJIANG!" << endl;	
	else if(((icode-tou1)%1000==0) || ((icode-tou2)%1000==0) || ((icode-tou3)%1000==0) || ((icode-zengkai)%1000==0))
		cout<< "Congrats! You won the $200 LIUJIANG!" << endl;	
	else if(((icode-tou1)%1000!=0) && ((icode-tou2)%1000!=0) && ((icode-tou3)%1000!=0) && ((icode-zengkai)%1000!=0))
		cout<< "Poor you, there's nothing you've got!" << endl;	
	cout << "Please enter your RECEIPT NUMBER:";}
}
