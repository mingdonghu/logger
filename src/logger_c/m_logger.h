#ifndef __M_LOGGER_H
#define __M_LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ulog.h"

// #define LOG_TRACE(...) ULOG_TRACE(__VA_ARGS__)
#define LOG_DEBUG(...) ULOG_DEBUG(__VA_ARGS__)
#define LOG_INFO(...) ULOG_INFO(__VA_ARGS__)
#define LOG_WARNING(...) ULOG_WARNING(__VA_ARGS__)
#define LOG_ERROR(...) ULOG_ERROR(__VA_ARGS__)
// #define LOG_CRITICAL(...) ULOG_CRITICAL(__VA_ARGS__)
// #define LOG_ALWAYS(...) ULOG_ALWAYS(__VA_ARGS__)

void error_handle(const char* filename, int lineno);

void m_logger_init(void);


#ifdef __cplusplus
}
#endif

#endif /* __M_LOGGER_H */
