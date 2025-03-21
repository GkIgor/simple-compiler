#include "utils.hpp"

namespace frontend
{
  std::map<std::string, std::string> get_current_os()
  {
    std::map<std::string, std::string> os_info;

#ifdef _WIN32
    SYSTEM_INFO sysInfo;
    GetNativeSystemInfo(&sysInfo);

    std::string arch;
    switch (sysInfo.wProcessorArchitecture)
    {
    case PROCESSOR_ARCHITECTURE_AMD64:
      arch = "x86_64";
      break;
    case PROCESSOR_ARCHITECTURE_ARM64:
      arch = "ARM64";
      break;
    case PROCESSOR_ARCHITECTURE_INTEL:
      arch = "x86";
      break;
    default:
      arch = "Desconhecido";
    }

    os_info.insert({"os", "Windows " + arch})

#elif __linux__ || __APPLE__
    struct utsname info;

    if (uname(&info) == 0)
    {
      os_info.insert({"os", std::string(info.sysname) + " " + info.machine});
    }
#endif
        return os_info;
  }
} // namespace frontend
