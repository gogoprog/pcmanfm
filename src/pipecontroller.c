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
#include <string.h>

void pc_on_data(struct PipeContext *ctx, const char *line)
{
    const size_t line_length = strlen(line);

    if (line_length > 6)
    {
        if (!strncmp(line,"CWD:",4))
        {
            //fm_main_win_chdir_by_name(ctx->win, line + 5);

            gtk_signal_emit_by_name(GTK_OBJECT(ctx->win), "directory-changed");
        }
    }
}

void *pc_thread(struct PipeContext *ctx)
{
    FILE *fp;
    char line[1024];

    if(fp = fopen(ctx->file_name->str, "r"))
    {
        while (fgets(line, 1024, fp) != NULL)
        {
            printf("%s: %s", ctx->file_name->str, line);
            pc_on_data(ctx,line);
        }
    }
    else
    {
        puts("Failure");
    }

    return 0;
}

struct PipeContext *pc_open(const char *file_name, FmMainWin *win)
{
    struct PipeContext *ctx;
    pthread_t tid = 0;

    ctx = (struct PipeContext*)g_malloc(sizeof(struct PipeContext));

    ctx->file_name = g_string_new(file_name);

    pthread_create(&tid, NULL, (void * (*)(void *)) pc_thread, (void*)ctx);

    return ctx;
}
