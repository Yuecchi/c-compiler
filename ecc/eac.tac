	_t1_ = 1
	x = _t1_
_L1_
	_t2_ = x
	if _t2_ == 0 goto _L2_
	_t3_ = x
	_t4_ = 1
	_t5_ = _t3_ + _t4_
	x = _t5_
	_t6_ = x
	_t7_ = 5
	_t8_ = _t6_ == _t7_
	if _t8_ == 0 goto _L4_
	goto _L1_
	goto _L3_
_L4_
	_t9_ = x
	_t10_ = 9
	_t11_ = _t9_ == _t10_
	if _t11_ == 0 goto _L5_
	goto _L2_
	goto _L3_
_L5_
_L3_
	_t12_ = x
	print _t12_
	goto _L1_
_L2_
