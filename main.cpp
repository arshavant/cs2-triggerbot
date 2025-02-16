#include "src/triggerbot.h"

#include <iostream>
#include <thread>

int main()
{	 
	 triggerbot::procID = memory::GetProcID(L"cs2.exe");
	 triggerbot::moduleBase = memory::GetModuleBaseAddress(triggerbot::procID, L"client.dll");

	 std::cout << "Process ID: " << triggerbot::procID << std::endl;
	 std::cout << "Module Base: " << "0x" << std::hex << triggerbot::moduleBase << std::dec << std::endl;

	 while (!GetAsyncKeyState(VK_F9))
	 {
		  if (GetAsyncKeyState('X') >> 15)
		  {
				triggerbot::execute();
		  }
	 }

	 return 0;
}