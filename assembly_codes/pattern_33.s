
# pattern_33.s

# section: Read only data
.section    .rodata
     msg_char:
              .string "%c\t"

     msg_newline:
              .string "\n"

     msg_space:
              .string "\t"

# section: Block started with symbol
.section    .bss
     .comm    column, 4, 4
     .comm    row   , 4, 4

# section: data
.section    .data

     .globl   asciiA
     .align   4
     .type    asciiA , @object
     .size    asciiA , 4
asciiA:
     .long    65


# section: text
.section    .text

# Entry point: _start
     .globl    _start
     .type     _start , @function
_start:
     
     # PROLOGUE
     pushl     %ebp
     movl      %esp , %ebp

     # 1. Initialization        (outer loop)
     movl     $5  , column

     # 2. Terminating condition    (outer loop)
.loop:
     movl     column, %eax
     cmpl     $5  , %eax
     jg       .epilogue

     movl     column , %eax
     cmpl     $0   , %eax
     jle      .epilogue

     # 3. Loop  body     (outer loop)
    
     # Initialization      (inner loop)
     movl     $1   , row

     # Terminating condition      (inner loop)
.inner_loop:
     movl     row  , %eax
     cmpl     $5 , %eax
     jg       .outer

     # Loop body        (inner loop)
     
     movl     row , %eax
     movl     column , %ebx
     cmpl     %ebx  , %eax
     jg       .space

     # printing message     
     pushl    asciiA
     pushl    $msg_char
     call     printf
     addl     $8   , %esp
     jmp      .out

.space:

     # printing message
     pushl   $msg_space
     call    printf
     addl    $8  , %esp
     jmp     .out

.out:

     # Incrementing steps      (inner loop)
     # row++
     incl    row 
     jmp     .inner_loop

.outer:
     # row=1
     movl    $1   , row

     # asciiA++  
     incl     asciiA

     # printing message
     pushl    $msg_newline
     call     printf
     addl     $8   , %esp

     # 4. Decrementing  steps      (inner loop)
     # column--
     decl     column
     jmp      .loop

.epilogue:
     pushl    $0
     call     exit 



