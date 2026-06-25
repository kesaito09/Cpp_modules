#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
 public:
  struct s_contact {
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string secret;
  };

  void set(s_contact& data);
  static bool is_empty_field(const std::string& field);
  static bool validate_format(const s_contact& data);
  static std::string format_field(const std::string& field);
  static void display_header(void);
  void display_row(int index) const;
  void display_details(void) const;

 private:
  s_contact _data;
};

#endif
