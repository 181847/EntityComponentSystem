///-------------------------------------------------------------------------------------------------
/// File:	src\Event\IEventListener.cpp.
///
/// Summary:	Declares the IEventListener interface.
///-------------------------------------------------------------------------------------------------

#include "Event/IEventListener.h"

#include "Engine.h"

namespace ECS { namespace Event {

	IEventListener::IEventListener()
	{}

	IEventListener::~IEventListener()
	{
		// unsubcribe from all subscribed events
		UnregisterAllEventCallbacks();
	}

	void IEventListener::UnregisterAllEventCallbacks()
	{
		// unsubcribe from all subscribed events
		for (auto cb : this->m_RegisteredCallbacks)
		{
			ECS_Engine->UnsubscribeEvent(cb->GetStaticEventTypeId(), cb->GetDelegateId());
			delete cb;
			cb = nullptr;
		}

		this->m_RegisteredCallbacks.clear();
	}

}} // namespace ECS::Event
