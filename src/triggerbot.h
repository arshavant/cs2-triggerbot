#pragma once

#include "../memory/memory.h"
#include "../sdk/offsets.h"

namespace triggerbot
{
	 inline uintptr_t procID;
	 inline uintptr_t moduleBase;

	 void execute();
}