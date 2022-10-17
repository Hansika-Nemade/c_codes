
# Read only data
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
      .comm    num1  , 4, 4

#  Data section
.section   .data
      .globl   space
      .align   4
      .type    space , @object
      .size    space , 4
space:
      .long    4
      .globl   i
      .align   4
      .type    i , @object
      .size    i , 4
i:
      .long    5

# Text section
.section   .text


# Entry point : _start
      .globl   _start
      .type    _start , @function
_start:

      # PROLOGUE
      pushl    %ebp
      movl     %esp , %ebp

      # MAIN CODE

      # 1. Initialization     (outer loop)
      movl     $1   , column
      
      # 2. Terminating condition     (outer loop)
.loop:
      movl     column, %eax
      movl     $5    , %ebx
      cmpl     %ebx  , %eax
      jg       .epilogue

      # 3. Loop body    (outer loop)
      
      # Initialization    (inner loop)
      movl     $1    , row
      
      # Terminating condition    (inner loop)
.inner_loop:
      movl     row , %eax
      movl     i   , %ebx
      cmpl     %ebx, %eax
      jg       .outer

     # loop body     (inner loop)
     
     movl     row  , %eax
     movl     space, %ebx
     cmpl     %ebx , %eax
     jg       .greater
  
     # Printing message
     pushl    $msg_space
     call     printf
     addl     $8   , %esp
     jmp      .continue

.greater:
     movl     row  , %eax
     movl     $5   , %ebx
     cmpl     %ebx , %eax
     jle       .else

     # num1--
     movl     num1 , %eax
     subl     $1   , %eax
     movl     %eax , num1

     # Printing message
     pushl    num1
     pushl    $msg_digit
     call     printf
     addl     $8   , %esp
     jmp      .continue

.else:
     
     # num1++
     movl     num1 , %eax
     addl     $1   , %eax
     movl     %eax , num1

     # Printing message
     pushl    num1
     pushl    $msg_digit
     call     printf
     addl     $8   , %esp
     jmp      .continue


.continue:
     # Incrementing condition     (inner loop)
     # row++
     movl     row  , %eax
     movl     $1   , %ebx
     addl     %ebx , %eax
     movl     %eax , row
     jmp      .inner_loop

.outer:
     # num1=0
     movl     $0   , num1

     #row=1
     movl     $1   , row

     # i++
     movl     i    , %eax
     movl     $1   , %ebx
     addl     %ebx , %eax
     movl     %eax , i

     #space--
     movl     space, %eax
     movl     $1   , %ebx
     subl     %ebx , %eax
     movl     %eax , space

     # message Printing
     pushl    $msg_newline
     call     printf
     addl     $8   , %esp
      
     # 4. Incrementing steps     (outer loop)
     # column++
     movl     column, %eax
     movl     $1    , %ebx
     addl     %ebx  , %eax
     movl     %eax  , column
     jmp      .loop

.epilogue:
     pushl    $0
     call     exit






































