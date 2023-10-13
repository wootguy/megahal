#pragma once

/*
 *  Copyright (C) 1998 Jason Hutchens
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the license or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.  See the Gnu Public License for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  675 Mass Ave, Cambridge, MA 02139, USA.
 * 
 *  Oct 2023 - Modified by wootguy
 */


void megahal_setnoprompt (void);
void megahal_setnowrap (void);
void megahal_setnobanner (void);

void megahal_seterrorfile(char *filename);
void megahal_setstatusfile(char *filename);

void megahal_initialize(void);

char *megahal_initial_greeting(void);

int megahal_command(char *input);

char *megahal_do_reply(char *input, int log);
void megahal_learn_no_reply(char *input, int log);
void megahal_output(char *output);

void megahal_cleanup(void);
