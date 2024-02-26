/*
	- The program should be menu driven. 
		[1] Deposit
		[2] Withdraw
		[3] View Client Record
		[4] Compute Interest
		[0] Exit
		Please choose ...
	
	- After ciient creates account, display the menu.

	- The program includes the following functions:  
		1. acceptAccNum () – accepts the account number of the client from the user and returns it to the caller. 
		2. acceptAmount () – accepts an amount from the user and returns it to the caller 
		3. computeDepBalance () – receives the balance and amount deposited from the caller, then returns the updated balance to the caller. 
		4. computeWithBalance() – receives the balance and amount withdrawn from the caller, then returns the new balance to the caller. 
		5. computeInt () – receives the balance from the caller, computes the annual interest and returns the interest to the caller. 
		6. displayClientRec () – receives all the information of the client and displays these to the screen.

	- PRGORAM FLOW:
		1. acceptAccNum()
		2. gets(cName)
		3. gets(address)
		4. acceptInitialBalance()
*/

acceptAccNum ();
acceptAmount ();
//	- shouldn't have a validation inside this function. Sa main ang validation.
computeDepBalance ();
computeWithBalance();
computeInt ();
displayClientRec ();

