inicio :-
	write('[a] especifica evidencia'),nl, %evidencias caracteristicas do animal
	write('[b] visualiza evidencia'),nl,
	write('[c] advinhe'),nl,
	write('[d] remove respostas'),nl,
	write('[x] SAIR'),nl,
	le_atomo(Op),
	execut(Op).

le_atomo(Op) :-
 	le_str(Str),
 	name(Op,Str).

le_str(String) :-
    get0(Char),
    le_str_aux(Char, String).
    le_str_aux(-1, []) :- !. % EOF
    le_str_aux(10, []) :- !. % EOL(UNIX)
    le_str_aux(13, []) :- !. % EOL (DOS)
    le_str_aux(Char, [Char|Resto]) :-
    le_str(Resto).



execut(Op) :-
	Op = 'x', nl, write('Vlw Flw!').

execut(Op) :- 
	Op = 'a', nl,hipotetiza(Animal),inicio.

execut(Op) :- 
	Op = 'b', nl,inicio.

execut(Op) :- 
	Op = 'c', advinhe,inicio.

execut(Op) :- 
	Op = 'd', removeRespostas,inicio.

execut(Op) :- nl,fail.

advinhe :-
	hipotetiza(Animal),
	write('O animal eh: '),
	write(Animal),
	nl.

/* hipoteses a serem testadas*/

hipotetiza(avestruz) :- avestruz, !.
hipotetiza(albatroz) :- albatroz, !.
hipotetiza(pinguim) :- pinguim, !.
hipotetiza(breno) :- breno,!.
hipotetiza(tigre) :- tigre, !.
hipotetiza(girafa) :- girafa, !.
hipotetiza(zebra) :- zebra, !.
hipotetiza(leopardo) :- leopardo, !.
hipotetiza(canguru) :- canguru,!.
hipotetiza(desconhecido). /* nao diagnosticado */

/* regras de identifica��o do animal */
canguru :-
    mamifero,
    verifica(pula),
    verifica(eh_nativo_da_australia).
leopardo :-
	mamifero,
	carnivoro,
	verifica(tem_manchas_escuras).
tigre :-
	mamifero,
	carnivoro,
	verifica(tem_listras_pretas).
breno :-
	mamifero,
	verifica(eh_babaca),
	verifica(manja_rola),
	verifica(eh_um_pau_no_cu).
girafa :-
	ungulado,
	verifica(tem_pescoco_grande),
	verifica(tem_pernas_grandes).
zebra :-
	ungulado,
	verifica(tem_listras_pretas).
avestruz :-
	passaro,
	verifica(nao_voa),
	verifica(tem_pescoco_grande).
pinguim :-
	passaro,
	verifica(nao_voa),
	verifica(nada),
	verifica(branco_e_preto).
albatroz :-
	passaro,
	verifica(aparece_em_estoria_de_marinheiro),
	verifica(voa).

/* regras de classifica��o */

mamifero :-
	verifica(tem_pelo), !.
mamifero :-
	verifica(amamenta).
passaro :-
	verifica(tem_penas), !.
passaro :-
	verifica(voa),
	verifica(poe_ovos).
carnivoro :-
	verifica(come_carne), !.
carnivoro :-
	verifica(tem_dentes_pontiagudos),
	verifica(tem_garras).
ungulado :-
	mamifero,
	verifica(tem_cascos), !.
ungulado :-
	mamifero,
	verifica(rumina).

/* formulando perguntas */
pergunta(Pergunta) :-
	write('Seu animal tem a seguinte caracteristica: '),
	write(Pergunta),
	write('? '),
	read(Resposta),
	nl,
	trate(Pergunta,Resposta).

trate(Pergunta,Resposta) :-
	Resposta == s,
	assert(sim(Pergunta)),!.
trate(Pergunta,_) :-
	assert(nao(Pergunta)),fail.

:- dynamic sim/1,nao/1.

/* verificando */

verifica(S) :- sim(S),!.
verifica(S) :- nao(S),!, fail.
verifica(S) :- pergunta(S).

/* remove todas as assercoes de sim e nao */

removeRespostas :- retractall(sim(_)), retractall(nao(_)), fail.

removeRespostas :- abolish(sim/1), abolish(nao/1),dynamic(sim/1),dynamic(nao/1).
