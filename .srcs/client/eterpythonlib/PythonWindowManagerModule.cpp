// Search:
void initwndMgr()
// Add before:
PyObject * wndMgrSetLineHeight(PyObject * poSelf, PyObject * poArgs) {
	UI::CWindow * pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();
	
	int iHeight;
	if (!PyTuple_GetInteger(poArgs, 1, &iHeight))
		return Py_BuildException();
	
	((UI::CTextLine*)pWin)->SetLineHeight(iHeight);
	return Py_BuildNone();
}

PyObject * wndMgrGetLineHeight(PyObject * poSelf, PyObject * poArgs) {
	UI::CWindow * pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();
	
	return Py_BuildValue("i", ((UI::CTextLine*)pWin)->GetLineHeight());
}

PyObject * wndMgrGetTextLineCount(PyObject * poSelf, PyObject * poArgs) {
	UI::CWindow * pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();
	
	return Py_BuildValue("i", ((UI::CTextLine*)pWin)->GetTextLineCount());
}



// Search:
		{ NULL,							NULL,								NULL },
// Add before:
		{"SetLineHeight",				wndMgrSetLineHeight,				METH_VARARGS},
		{"GetLineHeight",				wndMgrGetLineHeight,				METH_VARARGS},
		{"GetTextLineCount",			wndMgrGetTextLineCount,				METH_VARARGS},