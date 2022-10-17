
# pattern59.s

# section: Read only data
.section  .rodata
    msg_char:
    .string "%c\t"

    msg_space:
    .string "\t"

    msg_newline:
    .string "\n"

# section: Block started with symbol
.section   .bss
    .comm  column, 4, 4
    .comm   row  , 4, 4

# section: data
.section   .data
    .globl   asciiA
    .align   4
    .type    asciiA , @object
    .size    asciiA , 4
asciiA:
    .long    65
    .globl   space
    .align   4
    .type    space , @object
    .size    space , 4
space:
    .long    6
    .globl   space2
    .align   4
    .type    space2 , @object
    .size    space2 , 4
space2:
    .long    8

# section: text
.section  .text
   
# Entry point: _start
     .globl   _start
     .type    _start , @function
_start:
  
     # PROLOGUE
     pushl   %ebp
     mov     %esp , %ebp

     # MAIN CODE
     # 1. Initialization         (outer loop)
     movl   $1 , %eax
  
     # 2. Terminating condition        (outer loop)
.loop:
     movl   column, %eax
     movl    $7   , %ebx
     cmpl    %ebx , %eax
     jg      .epilogue

     # 3. Loop body         (outer loop)
     
     # Initialization           (inner loop)
     movl    $1 , row

     # Terminating condition         (inner loop)
.inner_loop:
     movl   row , %eax
     movl   $13 , %ebx
     cmpl   %ebx, %eax
     jg     .outer

     # Loop body         (inner loop)
     movl    row, %eax
     movl    space, %ebx
     cmpl    %ebx , %eax
     jg      .false_block1

     movl    row , %eax
     movl    space2 , %ebx
     cmpl    %ebx , %eax
     jl      .false_block1 
     jmp     .true_block1

.true_block1:
     # printing message
     pushl   $msg_space
     call    printf
     addl    $8  , %esp
     jmp      .inner_out1

.false_block1:
     # printing message
     pushl   asciiA
     pushl   $msg_char
     call    printf
     addl    $8  , %esp
     jmp     .inner_out1

.inner_out1:
     movl   row , %eax
     movl   $7  , %ebx
     cmpl   %ebx, %eax
     jl     .false_block2
     jmp    .true_block2

.true_block2:
     # asciiA--
     movl   asciiA , %eax
     subl   $1     , %eax
     movl   %eax   , asciiA
     jmp    .inner_out2

.false_block2:
     # asciiA++
     movl   asciiA, %eax
     addl    $1   , %eax
     movl    %eax , asciiA
     jmp     .inner_out2

.inner_out2:
     # Incrementing steps          (inner loop)
     # row++
     movl   row , %eax
     addl   $1  , %eax
     movl    %eax, row
     jmp     .inner_loop

.outer:
     # row=1
     movl    $1 , row

     # asciiA=65
     movl   $65 , asciiA

     # space2--
     movl   space2, %eax
     subl   $1    , %eax
     movl   %eax  , space2

     # space++
     movl   space , %eax
     addl    $1   , %eax
     movl    %eax , space

     # printing message
     pushl   $msg_newline
     call    printf
     addl    $8  , %esp

     # 4. Incrementing  steps         (outer loop)
     # column++
     movl   column, %eax
     addl    $1   , %eax
     movl    %eax , column
     jmp     .loop

.epilogue:
     pushl   $0
     call    exit
