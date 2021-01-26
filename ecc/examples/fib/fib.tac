#fib
	push $ra
	$t1 = $fp(4)
	$t2 = 0
	$t3 = $t1 == $t2
	if $t3 == 0 goto L2
	$t4 = 1
	return $t4
	goto L1
#L2
	$t5 = $fp(4)
	$t6 = 1
	$t7 = $t5 == $t6
	if $t7 == 0 goto L3
	$t8 = 1
	return $t8
	goto L1
#L3
	push $fp
	push 4
	$t9 = $fp(4)
	$t10 = 1
	$t11 = $t9 - $t10
	push $t11 4
	$t12 = call fib
	push $fp
	push 4
	$t13 = $fp(4)
	$t14 = 2
	$t15 = $t13 - $t14
	push $t15 4
	$t16 = call fib
	$t17 = $t12 + $t16
	return $t17
#L1
	return
#main
	push $sp
	$t18 = 0
	$fp(4) = $t18
#L4
	$t19 = $fp(4)
	$t20 = 10
	$t21 = $t19 < $t20
	if $t21 == 0 goto L5
	push $fp
	push 4
	$t22 = $fp(4)
	push $t22 4
	$t23 = call fib
	x = $t23
	$t24 = x
	print $t24
	$t25 = $fp(4)
	$t26 = 1
	$t27 = $t25 + $t26
	$fp(4) = $t27
	goto L4
#L5
	terminate
