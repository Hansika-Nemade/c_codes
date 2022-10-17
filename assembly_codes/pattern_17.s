
# Read only data
.section   .rodata
      msg_char:
      .string "%c\t\t"

      msg_space:
      .string "\t"

      msg_newline:
      .string "\n"

# Block started of symbol
.section   .bss
      .comm    column, 4, 4
      .comm    row   , 4, 4
      .comm    space , 4, 4

# Data section
.section   .data
      .globl    asciiE
      .align    4
      .type     asciiE , @object
      .size     asciiE , 4
asciiE:
      .long    69
      
# Text section
.section   .text

# Entry Point : _start
      .globl    _start
      .type     _start , @function
_start:
       #PROLOGUE
       pushl     %ebp
       movl      %esp , %ebp


       # MAIN CODE
      # 1. Initialization       (outer loop)
      movl    $1  , column

      # 2. Terminating condition     (outer loop)
.loop:
      movl    column, %eax
      movl    $5    , %ebx
      cmpl    %ebx  , %eax
      jg      .epilogue


      # 3. Loop body      (outer loop)
      # initialization    (inner loop)
      movl    $1    , row

      # Terminating condition    (inner loop)
.inner_loop:
      movl    row   , %eax
      movl    $5    , %ebx
      cmpl    %ebx  , %eax
      jg      .outer

      # Loop body     (inner loop)
      movl    row   , %eax
      movl    space , %ebx
      cmpl    %ebx  , %eax
      jg      .greater

      # printing message
      pushl   $msg_space
      call    printf
      addl    $8    , %esp
      jmp     .continue

.greater:
      pushl   asciiE
      pushl   $msg_char
      call    printf
      addl    $8    , %esp
      jmp     .continue
   
.continue:
      # Incrementing steps  (inner loop)
      # row++
      movl    row   , %eax
      movl    $1    , %ebx
      addl    %ebx  , %eax
      movl    %eax  , row
      jmp     .inner_loop

.outer:
      # row=1
      movl   $1  , row

      # asciiE--
      movl   asciiE , %eax
      movl   $1     , %ebx
      subl   %ebx   , %eax
      movl   %eax   , asciiE

      #space++
      movl   space  , %eax
      movl   $1     , %ebx
      addl   %ebx   , %eax
      movl   %eax   , space

      # Printing message
      pushl   $msg_newline
      call    printf
      addl    $8    , %esp

      # 4. Terminating steps
      # column++
      movl    column, %eax
      movl    $1    , %ebx
      addl    %ebx  , %eax
      movl    %eax  , column
      jmp     .loop

.epilogue:
      pushl   $0
      call    exit


































