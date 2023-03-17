cmake_minimum_required(VERSION 2.6)

INCLUDE_DIRECTORIES(${LIBSPDM_DIR}/include
                    ${SPDM_EMU_DIR}/include
)

SET(src_vtpm_responder_lib
    vtpm_dispatch.c
)

ADD_LIBRARY(vtpm_responder_lib STATIC ${src_vtpm_responder_lib})
