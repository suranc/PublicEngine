/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef OBJECTNOTDEPLOYEDEXCEPTION_H_
#define OBJECTNOTDEPLOYEDEXCEPTION_H_

#include "system/lang/Exception.h"

#include "../../log/Logger.h"

namespace engine {
  namespace ORB {

	class ObjectNotDeployedException : public sys::lang::Exception {
	public:
		ObjectNotDeployedException(ORBObjectStub* stub) : Exception() {
			message = "\'" + stub->_getORBName() + "\' is not deployed";
			
			cout << message << "\n";
			Logger::closeGlobalFileLogger();

			stub = NULL;
			stub->_getORBName();
		}
		
	};

  } // namespace ORB
} // namespace engine

using namespace engine::ORB;

#endif /*OBJECTNOTDEPLOYEDEXCEPTION_H_*/
