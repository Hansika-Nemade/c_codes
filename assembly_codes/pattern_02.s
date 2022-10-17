
# pattern_02
 
# Read only data
.section .rodata
     msg_digit:
     .string "%d\t"

     msg_newline:
     .string "\n"

     msg_space:
     .string "\t"

# Block started with symbol
.section .bss
      .comm      column ,4 ,4
      .comm      row    ,4 ,4

# Text section
.section .data
      .global    num1
      .align     4
      .type      num1 , @object
      .size      num1 , 4
num1:
      .long      3
      .globl     num2
      .align     4
      .type      num2 , @object
      .size      num2 , 4
num2:
      .long      3
      .globl     space
      .align     4
      .type      space , @object
      .size      space , 4
space:
      .long      1

# Entry point : _start
      .section    .text
      .globl      _start
      .type       _start , @function

_start:
       #PROLOGUE
       pushl      %ebp
       movl       %esp , %ebp
       
       # Main code
       
       # 1. Initialization (outer loop)

       movl     $1 , column

  
       # 2. Terminating condition  (outer loop)
.loop:
       movl     column , %eax
       cmpl     $7   , %eax
       jg       .epilogue
       
       #  3. Loop body (outer loop)

       #  Initialization (inner loop)
       movl     $1 , row
      
       #  Terminating condition (inner loop) 
.inner_loop:
       movl     row   , %eax
       cmpl     $4  , %eax
       jg       .outer
       
       #  Loop body (inner loop)
       
       movl    row  , %eax
       movl    space, %ebx
       cmpl    %ebx , %eax
       jg      .space
       
       
       #  Printing message
       pushl     num1
       pushl     $msg_digit
       call      printf
       addl      $8   , %esp
       jmp       .out

.space:
       # printing message
       pushl    $msg_space
       call     printf
       addl     $8  , %esp
       jmp      .out

.out:       
       # num1++
       incl      num1

       #  incrementing steps (inner loop)
       #  row++
       incl     row
       jmp      .inner_loop

.outer:
       # row=1
       movl      $1   , row
         
       movl      column,%eax
       cmpl      $3 , %eax
       jg        .greater
    
       # space++
       incl      space

       # num2--
       decl      num2
       jmp       .continue

.greater:
       # space--
       decl      space

       # num2++
       incl      num2
       jmp       .continue

.continue:
       # num1=num2
       movl      num2 , %eax
       movl      %eax , num1

       # Printing message
       pushl     $msg_newline
       call      printf
       addl      $8   , %esp
     
       # 4. incrementing condition (outer loop)
       # column++
       incl      column
       jmp       .loop

.epilogue:
       pushl     $0
       call      exit


