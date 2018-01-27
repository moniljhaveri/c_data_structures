linkedListProblems: linkedlistproblem.c  
	gcc -Wall -ggdb  -o linkedListProblems linkedlistproblem.c -lm 		

clean: 
	rm -f linkedListProblems
