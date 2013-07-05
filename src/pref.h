/*
 *      pref.h
 *      
 *      Copyright 2009 PCMan <pcman.tw@gmail.com>
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

#ifndef _PREF_DLG_H_
#define _PREF_DLG_H_

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef enum {
    PREF_GENERAL,
    PREF_INTERFACE,
    PREF_LAYOUT,
    PREF_VOLMAN,
    PREF_ADVANCED
}PrefDlgPage;

void fm_edit_preference( GtkWindow* parent, int page );

void fm_desktop_preference(GtkAction* act, GtkWindow* parent);

G_END_DECLS

#endif
