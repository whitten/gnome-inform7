/*  Copyright 2006 P.F. Chimento
 *  This file is part of GNOME Inform 7.
 * 
 *  GNOME Inform 7 is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  GNOME Inform 7 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GNOME Inform 7; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
#ifndef COMPILE_H
#define COMPILE_H

#include <gnome.h>

#include "story.h"

void run_census(gboolean wait);
void compile_project(struct story *thestory);

void prepare_ni_compiler(struct story *thestory);
void start_ni_compiler(struct story *thestory);
void finish_ni_compiler(GPid pid, gint status, gpointer data);

void prepare_i6_compiler(struct story *thestory);
void start_i6_compiler(struct story *thestory);
void finish_i6_compiler(GPid pid, gint status, gpointer data);

void prepare_cblorb_compiler(struct story *thestory);
void start_cblorb_compiler(struct story *thestory);
void finish_cblorb_compiler(GPid pid, gint status, gpointer data);

void finish_refresh_index(struct story *thestory);    
void finish_save_debug_build(struct story *thestory);
void finish_run(struct story *thestory);
void finish_release(struct story *thestory);

GPid run_command(const gchar *wd, gchar **argv, GtkTextBuffer *output);
void set_up_io_channel(gint fd, GtkTextBuffer *output);
gboolean write_channel_to_buffer(GIOChannel *ioc, GIOCondition cond,
  gpointer buffer);

#endif
