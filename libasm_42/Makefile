NAME = libasm.a

SRC = ft_write.s \
	  ft_read.s \
	  ft_strlen.s \
	  ft_strcpy.s \
	  ft_strdup.s \
	  ft_strcmp.s

SRC_BONUS = ft_list_size.s \
			ft_list_push_front.s \
			ft_list_remove_if.s

OBJ = $(SRC:.s=.o)


OBJ_BONUS = $(SRC_BONUS:.s=.o)

FLAGS = -f elf64

NM = nasm

all: $(NAME)

bonus: $(OBJ_BONUS) $(OBJ)
		@ar rcs $(NAME) $(OBJ_BONUS) $(OBJ)
		@echo 'SUCCESS'

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)
		@echo 'SUCCESS'

%.o : %.s
		@$(NM) $(FLAGS) $< -o $@

clean:
		@rm -rf $(OBJ)
		@rm -rf $(OBJ_BONUS)
		@echo 'CLEAN'

fclean: clean
		@rm -rf $(NAME)

re: fclean clean