// Copyright 2022 Frolov Gleb

#include "include/regular_expressions.h"

Text_for_regexp::Text_for_regexp() { text = ""; }
Text_for_regexp::Text_for_regexp(std::string _text) { text = _text; }
std::string Text_for_regexp::Get_text() { return text; }

/*
0123456789
qwer tyui asdf ghjk
*/

std::string Text_for_regexp::Search_for_regexp(std::string regexp) {
  std::string result_str;
  int begin_i, end_i, count, true_i;

  for (int i = 0; i < text.length();) {
    true_i = text.find(regexp, i);
    if (true_i != std::string::npos) {
      begin_i = text.rfind(' ', true_i);
      if (begin_i == std::string::npos) {
        begin_i = -1;
      }
      end_i = text.find(' ', true_i);
      if (end_i == std::string::npos) {
        end_i = text.length() + 1;
      }
      count = end_i - begin_i - 1;
      if (begin_i == 0) {
        result_str.append(text, begin_i, count);
      }
      else result_str.append(text, begin_i + 1, count);
      result_str.push_back('|');
      i = end_i + 1;
    }
    else if (i == 0) return "Not found";
    else break;
  }
  result_str.erase(result_str.length() - 1);
  return result_str;
}
