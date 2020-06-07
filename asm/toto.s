 	 	
.name "zork"
 	 	 
.comment "I'M ALIVE"
 	
l2:		sti r99,  1, %2147483648
		live %2147483647

live:	live %1
		zjmp %:live		

