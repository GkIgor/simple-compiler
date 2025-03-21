#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <string>
#include <sys/utsname.h>

#ifdef _WIN32
#include <windows.h>
#endif

namespace frontend
{
  bool isLittleEndian();

  std::map<std::string, std::string> get_current_os();

} // namespace frontend

#endif // !UTILS_H