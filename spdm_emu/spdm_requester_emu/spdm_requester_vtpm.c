/**
 *  Copyright Notice:
 *  Copyright 2021-2022 DMTF. All rights reserved.
 *  License: BSD 3-Clause License. For full text see link: https://github.com/DMTF/spdm-emu/blob/main/LICENSE.md
 **/

#include "spdm_requester_emu.h"
#include "industry_standard/vtpm.h"

void *m_vtpm_context;

libspdm_return_t vtpm_process_session_message(void *spdm_context, uint32_t session_id)
{
    libspdm_return_t status;
    size_t vtpm_request_size;
    size_t vtpm_response_size;
    char vtpm_request[32] = {0};
    char vtpm_response[32] = {0};

    // vtpm_app_message_header_t* header = (vtpm_app_message_header_t*)vtpm_request;
    // header->app_message_type = VTPM_APP_MESSAGE_TYPE_VTPM;
    sprintf(vtpm_request, "%s", "Hello, vtpm!");
    vtpm_request_size = sizeof("Hello, vtpm!");

    status = libspdm_send_receive_data (spdm_context,
                                        &session_id,
                                        true,
                                        (const void *)vtpm_request,
                                        vtpm_request_size,
                                        (void *)vtpm_response,
                                        &vtpm_response_size);
    if (LIBSPDM_STATUS_IS_ERROR(status)) {
        return status;
    }

    return LIBSPDM_STATUS_SUCCESS;
}
