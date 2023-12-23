#Name
GameName:= DotBoxes.exe

#header files
HDR_INC:= main.c
HDR_INC+= Print_Patterns.c
HDR_INC+= menu.c

Build:
	@g++ -o $(GameName) $(HDR_INC)

run: Build
	@./$(GameName)