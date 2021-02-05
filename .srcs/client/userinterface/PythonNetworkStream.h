// Search:
		//Security
		bool RecvHSCheckRequest();
		bool RecvXTrapVerifyRequest();
// Add after:
#ifdef ENABLE_DS_SET
		bool	RecvDSTablePacket();
#endif