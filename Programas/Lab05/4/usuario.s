	.file	"usuario.c"
	.text
	.globl	cria_lista
	.type	cria_lista, @function
cria_lista:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$4004, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L2
	movq	-8(%rbp), %rax
	movl	$0, 4000(%rax)
.L2:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	cria_lista, .-cria_lista
	.globl	apaga_lista
	.type	apaga_lista, @function
apaga_lista:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	apaga_lista, .-apaga_lista
	.globl	lista_vazia
	.type	lista_vazia, @function
lista_vazia:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	4000(%rax), %eax
	testl	%eax, %eax
	jne	.L6
	movl	$1, %eax
	jmp	.L7
.L6:
	movl	$0, %eax
.L7:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	lista_vazia, .-lista_vazia
	.globl	lista_cheia
	.type	lista_cheia, @function
lista_cheia:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	$1000, %eax
	jne	.L9
	movl	$1, %eax
	jmp	.L10
.L9:
	movl	$0, %eax
.L10:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	lista_cheia, .-lista_cheia
	.globl	insere_elem
	.type	insere_elem, @function
insere_elem:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L12
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	lista_cheia
	testl	%eax, %eax
	je	.L13
.L12:
	movl	$0, %eax
	jmp	.L14
.L13:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	leal	1(%rax), %ecx
	movq	-24(%rbp), %rdx
	movl	%ecx, 4000(%rdx)
	movq	-24(%rbp), %rdx
	cltq
	movl	-28(%rbp), %ecx
	movl	%ecx, (%rdx,%rax,4)
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jge	.L15
	movl	$1, %eax
	jmp	.L14
.L15:
	movl	$0, %eax
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	insere_elem, .-insere_elem
	.globl	insere_elem_ord
	.type	insere_elem_ord, @function
insere_elem_ord:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L17
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	lista_cheia
	testl	%eax, %eax
	je	.L18
.L17:
	movl	$0, %eax
	jmp	.L19
.L18:
	movl	$0, -8(%rbp)
	jmp	.L20
