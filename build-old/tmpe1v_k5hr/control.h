#include "test.h"

static inline void setup_control_plane() {
	int ok;
	int tableFileDescriptor;
	struct pipe_Check_src_ip_key key_pipe_Check_src_ip0 = {};
	key_pipe_Check_src_ip0.field0 = 0x0a01****;
	tableFileDescriptor = BPF_OBJ_GET(MAP_PATH "/pipe_Check_src_ip");
	if (tableFileDescriptor < 0) {fprintf(stderr, "map pipe_Check_src_ip not loaded"); exit(1); }
	struct pipe_Check_src_ip_value value_pipe_Check_src_ip0 = {
		.action = pipe_Reject,
		.u = {.pipe_Reject = {}},
	};
	ok = BPF_USER_MAP_UPDATE_ELEM(tableFileDescriptor, &key_pipe_Check_src_ip0, &value_pipe_Check_src_ip0, BPF_ANY);
	if (ok != 0) { perror("Could not write in pipe_Check_src_ip");exit(1); }
}
