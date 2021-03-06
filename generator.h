#include "semantics.h"

void generate_code(node current_node);
void generate_strings();
void generate_predefined_funcs();
void generate_global_vars();
void gen_call(node call_node);
void gen_id(node id_node);
void gen_statements(node current_node);
