#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "py/builtin.h"
#include "py/compile.h"
#include "py/runtime.h"
#include "py/repl.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "shared/runtime/pyexec.h"

static char *stack_top;
#if MICROPY_ENABLE_GC
static char heap[2048];
#endif

int main(int argc, char **argv) {
	int stack_dummy;
	stack_top = (char *)&stack_dummy;

#if MICROPY_ENABLE_GC
	gc_init(heap, heap + sizeof(heap));
#endif
	mp_init();
#if MICROPY_ENABLE_COMPILER
#if MICROPY_REPL_EVENT_DRIVEN
	pyexec_event_repl_init();
	for (;;) {
		int c = mp_hal_stdin_rx_chr();
		if (pyexec_event_repl_process_char(c)) {
			break;
		}
	}
#else
	pyexec_friendly_repl();
#endif
#endif
	mp_deinit();
	return 0;
}

#if MICROPY_ENABLE_GC
void gc_collect(void) {
	// WARNING: This gc_collect implementation doesn't try to get root
	// pointers from CPU registers, and thus may function incorrectly.
	void *dummy;
	gc_collect_start();
	gc_collect_root(&dummy, ((mp_uint_t)stack_top - (mp_uint_t)&dummy) / sizeof(mp_uint_t));
	gc_collect_end();
	gc_dump_info();
}
#endif

mp_lexer_t *mp_lexer_new_from_file(const char *filename) {
	mp_raise_OSError(MP_ENOENT);
}

mp_import_stat_t mp_import_stat(const char *path) {
	return MP_IMPORT_STAT_NO_EXIST;
}

void NORETURN __fatal_error(const char *msg) {
	while (1) {
		;
	}
}

#ifndef NDEBUG
void MP_WEAK __assert_func(const char *file, int line, const char *func, const char *expr) {
	printf("Assertion '%s' failed, at file %s:%d\n", expr, file, line);
	__fatal_error("Assertion failed");
}
#endif
