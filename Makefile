############
# Programs #
############

CC         = @sh-elf-gcc
LINKER     = @sh-elf-gcc
CONV       = @sh-elf-objcopy
INFO       = @echo
MAKEDIR    = @mkdir -p
REMOVER    = @rm -f
AWK        = @awk
TAR        = tar

#####################
# Operating Systems #
#####################

#OS         = $(shell uname)
GETOPTSRC  =
GETOPTENABLED  =
#non GNU unix systems should uncomment the following two lines
#GETOPTSRC  = getopt.o getopt1.o
#GETOPTENABLED  = -DENABLE_GETOPT

####################
# Compiler options #
####################

#Libraries: include path and linked libs
INCLUDE       = -Iinclude/ -Iports/include
#LIBS          = $(shell sdl-config --libs --cflags)
#but if you have problems porting to BSD use:
#LIBS         = -L/usr/local/lib -lSDL-1.1 -pthread 
LIBS         = C:/SaturnOrbit/SGL_302j/LIB_ELF/LIBSGL.A D:\saturn\SBL6\SEGALIB\LIB\elf\sega_gfs.a ./cdcrep.a D:\saturn\SBL6\SEGALIB\LIB\elf\sega_sys.a D:\saturn\SBL6\SEGALIB\LIB\elf\sega_dma.a 
#Defines
FS            = -DOUTPUT_FULLSCREEN
DEFINES       = -DOS=\"$(OS)\" $(FS) $(GETOPTENABLED)

TARGET   = root/sl.coff
TARGET1  = root/sl.bin
MPFILE   = $(TARGET:.coff=.maps)
LDFILE   = root/SL.LNK

#Release type

# RELEASE may be:
#  -g -Wall -ansi -pedantic        for debug
#  -O2                             for release
# LINKERRELEASE may be:
#  -s                              for release
RELEASE       = -Os -m2 --save-temps -Wno-narrowing -fuse-linker-plugin -fno-unit-at-a-time -fomit-frame-pointer  -Wall -ansi -pedantic 
LINKERRELEASE = -Os -m2 -Xlinker -flto -Xlinker -n -Xlinker -T$(LDFILE) -Xlinker -Map \
          -Xlinker $(MPFILE) -Xlinker -e -Xlinker ___Start -nostartfiles 

#  RELEASE       = -O2 
#  LINKERRELEASE = -s

#Binary code files
OBJFILES      = saturn.o workarea.o main.o kernel.o resources.o dat.o disk.o compress.o \
                output.o maps.o room.o titles.o \
                input.o kid.o states.o tiles.o walls.o anims.o\
                object.o $(GETOPTSRC)
EXEFILE       = root/sl.coff

GENERATEDRESHEADERS = include/res_conf_parts.h include/res_conf_files.h\
                      include/res_conf_types.h include/res_conf_mods.h\
                      include/res_conf_resources.h
GENERATEDSTAHEADERS = include/states_conf_static.h \
                      include/states_conf_flags.h
#include/states_conf_properties.h
GENERATEDTILHEADERS = include/tiles_conf_types.h include/tiles_conf_groups.h

GENERATEDOTHHEADERS = include/walls_conf.h include/anims_conf.h include/text_conf.h\
                      include/room_conf.h

PACKAGE             = freeprince.tar.bz2

#Use this to temporary remove an option
OPTIONS       = $(INCLUDE) $(DEFINES) $(RELEASE)
LINKEROPTIONS = $(LINKERRELEASE)

#############
# main file #
#############
#$(TARGET) : $(SYSOBJS) $(OBJS) $(MAKEFILE) $(LDFILE) #$(OBJECTS)
#$(CC) $(LDFLAGS) $(SYSOBJS) $(OBJFILES) $(LIBS) -o $@

#$(TARGET1) : $(SYSOBJS) $(OBJFILES) $(MAKEFILE) $(LDFILE)
#$(CONV) -O binary $(TARGET) $(TARGET1)

$(EXEFILE): $(OBJFILES)
	$(INFO) Linking files...
#	$(MAKEDIR) bin
	$(LINKER) $(LINKEROPTIONS) -o $(EXEFILE) $(OBJFILES) $(LIBS) $(LINKEROPTIONS)
	$(CONV) -O binary $(EXEFILE) $(TARGET1)
	$(INFO) Program successfully compiled

###################
# program checks  #
###################

.PHONY: checks checkcompiler checkawk clean build it run vg install download downloadmore all headers package

package: clean headers
	$(INFO) Creating package...
	@$(TAR) czf /tmp/a.tbz .. 2>/dev/null
	@mv /tmp/a.tbz $(PACKAGE) 

checks: checkcompiler checksdl checkawk

checkcompiler:
	$(INFO) Checking C compiler...
	$(CC) --version>/dev/null

checksdl:
	$(INFO) Checking SDL library...
	@sdl-config --version>/dev/null

checkawk:
	$(INFO) Checking AWK...
	@which awk>/dev/null

###################
# command options #
###################

