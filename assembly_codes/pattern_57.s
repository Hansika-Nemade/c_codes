
# pattern57.s

# section: Read only data
.section  .rodata
    msg_digit:
    .string "%d\t"

    msg_space:
    .string "\t"

    msg_newline:
    .string "\n"

# section: Block started with symbol
.section   .bss
    .comm   column , 4, 4
    .comm    row   , 4, 4

# section: data
.section  .data
    .globl   num1
    .align   4
    .type    num1 , @object
    .size    num1 , 4
num1:
    .long    9
    .globl   i
    .align   4
    .type    i , @object
    .size    i , 4
i:
    .long    9
    .globl   space
    .align   4
    .type    space , @object
    .size    space , 4
space:
    .zero    4

# section: text
.section  .text

# Entry point: _start
    .globl   _start
    .type    _start , @ function
_start:
   
    # PROLOGUE
    pushl   %ebp
    movl    %esp , %esp

    # 1. Initialization         (outer loop)
    movl   $1  , column
   
    # 2. Terminating condition        (outer loop)
.loop:
    movl   column, %eax
    movl    $5   , %ebx
    cmpl    %ebx , %eax
    jg     .epilogue

    # 3. Loop body         (outer loop)
    
    # Initialization           (inner loop)
    movl   $1  , row
   
    # Terminating condition         (inner loop)
.inner_loop:
    movl   row , %eax
    movl    i  , %ebx
    cmpl   %ebx, %eax
    jg     .outer

    # Loop body        (inner loop)
    movl   row , %eax
    movl   space, %ebx
    cmpl   %ebx , %eax
    jg     .false_block
    jmp    .true_block

.true_block:
    # Printing message
    pushl   $msg_space
    call    printf
    addl    $8  , %esp
    jmp     .out

.false_block:
    # Printing message
    pushl   num1
    pushl   $msg_digit
    call    printf
    addl    $8  , %esp
    jmp     .out

.out:
    # Incrementing steps       (inner loop)
    # row++
    movl   row , %eax
    addl   $1  , %eax
    movl   %eax, row
    jmp    .inner_loop

.outer:
    # row=1
    movl   $1 , row

    # num1=num1-2
    movl   num1, %eax
    subl   $2  , %eax
    movl   %eax, num1

    # space++
    movl   space , %eax
    addl    $1   , %eax
    movl    %eax , space

    # i--
    movl   i , %eax
    subl   $1, %eax
    movl   %eax, i

    # Printing message
    pushl   $msg_newline
    call    printf
    addl    $8  , %esp

    # 4. Incrementing steps          (outer loop)
    # column++
    movl   column, %eax
    addl   $1    , %eax
    movl   %eax  , column
    jmp    .loop

.epilogue:
    pushl   $0
    call    exit
