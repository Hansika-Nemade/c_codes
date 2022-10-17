
# pattern_12.s

# Read only data
.section  .rodata
       msg_char:
                 .string "%c\t"

       msg_newline:
                 .string "\n"

# Block started with symbol
.section   .bss
        .comm    column, 4, 4
        .comm    row   , 4, 4


#  Data Section
.section   .data
        .globl   asciiA
        .align   4
        .type    asciiA , @object
        .size    asciiA , 4
asciiA:
        .long    65


#  Text Section
.section  .text

# Entry point : _start
        .globl   _start
        .type    _start , @function
_start:
         # PROLOGUE
         pushl   %ebp
         movl    %esp , %ebp

         # MAIN CODE
         
         # 1. Initialization  (outer loop)
         movl    $1   , column

         # 2. Terminating condition  (outer loop)
.loop:
         movl    column , %eax
         cmpl    $5   , %eax
         jg      .epilogue

         # 3. Loop body    (outer loop)

         # Initialization     (inner loop)
         movl     $1     , row

         # Terminating condition    (inner loop)
.inner_loop:
         movl     row    , %eax
         cmpl     $5   , %eax
         jg       .outer

         # Loop body    (inner loop)
         # Printing Message
         pushl    asciiA
         pushl    $msg_char
         call     printf
         addl     $8     , %esp
     
         # Incrementing steps     (inner loop)
         # row++
         incl     row
         jmp      .inner_loop

.outer:
         # row=1
         movl     $1     , row

         #asciiA++
         incl     asciiA

         # Printing message
         pushl    $msg_newline
         call     printf
         addl     $8     , %esp

         # 4. Incrementing steps       (outer loop)
         # column++
         incl     column
         jmp      .loop

.epilogue:
         pushl    $0
         call     exit


