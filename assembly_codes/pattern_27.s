
# pattern27.s

# section: Read only data
.section   .rodata
    msg_digit:
    .string "%d\t"

    msg_space:
    .string "\t"

    msg_newline:
    .string "\n"

# Block started with symbol
.section   .bss
    .comm    column, 4, 4
    .comm    row   , 4, 4

# Section: data
.section   .data
    .globl  num1
    .align  4
    .type   num1 , @object
    .size   num1 , 4
num1:
    .long   1
    .globl  space 
    .align  4
    .type   space , @object
    .size   space , 4
space:
    .long   5
    .globl  space2
    .align  4
    .type   space2, @object
    .size   space2, 4
space2:
    .long   5

# section: text
.section   .text
     
   # Entry point: _start
   .globl   _start
   .type    _start , @function
_start:
    
    #PROLOGUE
    pushl   %ebp
    movl    %esp , %ebp

    # MAIN CODE

    # 1. Initialization     (outer loop)
    movl    $1   , column

    # 2. Terminating condition    (outer loop)
.loop:
    movl   column, %eax
    movl    $9   , %ebx
    cmpl    %ebx  , %eax
    jg      .epilogue

    # 3. Loop body     (outer loop)
    
    # Initialization   (inner loop)
    movl    $1  , row

    # Terminating condition     (inner loop)
.inner_loop:
    movl    row , %eax
    movl    $9  , %ebx
    cmpl    %ebx, %eax
    jg      .outer

    # Loop body     (inner loop)
    movl    row  , %eax
    movl    space, %ebx
    cmpl    %ebx , %eax
    je      .true_block
    
    movl    row  , %eax
    movl    space2, %ebx
    cmpl    %ebx  , %eax
    je      .true_block
    jmp     .false_block

.true_block:
    pushl   num1
    pushl   $msg_digit
    call    printf
    addl    $8  , %esp
    jmp     .inner_loop_out

.false_block:
    pushl   $msg_space
    call    printf
    addl    $8   , %esp
    jmp     .inner_loop_out

.inner_loop_out:
    # Incrementing steps    (inner loop)
    #row++
    movl    row  , %eax
    addl    $1   , %eax
    movl    %eax , row
    jmp     .inner_loop

.outer:
    # row=1
    movl    $1  , row

    movl    column, %eax
    movl    $4    , %ebx
    cmpl    %ebx  , %eax
    jg      .true_block_outer
    jmp     .false_block_outer

.true_block_outer:
    #space++
    movl    space , %eax
    addl    $1    , %eax
    movl    %eax  , space

    #num1--
    movl    num1  , %eax
    subl    $1    , %eax
    movl    %eax  , num1

    # space2--
    movl    space2 , %eax
    subl    $1    , %eax
    movl    %eax  , space2
    jmp     .out

.false_block_outer:
    #space--
    movl    space , %eax
    subl    $1    , %eax
    movl    %eax  , space

    #num1++
    movl    num1  , %eax
    addl    $1    , %eax
    movl    %eax  , num1

    # space2++
    movl    space2 , %eax
    addl    $1    , %eax
    movl    %eax  , space2
    jmp     .out

.out:
    # Printing message
    pushl   $msg_newline
    call    printf
    addl    $8    , %esp
    
    # 4. Incrementing condition     (outer loop)
    # column++
    movl    column , %eax
    addl    $1     , %eax
    movl    %eax   , column
    jmp     .loop

.epilogue:
    pushl    $0
    call     exit

