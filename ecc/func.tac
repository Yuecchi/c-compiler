#func
	push $ra
	return
#main
	push $sp
	push $fp
	push 4
	$t1 = 3
	push $t1 4
	$t2 = 4
	push $t2 8
	$t3 = 5
	push $t3 12
	call func
	terminate
