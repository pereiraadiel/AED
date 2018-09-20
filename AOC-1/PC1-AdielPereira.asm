# Primeiro Para Casa de AOC1
#     AUTOR:>
#	Aluno: Adiel Pereira Prado 
# 	Matricula: 11721BCC008
# 	3° Periodo - 2018-2
.data # a partir deste ponto tudo abaixo eh dados
$numerador: .asciiz "Numerador: " # a variavel $numerador eh instanciada com a string "Numerador: "
$denominador: .asciiz "Denominador: " # A variavel $denominador eh instanciada com a string "Denominador:"
$quociente: .asciiz "Quociente: " #A variavel $quociente eh instanciada com a string "Qouociente"
$resto: .asciiz "Resto: "# A variavel $resto eh instanciada com a string "Quociente"

.text # a partir desses ponto tudo abaixo eh codigo
main: #funcao principal
	li $v0,4 # configura o tipo de dado para impressao de string na tela
	
	li $a0,$numerador #coloca o conteudo de $numerador para ser impresso na tela
	syscall #chamada de funcao do SO para impressao na tela de uma string
	jal ler_inteiro #chama a funcao de leitura de inteiros
	la $s0, 0($v0) # carrega o inteiro lido em $s0
	
	li $v0,4 # configura o tipo de dado para impressao de string na tela
	li $a0,$denominador #coloca o conteudo de $denominador para ser impresso na tela
	syscall  #chamada de funcao do SO para impressao na tela de uma string
	jal ler_inteiro #chama a funcao de leitura de inteiros (jump)
	la $s1, 0($v0) # carrega o inteiro lido em $s0
	
	div $t7, $s0, $s1 # divide o conteudo de $s0 pelo conteudo de $s1 e guarda em #$t7 (quociente)
	li $v0,4 # configura o tipo de dado para impressao de string na tela
	li $a0,$quociente #coloca o conteudo de $quociente para ser impresso na tela
	syscall #chamada de funcao do SO para impressao na tela de uma string
	jal imprime_inteiro
	
	
	li $v0,4 # configura o tipo de dado para impressao de string na tela
	li $a0,$resto #coloca o conteudo de $resto para ser impresso na tela
	syscall #chamada de funcao do SO para impressao na tela de uma string
	
	li $v0, 10 # codigo para finalizar o programa
	syscall # chamada do SO (finalizar)
	
ler_inteiro: #funcao de leitura de inteiros
	li $v0,5 # configura o tipo de dado para leitura de inteiro
	syscall #executa a chamada de sistema (para leitura)
	jr $ra # retorna para onde a funcao foi chamada
	
imprime_inteiro: #funcao para impressao de um inteiro na tela
	li $v0, 1	# código para imprimir um inteiro
	la $a0, ($t7)	# carrega o conteudo de $t7 3m $a0 para ser impresso
	syscall		# executa a chamada do SO (para imprimir)
	jr $ra		# retorna para onde a funcao foi chamada
		
resto: #funcao para obter o resto de uma divisao inteira
    bgt $t0, 5, exit        # se $t0 > 5, interrompa laço
    move $v0, $t0           # registrador = $t0
    addiu $t0, $t0, 1       # incrementa índice
    j resto					# volta para o inicio do laço

exit: