	_t1_ = 9
	x = _t1_
	_t2_ = 5
	y = _t2_
	_t3_ = x
_L1_
	if _t3_ == 0 goto _L2_
	_t4_ = x
	_t5_ = _t4_ - y
	if _t5_ == 0 goto _L4_
	_t6_ = x
	print _t6_
	goto _L3_
_L4_
	goto _L2_
_L3_
	_t7_ = x
	_t8_ = _t7_ - 1
	x = _t8_
	goto _L1_
_L2_
