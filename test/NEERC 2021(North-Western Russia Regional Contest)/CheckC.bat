@echo off
:S
	Random_C.exe > C.in
	tmp.exe < C.in > C1.out
	tmpc2.exe < C.in > C2.out
fc C1.out C2.out
if not errorlevel 1 goto S
pause