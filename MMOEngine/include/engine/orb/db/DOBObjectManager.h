/*
 * DOBObjectManager.h
 *
 *  Created on: 18/08/2009
 *      Author: victor
 */

#ifndef DOBOBJECTMANAGER_H_
#define DOBOBJECTMANAGER_H_

#include "system/platform.h"

#include "engine/util/ObjectFactory.h"

#include "DistributedObjectDirectory.h"

namespace engine {
	namespace ORB {

	class DistributedObject;
	class DistributedObjectAdapter;
	class DistributedObjectStub;
	class DOBServiceClient;

	class DOBObjectManager : public Mutex {
	protected:
		DistributedObjectDirectory localObjectDirectory;

		uint64 nextObjectID;

	public:
		DOBObjectManager();

		virtual ~DOBObjectManager() {
			//localObjectDirectory.destroyContainingObjects();
		}

		virtual DistributedObject* loadPersistentObject(uint64 objid) {
			return NULL;
		}

		virtual void updateModifiedObjectsToDatabase();

		virtual int updatePersistentObject(DistributedObject* object);

		virtual DistributedObjectAdapter* addObject(DistributedObjectStub* object);

		virtual DistributedObject* getObject(uint64 objectID);

		virtual DistributedObjectAdapter* getAdapter(uint64 objectID);

		virtual DistributedObjectAdapter* removeObject(uint64 objectID);

		virtual void createObjectID(const String& name, DistributedObjectStub* object);

		virtual uint64 getNextFreeObjectID();

		//virtual void savePersistentObjects();
	};

	}
}

using namespace engine::ORB;

#endif /* DOBOBJECTMANAGER_H_ */
