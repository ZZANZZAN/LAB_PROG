#include <stdio.h>
#include <stdlib.h>
#include "HF\option_With_LIst.h"
#include "HF\struct.h"
#include "HF\free_List.h"
#include "HF\Program_output_input.h"
#include "HF\command_selecting.h"

int main(){
    head *q = NULL;
    q = create_head_DLL();

    fill_list(q);
    command_selecting(q);

    if((q -> N) == 1) free_head(q);
    else if((q -> N) > 1) free_list(q);
    else if ((q -> N) == 0) free(q);

    printf("\n");

    return 0;
}
