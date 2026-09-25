REACTOR_SIMULATION_INC	= Types PhysicsEngine
INC						= $(addprefix ReactorSimulation/,$(REACTOR_SIMULATION_INC))

REACTOR_SIMULATION_SRC	= Vector2D MaterialPoint Molecule SimpleMolecule ComplexMolecule Reactor PhysicsEngine
SRC						= $(addprefix ReactorSimulation/,$(REACTOR_SIMULATION_SRC)) main

COMMON_MAKEFILE = Common_Makefile.mk
include $(COMMON_MAKEFILE)

prepare::
	@mkdir -p $(addprefix $(DEP_SUBDIR),ReactorSimulation/) $(addprefix $(BIN_SUBDIR),ReactorSimulation/)
