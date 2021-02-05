// Search:
	PyModule_AddIntConstant(poModule, "CAMERA_STOP",			CPythonApplication::CAMERA_STOP);
// Add after:
#ifdef ENABLE_DS_SET
	PyModule_AddIntConstant(poModule, "ENABLE_DS_SET", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_DS_SET", 0);
#endif