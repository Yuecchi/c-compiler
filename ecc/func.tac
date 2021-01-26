#sum
	push $ra
	$t1 = 1
	$fp(8) = $t1
	$t2 = 0
	$fp(12) = $t2
#L1
	$t3 = $fp(8)
	$t4 = $fp(4)
	$t5 = $t3 <= $t4
	if $t5 == 0 goto L2
	$t6 = $fp(12)
	$t7 = $fp(8)
	$t8 = $t6 + $t7
	$fp(12) = $t8
	$t9 = $fp(8)
	$t10 = 1
	$t11 = $t9 + $t10
	$fp(8) = $t11
	goto L1
#L2
	$t12 = $fp(12)
	return $t12
	return
#main
	push $sp
	push $fp
	push 4
	$t13 = 100
	push $t13 4
	$t14 = call sum
	x = $t14
	$t15 = x
	print $t15
	terminate
