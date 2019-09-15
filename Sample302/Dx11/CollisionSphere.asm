
.data

.code

;int CollisionSp(SPHERE* sp1, SPHERE* sp2)
;dword ptr [rcx]		sp1.m_Center.x
;dword ptr [rcx+4]		sp1.m_Center.y
;dword ptr [rcx+8]		sp1.m_Center.z
;dword ptr [rcx+12]		sp1.m_Radius
;dword ptr [rdx]		sp2.m_Center.x
;dword ptr [rdx+4]		sp2.m_Center.y
;dword ptr [rdx+8]		sp2.m_Center.z
;dword ptr [rdx+12]		sp2.m_Radius
CollisionSp	proc
	;m_Center―mΜψ«Z
	movss	xmm4,	dword ptr [rcx]		;sp1.m_Center.x
	subss	xmm4,	dword ptr [rdx]		;sp2.m_Center.x
	mulss	xmm4,	xmm4					;x * x
	movss	xmm5,	dword ptr [rcx+4]		;sp1.m_Center.y
	subss	xmm5,	dword ptr [rdx+4]		;sp2.m_Center.y
	mulss	xmm5,	xmm5					;y * y
	movss	xmm6,	dword ptr [rcx+8]		;sp1.m_Center.z
	subss	xmm6,	dword ptr [rdx+8]		;sp2.m_Center.z
	mulss	xmm6,	xmm6					;z * z
	;dotZ
	addss	xmm4,	xmm5					
	addss	xmm4,	xmm6					; xmm4 == dot
	;Όa―mΜΑZ
	movss	xmm1,	dword ptr [rcx+12]		;sp1.m_Radius
	addss	xmm1,	dword ptr [rdx+12]		;sp2.m_Radius
	;ΑZΚΜ2ζ
	mulss	xmm1,	xmm1					
	;ΌaΑZ2ζͺdotZΚζθε«―κΞΥΛ
	comiss	xmm4,	xmm1
	JBE		truelabel
	mov		eax,	0
	ret	
truelabel:
	mov		eax,	1
	ret	
CollisionSp	endp
		end
