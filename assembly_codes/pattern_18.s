
# pattern_18.s

# Read only Data
.section  .rodata
      msg_digit:
                 .string "%d\t"

      msg_newline:
                 .string "\n"

      msg_space:
                 .string "\t"


# Block started with symbol
.section  .bss
      .comm    column , 4, 4
      .comm    row    , 4, 4


# Data section
.section   .data
      .globl   num1
      .align   4
      .type    num1 , @object
      .size    num1 , 4
num1:
      .long    1

      .globl   space
      .align   4
      .type    space, @object
      .size    space, 4
space:
      .long    5


# Text section
.section   .text

# Entry point : _start
      .globl   _start
      .type    _start , @function
_start:
      
      # PROLOGUE
      pushl   %ebp
      movl    %esp , %ebp

      # 1. Initialization      (outer loop)
      movl    $5   , column
      
      # 2. Terminating condition   (outer loop)
.loop:
      movl    column, %eax
      cmpl    $5  , %eax
      jg      .epilogue

      movl    column , %eax
      cmpl    $0  , %eax
      jle     .epilogue

      

      # 3. Loop body      (outer loop)
      
      # Initialization     (inner loop)
      movl    $1   , row
      
      # Terminating condition    (inner loop)
.inner_loop:
      movl    row  , %eax
      cmpl    $5 , %eax
      jg      .outer

      # Loop body   (inner loop)

      movl    row , %eax
      movl    column , %ebx
      cmpl    %ebx  , %eax
      jg      .space
      
      # Printing message
      pushl    num1
      pushl    $msg_digit
      call     printf
      addl     $8   , %esp

      # num1++
      incl    num1

      jmp      .out

.space:
      # printing message

      pushl    $msg_space
      call     printf
      addl     $8  , %esp
      jmp      .out

.out:

      # Incrementing steps    (inner loop)
      #  row++
      incl     row
      jmp      .inner_loop

.outer:
      # row=1
      movl    $1  , row

      # num1=1
      movl    $1  , num1

      # printing message
      pushl   $msg_newline
      call    printf
      addl    $8   , %esp
      
      # 4. Decrementing condition
      # column--
      decl    column
      jmp     .loop

.epilogue:
      pushl   $0
      call    exit



