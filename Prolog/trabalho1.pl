
%progressao aritmetica com calda
pa(1,B,R,B).
pa(A,B,R,S):-
	B1 is B+R,
	A1 is A-1,
	pa(A1,B1,R,S),!.

%--------- EXERCICIO 2 ----------

%soma de A termos de uma progressao aritmetica
soma_pa(1,B,R,B).
soma_pa(A,B,R,S):-
	B1 is B + R,
	S is B + B1,
	S1 is S+B1,
	A1 is A-1,
	soma_pa(A1,B1,R,S1),!.


%---------- EXERCICIO 3 ----------
	1. X = a
	2. X = []
	3. false
	4. X=[a]
	5. false
	6. X = a,
	   Y = b
	7. false
	8. X = a,
	   Y = b,
	   Z = c
	9. false.
	10. X = a,
	    Y = b
	11. X = a,
		Y = []
	12. false
	13. X = a,
		Y = [b,c]
	14. X = a,
		Y = b,
		Z = [c]
	15. X = a,
		Y = b,
		Z = []
	16. false
	17. X = a,
		Y = b,
		Z = [c,d]
	18. X = a,
		Y = b,
		Z = [a]
	19. X = Z,
		Z = [a],
		Y = b

%--------- EXERCICIO 4 ------------
n_esimo_lista(1,[X,Y],X).
n_esimo_lista(N,[X|Y],S):-
	S1 is N,
	N1 is N-1,
	n_esimo_lista(N1,X,S1),!.