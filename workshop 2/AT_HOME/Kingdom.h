/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// TODO: sict namespace

namespace sict{

// TODO: define the structure Kingdom in the sict namespace

	struct Kingdom{
		char m_name[32];
		int m_population;
	};
// TODO: declare the function display(...),
	
	void display(const Kingdom&);
	void display(const Kingdom*, int);

//         also in the sict namespace
}
#endif
