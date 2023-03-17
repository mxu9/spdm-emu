cmake_minimum_required(VERSION 2.6)

INCLUDE_DIRECTORIES(${LIBSPDM_DIR}/include
                    ${SPDM_EMU_DIR}/include
)

SET(src_vtpm_requester_lib
    vtpm_send_receive.c
)

ADD_LIBRARY(vtpm_requester_lib STATIC ${src_vtpm_requester_lib})