.L23:
	movq	-24(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cmpl	%eax, -28(%rbp)
	jl	.L27
	addl	$1, -8(%rbp)
.L20:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jl	.L23
	jmp	.L22
.L27:
	nop
.L22:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	subl	$1, %eax
	cmpl	%eax, -8(%rbp)
	jle	.L24
	movq	-24(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	movl	-28(%rbp), %ecx
	movl	%ecx, (%rax,%rdx,4)
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4000(%rax)
	movl	$1, %eax
	jmp	.L19
.L24:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	movl	%eax, -4(%rbp)
	jmp	.L25
.L26:
	movl	-4(%rbp), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %ecx
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	subl	$1, -4(%rbp)
.L25:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jg	.L26
	movq	-24(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	movl	-28(%rbp), %ecx
	movl	%ecx, (%rax,%rdx,4)
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4000(%rax)
	movl	$1, %eax
.L19:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	insere_elem_ord, .-insere_elem_ord
	.globl	remove_elem
	.type	remove_elem, @function
remove_elem:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L29
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	lista_vazia
	testl	%eax, %eax
	je	.L30
.L29:
	movl	$0, %eax
	jmp	.L31
.L30:
	movl	$0, -8(%rbp)
	jmp	.L32
.L37:
	movq	-24(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cmpl	%eax, -28(%rbp)
	jne	.L33
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jne	.L34
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4000(%rax)
	movl	$1, %eax
	jmp	.L31
.L34:
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L35
.L36:
	movl	-4(%rbp), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %ecx
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -4(%rbp)
.L35:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L36
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4000(%rax)
	movl	$1, %eax
	jmp	.L31
.L33:
	addl	$1, -8(%rbp)
.L32:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jl	.L37
	movl	$0, %eax
.L31:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	remove_elem, .-remove_elem
	.globl	remove_elem_ord
	.type	remove_elem_ord, @function
remove_elem_ord:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L39
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	lista_vazia
	testl	%eax, %eax
	je	.L40
.L39:
	movl	$0, %eax
	jmp	.L41
.L40:
	movl	$0, -8(%rbp)
	jmp	.L42
.L47:
	movq	-24(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cmpl	%eax, -28(%rbp)
	jne	.L43
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jne	.L44
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4000(%rax)
	movl	$1, %eax
	jmp	.L41
.L44:
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L45
.L46:
	movl	-4(%rbp), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %ecx
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -4(%rbp)
.L45:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L46
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4000(%rax)
	movl	$1, %eax
	jmp	.L41
.L43:
	addl	$1, -8(%rbp)
.L42:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jl	.L47
	movl	$0, %eax
.L41:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	remove_elem_ord, .-remove_elem_ord
	.globl	remove_todos
	.type	remove_todos, @function
remove_todos:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L49
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	lista_vazia
	testl	%eax, %eax
	je	.L50
.L49:
	movl	$0, %eax
	jmp	.L51
.L50:
	movl	$0, -12(%rbp)
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	movl	%eax, -4(%rbp)
	jmp	.L52
.L57:
	movq	-24(%rbp), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cmpl	%eax, -28(%rbp)
	jne	.L53
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	jne	.L54
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4000(%rax)
	movl	$1, %eax
	jmp	.L51
.L54:
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L55
.L56:
	movl	-8(%rbp), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %ecx
	movq	-24(%rbp), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	addl	$1, -8(%rbp)
.L55:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	subl	$1, %eax
	cmpl	%eax, -8(%rbp)
	jl	.L56
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4000(%rax)
	jmp	.L52
.L53:
	addl	$1, -12(%rbp)
.L52:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -12(%rbp)
	jl	.L57
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jle	.L58
	movl	$1, %eax
	jmp	.L51
.L58:
	movl	$0, %eax
.L51:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	remove_todos, .-remove_todos
	.section	.rodata
.LC0:
	.string	"Lista\n{"
.LC1:
	.string	"%d "
.LC2:
	.string	"%d"
.LC3:
	.string	"}"
	.text
	.globl	print_lista
	.type	print_lista, @function
print_lista:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -4(%rbp)
	jmp	.L60
.L63:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	subl	$1, %eax
	cmpl	%eax, -4(%rbp)
	jge	.L61
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L62
.L61:
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L62:
	addl	$1, -4(%rbp)
.L60:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L63
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	print_lista, .-print_lista
	.globl	delay
	.type	delay, @function
delay:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L65
.L68:
	movl	$0, -4(%rbp)
	jmp	.L66
.L67:
	addl	$1, -4(%rbp)
.L66:
	cmpl	$99999999, -4(%rbp)
	jle	.L67
	addl	$1, -8(%rbp)
.L65:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L68
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	delay, .-delay
	.section	.rodata
.LC4:
	.string	"========================"
.LC5:
	.string	"        Intercalar"
.LC6:
	.string	"------------------------"
.LC7:
	.string	"[0] Sair."
.LC8:
	.string	"[1] Usar novas listas."
.LC9:
	.string	"[2] Usar lista anterior."
	.align 8
.LC10:
	.string	"Quantos elementos na lista 1? "
.LC11:
	.string	"Elemento %d: "
	.align 8
.LC12:
	.string	"Quantos elementos na lista 2? "
	.text
	.globl	menu_intercala
	.type	menu_intercala, @function
menu_intercala:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -44(%rbp)
	movl	$0, -40(%rbp)
	movl	$0, %eax
	call	cria_lista
	movq	%rax, -32(%rbp)
	movl	$0, %eax
	call	cria_lista
	movq	%rax, -24(%rbp)
.L70:
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
	leaq	.LC7(%rip), %rdi
	call	puts@PLT
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	leaq	.LC9(%rip), %rdi
	call	puts@PLT
	movl	$58, %edi
	call	putchar@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-48(%rbp), %eax
	cmpl	$1, %eax
	je	.L72
	cmpl	$2, %eax
	je	.L73
	testl	%eax, %eax
	je	.L74
	jmp	.L88
.L72:
	movq	-32(%rbp), %rax
	testq	%rax, %rax
	je	.L75
	movq	-24(%rbp), %rax
	testq	%rax, %rax
	jne	.L76
.L75:
	movl	$0, %eax
	jmp	.L86
.L76:
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, -36(%rbp)
	jmp	.L78
.L79:
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %edx
	movq	-32(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insere_elem
	addl	$1, -36(%rbp)
.L78:
	movl	-44(%rbp), %eax
	cmpl	%eax, -36(%rbp)
	jl	.L79
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, -36(%rbp)
	jmp	.L80
.L81:
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insere_elem
	addl	$1, -36(%rbp)
.L80:
	movl	-44(%rbp), %eax
	cmpl	%eax, -36(%rbp)
	jl	.L81
	movq	-24(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	intercala_ord
	movq	%rax, -16(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	apaga_lista
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	apaga_lista
	movq	-16(%rbp), %rax
	jmp	.L86
.L73:
	movq	-56(%rbp), %rax
	testq	%rax, %rax
	je	.L82
	movq	-24(%rbp), %rax
	testq	%rax, %rax
	jne	.L83
.L82:
	movl	$0, %eax
	jmp	.L86
.L83:
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$0, -36(%rbp)
	jmp	.L84
.L85:
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insere_elem
	addl	$1, -36(%rbp)
.L84:
	movl	-44(%rbp), %eax
	cmpl	%eax, -36(%rbp)
	jl	.L85
	movq	-56(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	intercala_ord
	movq	%rax, -16(%rbp)
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	apaga_lista
	leaq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	apaga_lista
	movq	-16(%rbp), %rax
	jmp	.L86
.L74:
	movl	$0, %eax
	jmp	.L86
.L88:
	jmp	.L70
.L86:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L87
	call	__stack_chk_fail@PLT
.L87:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	menu_intercala, .-menu_intercala
	.globl	intercala_ord
	.type	intercala_ord, @function
intercala_ord:
.LFB17:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, %eax
	call	cria_lista
	movq	%rax, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L90
.L91:
	movq	-24(%rbp), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insere_elem_ord
	addl	$1, -12(%rbp)
.L90:
	movq	-24(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -12(%rbp)
	jl	.L91
	movl	$0, -12(%rbp)
	jmp	.L92
.L93:
	movq	-32(%rbp), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insere_elem_ord
	addl	$1, -12(%rbp)
.L92:
	movq	-32(%rbp), %rax
	movl	4000(%rax), %eax
	cmpl	%eax, -12(%rbp)
	jl	.L93
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	intercala_ord, .-intercala_ord
	.section	.rodata
.LC13:
	.string	"clear"
.LC14:
	.string	"        Escolha"
.LC15:
	.string	"[1] Inserir elemento."
.LC16:
	.string	"[2] Remover elemento."
.LC17:
	.string	"[3] Mostrar lista."
.LC18:
	.string	"[4] Limpar lista."
.LC19:
	.string	"[5] Remover tds ocorrencias."
.LC20:
	.string	"[6] Intercalar duas listas."
.LC21:
	.string	"[0] Sair"
.LC22:
	.string	": "
.LC23:
	.string	"Elemento: "
.LC24:
	.string	"Sucesso!!"
.LC25:
	.string	"Falha!"
.LC26:
	.string	"Erro!!"
.LC27:
	.string	"Sucesso!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB18:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %eax
	call	cria_lista
	movq	%rax, -24(%rbp)
.L96:
	leaq	.LC13(%rip), %rdi
	call	system@PLT
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
	leaq	.LC14(%rip), %rdi
	call	puts@PLT
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
	leaq	.LC15(%rip), %rdi
	call	puts@PLT
	leaq	.LC16(%rip), %rdi
	call	puts@PLT
	leaq	.LC17(%rip), %rdi
	call	puts@PLT
	leaq	.LC18(%rip), %rdi
	call	puts@PLT
	leaq	.LC19(%rip), %rdi
	call	puts@PLT
	leaq	.LC20(%rip), %rdi
	call	puts@PLT
	leaq	.LC21(%rip), %rdi
	call	puts@PLT
	leaq	.LC22(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-32(%rbp), %eax
	cmpl	$6, %eax
	ja	.L96
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L99(%rip), %rax
	movl	(%rdx,%rax), %eax
	movslq	%eax, %rdx
	leaq	.L99(%rip), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L99:
	.long	.L98-.L99
	.long	.L100-.L99
	.long	.L101-.L99
	.long	.L102-.L99
	.long	.L103-.L99
	.long	.L104-.L99
	.long	.L105-.L99
	.text
.L98:
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	apaga_lista
	nop
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L116
	jmp	.L117
.L100:
	leaq	.LC23(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-28(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insere_elem
	testl	%eax, %eax
	je	.L107
	leaq	.LC24(%rip), %rdi
	call	puts@PLT
	jmp	.L108
.L107:
	leaq	.LC25(%rip), %rdi
	call	puts@PLT
.L108:
	movl	$1, %edi
	call	delay
	jmp	.L96
.L101:
	leaq	.LC23(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-28(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	remove_elem
	testl	%eax, %eax
	je	.L109
	leaq	.LC24(%rip), %rdi
	call	puts@PLT
	jmp	.L110
.L109:
	leaq	.LC25(%rip), %rdi
	call	puts@PLT
.L110:
	movl	$1, %edi
	call	delay
	jmp	.L96
.L102:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	print_lista
	movl	$8, %edi
	call	delay
	jmp	.L96
.L103:
	movl	$0, %eax
	call	cria_lista
	movq	%rax, -24(%rbp)
	jmp	.L96
.L104:
	leaq	.LC23(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-28(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	remove_todos
	testl	%eax, %eax
	je	.L111
	leaq	.LC24(%rip), %rdi
	call	puts@PLT
	jmp	.L112
.L111:
	leaq	.LC25(%rip), %rdi
	call	puts@PLT
.L112:
	movl	$1, %edi
	call	delay
	jmp	.L96
.L105:
	movl	$0, %eax
	call	cria_lista
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	menu_intercala
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	testq	%rax, %rax
	jne	.L113
	leaq	.LC26(%rip), %rdi
	call	puts@PLT
	jmp	.L96
.L113:
	movq	-16(%rbp), %rax
	movq	%rax, -24(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	apaga_lista
	leaq	.LC27(%rip), %rdi
	call	puts@PLT
	jmp	.L96
.L117:
	call	__stack_chk_fail@PLT
.L116:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	main, .-main
	.ident	"GCC: (GNU) 7.3.1 20180312"
	.section	.note.GNU-stack,"",@progbits
