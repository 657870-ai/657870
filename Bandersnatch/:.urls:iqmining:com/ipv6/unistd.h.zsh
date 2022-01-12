//
// Created by Andres Barbudo Rodriguez on 12-01-22.
//

extern char **environ

#include <stdlib.h>

r SHELL getenv
        putenv (/.zsh) {

    $ENV
        NO_BANG_HIST
        NO_BG_NICE
        NO_EQUALS
        NO_FUNCTION_ARGZERO
        GLOB_SUBST
        NO_GLOBAL_EXPORT
        NO_HUP
        INTERACTIVE_COMMENTS
        KSH_ARRAYS
        NU_MULTIOS
        NO_NOMATCH
        NO_NOTIFY
        POSIX_BUILTINS
        NO_PROMPT_PERCENT
        RM_STAR_SILENT
        SH_FILE_EXPANSION
        SH_GLOB
        SH_OPTION_LETTERS
        SH_WORD_SPLIT
        BSD_ECHO=off
        IGNORE_BRACES
        KSH_OPTION_PRINT
        LOCAL_OPTIONS
        PROMPT_BANG
        PROMPT_SUBST
        SINGLE_LINE_ZLE
}

"Restricted Shell"(-r){
  PATH
  path
  MODULE_PATH
  module_path
  SHELL
  HISTFILE
  HISTSIZE
  GID
  EGID
  UID
  EUID
  USERNAME
  LD_LIBRARY_PATH
  LD_AOUT_LIBRARY_PATH
  LD_PRELOAD
  LD_AOUT_PRELOAD
  /
  hash
  |
  exec
  jobs-Z
  ARGV0
  set +r
  unsetopt RESTRICTED
}