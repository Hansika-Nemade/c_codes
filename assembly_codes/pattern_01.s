
# Pattern_01.s

# Read only data
.section     .rodata
   msg_char:
          .string "%c\t"

   msg_newline:
          .string "\n"

   msg_space:
          .string "\t"

# Block started with symbol
.section   .bss
        .comm  column ,4 ,4
        .comm  row    ,4 ,4

# Data Section
.section     .data

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
      .long     1
      
# Text Section
.section      .text

# Entry point: _start
      .global    _start
      .type      _start , @function
_start:
       #PROLOGUE
       pushl    %ebp
       movl     %esp , %ebp

       # Main code
       # 1. Initialization  (outer loop)
       movl     $1   , column

       # 2. Terminating condition     (outer loop)
.loop:
       movl     column , %eax
       cmpl     $7   , %eax
       jg       .epilogue

       # 3. Loop body  (outer loop)

       # Initialization (inner loop)
       movl     $1     , row

       # Terminating condition     (inner loop)
.inner:
       movl     row    , %eax
       cmpl     $4   , %eax
       jg       .outer
   
       # Loop body      (inner loop)

       movl    row  , %eax
       movl    space , %ebx
       cmpl    %ebx  , %eax
       jg      .space


       # Printing message
       pushl     asciiD
       pushl     $msg_char
       call      printf
       addl      $8  , %esp
       jmp       .out

.space:
       # printing message
       pushl    $msg_space
       call     printf
       addl     $8  , %esp
       jmp      .out

.out:

       # Decrementing condition  (inner loop)
       # asciiD--
       decl    asciiD

       # Incrementing condition (inner loop)
       # row++
       incl   row
       jmp       .inner

.outer:
       # row=1
       movl      $1    , row
       
       movl      column, %eax
       cmpl      $3  , %eax
       jg        .greater

       # space++
       incl     space
       jmp       .continue

.greater:
       #space--
       decl     space
       jmp       .continue

.continue:
       #asciiD=68
       movl      $68   , asciiD

       #printing message
       pushl     $msg_newline
       call      printf
       addl      $8    , %esp
   
       # 4. incrementing condition
       # column++
       incl      column
       jmp       .loop

.epilogue:
       pushl     $0
       call      exit
