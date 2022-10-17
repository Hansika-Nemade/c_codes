
# pattern35.s

# section: Read only data
.section   .rodata
     msg_char:
     .string "%c\t\t"

     msg_space:
     .string "\t"

     msg_newline:
     .string "\n"

# section: Block started with symbol
.section   .bss
     .comm     column, 4, 4
     .comm     row   , 4, 4

# section: data
.section   .data
     .globl    asciiA
     .align    4
     .type     asciiA , @object
     .size     asciiA , 4
asciiA:
     .long     65
     .globl    space
     .align    4
     .type     space , @object
     .size     space , 4
space:
     .long     3
     .globl    ascii
     .align    4 
     .type     ascii , @object
     .size     ascii , 4
ascii:
     .long     65

# section: text
.section   .text
 
# Entry point: _start
     .globl    _start
     .type     _start , @function
_start:
     
     # PROLOGUE
     pushl    %ebp
     movl     %esp , %ebp

     # MAIN CODE

     # 1. Initialization       (outer loop)
     movl     $1 , column

     # 2. Terminating condition     (outer loop)
.loop:
     movl     column, %eax
     movl      $7   , %ebx
     cmpl     %ebx  , %eax
     jg       .epilogue

     # 3. Loop body      (outer loop)
     
     # Initialization     (inner loop)
     movl    $1 , row
  
     # Terminating condition      (inner loop)
.inner_loop:
     movl    row , %eax
     movl    $4  , %ebx
     cmpl    %ebx, %eax
     jg      .outer

     # Loop body      (inner loop)
     
     movl    row , %eax
     movl    space, %ebx
     cmpl    %ebx, %eax
     jg      .false_block
     jmp     .true_block

.true_block:
     # Printing message
     pushl    $msg_space
     call     printf
     addl     $8   , %esp
     jmp      .out

.false_block:
     # Printing message
     pushl    asciiA
     pushl    $msg_char
     call     printf
     addl     $8  , %esp

     # asciiA++
     movl    asciiA , %eax
     addl    $1     , %eax
     movl    %eax   , asciiA
     jmp      .out

.out:
     # Incrementing  steps    (inner loop)
     # row++
     movl   row , %eax
     addl   $1  , %eax
     movl   %eax, row
     jmp    .inner_loop

.outer:
     # row=1
     movl    $1 , row

     movl    column, %eax
     movl    $3    , %ebx
     cmpl    %ebx  , %eax
     jg      .outer_true_block

     # space--
     movl    space , %eax
     subl    $1    , %eax
     movl    %eax  , space

     # asciiA=65
     movl   $65  , asciiA
     jmp    .continue

.outer_true_block:
     # space++
     movl   space , %eax
     addl   $1    , %eax
     movl   %eax  , space

     # ascii++
     movl   ascii , %eax
     addl   $1    , %eax
     movl   %eax  , ascii

     # asciiA=ascii
     movl    ascii , %eax
     movl    %eax  , asciiA
     jmp     .continue

.continue:
     # Printing message
     pushl    $msg_newline
     call     printf
     addl     $8  , %esp

     # 4. Incrementing steps      (outer loop)
     # column++
     movl    column , %eax
     addl    $1     , %eax
     movl    %eax   , column
     jmp     .loop

.epilogue:
     pushl    $0
     call     exit
