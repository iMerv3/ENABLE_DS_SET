// Search:
void initItem()
// Add before:
#ifdef ENABLE_DS_SET
PyObject * itemGetDSSetWeight(PyObject * poSelf, PyObject * poArgs) {
	int iDSType;
	if (!PyTuple_GetInteger(poArgs, 0, &iDSType))
		return Py_BadArgument();
	
	int iDSGrade;
	if (!PyTuple_GetInteger(poArgs, 1, &iDSGrade))
		return Py_BadArgument();
	
	return Py_BuildValue("f", CPythonItem::Instance().GetDSSetWeight(iDSType, iDSGrade));
}

PyObject * itemGetDSBasicApplyCount(PyObject * poSelf, PyObject * poArgs) {
	int iDSType;
	if (!PyTuple_GetInteger(poArgs, 0, &iDSType))
		return Py_BadArgument();
	
	int iDSGrade;
	if (!PyTuple_GetInteger(poArgs, 1, &iDSGrade))
		return Py_BadArgument();
	
	return Py_BuildValue("i", CPythonItem::Instance().GetDSBasicApplyCount(iDSType, iDSGrade));
}

PyObject * itemGetDSBasicApplyValue(PyObject * poSelf, PyObject * poArgs) {
	int iDSType;
	if (!PyTuple_GetInteger(poArgs, 0, &iDSType))
		return Py_BadArgument();
	
	int iDSApplyType;
	if (!PyTuple_GetInteger(poArgs, 1, &iDSApplyType))
		return Py_BadArgument();
	
	return Py_BuildValue("i", CPythonItem::Instance().GetDSBasicApplyValue(iDSType, iDSApplyType));
}

PyObject * itemGetDSAdditionalApplyValue(PyObject * poSelf, PyObject * poArgs) {
	int iDSType;
	if (!PyTuple_GetInteger(poArgs, 0, &iDSType))
		return Py_BadArgument();
	
	int iDSApplyType;
	if (!PyTuple_GetInteger(poArgs, 1, &iDSApplyType))
		return Py_BadArgument();
	
	return Py_BuildValue("i", CPythonItem::Instance().GetDSAdditionalApplyValue(iDSType, iDSApplyType));
}
#endif



// Search:
		{ NULL,								NULL,									NULL },
// Add before:
#ifdef ENABLE_DS_SET
		{ "GetDSSetWeight",					itemGetDSSetWeight,						METH_VARARGS },
		{ "GetDSBasicApplyCount",			itemGetDSBasicApplyCount,				METH_VARARGS },
		{ "GetDSBasicApplyValue",			itemGetDSBasicApplyValue,				METH_VARARGS },
		{ "GetDSAdditionalApplyValue",		itemGetDSAdditionalApplyValue,			METH_VARARGS },
#endif