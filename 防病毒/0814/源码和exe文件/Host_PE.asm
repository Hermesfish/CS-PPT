;******************************************
;PE病毒感染测试文件
;文件名：host_pe.asm
;*****************************************
.386
.model flat,stdcall
option casemap:none

include C:\RadASM\masm32\include\windows.inc
include C:\RadASM\masm32\include\kernel32.inc
include C:\RadASM\masm32\include\user32.inc
includelib C:\RadASM\masm32\lib\kernel32.lib
includelib C:\RadASM\masm32\lib\user32.lib

.data
szText     db       "这是一个PE程序",0
szCaption  db       "感染测试目标",0

.code
main:
    invoke MessageBox,NULL, addr szText, addr szCaption,MB_OK
    invoke ExitProcess,0
end main
