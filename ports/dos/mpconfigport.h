#include <alloca.h>
#include <stdint.h>

#define MICROPY_CONFIG_ROM_LEVEL (MICROPY_CONFIG_ROM_LEVEL_MINIMUM)
#define MICROPY_ENABLE_COMPILER     (1)

#define MICROPY_QSTR_EXTRA_POOL           mp_qstr_frozen_const_pool
#define MICROPY_ENABLE_GC                 (1)
#define MICROPY_HELPER_REPL               (1)
#define MICROPY_MODULE_FROZEN_MPY         (1)
#define MICROPY_ENABLE_EXTERNAL_IMPORT    (1)

#define MICROPY_ALLOC_PATH_MAX            (256)
#define MICROPY_ALLOC_PARSE_CHUNK_INIT    (16)

typedef intptr_t mp_int_t; // must be pointer size
typedef uintptr_t mp_uint_t; // must be pointer size
typedef long mp_off_t;

#define MICROPY_HW_BOARD_NAME "dos"
#define MICROPY_HW_MCU_NAME "8086"

#define MP_STATE_PORT MP_STATE_VM
#define MP_ENDIANNESS_LITTLE 1

#define NORETURN __declspec(noreturn)
#define MP_NOINLINE
#define MP_ALWAYSINLINE
