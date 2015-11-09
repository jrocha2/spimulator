.data
A: .space 64
.text
.globl main
main:
li $t1, 5
la $t2, A
li $t3, 0
sw $t3, 0($t2)
li $t3, 1
sw $t3, 4($t2)
li $t0, 2
j loop_condition
loop_body:
la $t2, A
addi $t3, $t0, -2 
sll $t3, $t3, 2 
addu $t4, $t2, $t3 
lw $t5, 0($t4)
addi $t3, $t0, -1 
sll $t3, $t3, 2 
addu $t4, $t2, $t3 
lw $t6, 0($t4)
addu $t6, $t6, $t5 
sll $t3, $t0, 2 
addu $t4, $t2, $t3 
sw $t6 0($t4)
addi $t0, $t0, 1
loop_condition:
slt $t6, $t0, $t1
bne $t6, $0, loop_body
# Done, terminate program. 
li $v0, 10
syscall # exit 
.end main
