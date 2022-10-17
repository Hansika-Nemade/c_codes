
# pattern_79.s

# section: Read only data
.section   .rodata
     msg_symbol:
               .string  "*\t"

     msg_space:
               .string  "\t"

     msg_newline:
               .string  "\n"

# section: Block started with symbol
.section   .bss
     .comm     column, 4, 4
     .comm     row   , 4, 4

# section: text
.section  .text

# Entry point: _start
     .globl    _start
     .type     _start , @function
_start:
     
     # PROLOGUE
     pushl   %ebp
     movl    %esp , %ebp

     # MAIN CODE

     # 1.Initialization         (outer loop)
     movl    $5  , column

     # 2.Terminating  condition           (outer loop)
.loop:
     movl    column, %eax
     cmpl    $0  , %eax
     jle      .epilogue

     # 3. Loop body         (outer loop)
     
     # Initialization          (inner loop)
     movl    $1  , row

     # Terminating condition     (inner loop)
.inner_loop:
     movl    row , %eax
     cmpl    $5 , %eax
     jg      .outer

     # Loop body      (inner loop)

     movl    row, %eax
     movl    column , %ebx
     cmpl    %ebx , %eax
     jl      .space

     # printing message
     pushl    $msg_symbol
     call     printf
     addl     $8  , %esp
     jmp      .out


.space:
     # Printing message 
     pushl    $msg_space
     call     printf
     addl     $8  , %esp
     jmp      .out

.out:
     # Incrementing steps         (inner loop)
     # row++
     incl   row
     jmp    .inner_loop

.outer:
     # row=1
     movl    $1 , row

     # Printing message
     pushl   $msg_newline
     call    printf
     addl    $8  , %esp

     # 4. decrementing steps        (outer loop)
     # column--
     decl    column
     jmp      .loop

.epilogue:
     pushl    $0
     call     exit
