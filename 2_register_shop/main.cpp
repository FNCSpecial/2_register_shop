#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <string>


/*
My cake shop is so popular, I’m adding some tables and hiring wait staff so folks can have a cute sit-down cake-eating experience.

I have two registers: one for take-out orders, and the other for the other folks eating inside the cafe. All the customer orders get combined into one list for the kitchen, where they should be handled first-come, first-served.

Recently, some customers have been complaining that people who placed orders after them are getting their food first. Yikes—that’s not good for business!

*/

//creating class for take out register. 

class Take_Out {
	//take out class 
public: std::string take_out_list[100];
	  //creating method that will add order to takeout list. 
public: void Add_take_out(int& i, std::string order) {
	//adding order to take out list
	take_out_list[i] = order;
	//incrementing the i , i  is like the order number its get incremented after adding something to list so that way i can have uniqe combine list. 
	i++;

}

};
//creating class for take in register. 
class Take_in {
public: std::string take_in_list[100];
	  // creating method that will add order to takein list.
public: void Add_take_in(int& i, std::string order) {
	//same steps as above
	take_in_list[i] = order;
	i++;
}
};



int main() {
	//the unique indetifier to list to make sure that orders are realesed first in first out. 
	int i = 0;
	//list for all orders
	std::string all_orders[200];
	//objects for take out and in class
	Take_Out take_out;
	Take_in take_in;
	//adding orders to list 
	take_out.Add_take_out(i, "test take out food 1");
	take_in.Add_take_in(i, "test take in food 1");
	take_out.Add_take_out(i, "test take out food 2");
	take_out.Add_take_out(i, "test take out food 3");
	take_in.Add_take_in(i, "test take in food 2");

	//iterating from 0 to i to add all the orders
	for (int j = 0; j < i; j++) {
		//checking if the take out list have any order at the index of J 
		if (take_out.take_out_list[j] != "")
		{
			all_orders[j] = take_out.take_out_list[j];
		}
		//if the take out list dont have any order it means that order must be in take in list so we will add it to all orders list.
		else {
			all_orders[j] = take_in.take_in_list[j];
		}
		//printing the orders to see if we are good to go 
		std::cout << all_orders[j] << std::endl;
	}

	
	return 0;
}
//seems to work fine, question is if i can use array of string and not an List strcture to complete the task
// also i am wasting a bit of space since not each array is being filled, a list would work better will do a follow up 