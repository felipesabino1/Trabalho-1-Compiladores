	.data
global_x:	.word 0
	.text
	.data
global_y:	.word 0
	.text
	.data
global_v:	.space 40
	.text
	.text
	.globl main
main:
	j func_principal

	.text
func_soma:
	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	addiu $sp, $sp, -4
	sw $fp, 0($sp)
	move $fp, $sp
	addiu $t2, $fp, 16
	lw $s0, 0($t2)
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	addiu $t2, $fp, 12
	lw $s0, 0($t2)
	lw $t1, 4($sp)
	addiu $sp, $sp, 4
	addu $s0, $t1, $s0
	move $v0, $s0
	b Func_Epilogue_soma
Func_Epilogue_soma:
	move $sp, $fp
	lw $fp, 0($sp)
	addiu $sp, $sp, 4
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra

	.text
func_principal:
	move $fp, $sp
	li $s0, 10
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	la $t2, global_x
	lw $s0, 4($sp)
	addiu $sp, $sp, 4
	sw $s0, 0($t2)
	li $s0, 5
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	la $t2, global_y
	lw $s0, 4($sp)
	addiu $sp, $sp, 4
	sw $s0, 0($t2)
	la $t2, global_x
	lw $s0, 0($t2)
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	la $t2, global_y
	lw $s0, 0($t2)
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	jal func_soma
	addiu $sp, $sp, 8
	move $s0, $v0
	sw $s0, 0($sp)
	addiu $sp, $sp, -4
	li $s0, 0
	# Multiplica indice por 4
	li $t3, 4
	mult $s0, $t3
	mflo $t3
	la $t2, global_v
	addu $t2, $t2, $t3
	lw $s0, 4($sp)
	addiu $sp, $sp, 4
	sw $s0, 0($t2)
	.data
str_1: .asciiz "Resultado:"
	.text
	la $a0, str_1
	li $v0, 4
	syscall
	li $a0, 10
	li $v0, 11
	syscall
	li $s0, 0
	# Multiplica indice por 4
	li $t3, 4
	mult $s0, $t3
	mflo $t3
	la $t2, global_v
	addu $t2, $t2, $t3
	lw $s0, 0($t2)
	move $a0, $s0
	li $v0, 1
	syscall
	li $a0, 10
	li $v0, 11
	syscall

	li $v0, 10
	syscall
