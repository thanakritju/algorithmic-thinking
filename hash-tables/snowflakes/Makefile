test:
	@gcc snowflakes.c
	@a.exe < input | diff output -
	@a.exe < input2 | diff output2 -

	@gcc snowflakes2.c
	@a.exe < input | diff output -
	@a.exe < input2 | diff output2 -