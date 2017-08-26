PUSH_SWAP_NAME = push_swap
CHECKER_NAME = checker

LIBRARY = libft/libft.a

CHECKER_C = checker operations_a operations_ab operations_b other_func

PUSH_C = additional swap_a push_swap min_b sort_three_a_down\
		recursion_a recursion_a_rev recursion_b recursion_b_rev commands_b commands_a commands_ab

PUSH_SWAP_DIR = push_swap_dir/
CHECKER_DIR = checker_dir/

OBJ_PUSH_SWAP = $(addprefix $(PUSH_SWAP_DIR),$(addsuffix .o,$(PUSH_C)))
OBJ_CHECKER = $(addprefix $(CHECKER_DIR),$(addsuffix .o,$(CHECKER_C)))


FLAGS = -Wall -Wextra -Werror

all: lib checker push_swap 

lib:
	@make -C ./libft

push_swap: $(OBJ_PUSH_SWAP)
	@gcc -o $(PUSH_SWAP_NAME) $(FLAGS) $(OBJ_PUSH_SWAP) $(LIBRARY) 
	@echo "\x1b[32m"push_swap has been made "\x1b[0m"

checker: $(OBJ_CHECKER)
	@gcc -o $(CHECKER_NAME) $(FLAGS) $(OBJ_CHECKER) $(LIBRARY)
	@echo "\x1b[32m"checker has been made "\x1b[0m"

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $< 

clean:
	@find . -name "*.o" -type f -delete
	@echo "\x1b[31m".o files were deleted "\x1b[0m"

fclean: clean
	@rm -f $(CHECKER_NAME) $(PUSH_SWAP_NAME) $(LIBRARY)
	@echo "\x1b[31m"exec files were deleted "\x1b[0m"

re: fclean all
