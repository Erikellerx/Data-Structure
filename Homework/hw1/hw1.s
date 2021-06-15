	.file	"hw1.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.section	.text._ZStorSt13_Ios_OpenmodeS_,"axG",@progbits,_ZStorSt13_Ios_OpenmodeS_,comdat
	.weak	_ZStorSt13_Ios_OpenmodeS_
	.type	_ZStorSt13_Ios_OpenmodeS_, @function
_ZStorSt13_Ios_OpenmodeS_:
.LFB1095:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	orl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1095:
	.size	_ZStorSt13_Ios_OpenmodeS_, .-_ZStorSt13_Ios_OpenmodeS_
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	_Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
	.type	_Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei, @function
_Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei:
.LFB1612:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1612
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -88(%rbp)
	movl	%esi, -92(%rbp)
	movq	%rdx, -104(%rbp)
	movl	%ecx, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$0, -76(%rbp)
	movl	$0, -72(%rbp)
.L11:
	movl	-72(%rbp), %eax
	cmpl	-92(%rbp), %eax
	jge	.L17
	cmpl	$0, -72(%rbp)
	je	.L5
	movl	-92(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -72(%rbp)
	jne	.L6
.L5:
	movq	-104(%rbp), %rbx
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	movl	-92(%rbp), %eax
	movslq	%eax, %rsi
	leaq	-77(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rcx
	movl	$42, %edx
	movq	%rax, %rdi
.LEHB0:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EmcRKS3_@PLT
.LEHE0:
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB1:
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE1:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L7
.L6:
	movq	-104(%rbp), %rax
	movl	$42, %esi
	movq	%rax, %rdi
.LEHB2:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movl	$0, -68(%rbp)
.L10:
	movl	-92(%rbp), %eax
	subl	$2, %eax
	cmpl	%eax, -68(%rbp)
	jge	.L8
	movl	-76(%rbp), %eax
	cmpl	-96(%rbp), %eax
	jne	.L9
	movl	$0, -76(%rbp)
.L9:
	movq	-104(%rbp), %rbx
	movl	-76(%rbp), %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm@PLT
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	addl	$1, -76(%rbp)
	addl	$1, -68(%rbp)
	jmp	.L10
.L8:
	movq	-104(%rbp), %rax
	movl	$42, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.L7:
	addl	$1, -72(%rbp)
	jmp	.L11
.L16:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L13
.L15:
	movq	%rax, %rbx
.L13:
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE2:
.L17:
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L14
	call	__stack_chk_fail@PLT
.L14:
	addq	$104, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1612:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1612:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1612-.LLSDACSB1612
.LLSDACSB1612:
	.uleb128 .LEHB0-.LFB1612
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L15-.LFB1612
	.uleb128 0
	.uleb128 .LEHB1-.LFB1612
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L16-.LFB1612
	.uleb128 0
	.uleb128 .LEHB2-.LFB1612
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE1612:
	.text
	.size	_Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei, .-_Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
	.globl	_Z14right_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
	.type	_Z14right_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei, @function
_Z14right_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei:
.LFB1613:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1613
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -88(%rbp)
	movl	%esi, -92(%rbp)
	movq	%rdx, -104(%rbp)
	movl	%ecx, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$0, -76(%rbp)
	movl	$0, -72(%rbp)
.L26:
	movl	-72(%rbp), %eax
	cmpl	-92(%rbp), %eax
	jge	.L32
	cmpl	$0, -72(%rbp)
	jne	.L20
	movq	-104(%rbp), %rax
	movl	$42, %esi
	movq	%rax, %rdi
.LEHB3:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE3:
	jmp	.L21
.L20:
	movl	-92(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -72(%rbp)
	jne	.L22
	movq	-104(%rbp), %rbx
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	movl	-92(%rbp), %eax
	movslq	%eax, %rsi
	leaq	-77(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rcx
	movl	$42, %edx
	movq	%rax, %rdi
.LEHB4:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EmcRKS3_@PLT
.LEHE4:
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB5:
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE5:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L21
.L22:
	movq	-104(%rbp), %rax
	movl	$42, %esi
	movq	%rax, %rdi
.LEHB6:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movl	$0, -68(%rbp)
.L25:
	movl	-72(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -68(%rbp)
	jge	.L23
	movl	-76(%rbp), %eax
	cmpl	-96(%rbp), %eax
	jne	.L24
	movl	$0, -76(%rbp)
.L24:
	movq	-104(%rbp), %rbx
	movl	-76(%rbp), %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm@PLT
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	addl	$1, -76(%rbp)
	addl	$1, -68(%rbp)
	jmp	.L25
.L23:
	movq	-104(%rbp), %rax
	movl	$42, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.L21:
	addl	$1, -72(%rbp)
	jmp	.L26
.L31:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L28
.L30:
	movq	%rax, %rbx
.L28:
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE6:
.L32:
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L29
	call	__stack_chk_fail@PLT
.L29:
	addq	$104, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1613:
	.section	.gcc_except_table
.LLSDA1613:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1613-.LLSDACSB1613
.LLSDACSB1613:
	.uleb128 .LEHB3-.LFB1613
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB1613
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L30-.LFB1613
	.uleb128 0
	.uleb128 .LEHB5-.LFB1613
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L31-.LFB1613
	.uleb128 0
	.uleb128 .LEHB6-.LFB1613
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
.LLSDACSE1613:
	.text
	.size	_Z14right_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei, .-_Z14right_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
	.globl	_Z18isosceles_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
	.type	_Z18isosceles_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei, @function
_Z18isosceles_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei:
.LFB1614:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1614
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -88(%rbp)
	movl	%esi, -92(%rbp)
	movq	%rdx, -104(%rbp)
	movl	%ecx, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movl	$0, -76(%rbp)
	movl	$0, -72(%rbp)
.L41:
	movl	-72(%rbp), %eax
	cmpl	-92(%rbp), %eax
	jge	.L51
	movq	-104(%rbp), %rbx
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	movl	-92(%rbp), %eax
	subl	$1, %eax
	subl	-72(%rbp), %eax
	movslq	%eax, %rsi
	leaq	-77(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rcx
	movl	$32, %edx
	movq	%rax, %rdi
.LEHB7:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EmcRKS3_@PLT
.LEHE7:
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB8:
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
.LEHE8:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movl	-92(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -72(%rbp)
	jne	.L35
	movq	-104(%rbp), %rbx
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	movl	-92(%rbp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	movslq	%eax, %rsi
	leaq	-77(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rcx
	movl	$42, %edx
	movq	%rax, %rdi
.LEHB9:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EmcRKS3_@PLT
.LEHE9:
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movq	%rbx, %rdi
.LEHB10:
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE10:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L36
.L35:
	cmpl	$0, -72(%rbp)
	jne	.L37
	movq	-104(%rbp), %rax
	movl	$42, %esi
	movq	%rax, %rdi
.LEHB11:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	jmp	.L36
.L37:
	movq	-104(%rbp), %rax
	movl	$42, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movl	$0, -68(%rbp)
.L40:
	movl	-72(%rbp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	cmpl	%eax, -68(%rbp)
	jge	.L38
	movl	-76(%rbp), %eax
	cmpl	-96(%rbp), %eax
	jne	.L39
	movl	$0, -76(%rbp)
.L39:
	movq	-104(%rbp), %rbx
	movl	-76(%rbp), %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEm@PLT
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	addl	$1, -76(%rbp)
	addl	$1, -68(%rbp)
	jmp	.L40
.L38:
	movq	-104(%rbp), %rax
	movl	$42, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.L36:
	addl	$1, -72(%rbp)
	jmp	.L41
.L48:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L43
.L47:
	movq	%rax, %rbx
.L43:
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.L50:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L45
.L49:
	movq	%rax, %rbx
.L45:
	leaq	-77(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
	call	_Unwind_Resume@PLT
.LEHE11:
.L51:
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L46
	call	__stack_chk_fail@PLT
.L46:
	addq	$104, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1614:
	.section	.gcc_except_table
.LLSDA1614:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1614-.LLSDACSB1614
.LLSDACSB1614:
	.uleb128 .LEHB7-.LFB1614
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L47-.LFB1614
	.uleb128 0
	.uleb128 .LEHB8-.LFB1614
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L48-.LFB1614
	.uleb128 0
	.uleb128 .LEHB9-.LFB1614
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L49-.LFB1614
	.uleb128 0
	.uleb128 .LEHB10-.LFB1614
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L50-.LFB1614
	.uleb128 0
	.uleb128 .LEHB11-.LFB1614
	.uleb128 .LEHE11-.LEHB11
	.uleb128 0
	.uleb128 0
.LLSDACSE1614:
	.text
	.size	_Z18isosceles_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei, .-_Z18isosceles_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
	.section	.rodata
.LC0:
	.string	"Missing argument"
.LC1:
	.string	"Can not open the file"
.LC2:
	.string	"The number is too small"
.LC3:
	.string	"square"
.LC4:
	.string	"right_triangle"
.LC5:
	.string	"isosceles_triangle"
.LC6:
	.string	"Don't have such shape"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1615:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1615
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$760, %rsp
	.cfi_offset 3, -24
	movl	%edi, -756(%rbp)
	movq	%rsi, -768(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-544(%rbp), %rax
	movq	%rax, %rdi
.LEHB12:
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1Ev@PLT
.LEHE12:
	cmpl	$5, -756(%rbp)
	je	.L53
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cerr(%rip), %rdi
.LEHB13:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE13:
	movl	$1, %edi
	call	exit@PLT
.L53:
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	movq	-768(%rbp), %rax
	addq	$32, %rax
	movq	(%rax), %rcx
	leaq	-745(%rbp), %rdx
	leaq	-736(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB14:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE14:
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	movl	$32, %esi
	movl	$16, %edi
	call	_ZStorSt13_Ios_OpenmodeS_
	movl	%eax, %edx
	leaq	-736(%rbp), %rcx
	leaq	-544(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB15:
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEE4openERKNSt7__cxx1112basic_stringIcS1_SaIcEEESt13_Ios_Openmode@PLT
	leaq	-544(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEE7is_openEv@PLT
	xorl	$1, %eax
	testb	%al, %al
	je	.L54
	leaq	.LC1(%rip), %rsi
	leaq	_ZSt4cerr(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE15:
	movl	$1, %edi
	call	exit@PLT
.L54:
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	movq	-768(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rcx
	leaq	-745(%rbp), %rdx
	leaq	-704(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB16:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE16:
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	movq	-768(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rcx
	leaq	-745(%rbp), %rdx
	leaq	-672(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB17:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE17:
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev@PLT
	movq	-768(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rcx
	leaq	-745(%rbp), %rdx
	leaq	-640(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
.LEHB18:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@PLT
.LEHE18:
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	leaq	-608(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@PLT
	leaq	-704(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv@PLT
	movl	%eax, -744(%rbp)
	leaq	-672(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv@PLT
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, -740(%rbp)
	cmpl	$0, -740(%rbp)
	jg	.L55
	leaq	.LC2(%rip), %rsi
	leaq	_ZSt4cerr(%rip), %rdi
.LEHB19:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
	movl	$1, %edi
	call	exit@PLT
.L55:
	leaq	-640(%rbp), %rax
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	testb	%al, %al
	je	.L56
	leaq	-704(%rbp), %rdx
	leaq	-576(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@PLT
.LEHE19:
	movl	-744(%rbp), %ecx
	leaq	-544(%rbp), %rdx
	movl	-740(%rbp), %esi
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
.LEHB20:
	call	_Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
.LEHE20:
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L57
.L56:
	leaq	-640(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	testb	%al, %al
	je	.L58
	leaq	-704(%rbp), %rdx
	leaq	-576(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB21:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@PLT
.LEHE21:
	movl	-744(%rbp), %ecx
	leaq	-544(%rbp), %rdx
	movl	-740(%rbp), %esi
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
.LEHB22:
	call	_Z14right_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
.LEHE22:
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L57
.L58:
	leaq	-640(%rbp), %rax
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	testb	%al, %al
	je	.L59
	leaq	-704(%rbp), %rdx
	leaq	-576(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB23:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@PLT
.LEHE23:
	movl	-744(%rbp), %ecx
	leaq	-544(%rbp), %rdx
	movl	-740(%rbp), %esi
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
.LEHB24:
	call	_Z18isosceles_triangleNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
.LEHE24:
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L57
.L59:
	leaq	.LC6(%rip), %rsi
	leaq	_ZSt4cerr(%rip), %rdi
.LEHB25:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE25:
	movl	$1, %edi
	call	exit@PLT
.L57:
	leaq	-608(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-640(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-672(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-704(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-736(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-544(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L73
	jmp	.L84
.L75:
	movq	%rax, %rbx
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L62
.L77:
	movq	%rax, %rbx
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L64
.L78:
	movq	%rax, %rbx
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L66
.L79:
	movq	%rax, %rbx
	leaq	-745(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev@PLT
	jmp	.L68
.L81:
	movq	%rax, %rbx
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L70
.L82:
	movq	%rax, %rbx
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L70
.L83:
	movq	%rax, %rbx
	leaq	-576(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L70
.L80:
	movq	%rax, %rbx
.L70:
	leaq	-608(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-640(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
.L68:
	leaq	-672(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
.L66:
	leaq	-704(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L64
.L76:
	movq	%rax, %rbx
.L64:
	leaq	-736(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L62
.L74:
	movq	%rax, %rbx
.L62:
	leaq	-544(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB26:
	call	_Unwind_Resume@PLT
.LEHE26:
.L84:
	call	__stack_chk_fail@PLT
.L73:
	addq	$760, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1615:
	.section	.gcc_except_table
.LLSDA1615:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1615-.LLSDACSB1615
.LLSDACSB1615:
	.uleb128 .LEHB12-.LFB1615
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB13-.LFB1615
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L74-.LFB1615
	.uleb128 0
	.uleb128 .LEHB14-.LFB1615
	.uleb128 .LEHE14-.LEHB14
	.uleb128 .L75-.LFB1615
	.uleb128 0
	.uleb128 .LEHB15-.LFB1615
	.uleb128 .LEHE15-.LEHB15
	.uleb128 .L76-.LFB1615
	.uleb128 0
	.uleb128 .LEHB16-.LFB1615
	.uleb128 .LEHE16-.LEHB16
	.uleb128 .L77-.LFB1615
	.uleb128 0
	.uleb128 .LEHB17-.LFB1615
	.uleb128 .LEHE17-.LEHB17
	.uleb128 .L78-.LFB1615
	.uleb128 0
	.uleb128 .LEHB18-.LFB1615
	.uleb128 .LEHE18-.LEHB18
	.uleb128 .L79-.LFB1615
	.uleb128 0
	.uleb128 .LEHB19-.LFB1615
	.uleb128 .LEHE19-.LEHB19
	.uleb128 .L80-.LFB1615
	.uleb128 0
	.uleb128 .LEHB20-.LFB1615
	.uleb128 .LEHE20-.LEHB20
	.uleb128 .L81-.LFB1615
	.uleb128 0
	.uleb128 .LEHB21-.LFB1615
	.uleb128 .LEHE21-.LEHB21
	.uleb128 .L80-.LFB1615
	.uleb128 0
	.uleb128 .LEHB22-.LFB1615
	.uleb128 .LEHE22-.LEHB22
	.uleb128 .L82-.LFB1615
	.uleb128 0
	.uleb128 .LEHB23-.LFB1615
	.uleb128 .LEHE23-.LEHB23
	.uleb128 .L80-.LFB1615
	.uleb128 0
	.uleb128 .LEHB24-.LFB1615
	.uleb128 .LEHE24-.LEHB24
	.uleb128 .L83-.LFB1615
	.uleb128 0
	.uleb128 .LEHB25-.LFB1615
	.uleb128 .LEHE25-.LEHB25
	.uleb128 .L80-.LFB1615
	.uleb128 0
	.uleb128 .LEHB26-.LFB1615
	.uleb128 .LEHE26-.LEHB26
	.uleb128 0
	.uleb128 0
.LLSDACSE1615:
	.text
	.size	main, .-main
	.section	.text._ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_,"axG",@progbits,_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_,comdat
	.weak	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	.type	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_, @function
_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_:
.LFB1895:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7compareEPKc@PLT
	testl	%eax, %eax
	sete	%al
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1895:
	.size	_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_, .-_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2168:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L89
	cmpl	$65535, -8(%rbp)
	jne	.L89
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L89:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2168:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei, @function
_GLOBAL__sub_I__Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei:
.LFB2169:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2169:
	.size	_GLOBAL__sub_I__Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei, .-_GLOBAL__sub_I__Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z6squareNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiRSt14basic_ofstreamIcS2_Ei
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
