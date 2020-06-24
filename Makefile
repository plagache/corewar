# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plagache <plagache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/21 21:06:39 by plagache          #+#    #+#              #
#    Updated: 2020/06/24 01:31:31 by alagache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM = vm/
ASM = asm/
DASM = disassemble/


all:
	$(MAKE) -C $(VM) #vm
	$(MAKE) -C $(ASM) #asm
	$(MAKE) -C $(DASM) #dasm

clean: 
	$(MAKE) -C $(VM) clean #fclean_vm
	$(MAKE) -C $(ASM) clean #fclean_asm
	$(MAKE) -C $(DASM) clean #fclean_dasm

fclean:
	$(MAKE) -C $(VM) fclean #fclean_vm
	$(MAKE) -C $(ASM) fclean #fclean_asm
	$(MAKE) -C $(DASM) fclean #fclean_dasm

re:
	$(MAKE) fclean
	$(MAKE) all

vm:
	$(MAKE) -C $(VM)

clean_vm:
	$(MAKE) -C $(VM) clean

fclean_vm:
	$(MAKE) -C $(VM) fclean

asm:
	$(MAKE) -C $(ASM)

clean_asm:
	$(MAKE) -C $(ASM) clean

fclean_asm:
	$(MAKE) -C $(ASM) fclean

dasm:
	$(MAKE) -C $(DASM)

clean_dasm:
	$(MAKE) -C $(DASM) clean

fclean_dasm:
	$(MAKE) -C $(DASM) fclean

.PHONY: all clean fclean re vm asm dasm clean_vm clean_asm clean_dasm fclean_vm fclean_asm fclean_dasm
.SILENT:
