StackProblems: stackproblem.c
	gcc -Wall -ggdb  -o stackProblems stackproblem.c -lm 		

linkedListProblems: linkedlistproblem.c  
	gcc -Wall -ggdb  -o linkedListProblems linkedlistproblem.c -lm 		

clean: 
	rm -f linkedListProblems
	rm -f stackProblems
