    GLOBAL main
    AREA mycode,CODE,READONLY
	
	ENTRY
myvar1 EQU 0xBEEFFEED
myvar2 EQU 0xABBCABBC
myvar3 EQU 0xCAADBAAD
main
     LDR R0,=0x20000002 ; R0 points to 0x20000002
	 LDR R1,=myvar1 ; R1 points to value 0xBEEFFEED
	 STR R1,[R0]        ; store value of R1 to address pointed by R0
	 LDR R3,=myvar2 ;R3 points to value 0xABBCABBC
	 STR R3,[R0,#4]     ; store value of R3 in to R0+4(byte),32 bit
     LDR R4,=myvar3	 ; R4 points to value 0xCAADBAAD
	 STR R4,[R0,#16]   ; Store R4 value to R0+16 (4*4)  
	 
stop B stop
     END
	 