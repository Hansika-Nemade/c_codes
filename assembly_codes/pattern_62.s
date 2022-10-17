
# pattern62.s

# section: read only data
.section  .rodata
   msg_char:
   .string "%c\t"

   msg_space:
   .string "\t"

   msg_newline:
   .string "\n"

# section: Block started with symbol
.section  .bss
    .comm    column, 4, 4
    .comm    row   , 4, 4

# section: data
.section  .data
    .globl    asciiD
    .align    4
    .type     asciiD , @object
    .size     asciiD , 4
asciiD:
    .long     68
    .globl    space
    .align    4
    .type     space , @object
    .size     space , 4
space:
    .long     3

# section: text
.section    .text

# Entry point: _start
     .globl   _start
     .type    _start , @function
_start:

     # PROLOGUE
     pushl    %ebp
     movl     %esp , %ebp

     # 1. Initialization               (outer loop)
     movl    $1  , column

     # 2. Terminating condition          (outer loop)
.loop:
     movl    column, %eax
     movl     $7   , %ebx
     cmpl    %ebx  , %eax
     jg      .epilogue

     # 3. Loop body        (outer loop)
     
     # Initialization          (inner loop)
     movl    $1  , row

     # Terminating condition       (inner loop)
.inner_loop:
     movl    row, %eax
     movl    $4 , %ebx
     cmpl    %ebx, %eax
     jg      .outer

     # Loop body         (inner loop)
     movl   row, %eax
     movl   space, %ebx
     cmpl   %ebx , %eax
     jg     .false_block
     jmp    .true_block

.true_block:
     # printing message
     pushl   $msg_space
     call    printf
     addl    $8 , %esp
     jmp     .out

.false_block:
     # printing message
     pushl   asciiD
     pushl   $msg_char
     call    printf
     addl    $8  , %esp
    
     # asciiD--
     movl   asciiD, %eax
     subl   $1    , %eax
     movl   %eax  , asciiD
     jmp     .out

.out:
     # Incrementing steps       (inner loop)
     # row++
     movl   row, %eax
     addl   $1 , %eax
     movl   %eax, row
     jmp    .inner_loop

.outer:
     # row=1
     movl   $1 , row
    
     # asciiD=68
     movl   $68 , asciiD

     movl   column, %eax
     movl    $3   , %ebx
     cmpl    %ebx , %eax
     jg      .outer_true_block
     jmp     .outer_false_block

.outer_true_block:
     # space++
     movl    space, %eax
     addl    $1   , %eax
     movl    %eax , space
     jmp     .continue    

.outer_false_block:
     # space--
     movl   space, %eax
     subl    $1  , %eax
     movl    %eax, space
     jmp     .continue

.continue:
     # printing message
     pushl    $msg_newline
     call     printf
     addl     $8 , %esp

     # 4. Incrementing steps          (outer loop)
     # column++
     movl   column, %eax
     addl    $1   , %eax
     movl    %eax , column
     jmp     .loop

.epilogue:
     pushl    $0
     call     exit 
