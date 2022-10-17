
# pattern_13.s

# Read only data
.section   .rodata
     msg_char:
              .string "%c\t"

     msg_newline:
              .string "\n"

#  Block started with symbol
.section  .bss
     .comm    column, 4, 4
     .comm    row   , 4, 4


# Data section
.section  .data
     .globl   asciiE
     .align   4
     .type    asciiE , @object
     .size    asciiE , 4
asciiE:
     .long    69


# Text section
.section  .text

# Entry point : _start
     .global  _start
     .type    _start , @function
_start:
     
     #PROLOGUE
     pushl    %ebp
     movl     %esp , %ebp

     # MAIN CODE

     # 1. Initialization  (outer loop)
     movl     $1  , column

     # 2. Terminating condition  (outer loop)
.loop:
     movl    column , %eax
     cmpl    $5  , %eax
     jg      .epilogue

     # 3. Loop body    (outer loop)
    
     # Initialization   (inner loop)
     movl    $1    , row
     
    # Terminating condition   (inner loop)
.inner_loop:
     movl    row   , %eax
     cmpl    $5  , %eax
     jg      .outer

     # Loop body   (inner loop)

     # Printing message
     pushl   asciiE
     pushl   $msg_char
     call    printf
     addl    $8    , %esp

     #asciiE--
     decl    asciiE

     # Incrementing steps  (inner loop)
     # row++
     incl    row
     jmp     .inner_loop

.outer:
     #row=1
     movl    $1    , row

     #asciiE=69
     movl    $69   , asciiE

     # Message printing
     pushl   $msg_newline
     call    printf
     addl    $8    , %esp

     # 4. Incrementing steps   (outer loop)
     # column++
     incl    column
     jmp     .loop

.epilogue:
     pushl   $0
     call    exit


