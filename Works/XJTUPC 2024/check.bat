@echo off
:ss
	random.exe>a.in
	StarRail.exe<a.in>a1.out
	sr2.exe<a.in>a2.out
fc a1.out a2.out
if not errorlevel 1 goto ss
pause