		INCLUDE MSP432xx_constants.s
		INCLUDE MSP432xx_tim_constants.s
		AREA main,CODE,READONLY	
		EXPORT __main
		ENTRY
__main	PROC
		MOV R0,#123
		LDR R9,=0x20000000
		STR R0,[R9]
		LSL R0,#3
		STR R0,[R9,#4]
		LSR R0,#3
		STR R0,[R9,#8]
		ASR R0,#3
		STR R0,[R9,#12]
		ROR R0,#5
		STR R0,[R9,#16]
		
		ENDP
					
		ALIGN
		AREA allocations, DATA, READWRITE
		END

