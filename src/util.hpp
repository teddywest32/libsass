#ifndef SASS_UTIL_H
#define SASS_UTIL_H

#include <vector>
#include <string>
#include <assert.h>
#include "sass.hpp"
#include "sass/base.h"
#include "ast_fwd_decl.hpp"

#define SASS_ASSERT(cond, msg) assert(cond && msg)

namespace Sass {

  #define out_of_memory() do {            \
      std::cerr << "Out of memory.\n";    \
      exit(EXIT_FAILURE);                 \
    } while (0)

  double round(double val, size_t precision = 0);
  double sass_atof(const char* str);
  const char* safe_str(const char *, const char* = "");
  void free_string_array(char **);
  char **copy_strings(const std::vector<std::string>&, char ***, int = 0);
  std::string read_css_string(const std::string& str);
  std::string evacuate_escapes(const std::string& str);
  std::string string_to_output(const std::string& str);
  std::string comment_to_string(const std::string& text);
  void newline_to_space(std::string& str);

  std::string quote(const std::string&, char q = 0);
  std::string unquote(const std::string&, char* q = 0, bool keep_utf8_sequences = false);
  char detect_best_quotemark(const char* s, char qm = '"');

  bool is_hex_doublet(double n);
  bool is_color_doublet(double r, double g, double b);

  bool peek_linefeed(const char* start);

  namespace Util {

    std::string rtrim(const std::string& str);

    std::string normalize_underscores(const std::string& str);
    std::string normalize_decimals(const std::string& str);
    std::string normalize_sixtuplet(const std::string& col);

    std::string vecJoin(const std::vector<std::string>& vec, const std::string& sep);
    bool containsAnyPrintableStatements(Block* b);

    bool isPrintable(Ruleset* r, Sass_Output_Style style = NESTED);
    bool isPrintable(Supports_Block* r, Sass_Output_Style style = NESTED);
    bool isPrintable(Media_Block* r, Sass_Output_Style style = NESTED);
    bool isPrintable(Comment* b, Sass_Output_Style style = NESTED);
    bool isPrintable(Block* b, Sass_Output_Style style = NESTED);
    bool isPrintable(String_Constant* s, Sass_Output_Style style = NESTED);
    bool isPrintable(String_Quoted* s, Sass_Output_Style style = NESTED);
    bool isPrintable(Declaration* d, Sass_Output_Style style = NESTED);
    bool isAscii(const char chr);

  }
}
#endif
