.model flat, c

.code

;int func102(int a,int b)
func102	proc a:DWORD,b:DWORD
		mov eax,a
		add eax,b
		ret
func102	endp
end
