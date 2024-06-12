Consider a function roll(S, n, k) that can be applied to a stack S. 
The roll function rotates the top n ≥ 0 elements of stack S by k ≥ 0 positions in a
circular fashion. Figure 6 illustrates three examples of the roll function
Consider a function roll(S, n, k) that can be applied to a stack S. 
The roll function rotates the top n ≥ 0 elements of stack S by k ≥ 0 positions in a
circular fashion. Figure 6 illustrates three examples of the roll function

Algorithm: roll(Stack s,int n,int k)
2 if n < 0 or k < 0 or n > s.size() then return;
3 Initialize array arr of length n;
4 for i=0 to n-1 do arr[i] = s.pop(); ;
5 for i=n-1 to 0 do s.push(arr[(i+k) mod n]); ;