clean:
	$(INFO) Erasing temporary object files...
	$(REMOVER) $(OBJFILES) $(EXEFILE) $(GENERATEDRESHEADERS)\
	           $(GENERATEDSTAHEADERS) $(GENERATEDTILHEADERS)\
	           $(GETOPTSRC) $(GENERATEDOTHHEADERS) $(PACKAGE)

build: clean $(EXEFILE) $(TARGET) $(TARGET1)

all: build

install: checks download build

headers: $(GENERATEDRESHEADERS) $(GENERATEDSTAHEADERS) $(GENERATEDTILHEADERS)\
         $(GENERATEDOTHHEADERS)

download:
	$(MAKEDIR) bin
	$(INFO) Downloading data art files...
	@wget http://fp.princed.com.ar/freeprince.script -O - -nv 2>/dev/null|$(TAR) xjC bin

downloadmore:
	$(MAKEDIR) bin
	$(INFO) Downloading extra files...
	@wget http://fp.princed.com.ar/freeprince2.script -O - -nv 2>/dev/null|$(TAR) xjC bin

run:
	@cd bin;./freeprince;cd ..

vg:
	@cd bin;valgrind ./freeprince;cd ..
	
it: $(EXEFILE) run

################
# Source files #
################

main.o: main.c include/kernel.h include/main.h include/maps.h\
        include/map_defs.h include/tiles.h include/tiles_conf.h
	$(INFO) Compiling command line parser...
	$(CC) -c main.c $(OPTIONS)

resources.o: res/resources.c include/resources.h include/compress.h \
             include/dat.h include/disk.h include/res_conf.h
	$(INFO) Compiling main resource manager module...
	$(CC) -c res/resources.c $(OPTIONS)

disk.o: res/disk.c include/memory.h include/disk.h include/resources.h include/res_conf.h
	$(INFO) Compiling resource disk access library...
	$(CC) -c res/disk.c $(OPTIONS)

dat.o: res/dat.c include/disk.h include/dat.h
	$(INFO) Compiling resource dat editing library...
	$(CC) -c res/dat.c $(OPTIONS)

kernel.o: ker/kernel.c include/kernel.h include/resources.h\
          include/res_conf.h include/output.h include/object.h\
          $(GENERATEDSTAHEADERS) $(GENERATEDTILHEADERS) $(GENERATEDOTHHEADERS)
	$(INFO) Compiling main kernel...
	$(CC) -c ker/kernel.c $(OPTIONS)

room.o: ker/room.c include/room.h include/resources.h include/res_conf.h\
        include/walls_conf.h $(GENERATEDTILHEADERS) include/room_conf.h
	$(INFO) Compiling kernel room object...
	$(CC) -c ker/room.c $(OPTIONS)

kid.o: ker/kid.c include/kid.h include/states.h $(GENERATEDSTAHEADERS) \
       $(GENERATEDTILHEADERS) include/res_conf.h $(GENERATEDOTHHEADERS)\
       include/types.h include/tiles.h include/tiles_conf.h
	$(INFO) Compiling kernel object support...
	$(CC) -c ker/kid.c $(OPTIONS)

object.o: ker/object.c include/object.h include/resources.h include/res_conf.h\
       include/states.h $(GENERATEDRESHEADERS)\
       $(GENERATEDSTAHEADERS) $(GENERATEDTILHEADERS) include/res_conf.h\
       include/types.h include/tiles.h include/tiles_conf.h include/output.h\
       include/kid.h $(GENERATEDOTHHEADERS)
	$(INFO) Compiling kernel kid object support...
	$(CC) -c ker/object.c $(OPTIONS)

titles.o: ker/titles.c include/resources.h include/res_conf.h\
          include/anims_conf.h $(GENERATEDSTAHEADERS) $(GENERATEDRESHEADERS)\
          include/object.h $(GENERATEDOTHHEADERS)
	$(INFO) Compiling kernel titles module...
	$(CC) -c ker/titles.c $(OPTIONS)

compress.o: res/compress.c include/compress.h include/memory.h \
            include/disk.h
	$(INFO) Compiling resource compression module...
	$(CC) -c res/compress.c $(OPTIONS)

maps.o: res/maps.c include/maps.h include/map_defs.h include/tiles.h\
        include/tiles_conf.h
	$(INFO) Compiling resource map handling module...
	$(CC) -c res/maps.c $(OPTIONS)

output.o: out/output.c include/resources.h include/res_conf.h\
          include/text_conf.h
	$(INFO) Compiling main output module...
	$(CC) -c out/output.c $(OPTIONS)

input.o: out/input.c include/input.h
	$(INFO) Compiling main input module...
	$(CC) -c out/input.c $(OPTIONS)

config.o: res/config.c include/resources.h include/res_conf.h
	$(INFO) Compiling resource configuration module...
	$(CC) -c res/config.c $(OPTIONS)

states.o: ker/states.c include/states.h\
          include/resources.h include/res_conf.h include/types.h\
          include/tiles.h include/tiles_conf.h $(GENERATEDRESHEADERS)\
          $(GENERATEDSTAHEADERS) $(GENERATEDTILHEADERS)
	$(INFO) Compiling kernel states module...
	$(CC) -c ker/states.c $(OPTIONS)

