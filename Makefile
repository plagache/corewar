# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plagache <plagache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/21 21:06:39 by plagache          #+#    #+#              #
#    Updated: 2020/06/23 14:39:37 by alagache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM = vm/
ASM = asm/
DASM = disassemble/


all: vm asm dasm

clean: clean_vm clean_asm clean_dasm

fclean: fclean_vm fclean_asm fclean_dasm

vm:
	$(MAKE) -s -C $(VM)

clean_vm:
	$(MAKE) -s -C $(VM) clean

fclean_vm:
	$(MAKE) -s -C $(VM) fclean

asm:
	$(MAKE) -s -C $(ASM)

clean_asm:
	$(MAKE) -s -C $(ASM) clean

fclean_asm:
	$(MAKE) -s -C $(ASM) fclean

dasm:
	$(MAKE) -s -C $(DASM)

clean_dasm:
	$(MAKE) -s -C $(DASM) clean

fclean_dasm:
	$(MAKE) -s -C $(DASM) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re vm clean_vm fclean_vm asm clean_asm fclean_asm dasm clean_dasm fclean_dasm

.SILENT:
