#ifndef NODE_HANDLERS_H
#define NODE_HANDLERS_H

/*************************** node_handlers.h ***********************************
 
  Description:  

*******************************************************************************/
/*------------------------------------------------------------------------------
  Version 0.1     Yasperzee   12'22     Cleaning and refactoring
 
------------------------------------------------------------------------------*/

#include "setup.h"
#include "build_json_docs.h"
#include "build_light_html.h"

void set_callbacks();
void getNodeData();
void getNodeInfo();
void getNodeDebug();
void getNodeSettings();
void putNodeSettings();
void handleNotFoundRest();
void restServerRoutingRest();
void handle_iot_rest_client_requests();

#endif // NODE_HANDLERS_H