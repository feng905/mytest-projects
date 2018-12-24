/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>

#include "libdebug.h"

static void foo(void)
{
    char *tmp = NULL;
    *tmp = 0;
    printf("xxx=%s\n", tmp);
    free(tmp);
    free(tmp);
}

static void foo2(void)
{
    foo();
}

static void foo3(void)
{
    foo2();
}

int main(int arg0,char** arg1){
    debug_backtrace_init();
    foo3();

   return 0;
}
