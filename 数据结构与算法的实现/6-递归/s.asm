	TITLE	Hanoi.c
	.386P
include listing.inc
if @Version gt 510
.model FLAT
else
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
_DATA	SEGMENT DWORD USE32 PUBLIC 'DATA'
_DATA	ENDS
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
_BSS	SEGMENT DWORD USE32 PUBLIC 'BSS'
_BSS	ENDS
_TLS	SEGMENT DWORD USE32 PUBLIC 'TLS'
_TLS	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
PUBLIC	_Hanoii
EXTRN	_printf:NEAR
_DATA	SEGMENT
$SG353	DB	'%d:%c->%c', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_n$ = 8
_s$ = 12
_a$ = 16
_t$ = 20
_Hanoii	PROC NEAR
; File Hanoi.c
; Line 6
	push	ebp
	mov	ebp, esp
; Line 7
	cmp	DWORD PTR _n$[ebp], 0
	jle	SHORT $L352
; Line 8
	mov	al, BYTE PTR _a$[ebp]
	push	eax
	mov	cl, BYTE PTR _t$[ebp]
	push	ecx
	mov	dl, BYTE PTR _s$[ebp]
	push	edx
	mov	eax, DWORD PTR _n$[ebp]
	sub	eax, 1
	push	eax
	call	_Hanoii
	add	esp, 16					; 00000010H
; Line 9
	movsx	ecx, BYTE PTR _t$[ebp]
	push	ecx
	movsx	edx, BYTE PTR _s$[ebp]
	push	edx
	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	push	OFFSET FLAT:$SG353
	call	_printf
	add	esp, 16					; 00000010H
; Line 10
	mov	cl, BYTE PTR _t$[ebp]
	push	ecx
	mov	dl, BYTE PTR _s$[ebp]
	push	edx
	mov	al, BYTE PTR _a$[ebp]
	push	eax
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	push	ecx
	call	_Hanoii
	add	esp, 16					; 00000010H
$L352:
; Line 12
	pop	ebp
	ret	0
_Hanoii	ENDP
_TEXT	ENDS
PUBLIC	_main
_TEXT	SEGMENT
_hight$ = -4
_main	PROC NEAR
; Line 14
	push	ebp
	mov	ebp, esp
	push	ecx
; Line 15
	mov	DWORD PTR _hight$[ebp], 3
; Line 17
	push	67					; 00000043H
	push	66					; 00000042H
	push	65					; 00000041H
	mov	eax, DWORD PTR _hight$[ebp]
	push	eax
	call	_Hanoii
	add	esp, 16					; 00000010H
; Line 18
	xor	eax, eax
; Line 19
	mov	esp, ebp
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
END
