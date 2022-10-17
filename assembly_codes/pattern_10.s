
# Read only data
 .section  .rodata
      msg_char:
      .string "%c\t"

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
        .globl   asciiA
        .align   4
        .type    asciiA , @object
        .size    ascii  , 4
asciiA:
        .long    65
        .globl   asciiB
        .align   4
        .type    asciiB , @object
        .size    asciiB , 4
asciiB:
        .long    66
        .globl   ascii
        .align   4
        .type    ascii , @object
        .size    ascii , 4
ascii:
        .long    65
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
        movl     asciiA , %eax
        movl     $65    , %ebx
        cmpl     %ebx   , %eax
        jge      .greater2

        # Printing message
        pushl    asciiB
        pushl    $msg_char
        call     printf
        addl     $8    , %esp
        
        #asciiB++
        movl     asciiB , %eax
        movl     $1     , %ebx
        addl     %ebx   , %eax
        movl     %eax   ,  asciiB
        jmp      .continue

.greater2:
        # Printing message
        pushl     asciiA
        pushl     $msg_char
        call      printf
        addl      $8     , %esp
    
        # asciiA--
        movl      asciiA , %eax
        movl      $1     , %ebx
        subl      %ebx   , %eax
        movl      %eax   , asciiA
        jmp       .continue

.continue:
        # Incrementing condition (inner loop)
        # row++
        movl      row     , %eax
        movl      $1      , %ebx
        addl      %ebx    , %eax
        movl      %eax    ,  row
        jmp       .inner_loop

.outer:
        #row=1
        movl      $1      , row
        #asciiB
        movl      $66     , asciiB
        #ascii++
        movl      ascii   , %eax
        movl      $1      , %ebx
        addl      %ebx    , %eax
        movl      %eax    , ascii
        #asciiA=ascii
        movl      ascii   , %eax
        movl      %eax    , asciiA
        #space--
        movl      space   , %eax
        movl      $1      , %ebx
        subl      %ebx    , %eax
        movl      %eax    , space
        #sub_cal++
        movl      sub_col , %eax
        movl      $1      , %ebx
        addl      %ebx    , %eax
        movl      %eax    , sub_col
        # Printing message
        pushl     $msg_newline
        call      printf
        addl      $8      , %esp

        # 4. Icrementing condition
        # column++
        movl      column  , %eax
        movl      $1      , %ebx
        addl      %ebx    , %eax
        movl      %eax    , column
        jmp       .loop

.epilogue:
        pushl     $0
        call      exit




        


















































