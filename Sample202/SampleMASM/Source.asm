
.code

;float funcSample(Vector* v)
funcSample	proc
	movss	xmm0,	dword ptr [rcx]
	addss	xmm0,	dword ptr [rcx+4]
	addss	xmm0,	dword ptr [rcx+8]
	addss	xmm0,	dword ptr [rcx+12]
	ret	
funcSample	endp
		end
