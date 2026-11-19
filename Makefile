NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude

SRC = main.c count.c parse.c memory.c checks.c \
      rank.c stack_moves.c op_swap.c op_push.c \
      op_rotate.c op_reverse.c sort_small.c sort_radix.c \
      options.c strategy.c positions.c sort_simple.c \
      sort_medium.c emit.c bench.c bench_io.c

BONUS_SRC = Bonus/checker.c \
            Bonus/checker_utils.c \
            Bonus/check_instruction.c \
            Bonus/execute_instruction.c \
            Bonus/read_instructions.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

BONUS_LIB_OBJ = $(filter-out main.o,$(OBJ))

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(BONUS_LIB_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(BONUS_LIB_OBJ) -o $(BONUS_NAME)

%.o: %.c $(HEADER)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus

