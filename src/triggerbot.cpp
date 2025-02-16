#include "triggerbot.h"

#include <iostream>
#include <thread>

void triggerbot::execute()
{
	 uintptr_t localPlayer = memory::Read<uintptr_t>(moduleBase + offsets::dwLocalPlayerPawn);
	 BYTE localPlayerTeam = memory::Read<BYTE>(localPlayer + offsets::m_iTeamNum);

	 uintptr_t entityList = memory::Read<uintptr_t>(moduleBase + offsets::dwEntityList);
	 
	 int localPlayerCrosshairId = memory::Read<int>(localPlayer + offsets::m_iIDEntIndex);
	 if (localPlayerCrosshairId < 0)
		  return;

	 uintptr_t entryList = memory::Read<uintptr_t>(entityList + 0x8 * (localPlayerCrosshairId >> 9) + 0x10);
	 uintptr_t entity = memory::Read<uintptr_t>(entryList + 120 * (localPlayerCrosshairId & 0x1ff));
	 BYTE entityTeam = memory::Read<BYTE>(entity + offsets::m_iTeamNum);
	 int entityHealth = memory::Read<int>(entity + offsets::m_iHealth);

	 if (!entity)
		  return;

	 if (localPlayerTeam == entityTeam)
		  return;

	 if (entityHealth <= 0)
		  return;
	 
	 memory::Write<int>(moduleBase + offsets::attack, 65537);
	 std::this_thread::sleep_for(std::chrono::milliseconds(5));
	 memory::Write<int>(moduleBase + offsets::attack, 256);
	 std::this_thread::sleep_for(std::chrono::milliseconds(5));
}