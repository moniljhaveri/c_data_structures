StackProblems: stackproblem.c
	gcc -Wall -ggdb  -o stackProblems stackproblem_2.c -lm 		

linkedListProblems: linkedlistproblem.c  
	gcc -Wall -ggdb  -o linkedListProblems linkedlistproblem.c -lm 		

clean: 
	rm -f linkedListProblems
	rm -f stackProblems
