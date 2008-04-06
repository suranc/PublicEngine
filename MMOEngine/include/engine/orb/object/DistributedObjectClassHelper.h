/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef DISTRIBUTEDOBJECTCLASSHELPER_H_
#define DISTRIBUTEDOBJECTCLASSHELPER_H_

#include "DistributedObject.h"
#include "DistributedObjectAdapter.h"

namespace engine {
  namespace ORB {

	class DistributedObjectServant;
	
	class DistributedObjectClassHelper {
	protected:
		string className;
		
	public:
		DistributedObjectClassHelper() {
		}
		
		virtual ~DistributedObjectClassHelper() {
		}	
	
		virtual void finalizeHelper() = 0;
		
		virtual DistributedObject* instantiateObject() = 0;
	
		virtual DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj) = 0;
		
		inline const string& getClassName() {
			return className;
		}
	};

  } // namespace ORB
} // namespace engine

using namespace engine::ORB;

#endif /*DISTRIBUTEDOBJECTCLASSHELPER_H_*/