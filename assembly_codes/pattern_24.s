
# Pattern24.s

# Section : rodata
.section   .rodata
    msg_digit:
    .string "%d\t"

    msg_newline:
    .string "\n"

# Block Started with symbol
.section   .bss
    .comm    column, 4, 4
    .comm    row   , 4, 4

#  Section : data
.section   .data
    .globl   num1
    .align   4
    .type    num1 , @object
    .size    num1 , 4
num1:
    .long    3
    .globl   sub_row
    .align   4
    .type    sub_row , @object
    .size    sub_row , 4
sub_row:
    .long    1

# Section : Text
.section   .text

# Entry point: _start
    .globl   _start
    .type    _start , @function
_start:
    
    # PROLOGUE
    pushl    %ebp
    movl     %esp , %ebp


    # 1. Initialization     (outer loop)
    movl    $1   , column

    # 2. Terminating condition (outer loop)
.loop:
    movl    column, %eax
    movl    $7    , %ebx
    cmpl    %ebx  , %eax
    jg      .epilogue

    # 3. Loop body    (outer loop)

    # Initialization    (inner loop)
    movl    $1    , row

    # Terminating condition    (inner loop)
.inner_loop:
    movl    row   , %eax
    movl    sub_row, %ebx
    cmpl    %ebx  , %eax
    jg      .outer

    # Printing message
    pushl   num1
    pushl   $msg_digit
    call    printf
    addl    $8    , %esp
    
    # num1--
    movl    num1  , %eax
    subl    $1    , %eax
    movl    %eax  , num1

    # Incrementing condition    (inner loop)
    # row++
    movl    row   , %eax
    addl    $1    , %eax
    movl    %eax  , row
    jmp     .inner_loop

.outer:
    
    # row=1
    movl    $1   , row

    movl    column , %eax
    cmpl    $3   , %eax
    jle     .false_block
    jmp     .true_block


.true_block:
    # sub_row--
    movl    sub_row, %eax
    subl    $1     , %eax
    movl    %eax   , sub_row
    jmp     .out

.false_block:
    # sub_row++
    movl    sub_row, %eax
    addl    $1     , %eax
    movl    %eax   , sub_row
    jmp     .out

.out:
    # num1=3
    movl    $3  , num1

    # Printing message
    pushl   $msg_newline
    call    printf
    addl    $8  , %esp

    # 4. Incrementing steps     (outer loop)
    # column++
    movl    column, %eax
    addl    $1    , %eax
    movl    %eax  , column
    jmp     .loop

.epilogue:
    pushl    $0
    call     exit


