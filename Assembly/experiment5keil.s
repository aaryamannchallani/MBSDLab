		INCLUDE MSP432xx_constants.s
		INCLUDE MSP432xx_tim_constants.s
		AREA main,CODE,READONLY	
		EXPORT __main
		ENTRY
__main	PROC
		LDR R9,=0x20000000
		MOV R8,#0x00
		MOV R7,#0x04
		MOV R0,#12
		MOV R1,#13
		MOV R2,#0x34
		MOV R3,#0x12
__loop	ADD R0,R0
		STR R0,[R9,R8]
		ADD R8,#4
		SUBS R7,#1
		BNE __loop
		
		
		
		ENDP
					
		ALIGN
		AREA allocations, DATA, READWRITE
		END

