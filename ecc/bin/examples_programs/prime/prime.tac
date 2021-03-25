#primes
	push $ra
	$t1 = 3
	$fp(8) = $t1
#L1
	$t2 = $fp(8)
	$t3 = $fp(4)
	$t4 = $t2 < $t3
	if $t4 == 0 goto L2
	$t5 = 1
	$fp(12) = $t5
	$t6 = 3
	$fp(16) = $t6
	$t7 = $fp(8)
	$t8 = 2
	$t9 = $t7 / $t8
	$fp(20) = $t9
#L3
	$t10 = $fp(16)
	$t11 = $fp(20)
	$t12 = $t10 < $t11
	if $t12 == 0 goto L4
	$t13 = $fp(8)
	$t14 = $fp(16)
	$t15 = $t13 % $t14
	$fp(24) = $t15
	$t16 = $fp(24)
	$t17 = 0
	$t18 = $t16 == $t17
	if $t18 == 0 goto L6
	$t19 = 0
	$fp(12) = $t19
	goto L4
	goto L5
#L6
#L5
	$t20 = $fp(16)
	$t21 = 2
	$t22 = $t20 + $t21
	$fp(16) = $t22
	goto L3
#L4
	$t23 = $fp(12)
	if $t23 == 0 goto L8
	$t24 = $fp(8)
	print $t24
	goto L7
#L8
#L7
	$t25 = $fp(8)
	$t26 = 2
	$t27 = $t25 + $t26
	$fp(8) = $t27
	goto L1
#L2
	return
#main
	push $sp
	push $fp
	push 4
	$t28 = 2147483647
	push $t28 4
	call primes
	terminate
