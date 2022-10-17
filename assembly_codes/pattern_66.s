
# pattern66.s

# Read only data
 .section  .rodata
      msg_digit:
      .string "%d\t"

      msg_space:
      .string "\t"

      msg_newline:
      .string "\n"

# Block started with symbol
.section .bss
        .comm   column , 4, 4
        .comm   row    , 4, 4

#  Data Section
.section  .data
        .globl   num1
        .align   4
        .type    num1 , @object
        .size    num1 , 4
num1:
        .long    0
        .globl   num2
        .align   4
        .type    num2 , @object
        .size    num2 , 4
num2:
        .long    1
        .globl   num
        .align   4
        .type    num , @object
        .size    num , 4
num:
        .long    0
        .globl   space
        .align   4
        .type    space , @object
        .size    space , 4
space:
        .long    4
        .globl   sub_col
        .align   4
        .type    sub_col , @object
        .size    sub_col , 4
sub_col:
        .long    5

# Text Section
.section  .text

# Entry point : _start
        .globl   _start
        .type    _start , @function
_start:
        #PROLOGUE
        pushl    %ebp
        movl     %esp , %ebp
    
        # 1. Initialization (outer loop)
        movl     $1   , column

        # 2. Terminating condition  (outer loop)
.loop:
        movl     column , %eax
        movl     $5     , %ebx
        cmpl     %ebx   , %eax
        jg       .epilogue

        # 3. Loop body (outer loop)
        # initialization    (inner loop)
        movl     $1     , row

        # Terminating condition  (inner loop)
.inner_loop:
        movl     row    , %eax
        movl     sub_col, %ebx
        cmpl     %ebx   , %eax
        jg       .outer
        
        movl     row    , %eax
        movl     space  , %ebx
        cmpl     %ebx   , %eax
        jg       .greater

        #printing message
        pushl    $msg_space
        call     printf
        addl     $8   , %esp
        jmp      .continue

.greater:
        movl     num1 , %eax
        movl     $0    , %ebx
        cmpl     %ebx   , %eax
        jge      .greater2

        # Printing message
        pushl    num2
        pushl    $msg_digit
        call     printf
        addl     $8    , %esp
        
        # num2++
        movl     num2 , %eax
        addl      $1  , %eax
        movl     %eax , num2
        jmp      .continue

.greater2:
        # Printing message
        pushl     num1
        pushl     $msg_digit
        call      printf
        addl      $8     , %esp
    
        # num1--
        movl      num1 , %eax
        subl       $1  , %eax
        movl      %eax , num1
        jmp       .continue

.continue:
        # Incrementing condition (inner loop)
        # row++
        movl      row , %eax
        addl       $1 , %eax
        movl      %eax,  row
        jmp       .inner_loop

.outer:
        #row=1
        movl      $1  , row

        # num2
        movl      $1  , num2

        # num++
        movl      num , %eax
        addl       $1 , %eax
        movl      %eax, num

        # num1=num
        movl      num  , %eax
        movl      %eax , num1

        #space--
        movl      space , %eax
        subl       $1   , %eax
        movl      %eax  , space

        #sub_cal++
        movl      sub_col, %eax
        addl       $1    , %eax
        movl      %eax   , sub_col

        # Printing message
        pushl     $msg_newline
        call      printf
        addl      $8  , %esp

        # 4. Icrementing condition
        # column++
        movl      column, %eax
        addl       $1   , %eax
        movl      %eax  , column
        jmp       .loop

.epilogue:
        pushl     $0
        call      exit
