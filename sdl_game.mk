##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=sdl_game
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/steve/Documents/sdl
ProjectPath            :=C:/Users/steve/Documents/GitHub/sdl_sdk
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=steve
Date                   :=21/11/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="sdl_game.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch)C:\Users\steve\Documents\sdl\SDL2-2.0.5\x86_64-w64-mingw32\include\SDL2 $(IncludeSwitch)C:\Users\steve\Documents\sdl\SDL2_image-2.0.1\x86_64-w64-mingw32\include\SDL2 $(IncludeSwitch)C:\Users\steve\Downloads\SDL2_ttf-2.0.14\x86_64-w64-mingw32\include\SDL2 $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mingw32 $(LibrarySwitch)SDL2main $(LibrarySwitch)SDL2 $(LibrarySwitch)SDL2_image $(LibrarySwitch)SDL2_ttf 
ArLibs                 :=  "mingw32" "SDL2main" "SDL2" "SDL2_image" "SDL2_ttf" 
LibPath                := $(LibraryPathSwitch)C:\Users\steve\Documents\sdl\SDL2-2.0.5\x86_64-w64-mingw32\lib $(LibraryPathSwitch)C:\Users\steve\Documents\sdl\SDL2_image-2.0.1\x86_64-w64-mingw32\lib $(LibraryPathSwitch)C:\Users\steve\Downloads\SDL2_ttf-2.0.14\x86_64-w64-mingw32\lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameCore.cpp$(ObjectSuffix) $(IntermediateDirectory)/Texture.cpp$(ObjectSuffix) $(IntermediateDirectory)/Config.cpp$(ObjectSuffix) $(IntermediateDirectory)/Translate.cpp$(ObjectSuffix) $(IntermediateDirectory)/time_user.cpp$(ObjectSuffix) $(IntermediateDirectory)/Input.cpp$(ObjectSuffix) $(IntermediateDirectory)/Container.cpp$(ObjectSuffix) $(IntermediateDirectory)/World.cpp$(ObjectSuffix) $(IntermediateDirectory)/Generator.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Civilian.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/GameCore.cpp$(ObjectSuffix): GameCore.cpp $(IntermediateDirectory)/GameCore.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/GameCore.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameCore.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameCore.cpp$(DependSuffix): GameCore.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameCore.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameCore.cpp$(DependSuffix) -MM GameCore.cpp

$(IntermediateDirectory)/GameCore.cpp$(PreprocessSuffix): GameCore.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameCore.cpp$(PreprocessSuffix) GameCore.cpp

$(IntermediateDirectory)/Texture.cpp$(ObjectSuffix): Texture.cpp $(IntermediateDirectory)/Texture.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/Texture.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Texture.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Texture.cpp$(DependSuffix): Texture.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Texture.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Texture.cpp$(DependSuffix) -MM Texture.cpp

$(IntermediateDirectory)/Texture.cpp$(PreprocessSuffix): Texture.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Texture.cpp$(PreprocessSuffix) Texture.cpp

$(IntermediateDirectory)/Config.cpp$(ObjectSuffix): Config.cpp $(IntermediateDirectory)/Config.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/Config.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Config.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Config.cpp$(DependSuffix): Config.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Config.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Config.cpp$(DependSuffix) -MM Config.cpp

$(IntermediateDirectory)/Config.cpp$(PreprocessSuffix): Config.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Config.cpp$(PreprocessSuffix) Config.cpp

$(IntermediateDirectory)/Translate.cpp$(ObjectSuffix): Translate.cpp $(IntermediateDirectory)/Translate.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/Translate.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Translate.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Translate.cpp$(DependSuffix): Translate.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Translate.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Translate.cpp$(DependSuffix) -MM Translate.cpp

$(IntermediateDirectory)/Translate.cpp$(PreprocessSuffix): Translate.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Translate.cpp$(PreprocessSuffix) Translate.cpp

$(IntermediateDirectory)/time_user.cpp$(ObjectSuffix): time_user.cpp $(IntermediateDirectory)/time_user.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/time_user.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/time_user.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/time_user.cpp$(DependSuffix): time_user.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/time_user.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/time_user.cpp$(DependSuffix) -MM time_user.cpp

$(IntermediateDirectory)/time_user.cpp$(PreprocessSuffix): time_user.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/time_user.cpp$(PreprocessSuffix) time_user.cpp

$(IntermediateDirectory)/Input.cpp$(ObjectSuffix): Input.cpp $(IntermediateDirectory)/Input.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/Input.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Input.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Input.cpp$(DependSuffix): Input.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Input.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Input.cpp$(DependSuffix) -MM Input.cpp

$(IntermediateDirectory)/Input.cpp$(PreprocessSuffix): Input.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Input.cpp$(PreprocessSuffix) Input.cpp

$(IntermediateDirectory)/Container.cpp$(ObjectSuffix): Container.cpp $(IntermediateDirectory)/Container.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/Container.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Container.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Container.cpp$(DependSuffix): Container.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Container.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Container.cpp$(DependSuffix) -MM Container.cpp

$(IntermediateDirectory)/Container.cpp$(PreprocessSuffix): Container.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Container.cpp$(PreprocessSuffix) Container.cpp

$(IntermediateDirectory)/World.cpp$(ObjectSuffix): World.cpp $(IntermediateDirectory)/World.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/World.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/World.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/World.cpp$(DependSuffix): World.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/World.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/World.cpp$(DependSuffix) -MM World.cpp

$(IntermediateDirectory)/World.cpp$(PreprocessSuffix): World.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/World.cpp$(PreprocessSuffix) World.cpp

$(IntermediateDirectory)/Generator.cpp$(ObjectSuffix): Generator.cpp $(IntermediateDirectory)/Generator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/Generator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Generator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Generator.cpp$(DependSuffix): Generator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Generator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Generator.cpp$(DependSuffix) -MM Generator.cpp

$(IntermediateDirectory)/Generator.cpp$(PreprocessSuffix): Generator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Generator.cpp$(PreprocessSuffix) Generator.cpp

$(IntermediateDirectory)/Civilian.cpp$(ObjectSuffix): Civilian.cpp $(IntermediateDirectory)/Civilian.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/steve/Documents/GitHub/sdl_sdk/Civilian.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Civilian.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Civilian.cpp$(DependSuffix): Civilian.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Civilian.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Civilian.cpp$(DependSuffix) -MM Civilian.cpp

$(IntermediateDirectory)/Civilian.cpp$(PreprocessSuffix): Civilian.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Civilian.cpp$(PreprocessSuffix) Civilian.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


