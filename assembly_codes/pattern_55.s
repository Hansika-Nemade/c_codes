
# pattern_55.s

# section: Read only data
.section  .rodata
    msg_digit:
            .string "%d\t"

    msg_newline:
            .string "\n"

# section: Block started with symbol
.section  .bss
    .comm   column, 4, 4
    .comm    row  , 4, 4

# section: data
.section  .data
    .globl   num1
    .align   4
    .type    num1 , @object
    .size    num1 , 4
num1:
    .long    1

    .globl   num
    .align   4
    .type    num , @object
    .size    num , 4
num:
    .zero    4

    .globl   gap
    .align   4
    .type    gap , @object
    .size    gap , 4
gap:
    .long    1

    .globl   newline
    .align   4
    .type    newline , @object
    .size    newline , 4
newline:
    .zero    4

# section: text
.section   .text
    
# Entry point: _start
    .globl    _start
    .type     _start , @function
_start:

    # PROLOGUE
    pushl   %ebp
    movl    %esp , %ebp

    # 1. Initialization            (outer loop)
    movl     $1 , column

    # 2. Terminating condition        (outer loop)
.loop:
    movl    column, %eax
    cmpl    $4, %eax
    jg       .epilogue

    # 3. Loop body         (outer loop)
    
    # Initialization        (inner loop)
    movl   $1  , row

    # Terminating condition      (inner loop)
.inner_loop:
    movl   row, %eax
    cmpl   $6, %eax
    jg     .outer

    # Loop body         (inner loop)
    movl   num1 , %eax
    movl    $8  , %ebx
    cmpl    %ebx, %eax
    jle     .true_block
    jmp     .false_block

.true_block:
    # num=num-gap
    movl   num, %eax
    movl   gap, %ebx
    subl   %ebx, %eax
    movl   %eax, num

    # Printing message
    pushl   num
    pushl   $msg_digit
    call    printf
    addl    $8  , %esp

    # gap++
    incl    gap
    jmp     .out

.false_block:

    # printing message
    pushl   num1
    pushl   $msg_digit
    call    printf
    addl    $8  , %esp

    # num=num1
    movl   num1 , %eax
    movl   %eax , num

    # num1=num1+num1
    movl   num1, %eax
    addl   %eax, %eax
    movl   %eax, num1
    jmp    .out

.out:
    # newline++
    incl   newline

    movl    newline, %eax
    movl     $4    , %ebx
    cltd
    idivl    %ebx
    cmpl     $0   , %edx
    je       .newline
    jmp      .out2

.newline:
    # printing message
    pushl   $msg_newline
    call    printf
    addl    $8  , %esp
    jmp     .out2

.out2:
    movl    newline, %eax
    movl    $16    , %ebx
    cmpl    %ebx   , %eax
    je      .outer
    jmp     .out3

.out3:
    # Incrementing steps           (inner loop)
    # row++
    incl    row
    jmp     .inner_loop


.outer:
    # row=1
    movl    $1  , row

    # num=0
    movl    $0  , num

    # gap=1
    movl   $1  , gap

    # num1=1
    movl   $1  , num1

    movl    newline, %eax
    movl     $16   , %ebx
    cmpl    %ebx   , %eax
    je      .epilogue
    jmp     .continue

.continue:
    # 4. Incrementing steps           (outer loop)
    # column++
    incl    column
    jmp      .loop

.epilogue:
    pushl    $0
    call     exit


