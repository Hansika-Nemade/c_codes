
# pattern_92.s

# section: Read only data
.section  .rodata
    msg_symbol:
    .string "*\t"

    msg_newline:
    .string "\n"

# section: Block started with symbol
.section  .bss
    .comm   column, 4, 4
    .comm    row  , 4, 4

# section: text
.section   .text

# Entry point: _start
    .globl   _start
    .type    _start , @function
_start:
    
     # PROLOGUE
    
     # MAIN CODE

     # 1.Initialization            (outer loop)
     movl    $1 , column

     # 2. Terminating condition       (outer loop)
.loop:
     movl    column, %eax
     cmpl    $5  , %eax
     jg      .epilogue

     # 3. loop body          (outer loop)
  
     # Initialization             (inner loop)
     movl    $1 , row

     # Terminating condition        (inner loop)
.inner_loop:
     movl    row , %eax
     cmpl    $5, %eax
     jg      .outer

     # Loop body          (inner loop)

     # Printing message      
     pushl   $msg_symbol
     call    printf
     addl    $8  , %esp

     # incrementing steps        (inner loop)
     # row++
     incl    row 
     jmp     .inner_loop

.outer:
     # row=1
     movl   $1  , row

     # Printing message
     pushl   $msg_newline
     call    printf
     addl    $8  , %esp

     # 4. Incrementing step       (outer loop)
     # column++
     incl    column
     jmp     .loop

.epilogue:
     pushl   $0
     call     exit
