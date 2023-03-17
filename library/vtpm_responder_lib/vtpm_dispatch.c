/**
 *  Copyright Notice:
 *  Copyright 2021-2022 DMTF. All rights reserved.
 *  License: BSD 3-Clause License. For full text see link: https://github.com/DMTF/libspdm/blob/main/LICENSE.md
 **/

#include "hal/base.h"
#include "hal/library/memlib.h"
#include "hal/library/debuglib.h"
#include "library/spdm_requester_lib.h"
#include "library/spdm_transport_vtpm_lib.h"
#include "library/vtpm_responder_lib.h"

// typedef struct {
//     vtpm_app_message_header_t header;
//     vtpm_get_secured_app_request_func_t func;
// } vtpm_secured_app_dispatch_struct_t;

// vtpm_secured_app_dispatch_struct_t m_vtpm_secured_app_dispatch[] = {
//     {{VTPM_APP_MESSAGE_TYPE_VTPM}, vtpm_get_response_secured_app_request },
// };

/**
 * Process the VTPM request and return the response.
 *
 *  @param request       the VTPM request message, the vtpm_app_message_header_t has been derived off.
 *  @param request_size  size in bytes of request.
 *  @param response      the VTPM response message.
 *  @param response_size size in bytes of response.
 *
 *  @retval LIBSPDM_STATUS_SUCCESS The request is processed and the response is returned.
 *  @return ERROR          The request is not processed.
 **/
libspdm_return_t vtpm_get_response_secured_app_request(const void *vtpm_context,
                                                       void *spdm_context,
                                                       const uint32_t *session_id,
                                                       const void *request,
                                                       size_t request_size,
                                                       void *response,
                                                       size_t *response_size)
{
    size_t index;
    LIBSPDM_ASSERT (*response_size > request_size);

    // revert the data in app_request
    for (index = 0; index < request_size; index++) {
        ((uint8_t *)response)[index] = ((uint8_t *)request)[request_size - index - 1];
    }
    *response_size = request_size;

    return LIBSPDM_STATUS_SUCCESS;
}
