/*
 *      pipecontroller.c
 *
 *      Copyright 2013 gogoprog @ gmail . com
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include "pipecontroller.h"

#include <glib.h>

void *pc_thread(struct PipeContext *ctx)
{
    while (1)
    {
        puts(ctx->file_name->str);
        sleep(1);
    }
}

struct PipeContext *pc_open(const char *file_name, FmMainWin *win)
{
    struct PipeContext *ctx;
    pthread_t tid = 0;

    ctx = (struct PipeContext*)g_malloc(sizeof(struct PipeContext));

    ctx->file_name = g_string_new(file_name);

    pthread_create(&tid, NULL, pc_thread, (void*)ctx);

    return ctx;
}
