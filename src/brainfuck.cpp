#include <iostream>
using namespace std;

//prints out all the factors of an inputted number ended with "."
//only expects digits and dot
/*
+
++
++++
++++++++
++++++++++++++++
++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

-
--
----
--------
----------------
--------------------------------
----------------------------------------------------------------

46=++++++++++++++++++++++++++++++++++++++++++++++ (.)
48=++++++++++++++++++++++++++++++++++++++++++++++++ (0)

[-]++++++++++++++++++++++++++++++++++++++++++++++
[-]++++++++++++++++++++++++++++++++++++++++++++++++

- first make a sentinel of minus 1
>[-]	move to the next cell to store the number of digits (need at least one so start at 1)
>[-]-	another sentinel

read; subtract dot (make everything relative to dot)
++[
--	(if it wasn't dot then make it back into a digit
>,
--------
--------
--------
--------
--------
--------
	go back and add to count
	first mark a sentinel
	>[-]-
	then go back to the first sentinel
	+[-<+]-	(move left until minus 1)
	<+>		add to the count
	+[->+]-	(move right until minus 1)
	<		(go back to the justread cell)
++	check for dot
]//done
- (change dot to minus 1
first mark a sentinel (the former dot)
-


*/

//Hello World (wikip
// ++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.
const char* bf(const char* s){
	static char blah[1000]={0};
	static char* ptr=blah;

	while(*s)
		switch(*s++){
		case '-':	--*ptr;break;
		case '+':	++*ptr;break;
		case '<':	--ptr;break;
		case '>':	++ptr;break;
		case '[':{
			char const* c = bf(s);
			while(*ptr) bf(s);
			s=c;break;}
		case ']':	return s;
		case '.':	cout.put(*ptr);break;
		case ',':	*ptr = cin.get();break;
		}
	return s;
}


int main(){
	string s = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
	bf(s.c_str());
	
	return 0;
}