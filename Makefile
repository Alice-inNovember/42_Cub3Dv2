#NAME--------------------------------------------------
NAME			=	cub3D
#CMDS--------------------------------------------------
CC				=	cc
RM				=	rm -rf
LIBC			=	ar rcs
#FLAGS-------------------------------------------------
CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-framework OpenGL -framework AppKit
#DIRS--------------------------------------------------
D_LIBS		=	01.libs
D_INCS		=	02.incs
D_SRCS		=	03.srcs
D_OBJS		=	04.Objs

SD_DATA		=	$(D_SRCS)/gameplay
SD_PLAYER	=	$(D_SRCS)/initial
SD_RANDER	=	$(D_SRCS)/minimap
SD_UTILITY	=	$(D_SRCS)/utility

OD_DATA		=	$(D_OBJS)/gameplay
OD_PLAYER	=	$(D_OBJS)/initial
OD_RANDER	=	$(D_OBJS)/minimap
OD_UTILITY	=	$(D_OBJS)/utility
#FILES-------------------------------------------------
SRCS		=	$(D_SRCS)/main.c
OBJS		=	$(subst $(D_SRCS), $(D_OBJS), $(SRCS:.c=.o))
LIBGNL		=	$(D_LIBS)/GNL/LIBGNL.a
LIB42		=	$(D_LIBS)/LIB42/lib42.a
LIBMLX		=	$(D_LIBS)/MLX/libmlx.dylib
#COLOR-------------------------------------------------
C_OFF		=	"\033[0m"
C_RED		=	"\033[1;31m"
C_GRN		=	"\033[1;32m"
C_BLE		=	"\033[1;34m"
C_PLE		=	"\033[1;35m"
C_CYN		=	"\033[1;36m"
INFO		=
#PRINTER-----------------------------------------------
define P_STAT
	$(eval INFO = $(shell echo $(1)$(C_OFF)))
	$(info $(INFO))
endef
#KEY---------------------------------------------------
all : $(NAME)

mlx :
	@$(MAKE) -C $(D_LIBS)/MLX
	$(call P_STAT,$(C_BLE)MLX processing...)
#NAME--------------------------------------------------
$(NAME) : $(OBJS)
	$(call P_STAT,$(C_BLE)Compiling)

	@$(MAKE) -C $(D_LIBS)/GNL
	$(call P_STAT,$(C_CYN)libgnl.a"     "✅)
	@$(MAKE) -C $(D_LIBS)/MLX
	$(call P_STAT,$(C_CYN)mlx.dylib"    "✅)

	@$(CC) $(CFLAGS) -o $@ $^ $(LIBGNL) $(MLXFLAGS) -L$(D_LIBS)/MLX -lmlx
	@-install_name_tool -change libmlx.dylib ./$(LIBMLX) $(NAME)
	$(call P_STAT,$(C_PLE)cub3D"        "✅)

	$(call P_STAT,$(C_GRN)Done!)
	$(info )
	$(call P_STAT,$(C_BLE)MLX processing...)
#OBJS--------------------------------------------------
$(D_OBJS)/%.o : $(D_SRCS)/%.c | $(D_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OD_DATA)/%.o : $(SD_DATA)/%.c | $(OD_DATA)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OD_PLAYER)/%.o : $(SD_PLAYER)/%.c | $(OD_PLAYER)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OD_RANDER)/%.o : $(SD_RANDER)/%.c | $(OD_RANDER)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OD_UTILITY)/%.o : $(SD_UTILITY)/%.c | $(OD_UTILITY)
	@$(CC) $(CFLAGS) -c $< -o $@
#MKDIR-------------------------------------------------
$(D_OBJS):
	$(call P_STAT,$(C_BLE)Create DIR)

	@mkdir -p $(D_OBJS)
	$(call P_STAT,$(C_CYN)D_OBJS"       "✅)

	@mkdir -p $(OD_DATA)
	$(call P_STAT,$(C_CYN)OD_DATA"      "✅)

	@mkdir -p $(OD_PLAYER)
	$(call P_STAT,$(C_CYN)OD_PLAYER"    "✅)

	@mkdir -p $(OD_RANDER)
	$(call P_STAT,$(C_CYN)OD_RANDER"    "✅)

	@mkdir -p $(OD_UTILITY)
	$(call P_STAT,$(C_CYN)OD_UTILITY"   "✅)

	$(call P_STAT,$(C_GRN)Done!)
	$(info )
#CLEAN-------------------------------------------------
clean :
	$(call P_STAT,$(C_RED)Cleaning)

	@$(MAKE) -C $(D_LIBS)/GNL fclean
	$(call P_STAT,$(C_CYN)libgnl"       "✅)

	@$(MAKE) -C $(D_LIBS)/MLX fclean
	$(call P_STAT,$(C_CYN)libmlx"       "✅)

	@$(RM) $(D_OBJS)
	$(call P_STAT,$(C_CYN)ObjDir"       "✅)

	$(call P_STAT,$(C_GRN)Done!)
	$(info )
#FCLEAN------------------------------------------------
fclean : clean
	$(call P_STAT,$(C_RED)Removing)

	@$(RM) $(NAME)
	$(call P_STAT,$(C_PLE)cub3D"        "✅)

	$(call P_STAT,$(C_GRN)Done!)
	$(info )
#RE----------------------------------------------------
re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re