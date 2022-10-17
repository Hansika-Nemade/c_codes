
# pattern_85.s

# section: Read only data
.section  .rodata
     msg_digit:
            .string "%d\t"
 
     msg_newline:
            .string "\n"

     msg_space:
            .string "\t"

# section: Block started with symbol
.section  .bss
     .comm  column , 4, 4
     .comm  row    , 4, 4

# section: Data 
.section  .data
     .globl   num1
     .align   4
     .type    num1 , @object
     .size    num1 , 4
num1:
     .long    5
        
# section: Text 
.section  .text

# Entry point : _start
     .global   _start
     .type     _start , @function
_start:
     #PROLOGUE
     pushl    %ebp
     movl     %esp , %ebp

     # 1. Initialization (outer loop)
     movl    $5   , column

     # 2. Terminating condition (outer loop)
.loop:
     movl    column , %eax
     cmpl    $0   , %eax
     jle      .epilogue

     # 3. loop body

     # Initialization (inner loop)
     movl    $1     , row
        
     # Terminating condition (inner loop)
.inner_loop:
     movl    row    , %eax
     cmpl    $5   , %eax
     jg      .outer

     # loop body         (inner loop)

     movl    row , %eax
     movl    column , %ebx
     cmpl    %ebx , %eax
     jg      .space

     # Printing message
     pushl   num1
     pushl   $msg_digit
     call    printf
     addl    $8    , %esp
     jmp     .out

.space:
     # printing message
     pushl   $msg_space
     call    printf
     addl    $8  , %esp
     jmp     .out

.out:   
     # incrementing condition (inner loop)
     # row++
     incl    row
     jmp     .inner_loop

.outer:
     # row=1
     movl    $1   , row

     # num1--
     decl    num1
        
     # Printing message
     pushl   $msg_newline
     call    printf
     addl    $8    , %esp

     # 4. decrementing condition (outer loop)
     # column--
     decl    column 
     jmp     .loop

.epilogue:
     pushl   $0
     call    exit
