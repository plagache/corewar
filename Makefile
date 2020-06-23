# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plagache <plagache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/21 21:06:39 by plagache          #+#    #+#              #
#    Updated: 2020/05/21 21:51:41 by plagache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM = vm/
ASM = asm/


all: vm asm

clean: clean_vm clean_asm

fclean: fclean_vm fclean_asm

vm:
	make -s -C $(VM)

clean_vm:
	make -s -C $(VM) clean

fclean_vm:
	make -s -C $(VM) fclean

asm:
	make -s -C $(ASM)

clean_asm:
	make -s -C $(ASM) clean

fclean_asm:
	make -s -C $(ASM) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re vm clean_vm fclean_vm asm clean_asm fclean_asm

.SILENT: all clean fclean re vm clean_vm fclean_vm asm clean_asm fclean_asm