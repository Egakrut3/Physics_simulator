LINKER_FIXED_OPTIONS	+= -lsfml-graphics -lsfml-window -lsfml-system

REACTOR_SIMULATION_INC	= Types GraphicEngine PhysicsEngine ControlEngine
INC						= $(addprefix ReactorSimulation/,$(REACTOR_SIMULATION_INC))

REACTOR_SIMULATION_SRC	= Vector2D MaterialPoint Molecule SimpleMolecule ComplexMolecule Reactor GraphicEngine PhysicsEngine ControlEngine
SRC						= $(addprefix ReactorSimulation/,$(REACTOR_SIMULATION_SRC)) main

RUN_TARGET				= prime-run taskset -c 14 ./$(TARGET)

COMMON_MAKEFILE = Common_Makefile.mk
include $(COMMON_MAKEFILE)

prepare::
	@mkdir -p $(addprefix $(DEP_SUBDIR),ReactorSimulation/) $(addprefix $(BIN_SUBDIR),ReactorSimulation/)
