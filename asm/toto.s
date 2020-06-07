.name "toto"
.comment "BEST TEST FILE FOR ASM"
 	
live %42
ld %42, r1
ld 41, r2
st r2, 42
st r2, r1
add r1, r2, r3
sub r1, r2, r3
and r1 , r2, r3
and 1 , 2, r3
and r1 , 2, r3
and 1 , r2, r3
and r1 , %2, r3
and %1 , r2, r3
or r1 , r2, r3
or 1 , 2, r3
or r1 , 2, r3
or 1 , r2, r3
or r1 , %2, r3
or %1 , r2, r3
xor r1 , r2, r3
xor 1 , 2, r3
xor r1 , 2, r3
xor 1 , r2, r3
xor r1 , %2, r3
xor %1 , r2, r3
zjmp %42
ldi r1, r2, r3
ldi r1, %2, r3
ldi %1, r2, r3
ldi %1, %2, r3
ldi 1, r2, r3
ldi 1, %2, r3
sti r1, r2, r3
sti r1, r2, %3
sti r1, 2, r3
sti r1, 2, %3
sti r1, %2, r3
sti r1, %2, %3
fork %42
lld 1, r1
lld %1, r1
lldi r1, r2, r3
lldi r1, %2, r3
lldi 1, r2, r3
lldi 1, %2, r3
lldi %1, r2, r3
lldi %1, %2, r3
lfork %42
aff r1
