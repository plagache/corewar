.name "zork"
.comment "I'M ALIVEmdaowndoanowidnaoiwndoianwdionaiowdniao
dwa
dwa
dwa
dwa
dwa
dwa
"

		ld :live, r1
l2:		sti r99,  1, %1
		live %1

live:	live %1
		zjmp %:live
