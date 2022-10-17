
# Read only memory
.section .rodata
         msg_symbol:
         .string "*\t"

         msg_space:
         .string "\t"

         msg_newline:
         .string "\n"
# Section : block started with symbol
.section  .bss
         .comm     column_hpn , 4, 4
         .comm     row_hpn    , 4, 4

#Section : Data
.section  .data
          .globl   space_hpn
          .align   4
          .type    space_hpn , @object
          .size    space_hpn , 4
space_hpn:
          .long    4
          .globl   i_hpn
          .align   4
          .type    i_hpn , @object
          .size    i_hpn , 4
i_hpn:
          .long    5

# Text section
.section  .text

# Entry point : _start
          .global   _start
          .type     _start , @function
_start:
          #PROLOGUE
          pushl     %ebp
          movl      %esp , %ebp

          # Main code
          # 1. Initialization  (outer loop)
          movl     $1   , column_hpn

          # 2. Termination condition (outer loop)
.loop:
          movl     column_hpn , %eax
          movl     $5         , %ebx
          cmpl     %ebx       , %eax
          jg       .epilogue

          # 3. Loop body (outer loop)
          # Initialization (inner loop)
          movl     $1    , row_hpn
       
          # Terminating Condition (inner loop)
.inner_loop:
          movl     row_hpn , %eax
          movl     i_hpn   , %ebx
          cmpl     %ebx    , %eax
          jg       .outer
         
          # Loop body
          movl     row_hpn , %eax
          movl     space_hpn, %ebx
          cmpl     %ebx    , %eax
          jg       .greater

          # Printing message
          pushl    $msg_space
          call     printf
          addl     $8    , %esp
          jmp      .continue

.greater:
          #Printing message
          pushl    $msg_symbol
          call     printf
          addl     $8    , %esp
          jmp      .continue

.continue:
          # incrementing condition (inner loop)
          # row_hpn++
          movl    row_hpn  , %eax
          movl    $1       , %ebx
          addl    %ebx     , %eax
          movl    %eax     , row_hpn          
          jmp     .inner_loop

.outer:
          #row_hpn=1
          movl    $1   , row_hpn
          #space_hpn--
          movl    space_hpn , %eax
          movl    $1        , %ebx
          subl    %ebx      , %eax
          movl    %eax      , space_hpn
          #i_hpn++
          movl    i_hpn , %eax
          movl    $1        , %ebx
          addl    %ebx      , %eax
          movl    %eax      , i_hpn 
          # Printing message
          pushl   $msg_newline
          call    printf
          addl    $8   , %esp

          # 4. Incrementing condition (outer loop)
          #column_hpn++
          movl    column_hpn , %eax
          movl    $1        , %ebx
          addl    %ebx      , %eax
          movl    %eax      , column_hpn
          jmp     .loop

.epilogue:
          pushl   $0
          call    exit





























