tiles.o: res/tiles.c include/tiles.h include/tiles_conf.h 
	$(INFO) Compiling resource tile classification module...
	$(CC) -c res/tiles.c $(OPTIONS)

walls.o: res/walls.c include/walls.h include/walls_conf.h
	$(INFO) Compiling wall algorithm module...
	$(CC) -c res/walls.c $(OPTIONS)

anims.o: res/anims.c include/anims.h include/anims_conf.h\
         $(GENERATEDRESHEADERS) $(GENERATEDSTAHEADERS)\
         $(GENERATEDTILHEADERS)
	$(INFO) Compiling animation loader module...
	$(CC) -c res/anims.c $(OPTIONS)
	
#AWK scripts: header generation
include/res_conf.h: $(GENERATEDRESHEADERS)

include/res_conf_parts.h: conf/parts.conf conf/awk/res_conf_parts.awk
	$(INFO) Creating resource id parts configuration file...
	$(AWK) -f conf/awk/res_conf_parts.awk conf/parts.conf>include\res_conf_parts.h

include/res_conf_files.h: conf/files.conf conf/awk/res_conf_files.awk
	$(INFO) Creating resource dat files list configuration file...
	$(AWK) -f conf/awk/res_conf_files.awk conf/files.conf>include\res_conf_files.h

include/res_conf_types.h: conf/types.conf conf/awk/res_conf_types.awk
	$(INFO) Creating resource types configuration file...
	$(AWK) -f conf/awk/res_conf_types.awk conf/types.conf>include\res_conf_types.h

include/res_conf_mods.h: conf/mods.conf conf/awk/res_conf_mods.awk
	$(INFO) Creating resource modifiers configuration file...
	$(AWK) -f conf/awk/res_conf_mods.awk conf/mods.conf>include\res_conf_mods.h

include/res_conf_resources.h: conf/resources.conf conf/awk/res_conf_resources.awk
	$(INFO) Creating resource list configuration file...
	$(AWK) -f conf/awk/res_conf_resources.awk conf/resources.conf>include\res_conf_resources.h

include/states_conf.h: $(GENERATEDSTAHEADERS)

include/states_conf_static.h: conf/awk/states_conf_static.awk conf/states/*.conf
	$(INFO) Creating states list configuration file...
	$(AWK) -f conf/awk/states_conf_static.awk conf/states/*.conf>include\states_conf_static.h

#include/states_conf_properties.h: conf/statesproperties.conf conf/awk/states_conf_properties.awk
#	$(INFO) Creating states condition properties configuration file...
#	$(AWK) -f conf/awk/states_conf_properties.awk conf/statesproperties.conf>include\states_conf_properties.h

include/states_conf_flags.h: conf/flags.conf conf/awk/states_conf_flags.awk
	$(INFO) Creating states frame flags configuration file...
	$(AWK) -f conf/awk/states_conf_flags.awk conf/flags.conf>include\states_conf_flags.h

include/tiles_conf.h: $(GENERATEDTILHEADERS)

include/tiles_conf_types.h: conf/tiles.conf conf/awk/tiles_conf_types.awk
	$(INFO) Creating tile list configuration file...
	$(AWK) -f conf/awk/tiles_conf_types.awk conf/tiles.conf>include\tiles_conf_types.h

include/tiles_conf_groups.h: conf/tiles.conf conf/awk/tiles_conf_groups.awk
	$(INFO) Creating tile groups configuration file...
	$(AWK) -f conf/awk/tiles_conf_groups.awk conf/tiles.conf>include\tiles_conf_groups.h

include/walls_conf.h: conf/walls.conf conf/awk/walls_conf.awk
	$(INFO) Creating wall algorithm randomization file...
	$(AWK) -f conf/awk/walls_conf.awk conf/walls.conf>include\walls_conf.h

include/anims_conf.h: conf/anims.conf conf/awk/anims_conf.awk
	$(INFO) Binding animation indexes to the source...
	$(AWK) -f conf/awk/anims_conf.awk conf/anims.conf>include\anims_conf.h

include/text_conf.h: conf/alphabet.conf conf/awk/text_conf.awk
	$(INFO) Generating font alphabet...
	$(AWK) -f conf/awk/text_conf.awk conf/alphabet.conf>include\text_conf.h

include/room_conf.h: conf/room.conf conf/awk/room_conf.awk
	$(INFO) Generating room drawing code...
	$(AWK) -f conf/awk/room_conf.awk conf/room.conf>include\room_conf.h

#ports
getopt.o: ports/getopt.c
	$(INFO) Porting the Unix-like getopt function \(first part\)...
	$(CC) $(OPTIONS) -c ports/getopt.c

getopt1.o: ports/getopt1.c
	$(INFO) Porting the Unix-like getopt function \(second part\)...
	$(CC) $(OPTIONS) -c ports/getopt1.c

