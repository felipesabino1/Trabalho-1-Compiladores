	.text
	.globl main
main:
	j func_principal

	.text
func_principal:
	move $fp, $sp
	addiu $sp, $sp, -4
	addiu $sp, $sp, -4
	addiu $sp, $sp, -4
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	addiu $t2, $fp, -12
	lw $s0, 4($sp)
	addiu $sp, $sp, 4
	sw $s0, 0($t2)
L1:
	addiu $t2, $fp, -12
	lw $s0, 0($t2)
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	li $s0, 0
	lw $t1, 4($sp)
	addiu $sp, $sp, 4
	sle $s0, $t1, $s0
	beq $s0, $zero, L2
	.data
str_3: .asciiz "Digite um numero inteiro nao negativo"
	.text
	la $a0, str_3
	li $v0, 4
	syscall
	li $a0, 10
	li $v0, 11
	syscall
	li $v0, 5
	syscall
	move $s0, $v0
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	addiu $t2, $fp, -12
	lw $s0, 4($sp)
	addiu $sp, $sp, 4
	sw $s0, 0($t2)
	j L1
L2:
	addiu $t2, $fp, -12
	lw $s0, 0($t2)
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	addiu $t2, $fp, -4
	lw $s0, 4($sp)
	addiu $sp, $sp, 4
	sw $s0, 0($t2)
	addiu $t2, $fp, -12
	lw $s0, 0($t2)
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	li $s0, 1
	lw $t1, 4($sp)
	addiu $sp, $sp, 4
	subu $s0, $t1, $s0
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	addiu $t2, $fp, -8
	lw $s0, 4($sp)
	addiu $sp, $sp, 4
	sw $s0, 0($t2)
L4:
	addiu $t2, $fp, -8
	lw $s0, 0($t2)
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	li $s0, 1
	lw $t1, 4($sp)
	addiu $sp, $sp, 4
	sgt $s0, $t1, $s0
	beq $s0, $zero, L5
	addiu $t2, $fp, -4
	lw $s0, 0($t2)
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	addiu $t2, $fp, -8
	lw $s0, 0($t2)
	lw $t1, 4($sp)
	addiu $sp, $sp, 4
	mult $t1, $s0
	mflo $s0
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	addiu $t2, $fp, -4
	lw $s0, 4($sp)
	addiu $sp, $sp, 4
	sw $s0, 0($t2)
	addiu $t2, $fp, -8
	lw $s0, 0($t2)
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	li $s0, 1
	lw $t1, 4($sp)
	addiu $sp, $sp, 4
	subu $s0, $t1, $s0
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	addiu $t2, $fp, -8
	lw $s0, 4($sp)
	addiu $sp, $sp, 4
	sw $s0, 0($t2)
	j L4
L5:
	.data
str_6: .asciiz "O fatorial de "
	.text
	la $a0, str_6
	li $v0, 4
	syscall
	addiu $t2, $fp, -12
	lw $s0, 0($t2)
	move $a0, $s0
	li $v0, 1
	syscall
	.data
str_7: .asciiz " e: "
	.text
	la $a0, str_7
	li $v0, 4
	syscall
	addiu $t2, $fp, -4
	lw $s0, 0($t2)
	move $a0, $s0
	li $v0, 1
	syscall
	li $a0, 10
	li $v0, 11
	syscall

	li $v0, 10
	syscall
