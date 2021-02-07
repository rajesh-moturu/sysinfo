#include "sysinfowindowsimpl.h"

#include <windows.h>

SysInfoWindowsImpl::SysInfoWindowsImpl():
  SysInfo(),
  mCpuLoadLastValues()
{

}

void SysInfoWindowsImpl::init()
{
  mCpuLoadLastValues = cpuRawData();
}

double SysInfoWindowsImpl::memoryUsed()
{
  MEMORYSTATUSEX memory_status;
  memory_status.dwLength = sizeof (MEMORYSTATUSEX);
  GlobalMemoryStatusEx(&memory_status);
  qulonglong memory_physical_used =
      memory_status.ullTotalPhys - memory_status.ullAvailPhys;
  return (double)memory_physical_used/(double)memory_status.ullTotalPhys * 100;
}
