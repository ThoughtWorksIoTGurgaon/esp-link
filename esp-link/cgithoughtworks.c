#include <esp8266.h>
#include "cgithoughtworks.h"
#include "cgi.h"
#include "status.h"
#include "config.h"
#include "log.h"

#ifdef CGITHOUGHTWORKS_DBG
#define DBG(format, ...) do { os_printf(format, ## __VA_ARGS__); } while(0)
#else
#define DBG(format, ...) do { } while(0)
#endif

# define VERS_STR_STR(V) #V
# define VERS_STR(V) VERS_STR_STR(V)

//Toggle GPIO2 pin
int ICACHE_FLASH_ATTR cgiThoughtWorksGPIOToggle(HttpdConnData *connData) {

    char buff[1024];
    if (connData->conn == NULL) return HTTPD_CGI_DONE; // Connection aborted. Clean up.
    DBG("Now trying to toggle GPIO2");
    os_sprintf(buff,
               "{ "
               "\"toggle_status\": \"%s\" "
               " }",
               "true"
               );

    jsonHeader(connData, 200);
    httpdSend(connData, buff, -1);
    return HTTPD_CGI_DONE;
}
