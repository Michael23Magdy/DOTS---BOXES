#Name
GameName:= DotBoxes.exe

#header files
HDR_INC:= main.c
HDR_INC+= Print_Patterns.c
HDR_INC+= menu.c
HDR_INC+= Grid.c
HDR_INC+= Player.c
HDR_INC+= Game.c

Build:
	@g++ -o $(GameName) $(HDR_INC)

run: Build
	@./$(GameName)