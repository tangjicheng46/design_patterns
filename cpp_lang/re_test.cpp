#include <iostream>
#include <regex>
#include <string>

void test1() {
  std::regex html("<.*>.*</.*>");
  bool ret = std::regex_match("<html>val</html>", html);
  std::cout << std::boolalpha << ret << std::endl;
  std::cout << std::boolalpha << std::regex_match("<xml>val<xml>", html) << std::endl;
  std::cmatch m;
  ret = std::regex_search("aaa<html>val</html>", m, html);
  std::cout << m.str() << std::endl << m.position() << std::endl;
}

void test2() {
  std::string pattern_str("[abc]{2}.+(!!!)[123]\\1(xxx).*(?:x)");
  std::regex pattern(pattern_str);
  std::smatch m;
  std::string text("acHELLO!!!2!!!xxxxx");
  bool is_matched = std::regex_match(text, m, pattern);
  if (!is_matched) {
    std::cout << "NOT MATCHED\n";
    return;
  }
  std::cout << "text length: " << text.length() << std::endl;
  std::cout << "m.size: " << m.size() << ", m.length: " << m.length() << std::endl;
  std::cout << m[0] << "\n" << m[1] << "\n" << m[2] << std::endl;
}

void test3() {
  // std::string pattern_str("Jack(?=Ross|Alex).*");
  std::string pattern_str("Jack(?!Ross|Alex).*");
  std::regex pattern(pattern_str);
  std::string text("JackAlexHello");
  std::smatch m;
  bool is_matched = std::regex_match(text, m, pattern);
  if (!is_matched) {
    std::cout << "NOT MATCHED\n";
    return;
  }
  std::cout << m[0] << std::endl;
}

void test4() {
  std::string pattern_str("a(Jack)[abc](\\1Ross)");
  std::regex pattern(pattern_str.c_str());
  std::string text("aJackcJackRoss");
  std::smatch m;
  bool is_matched = std::regex_match(text, m, pattern);
  std::cout << std::boolalpha << is_matched << std::endl;
  for (int i = 0; i < m.size(); i++) {
    std::cout << m.position(i) << " : " << m.str(i) << std::endl;
  }
  std::cout << m.position(m.size() + 1) << " : " << m.str(m.size()) << std::endl;
  std::cout << "prefix: " << m.prefix() << std::endl;
}

void test5() {
  std::string pattern_str("<(.){1}>.*</\\1>");
  std::regex pattern(pattern_str);
  std::smatch m;
  std::string text("<h>Hello</h> <p>World</p>");

  while (text != "") {
    bool is_matched = std::regex_search(text, m, pattern);
    if (!is_matched) {
      break;
    }
    std::cout << m.size() << std::endl;
    std::cout << "prefix: " << m.prefix().str() << " matched: " << m[0].str() << " suffix: " << m.suffix().str()
              << std::endl;
    std::cout << "position: " << m.position() << std::endl;
    std::cout << std::boolalpha << is_matched << std::endl;

    text = text.substr(m.position() + m[0].length());
  }
  return;
}

void test6() {
  // 匹配对话
  std::regex pattern("(\"|“|”)((?!\"|“|”).)*\\1");
  std::smatch m;
  std::vector<std::string> vec{"你好，“哈哈”", "“怎么说呢”", "你说啥，“什么”"};
  for (auto iter : vec) {
    bool is_match = std::regex_match(iter, m, pattern);
    std::cout << std::boolalpha << is_match << std::endl;
  }
}

int main() {
  // test1();
  // test2();
  // test3();
  // test4();
  // test5();
  test6();

  return 0;
}