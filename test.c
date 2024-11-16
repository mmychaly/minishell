Error opening input file: No such file or directory
==15771== 
==15771== FILE DESCRIPTORS: 5 open (3 std) at exit.
==15771== Open file descriptor 20: /home/mikerf/.vscode-server/data/logs/20241022T192244/remoteagent.log
==15771==    <inherited from parent>
==15771== 
==15771== Open file descriptor 19: /home/mikerf/.vscode-server/data/logs/20241022T192244/ptyhost.log
==15771==    <inherited from parent>
==15771== 
==15771== 
==15771== HEAP SUMMARY:
==15771==     in use at exit: 209,082 bytes in 249 blocks
==15771==   total heap usage: 671 allocs, 422 frees, 239,959 bytes allocated
==15771== 
==15771== 3 bytes in 3 blocks are still reachable in loss record 1 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4897CFD: replace_history_entry (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E62C: readline_internal_teardown (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D2A: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4 bytes in 1 blocks are still reachable in loss record 2 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x10BD23: ft_strdup (in /home/mikerf/projects_group/minishell/minishell)
==15771==    by 0x109CE4: handle_command_args (in /home/mikerf/projects_group/minishell/minishell)
==15771==    by 0x109EB7: parse_single_command (in /home/mikerf/projects_group/minishell/minishell)
==15771==    by 0x10A042: parse_pipeline (in /home/mikerf/projects_group/minishell/minishell)
==15771==    by 0x1099A2: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4 bytes in 1 blocks are still reachable in loss record 3 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x10BD23: ft_strdup (in /home/mikerf/projects_group/minishell/minishell)
==15771==    by 0x109AF4: handle_redirection (in /home/mikerf/projects_group/minishell/minishell)
==15771==    by 0x109E9E: parse_single_command (in /home/mikerf/projects_group/minishell/minishell)
==15771==    by 0x10A042: parse_pipeline (in /home/mikerf/projects_group/minishell/minishell)
==15771==    by 0x1099A2: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8 bytes in 1 blocks are still reachable in loss record 4 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x496358E: strdup (strdup.c:42)
==15771==    by 0x4B01D17: _nc_trim_sgr0 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B006A8: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8 bytes in 1 blocks are still reachable in loss record 5 of 81
==15771==    at 0x484DCD3: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A1491: xrealloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488D626: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488DE0D: rl_expand_prompt (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D1BF: rl_set_prompt (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CCF: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 9 bytes in 1 blocks are still reachable in loss record 6 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x496358E: strdup (strdup.c:42)
==15771==    by 0x4AF7D54: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB098: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x48918B1: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4892CE1: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FB56: _rl_internal_char_cleanup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FD8F: readline_internal_char (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D14: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 9 bytes in 1 blocks are still reachable in loss record 7 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x496358E: strdup (strdup.c:42)
==15771==    by 0x4AF7D54: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB098: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4891F9A: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4892CE1: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FB56: _rl_internal_char_cleanup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FD8F: readline_internal_char (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D14: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 10 bytes in 1 blocks are still reachable in loss record 8 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E694: readline_internal_teardown (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D2A: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 12 bytes in 1 blocks are still reachable in loss record 9 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D1E3: rl_set_prompt (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CCF: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 12 bytes in 1 blocks are still reachable in loss record 10 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488D5F2: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488DE0D: rl_expand_prompt (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D1BF: rl_set_prompt (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CCF: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 13 bytes in 1 blocks are still reachable in loss record 11 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x496358E: strdup (strdup.c:42)
==15771==    by 0x4AF3377: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AF5BF8: _nc_first_db (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF696: _nc_read_entry2 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF711: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF866: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 13 bytes in 1 blocks are still reachable in loss record 12 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488EBF5: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A38: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 15 bytes in 1 blocks are still reachable in loss record 13 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x496358E: strdup (strdup.c:42)
==15771==    by 0x4AFF8AE: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 16 bytes in 1 blocks are still reachable in loss record 14 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4888B26: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 16 bytes in 1 blocks are still reachable in loss record 15 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x109F71: parse_pipeline (in /home/mikerf/projects_group/minishell/minishell)
==15771==    by 0x1099A2: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 20 bytes in 1 blocks are still reachable in loss record 16 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488BD8B: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488E6C9: rl_parse_and_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488EB6C: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A38: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 24 bytes in 1 blocks are still reachable in loss record 17 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x49DAF34: tsearch (tsearch.c:337)
==15771==    by 0x4AF7D6E: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB098: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01C7D: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01D09: _nc_trim_sgr0 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B006A8: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 24 bytes in 1 blocks are still reachable in loss record 18 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x49DAF9E: tsearch (tsearch.c:337)
==15771==    by 0x4AF7D6E: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB098: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x48918B1: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4892CE1: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FB56: _rl_internal_char_cleanup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FD8F: readline_internal_char (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D14: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 24 bytes in 1 blocks are still reachable in loss record 19 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x49DAF9E: tsearch (tsearch.c:337)
==15771==    by 0x4AF7D6E: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB098: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4891F9A: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4892CE1: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FB56: _rl_internal_char_cleanup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FD8F: readline_internal_char (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D14: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 24 bytes in 2 blocks are still reachable in loss record 20 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4899F28: add_history (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109940: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 25 bytes in 1 blocks are still reachable in loss record 21 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF5624: _nc_home_terminfo (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AF5BE2: _nc_first_db (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF696: _nc_read_entry2 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF711: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF866: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 40 bytes in 1 blocks are still reachable in loss record 22 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x10994A: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 42 bytes in 2 blocks are still reachable in loss record 23 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4897B39: alloc_history_entry (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4899F65: add_history (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109940: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 46 bytes in 1 blocks are still reachable in loss record 24 of 81
==15771==    at 0x484DCD3: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF46CC: _nc_doalloc (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF16F: _nc_read_termtype (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF52A: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01C40: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF6BB: _nc_read_entry2 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF711: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF866: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771== 
==15771== 46 bytes in 1 blocks are still reachable in loss record 25 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF3FDE: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF87D: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 48 bytes in 1 blocks are still reachable in loss record 26 of 81
==15771==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF5833: _nc_first_db (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF696: _nc_read_entry2 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF711: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF866: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 48 bytes in 2 blocks are still reachable in loss record 27 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4897B1D: alloc_history_entry (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4899F65: add_history (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109940: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 70 bytes in 1 blocks are still reachable in loss record 28 of 81
==15771==    at 0x484DCD3: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF46CC: _nc_doalloc (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB731: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x48918B1: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4892CE1: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FB56: _rl_internal_char_cleanup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FD8F: readline_internal_char (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D14: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 72 bytes in 1 blocks are still reachable in loss record 29 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x109FAD: parse_pipeline (in /home/mikerf/projects_group/minishell/minishell)
==15771==    by 0x1099A2: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 72 bytes in 3 blocks are still reachable in loss record 30 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4897CAA: replace_history_entry (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E62C: readline_internal_teardown (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D2A: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 78 bytes in 1 blocks are still reachable in loss record 31 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF404B: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF87D: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 93 bytes in 1 blocks are still reachable in loss record 32 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x496358E: strdup (strdup.c:42)
==15771==    by 0x4AF7D54: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB098: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01C7D: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01D09: _nc_trim_sgr0 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B006A8: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 94 bytes in 1 blocks are still reachable in loss record 33 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF579A: _nc_first_db (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF696: _nc_read_entry2 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF711: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF866: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 94 bytes in 1 blocks are still reachable in loss record 34 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF795B: _nc_tparm_analyze (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AF7C62: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB098: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01C7D: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01D09: _nc_trim_sgr0 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B006A8: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 114 bytes in 3 blocks are still reachable in loss record 35 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4897CCF: replace_history_entry (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E62C: readline_internal_teardown (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D2A: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 156 bytes in 1 blocks are still reachable in loss record 36 of 81
==15771==    at 0x484DCD3: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF46CC: _nc_doalloc (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF197: _nc_read_termtype (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF52A: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01C40: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF6BB: _nc_read_entry2 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF711: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF866: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771== 
==15771== 168 bytes in 1 blocks are still reachable in loss record 37 of 81
==15771==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF7CCD: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB098: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01C7D: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01D09: _nc_trim_sgr0 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B006A8: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 168 bytes in 1 blocks are still reachable in loss record 38 of 81
==15771==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF7CCD: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB098: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x48918B1: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4892CE1: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FB56: _rl_internal_char_cleanup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FD8F: readline_internal_char (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D14: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 168 bytes in 1 blocks are still reachable in loss record 39 of 81
==15771==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF7CCD: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFB098: _nc_tiparm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4891F9A: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4892CE1: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FB56: _rl_internal_char_cleanup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487FD8F: readline_internal_char (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888D14: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 256 bytes in 1 blocks are still reachable in loss record 40 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888C86: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 608 bytes in 1 blocks are still reachable in loss record 41 of 81
==15771==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AFF37E: _nc_read_termtype (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF52A: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01C40: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF6BB: _nc_read_entry2 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF711: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF866: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 608 bytes in 1 blocks are still reachable in loss record 42 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF4119: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF87D: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 760 bytes in 1 blocks are still reachable in loss record 43 of 81
==15771==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AFF819: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 940 bytes in 1 blocks are still reachable in loss record 44 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AFF287: _nc_read_termtype (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF52A: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01C40: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF6BB: _nc_read_entry2 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF711: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF866: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 1,024 bytes in 1 blocks are still reachable in loss record 45 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A14A7: xrealloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488AC7B: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488AD67: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4893C7E: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E458: readline_internal_setup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CF8: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 1,024 bytes in 1 blocks are still reachable in loss record 46 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A14A7: xrealloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488AC8B: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488AD67: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4893C7E: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E458: readline_internal_setup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CF8: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 1,024 bytes in 1 blocks are still reachable in loss record 47 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A14A7: xrealloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488ACA2: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488AD67: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4893C7E: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E458: readline_internal_setup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CF8: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 1,024 bytes in 1 blocks are still reachable in loss record 48 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A14A7: xrealloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488ACBB: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488AD67: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4893C7E: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E458: readline_internal_setup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CF8: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 1,024 bytes in 1 blocks are still reachable in loss record 49 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488ADC5: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4893C7E: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E458: readline_internal_setup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CF8: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 1,024 bytes in 1 blocks are still reachable in loss record 50 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488ADDA: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4893C7E: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E458: readline_internal_setup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CF8: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 1,024 bytes in 1 blocks are still reachable in loss record 51 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488ADE8: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4893C7E: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E458: readline_internal_setup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CF8: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 1,024 bytes in 1 blocks are still reachable in loss record 52 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488ADF6: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4893C7E: rl_redisplay (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E458: readline_internal_setup (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CF8: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 1,536 bytes in 1 blocks are still reachable in loss record 53 of 81
==15771==    at 0x484DCD3: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A1491: xrealloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E877: rl_add_funmap_entry (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E8C8: rl_initialize_funmap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A2C: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 1,664 bytes in 1 blocks are still reachable in loss record 54 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AFEACD: _nc_read_termtype (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF52A: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01C40: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF6BB: _nc_read_entry2 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF711: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF866: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 2,032 bytes in 1 blocks are still reachable in loss record 55 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C419: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 2,240 bytes in 140 blocks are still reachable in loss record 56 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E822: rl_add_funmap_entry (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487E8C8: rl_initialize_funmap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A2C: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 3,904 bytes in 1 blocks are still reachable in loss record 57 of 81
==15771==    at 0x484DCD3: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF46CC: _nc_doalloc (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF1B5: _nc_read_termtype (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF52A: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B01C40: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF6BB: _nc_read_entry2 (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF711: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF866: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771== 
==15771== 3,904 bytes in 1 blocks are still reachable in loss record 58 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF3FFF: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AFF87D: _nc_setupterm (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4B004C9: tgetent_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C1CD: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4,016 bytes in 1 blocks are still reachable in loss record 59 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4899FD6: add_history (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109940: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4,080 bytes in 1 blocks are still reachable in loss record 60 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C3F9: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4,112 bytes in 1 blocks are still reachable in loss record 61 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489BDD5: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C31F: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4,112 bytes in 1 blocks are still reachable in loss record 62 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489BE5A: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C31F: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4,112 bytes in 1 blocks are still reachable in loss record 63 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489BE5A: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C32B: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4,112 bytes in 1 blocks are still reachable in loss record 64 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489BE5A: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C337: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4,112 bytes in 1 blocks are still reachable in loss record 65 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488894C: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A84: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4,112 bytes in 1 blocks are still reachable in loss record 66 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488894C: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A93: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 4,112 bytes in 1 blocks are still reachable in loss record 67 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488894C: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888AB8: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 7,952 bytes in 1 blocks are still reachable in loss record 68 of 81
==15771==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x4AF2C97: ??? (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AF43AF: _nc_find_type_entry (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x4AF6E4C: tgetstr_sp (in /usr/lib/x86_64-linux-gnu/libtinfo.so.6.3)
==15771==    by 0x489C21A: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8,224 bytes in 2 blocks are still reachable in loss record 69 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489BE47: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C31F: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8,224 bytes in 2 blocks are still reachable in loss record 70 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489BDD5: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C32B: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8,224 bytes in 2 blocks are still reachable in loss record 71 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489BE47: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C32B: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8,224 bytes in 2 blocks are still reachable in loss record 72 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489BDD5: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C337: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8,224 bytes in 2 blocks are still reachable in loss record 73 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489BE47: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x489C337: _rl_init_terminal_io (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A0F: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8,224 bytes in 2 blocks are still reachable in loss record 74 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488893D: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A84: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8,224 bytes in 2 blocks are still reachable in loss record 75 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488893D: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A93: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8,224 bytes in 2 blocks are still reachable in loss record 76 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488893D: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888AB8: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8,224 bytes in 2 blocks are still reachable in loss record 77 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888AD2: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 8,224 bytes in 2 blocks are still reachable in loss record 78 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888AE1: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 12,336 bytes in 3 blocks are still reachable in loss record 79 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888914: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A93: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 12,336 bytes in 3 blocks are still reachable in loss record 80 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488875D: rl_bind_keyseq_if_unbound_in_map (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888914: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888AB8: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== 28,784 bytes in 7 blocks are still reachable in loss record 81 of 81
==15771==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==15771==    by 0x48A0BAC: xmalloc (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487D251: rl_make_bare_keymap (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x487DB6A: rl_generic_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488E99E: rl_parse_and_bind (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x488EB6C: ??? (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888A38: rl_initialize (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x4888CD4: readline (in /usr/lib/x86_64-linux-gnu/libreadline.so.8.1)
==15771==    by 0x109915: main (in /home/mikerf/projects_group/minishell/minishell)
==15771== 
==15771== LEAK SUMMARY:
==15771==    definitely lost: 0 bytes in 0 blocks
==15771==    indirectly lost: 0 bytes in 0 blocks
==15771==      possibly lost: 0 bytes in 0 blocks
==15771==    still reachable: 209,082 bytes in 249 blocks
==15771==         suppressed: 0 bytes in 0 blocks
==15771== 
==15771== For lists of detected and suppressed errors, rerun with: -s
==15771== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)