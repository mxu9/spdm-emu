/**
 *  Copyright Notice:
 *  Copyright 2021-2022 DMTF. All rights reserved.
 *  License: BSD 3-Clause License. For full text see link: https://github.com/DMTF/libspdm/blob/main/LICENSE.md
 **/

#ifndef __VTPM_RESPONDER_LIB_H__
#define __VTPM_RESPONDER_LIB_H__

#include "library/vtpm_common_lib.h"

/**
 *  Process the VTPM request and return the response.
 *
 *  @param request       the MCTP request message, start from mctp_message_header_t.
 *  @param request_size  size in bytes of request.
 *  @param response      the MCTP response message, start from mctp_message_header_t.
 *  @param response_size size in bytes of response.
 *
 *  @retval LIBSPDM_STATUS_SUCCESS The request is processed and the response is returned.
 *  @return ERROR          The request is not processed.
 **/
libspdm_return_t vtpm_get_response_secured_app_request(const void *vtpm_context,
                                                       void *spdm_context,
                                                       const uint32_t *session_id,
                                                       const void *request, size_t request_size,
                                                       void *response, size_t *response_size);
#endif
