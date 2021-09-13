#pragma once

#include <stdint.h>
#include <string>

class SystemError
{
public:
    SystemError(int errorno, const std::string& syscall, const std::string& message, const std::string& path)
        : m_errorno(errorno), m_syscall(syscall), m_message(message), m_path(path)
    {}

    int errorno() const { return m_errorno; }
    std::string syscall() const { return m_syscall; }
    std::string message() const { return m_message; }
    std::string path() const { return m_path; }

private:
    int m_errorno;
    std::string m_syscall;
    std::string m_message;
    std::string m_path;
};

struct DiskUsage {
    uint64_t available;
    uint64_t free;
    uint64_t total;
};

DiskUsage GetDiskUsage(const char* path);
