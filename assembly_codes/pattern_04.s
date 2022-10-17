
# pattern_04.s

#Read only data
.section .rodata
      msg_space:
               .string "\t"

      msg_digit:
               .string "%d\t"

      msg_newline:
                .string "\n"

# Block started with symbol   
.section  .bss
          .comm     column , 4, 4
          .comm     row    , 4, 4

# Data Section
.section  .data

          .globl     num1
          .align     4
          .type      num1 , @object
          .size      num1 , 4
num1:
          .long      1

          .globl     num2
          .align     4
          .type      num2 , @object
          .size      num2 , 4
num2:
          .long      1

          .globl     space
          .align     4
          .type      space, @object
          .size      space, 4
space:    
          .long      4

          .globl     i
          .align     4
          .type      i    , @object
          .size      i    , 4
i:
          .long      5

# Text Section
.section   .text

# Entry point : _start
          .globl     _start
          .type      _start  , @function
_start:
          #PROLOGUE
          pushl      %ebp
          movl       %esp , %ebp
     
          # Main code
          
          # 1. Initialization
          movl       $1   , column

          # 2. Terminating Condition  (outer loop)
.loop:
          movl     column , %eax
          cmpl     $5   , %eax
          jg       .epilogue
 
          # 3. Loop body    (outer loop)
          
          # Initialization  (inner loop)
          movl      $1    , row

          # Terminating Condition (inner loop)
.inner_loop:
          movl      row   , %eax
          movl      i     , %ebx
          cmpl      %ebx  , %eax
          jg        .outer

          # Loop body  (inner loop)
          movl      row   , %eax
          movl      space , %ebx
          cmpl      %ebx  , %eax
          jle        .space

          # Printing message
          pushl     num1
          pushl     $msg_digit
          call      printf
          addl      $8    , %esp

          #num1--
          decl      num1
          jmp       .continue_inner

.space:
          # Printing message
          pushl     $msg_space
          call      printf
          addl      $8    , %esp 
          jmp       .continue_inner

.continue_inner:
          # Incrementing Condition  (inner loop)
          # row++
          incl      row
          jmp       .inner_loop

.outer:
          #num2=num2+2
          movl      num2  , %eax
          addl      $2  , %eax
          movl      %eax  , num2

          #num1=num2
          movl      num2  , %eax
          movl      %eax  , num1

          #row=1
          movl      $1    , row

          #space--
          decl      space

          # i++
          incl      i

          # Printing Message
          pushl     $msg_newline
          call      printf
          addl      $8    , %esp
          
          # 4. Incrementing Condition  (outer Loop)
          # column++
          incl      column
          jmp       .loop

.epilogue:
          pushl     $0
          call      exit


