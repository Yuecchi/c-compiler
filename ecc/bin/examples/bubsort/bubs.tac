#main
	push $sp
	$t1 = 5
	$fp(4) = $t1
	$t2 = 0
	$fp(8) = $t2
#L1
	$t3 = $fp(8)
	$t4 = $fp(4)
	$t5 = 1
	$t6 = $t4 - $t5
	$t7 = $t3 < $t6
	if $t7 == 0 goto L2
	$t8 = $fp(8)
	$t9 = 1
	$t10 = $t8 + $t9
	$fp(12) = $t10
#L3
	$t11 = $fp(12)
	$t12 = $fp(4)
	$t13 = $t11 < $t12
	if $t13 == 0 goto L4
	$t14 = $fp(12)
	$t15 = arr[$t14]
	$t16 = $fp(8)
	$t17 = arr[$t16]
	$t18 = $t15 < $t17
	if $t18 == 0 goto L6
	$t19 = $fp(8)
	$t20 = arr[$t19]
	$fp(16) = $t20
	$t21 = $fp(8)
	$t22 = $fp(12)
	$t23 = arr[$t22]
	arr[$t21] = $t23
	$t24 = $fp(12)
	$t25 = $fp(16)
	arr[$t24] = $t25
	goto L5
#L6
#L5
	$t26 = $fp(12)
	$t27 = 1
	$t28 = $t26 + $t27
	$fp(12) = $t28
	goto L3
#L4
	$t29 = $fp(8)
	$t30 = 1
	$t31 = $t29 + $t30
	$fp(8) = $t31
	goto L1
#L2
	$t32 = 0
	$fp(8) = $t32
#L7
	$t33 = $fp(8)
	$t34 = $fp(4)
	$t35 = $t33 < $t34
	if $t35 == 0 goto L8
	$t36 = $fp(8)
	$t37 = arr[$t36]
	print $t37
	$t38 = $fp(8)
	$t39 = 1
	$t40 = $t38 + $t39
	$fp(8) = $t40
	goto L7
#L8
	terminate
